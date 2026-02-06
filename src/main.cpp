/**
 * @file main.cpp
 * @brief File with the DllMain function, used for initialization.
 */

#include "backend/backend.hpp"
#include "byte_patch_manager.hpp"
#include "common.hpp"
#include "fiber_pool.hpp"
#include "file_manager.hpp"
#include "gta/big_program.hpp"
#include "gta/joaat.hpp"
#include "hooking/hooking.hpp"
#include "invoker.hpp"
#include "lua/lua_manager.hpp"
#include "native_hooks/native_hooks.hpp"
#include "pointers.hpp"
#include "script_mgr.hpp"
#include "security/ObfVar.hpp"
#include "services/gta_data/gta_data_service.hpp"
#include "services/notifications/notification_service.hpp"
#include "services/players/player_service.hpp"
#include "services/script_patcher/script_patcher_service.hpp"
#include "services/tunables/tunables_service.hpp"
#include "thread_pool.hpp"
#include "util/is_enhanced.hpp"


#ifdef ENABLE_EXCEPTION_HANDLER
	#include "logger/exception_handler.hpp"
#endif
#ifdef ENABLE_GUI
	#include "gui.hpp"
	#include "renderer/renderer.hpp"
	#include "renderer/renderer_dx11.hpp"
	#include "renderer/renderer_dx12.hpp"
#endif

