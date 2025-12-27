#pragma once
#include "function_types.hpp"
#include "gta/enums.hpp"
#include "gta/fwddec.hpp"
#include "memory/byte_patch.hpp"
#include "script/scrThread.hpp"

#include <memory/handle.hpp>
#include <player/CPlayerInfo.hpp>

namespace big
{
	class pointers
	{
	public:
		explicit pointers();
		~pointers();

	public:
#ifdef ENABLE_GUI
		HWND m_hwnd{};
#endif

		eGameState* m_game_state{};
		bool* m_is_session_started{};

		PVOID m_game_skeleton_update;

		CPedFactory** m_ped_factory{};
		CNetworkPlayerMgr** m_network_player_mgr{};

		rage::scrNativeRegistrationTable* m_native_registration_table{};

		rage::atArray<rage::scrThread*>* m_script_threads{};
		rage::scrProgramTable* m_script_program_table{};
		functions::run_script_threads_t m_run_script_threads{};
		std::int64_t** m_script_globals{};
		PVOID m_init_native_tables{};
		functions::script_vm m_script_vm{};

		CGameScriptHandlerMgr** m_script_handler_mgr{};

		IDXGISwapChain** m_swapchain{};
		ID3D12CommandQueue** m_command_queue;

		uint32_t* m_resolution_x;
		uint32_t* m_resolution_y;

		memory::byte_patch* m_model_spawn_bypass;

		functions::ptr_to_handle m_ptr_to_handle{};
		functions::handle_to_ptr m_handle_to_ptr{};

		PVOID m_queue_dependency;
		PVOID m_sig_scan_memory;

		const char* m_game_version;
		const char* m_online_version;

		void** m_ped_pool{};
		void** m_prop_pool{};
		void*** m_vehicle_pool{};

		functions::give_pickup_rewards m_give_pickup_rewards{};
		functions::queue_packet m_queue_packet{};

		functions::get_net_object m_get_net_object;

		functions::request_control m_request_control{};

		CNetworkObjectMgr** m_network_object_mgr{};

		functions::fidevice_get_device m_fidevice_get_device;
		functions::fipackfile_ctor m_fipackfile_ctor;
		functions::fipackfile_dtor m_fipackfile_dtor;
		rage::fiPackfile** m_fipackfile_instances;
		functions::fipackfile_open_archive m_fipackfile_open_archive;
		functions::fipackfile_mount m_fipackfile_mount;
		functions::fipackfile_unmount m_fipackfile_unmount;
		functions::fipackfile_close_archive m_fipackfile_close_archive;

		rage::Obf32** m_anticheat_initialized_hash;
		PVOID m_get_anticheat_initialized_hash;
		PVOID m_get_anticheat_initialized_hash_2;
		CAnticheatContext** m_anticheat_context;

		bool* m_natives_registered;
		PVOID m_gta_thread_vtable;

		uint32_t m_tls_context_allocator_offset;
		uint32_t m_tls_context_thread_offset;
		rage::sysMemAllocator* m_allocator;
	};

	inline pointers* g_pointers{};
}
