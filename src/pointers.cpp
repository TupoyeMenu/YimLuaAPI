/**
 * @file pointers.cpp
 * @brief All the signature scans are here.
 */

#include "pointers.hpp"

#include "common.hpp"
#include "memory/all.hpp"

namespace big
{
	pointers::pointers()
	{
		memory::batch early_batch;

		early_batch.add("Game Version", "8B C3 33 D2 C6 44 24 20", -1, -1, eGameBranch::Legacy, [this](memory::handle ptr) {
			g_game_version = std::stoi(ptr.add(0x24).rip().as<const char*>());
			m_game_version = ptr.add(0x24).rip().as<const char*>();
		});
		early_batch.add("Game Version", "4C 8D 0D ? ? ? ? 48 8D 5C 24 ? 48 89 D9 48", -1, -1, eGameBranch::Enhanced, [this](memory::handle ptr) {
			g_game_version = std::stoi(ptr.add(3).rip().as<const char*>());
			m_game_version = ptr.add(3).rip().as<const char*>();
		});

		early_batch.run(memory::module(""));

		memory::batch main_batch;

		main_batch.add("Screen Resolution", "66 0F 6E 0D ? ? ? ? 0F B7 3D", -1, -1, eGameBranch::Legacy, [this](memory::handle ptr) {
			m_resolution_x = ptr.sub(4).rip().as<uint32_t*>();
			m_resolution_y = ptr.add(4).rip().as<uint32_t*>();
		});
		main_batch.add("Screen Resolution", "75 39 0F 57 C0 F3 0F 2A 05", -1, -1, eGameBranch::Enhanced, [this](memory::handle ptr) {
			m_resolution_x = ptr.add(0x5).add(4).rip().as<uint32_t*>();
			m_resolution_y = ptr.add(0x1E).add(4).rip().as<uint32_t*>();
		});


		main_batch.add("Game state", "83 3D ? ? ? ? ? 75 17 8B 43 20 25", -1, -1, eGameBranch::Legacy, [this](memory::handle ptr) {
			m_game_state = ptr.add(2).rip().add(1).as<eGameState*>();
		});
		main_batch.add("Game state", "83 3D ? ? ? ? ? 0F 85 ? ? ? ? BA ? 00", -1, -1, eGameBranch::Enhanced, [this](memory::handle ptr) {
			m_game_state = ptr.add(2).rip().add(1).as<eGameState*>();
		});

		main_batch.add("Is session started", "40 38 35 ? ? ? ? 75 0E 4C 8B C3 49 8B D7 49 8B CE", -1, -1, eGameBranch::Legacy, [this](memory::handle ptr) {
			m_is_session_started = ptr.add(3).rip().as<bool*>();
		});
		main_batch.add("Is session started", "0F B6 05 ? ? ? ? 0A 05 ? ? ? ? 75 2A", -1, -1, eGameBranch::Enhanced, [this](memory::handle ptr) {
			m_is_session_started = ptr.add(3).rip().as<bool*>();
		});

		main_batch.add("Ped factory", "48 8B 05 ? ? ? ? 48 8B 48 08 48 85 C9 74 52 8B 81", -1, -1, eGameBranch::Legacy, [this](memory::handle ptr) {
			m_ped_factory = ptr.add(3).rip().as<CPedFactory**>();
		});
		main_batch.add("Ped factory", "C7 40 30 03 00 00 00 48 8B 0D", -1, -1, eGameBranch::Enhanced, [this](memory::handle ptr) {
			m_ped_factory = ptr.add(7).add(3).rip().as<CPedFactory**>();
		});

		main_batch.add("Network player manager", "48 8B 0D ? ? ? ? 8A D3 48 8B 01 FF 50 ? 4C 8B 07 48 8B CF", -1, -1, eGameBranch::Legacy, [this](memory::handle ptr) {
			m_network_player_mgr = ptr.add(3).rip().as<CNetworkPlayerMgr**>();
		});
		main_batch.add("Network player manager", "75 0E 48 8B 05 ? ? ? ? 48 8B 88 F0 00 00 00", -1, -1, eGameBranch::Enhanced, [this](memory::handle ptr) {
			m_network_player_mgr = ptr.add(2).add(3).rip().as<CNetworkPlayerMgr**>();
		});

		main_batch.add("Native handlers", "48 8D 0D ? ? ? ? 48 8B 14 FA E8 ? ? ? ? 48 85 C0 75 0A", -1, -1, eGameBranch::Legacy, [this](memory::handle ptr) {
			m_init_native_tables        = ptr.sub(37).as<PVOID>();
			m_native_registration_table = ptr.add(3).rip().as<rage::scrNativeRegistrationTable*>();
		});
		main_batch.add("Native handlers", "EB 2A 0F 1F 40 00 48 8B 54 17 10", -1, -1, eGameBranch::Enhanced, [this](memory::handle ptr) {
			m_init_native_tables        = ptr.sub(0x2A).as<PVOID>();
			m_native_registration_table = ptr.sub(0xE).rip().as<rage::scrNativeRegistrationTable*>();
		});

		main_batch.add("Script threads", "45 33 F6 8B E9 85 C9 B8", -1, -1, eGameBranch::Legacy, [this](memory::handle ptr) {
			m_script_threads     = ptr.sub(4).rip().sub(8).as<decltype(m_script_threads)>();
			m_run_script_threads = ptr.sub(0x1F).as<functions::run_script_threads_t>();
		});
		main_batch.add("Script threads", "BE 40 5D C6 00", -1, -1, eGameBranch::Enhanced, [this](memory::handle ptr) {
			m_script_threads     = ptr.add(0x1B).rip().as<decltype(m_script_threads)>();
			m_run_script_threads = ptr.sub(0xA).as<functions::run_script_threads_t>();
		});

		main_batch.add("Script programs", "48 8B 1D ? ? ? ? 41 83 F8 FF", -1, -1, eGameBranch::Legacy, [this](memory::handle ptr) {
			m_script_program_table = ptr.add(3).rip().as<decltype(m_script_program_table)>();
		});
		main_batch.add("Script programs", "89 46 38 48 8B 0D ? ? ? ? 0F", -1, -1, eGameBranch::Enhanced, [this](memory::handle ptr) {
			m_script_program_table = ptr.add(0x16).rip().as<decltype(m_script_program_table)>();
		});

		main_batch.add("Script globals", "48 8D 15 ? ? ? ? 4C 8B C0 E8 ? ? ? ? 48 85 FF 48 89 1D", -1, -1, eGameBranch::Legacy, [this](memory::handle ptr) {
			m_script_globals = ptr.add(3).rip().as<std::int64_t**>();
		});
		main_batch.add("Script globals", "48 8B 8E B8 00 00 00 48 8D 15 ? ? ? ? 49 89 D8", -1, -1, eGameBranch::Enhanced, [this](memory::handle ptr) {
			m_script_globals = ptr.add(10).rip().as<std::int64_t**>();
		});

		main_batch.add("Script VM", "E8 ? ? ? ? 48 85 FF 48 89 1D", -1, -1, eGameBranch::Legacy, [this](memory::handle ptr) {
			m_script_vm = ptr.add(1).rip().as<functions::script_vm>();
		});
		main_batch.add("Script VM", "49 63 41 1C", -1, -1, eGameBranch::Enhanced, [this](memory::handle ptr) {
			m_script_vm = ptr.sub(0x24).as<functions::script_vm>();
		});

		main_batch.add("Swapchain", "48 8B 0D ? ? ? ? 48 8B 01 44 8D 43 01 33 D2 FF 50 40 8B C8", -1, -1, eGameBranch::Legacy, [this](memory::handle ptr) {
			m_swapchain = ptr.add(3).rip().as<IDXGISwapChain**>();
		});
		main_batch.add("Swapchain", "72 C7 EB 02 31 C0 8B 0D", -1, -1, eGameBranch::Enhanced, [this](memory::handle ptr) {
			m_command_queue = ptr.add(0x1A).add(3).rip().as<ID3D12CommandQueue**>();
			m_swapchain     = ptr.add(0x21).add(3).rip().as<IDXGISwapChain**>();
		});

		main_batch.add("Model Spawn Bypass", "48 8B C8 FF 52 30 84 C0 ? ? 48 8B C3", -1, -1, eGameBranch::Legacy, [this](memory::handle ptr) {
			m_model_spawn_bypass =
			    memory::byte_patch::make(ptr.add(8).as<PVOID>(), std::to_array<uint8_t>({0x90, 0x90})).get();
		});
		main_batch.add("Model Spawn Bypass", "E8 ? ? ? ? 48 8B 78 48", -1, -1, eGameBranch::Enhanced, [this](memory::handle ptr) {
			m_model_spawn_bypass = memory::byte_patch::make(ptr.add(1).rip().add(0x2B).as<uint8_t*>(), 0xEB).get();
		});

		main_batch.add("Ptr To Handle", "48 8B F9 48 83 C1 10 33 DB", -1, -1, eGameBranch::Legacy, [this](memory::handle ptr) {
			m_ptr_to_handle = ptr.sub(0x15).as<decltype(m_ptr_to_handle)>();
		});
		main_batch.add("Handle To Ptr", "83 F9 FF 74 31 4C 8B 0D", -1, -1, eGameBranch::Legacy, [this](memory::handle ptr) {
			m_handle_to_ptr = ptr.as<decltype(m_handle_to_ptr)>();
		});
		main_batch.add("HandlesAndPtrs", "0F 1F 84 00 00 00 00 00 89 F8 0F 28 FE 41", -1, -1, eGameBranch::Enhanced, [this](memory::handle ptr) {
			m_handle_to_ptr = ptr.add(0x21).add(1).rip().as<decltype(m_handle_to_ptr)>();
			m_ptr_to_handle = ptr.sub(0xB).add(1).rip().as<decltype(m_ptr_to_handle)>();
		});

		main_batch.add("Ped Pool", "4C 8B 35 ? ? ? ? B8", -1, -1, eGameBranch::Legacy, [this](memory::handle ptr) {
			m_ped_pool = ptr.add(3).rip().as<void**>();
		});
		main_batch.add("Ped Pool", "80 79 4B 00 0F 84 F5 00 00 00 48 89 F1", -1, -1, eGameBranch::Enhanced, [this](memory::handle ptr) {
			m_ped_pool = ptr.add(0x18).add(3).rip().as<void**>();
		});

		main_batch.add("Prop Pool", "48 8B 05 ? ? ? ? 0F B7 50 10 48 8B 05", -1, -1, eGameBranch::Legacy, [this](memory::handle ptr) {
			m_prop_pool = ptr.add(3).rip().as<void**>();
		});
		main_batch.add("Prop Pool", "48 8B 04 0A C3 0F B6 05", -1, -1, eGameBranch::Enhanced, [this](memory::handle ptr) {
			m_prop_pool = ptr.add(5).add(3).rip().as<void**>();
		});

		main_batch.add("Vehicle Pool", "4C 8B 25 ? ? ? ? 8B 29", -1, -1, eGameBranch::Legacy, [this](memory::handle ptr) {
			m_vehicle_pool = ptr.add(3).rip().as<void***>();
		});
		main_batch.add("Vehicle Pool", "48 83 78 18 0D", -1, -1, eGameBranch::Enhanced, [this](memory::handle ptr) {
			m_vehicle_pool = ptr.sub(0xA).add(3).rip().as<void***>();
		});

		main_batch.add("Give Pickup Reward", "48 8B C8 33 C0 48 85 C9 74 0A 44 8B C3 8B D7 E8", -1, -1, eGameBranch::Legacy, [this](memory::handle ptr) {
			m_give_pickup_rewards = ptr.sub(0x28).as<decltype(m_give_pickup_rewards)>();
		});
		main_batch.add("Give Pickup Reward", "8B 53 08 89 F9 E8 ? ? ? ? E9", -1, -1, eGameBranch::Enhanced, [this](memory::handle ptr) {
			m_give_pickup_rewards = ptr.add(6).rip().as<decltype(m_give_pickup_rewards)>();
		});

		main_batch.add("Queue Packet", "E8 ? ? ? ? 84 C0 74 4D B3 01", -1, -1, eGameBranch::Legacy, [this](memory::handle ptr) {
			m_queue_packet = ptr.add(1).rip().as<functions::queue_packet>();
		});
		main_batch.add("Queue Packet", "45 89 F1 E8 ? ? ? ? 84 C0 74 25", -1, -1, eGameBranch::Enhanced, [this](memory::handle ptr) {
			m_queue_packet = ptr.add(4).rip().as<functions::queue_packet>();
		});

		main_batch.add("Get Net Object", "E8 ? ? ? ? 0F B7 53 7C", -1, -1, eGameBranch::Legacy, [this](memory::handle ptr) {
			m_get_net_object = ptr.add(1).rip().as<decltype(pointers::m_get_net_object)>();
		});
		main_batch.add("Get Net Object", "0F B7 57 ? 45 31 C0 E8 ? ? ? ? 48 89 C7 48 89 D9", -1, -1, eGameBranch::Enhanced, [this](memory::handle ptr) {
			m_get_net_object = ptr.add(8).rip().as<decltype(pointers::m_get_net_object)>();
		});

		main_batch.add("Request Control", "E8 ? ? ? ? EB 50 48 8B D3", -1, -1, eGameBranch::Legacy, [this](memory::handle ptr) {
			m_request_control = ptr.add(1).rip().as<functions::request_control>();
		});
		main_batch.add("Request Control", "74 0A 48 89 F9 E8 ? ? ? ? 31 F6 89 F0 48 83 C4 20", -1, -1, eGameBranch::Enhanced, [this](memory::handle ptr) {
			m_request_control = ptr.add(6).rip().as<functions::request_control>();
		});

		main_batch.add("CNetworkObjectMgr", "48 8B 0D ? ? ? ? 45 33 C0 E8 ? ? ? ? 33 FF 4C 8B F0", -1, -1, eGameBranch::Legacy, [this](memory::handle ptr) {
			m_network_object_mgr = ptr.add(3).rip().as<CNetworkObjectMgr**>();
		});
		main_batch.add("CNetworkObjectMgr", "41 83 7E FA 02 40 0F 9C C5 C1 E5 02", -1, -1, eGameBranch::Enhanced, [this](memory::handle ptr) {
			m_network_object_mgr     = ptr.add(0xC).add(3).rip().as<CNetworkObjectMgr**>();
		});

		main_batch.add("fiDevice Get Device", "41 B8 07 00 00 00 48 8B F1 E8", -1, -1, eGameBranch::Legacy, [this](memory::handle ptr) {
			m_fidevice_get_device = ptr.sub(0x1F).as<functions::fidevice_get_device>();
		});

		main_batch.add("fiPackfile ctor", "44 89 41 28 4C 89 41 38 4C 89 41 50 48 8D", -1, -1, eGameBranch::Legacy, [this](memory::handle ptr) {
			m_fipackfile_ctor      = ptr.sub(0x1E).as<functions::fipackfile_ctor>();
			m_fipackfile_instances = ptr.add(26).rip().as<rage::fiPackfile**>();
		});

		main_batch.add("fiPackfile dtor", "48 89 5C 24 08 57 48 83 EC 20 48 8D 05 ? ? ? ? 33 FF 48 8B D9 48 89 01 40 88", -1, -1, eGameBranch::Legacy, [this](memory::handle ptr) {
			m_fipackfile_dtor = ptr.as<functions::fipackfile_dtor>();
		});
		
		main_batch.add("fiPackfile stuff", "E8 ? ? ? ? 48 8D 0D ? ? ? ? E8 ? ? ? ? 8A 05 ? ? ? ? 48 8D 0D", -1, -1, eGameBranch::Legacy, [this](memory::handle ptr) {
			m_fipackfile_unmount = ptr.add(1).rip().as<functions::fipackfile_unmount>();
			m_fipackfile_close_archive = ptr.add(0xD).rip().as<functions::fipackfile_close_archive>();
			m_fipackfile_open_archive = ptr.add(0x34).rip().as<functions::fipackfile_open_archive>();
			m_fipackfile_mount = ptr.add(0x47).rip().as<functions::fipackfile_mount>();
		});

		main_batch.add("Gta Thread Vtable", "48 83 A3 ? ? ? 00 00 48 8D 05 ? ? ? ? 48 8B CB 48 89 03 E8", -1, -1, eGameBranch::Legacy, [this](memory::handle ptr) {
			m_gta_thread_vtable = ptr.add(11).rip().as<PVOID>();
		});
		main_batch.add("Gta Thread Vtable", "89 F3 31 FF 4C 8D 25", -1, -1, eGameBranch::Enhanced, [this](memory::handle ptr) {
			m_gta_thread_vtable = ptr.add(7).rip().as<PVOID>();
		});

		main_batch.add("Natives Registered", "48 8B CB 40 88 2D ? ? ? ? 48", -1, -1, eGameBranch::Legacy, [this](memory::handle ptr) {
			m_natives_registered = ptr.add(6).rip().as<bool*>();
		});
		main_batch.add("Natives Registered", "C6 05 ? ? ? ? ? 48 89 F1 0F 28 74", -1, -1, eGameBranch::Enhanced, [this](memory::handle ptr) {
			m_natives_registered = ptr.add(3).rip().as<bool*>();
		});

		main_batch.add("tlsContext allocator offset", "4C 8B C2 B9", -1, -1, eGameBranch::Legacy, [this](memory::handle ptr) {
			// Multiple results but they all point to the same offset.
			m_tls_context_allocator_offset = *ptr.add(4).as<uint32_t*>();
		});
		main_batch.add("tlsContext allocator offset", "48 8B 04 C1 48 8B 88 ? ? ? ? 48 8B 01 48 8B 40 40 48", -1, -1, eGameBranch::Enhanced, [this](memory::handle ptr) {
			m_tls_context_allocator_offset = *ptr.add(8).as<uint32_t*>();
		});

		main_batch.add("tlsContext thread offset", "48 8B F9 E8 ? ? ? ? FF 47", -1, -1, eGameBranch::Legacy, [this](memory::handle ptr) {
			m_tls_context_thread_offset = *ptr.add(4).rip().add(16).as<uint32_t*>();
		});
		main_batch.add("tlsContext thread offset", "F3 45 0F 58 DC E8", -1, -1, eGameBranch::Enhanced, [this](memory::handle ptr) {
			m_tls_context_thread_offset = *ptr.add(6).rip().add(22).as<uint32_t*>();
		});

		main_batch.add("Allocator", "48 8D 1D ? ? ? ? A8 08", -1, -1, eGameBranch::Legacy, [this](memory::handle ptr) {
			m_allocator = ptr.add(3).rip().as<rage::sysMemAllocator*>();
		});
		main_batch.add("Allocator", "48 8D 3D ? ? ? ? 48 89 F9 BA 07", -1, -1, eGameBranch::Enhanced, [this](memory::handle ptr) {
			m_allocator = ptr.add(3).rip().as<rage::sysMemAllocator*>();
		});

		main_batch.run(memory::module(""));

#ifdef ENABLE_GUI
		LPCWSTR lpClassName = g_is_enhanced ? L"sgaWindow" : L"grcWindow";
		m_hwnd              = FindWindowW(lpClassName, nullptr);
		if (!m_hwnd)
			throw std::runtime_error("Failed to find the game's window.");
#endif

		g_pointers = this;
	}

	pointers::~pointers()
	{
		g_pointers = nullptr;
	}
}