BOOL APIENTRY DllMain(HMODULE hmod, DWORD reason, PVOID)
{
	using namespace big;
	if (reason == DLL_PROCESS_ATTACH)
	{
		DisableThreadLibraryCalls(hmod);

		g_is_enhanced = big::is_enhanced();

		g_hmodule     = hmod;
		g_main_thread = CreateThread(
		    nullptr,
		    0,
		    [](PVOID) -> DWORD {
#ifdef ENABLE_EXCEPTION_HANDLER
			    auto handler = exception_handler();
#endif
			    std::srand(std::chrono::system_clock::now().time_since_epoch().count());

			    LPCSTR lpClassName = g_is_enhanced ? "sgaWindow" : "grcWindow";
			    while (!FindWindow(lpClassName, nullptr))
				    std::this_thread::sleep_for(1s);

			    std::filesystem::path base_dir = std::getenv("appdata");
			    base_dir /= PROJECT_NAME;
			    g_file_manager.init(base_dir);
			    g_log.initialize(PROJECT_NAME,
			        g_file_manager.get_project_file("./cout.log")
#ifndef ENABLE_GUI
			            ,
			        false // Disable log window when GUI is disabled.
#endif
			    );
			    try
			    {
				    LOG(INFO) << R"kek(
 ______  _       ______                        ______  
(____  \(_)     (____  \                      (_____ \
 ____)  )_  ____ ____)  ) ____  ___  ____ _   _ ____) )
|  __  (| |/ _  |  __  ( / _  |/___)/ _  ) | | /_____/ 
| |__)  ) ( ( | | |__)  | ( | |___ ( (/ / \ V /_______ 
|______/|_|\_|| |______/ \_||_(___/ \____) \_/(_______)
          (_____|)kek";

				    auto thread_pool_instance = std::make_unique<thread_pool>();
				    LOG(INFO) << "Thread pool initialized.";

				    g.init(g_file_manager.get_project_file("./settings.json"));
				    LOG(INFO) << "Settings Loaded.";

				    auto pointers_instance = std::make_unique<pointers>();
				    LOG(INFO) << "Pointers initialized.";

				    auto byte_patch_manager_instance = std::make_unique<byte_patch_manager>();
				    LOG(INFO) << "Byte Patch Manager initialized.";

#ifdef ENABLE_GUI
				    std::unique_ptr<renderer_dx11> dx11_renderer_instance;
				    std::unique_ptr<renderer_dx12> dx12_renderer_instance;
				    if (g_is_enhanced)
				    {
					    while (!*g_pointers->m_resolution_x)
					    {
						    std::this_thread::sleep_for(1s);
					    }
					    dx12_renderer_instance = std::make_unique<renderer_dx12>();
				    }
				    else
				    {
					    dx11_renderer_instance = std::make_unique<renderer_dx11>();
				    }

				    LOG(INFO) << "Renderer initialized.";
				    auto gui_instance = std::make_unique<gui>();
#endif

				    auto fiber_pool_instance = std::make_unique<fiber_pool>(10);
				    LOG(INFO) << "Fiber pool initialized.";

				    auto hooking_instance = std::make_unique<hooking>();
				    LOG(INFO) << "Hooking initialized.";

				    while (g_pointers->m_script_threads->size() == 0)
					{
						LOG(VERBOSE) << "Natives not initialised yet. Waiting 5s and trying again.";
					    std::this_thread::sleep_for(5s);
					}

				    auto script_program_instance = std::make_unique<big_program>("BadAPIInternal");
				    create_script_thread("BadAPIInternal");
				    LOG(INFO) << "Script Program initialized.";

				    g_native_invoker.cache_handlers();
				    LOG(INFO) << "Native handlers cached.";

				    auto notification_service_instance   = std::make_unique<notification_service>();
				    auto player_service_instance         = std::make_unique<player_service>();
				    auto script_patcher_service_instance = std::make_unique<script_patcher_service>();
				    auto tunables_service_instance       = std::make_unique<tunables_service>();
				    LOG(INFO) << "Registered service instances...";

				    g_notification_service.initialise();
				    LOG(INFO) << "Finished initialising services.";

				    g_script_mgr.add_script(std::make_unique<script>(&backend::loop));
#ifdef ENABLE_GUI
				    g_script_mgr.add_script(std::make_unique<script>(&gui::script_func));
#endif
				    LOG(INFO) << "Scripts registered.";

				    g_hooking->enable();
				    LOG(INFO) << "Hooking enabled.";

				    auto native_hooks_instance = std::make_unique<native_hooks>();
				    LOG(INFO) << "Dynamic native hooker initialized.";

				    auto lua_manager_instance =
				        std::make_unique<lua_manager>(g_file_manager.get_project_folder("scripts"), g_file_manager.get_project_folder("scripts_config"));
				    LOG(INFO) << "Lua manager initialized.";

				    while (g_running)
					    std::this_thread::sleep_for(500ms);

				    lua_manager_instance.reset();
				    LOG(INFO) << "Lua manager uninitialized.";

				    g_script_mgr.remove_all_scripts();
				    LOG(INFO) << "Scripts unregistered.";

				    g_hooking->disable();
				    LOG(INFO) << "Hooking disabled.";

				    // cleans up the thread responsible for saving settings
				    g.destroy();

				    // Make sure that all threads created don't have any blocking loops
				    // otherwise make sure that they have stopped executing
				    thread_pool_instance->destroy();
				    LOG(INFO) << "Destroyed thread pool.";

				    tunables_service_instance.reset();
				    LOG(INFO) << "Player Database Service reset.";
				    script_patcher_service_instance.reset();
				    LOG(INFO) << "Mobile Service reset.";
				    player_service_instance.reset();
				    LOG(INFO) << "Xml Vehicles Service reset.";
				    notification_service_instance.reset();
				    LOG(INFO) << "Notification Service reset.";
				    LOG(INFO) << "Services uninitialized.";

				    hooking_instance.reset();
				    LOG(INFO) << "Hooking uninitialized.";

				    native_hooks_instance.reset();
				    LOG(INFO) << "Dynamic native hooker uninitialized.";

				    fiber_pool_instance.reset();
				    LOG(INFO) << "Fiber pool uninitialized.";

				    destroy_script_thread();
				    script_program_instance.reset();
				    LOG(INFO) << "Script Program uninitialized.";

#ifdef ENABLE_GUI
				    if (g_is_enhanced)
					    dx12_renderer_instance.reset();
				    else
					    dx11_renderer_instance.reset();
				    LOG(INFO) << "Renderer uninitialized.";
#endif

				    byte_patch_manager_instance.reset();
				    LOG(INFO) << "Byte Patch Manager uninitialized.";

				    pointers_instance.reset();
				    LOG(INFO) << "Pointers uninitialized.";
			    }
			    catch (std::exception const& ex)
			    {
				    LOG(WARNING) << ex.what();
				    MessageBoxA(nullptr, ex.what(), nullptr, MB_OK | MB_ICONEXCLAMATION);
			    }

			    LOG(INFO) << "Farewell!";
			    g_log.destroy();

			    CloseHandle(g_main_thread);
			    FreeLibraryAndExitThread(g_hmodule, 0);
		    },
		    nullptr,
		    0,
		    &g_main_thread_id);
	}

	return true;
}
