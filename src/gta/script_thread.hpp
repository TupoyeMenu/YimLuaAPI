/**
 * @file script_thread.hpp
 * 
 * @copyright GNU General Public License Version 2.
 * This file is part of YimMenu.
 * YimMenu is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 2 of the License, or (at your option) any later version.
 * YimMenu is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
 * You should have received a copy of the GNU General Public License along with YimMenu. If not, see <https://www.gnu.org/licenses/>.
 */

#if !SCRIPT_THREAD_HPP_LEGACY || !SCRIPT_THREAD_HPP_ENHANCED
	#if ENHANCED
		#define SCRIPT_THREAD_HPP_ENHANCED 1
	#else
		#define SCRIPT_THREAD_HPP_LEGACY 1
	#endif

	#include "fwddec.hpp"
	#include "joaat.hpp"
	#include "script/scrThreadContext.hpp"

	#include <cstdint>

namespace GAME_BRANCH
{
	namespace rage
	{
		class scrThread
		{
		public:
			class scrThreadContext
			{
			public:
				std::uint32_t m_thread_id; // 0x00
	#if ENHANCED
				std::uint64_t m_script_hash; // 0x08 TODO: is this still the script hash in enhanced? why is it an 8-byte value now?
	#else
				::rage::joaat_t m_script_hash;
	#endif
				::rage::eThreadState m_state;        // 0x10
				std::uint32_t m_instruction_pointer; // 0x14
				std::uint32_t m_frame_pointer;       // 0x18
				std::uint32_t m_stack_pointer;       // 0x1C
				float m_timer_a;                     // 0x20
				float m_timer_b;                     // 0x24
				float m_wait_timer;                  // 0x28
				char m_padding1[0x2C];               // 0x2C
				std::uint32_t m_stack_size;          // 0x58
				char m_Pad[0x54];                    // 0x2C don't really need this fields after this
			};
	#if ENHANCED
			static_assert(sizeof(scrThreadContext) == 0xB0);
	#else
			static_assert(sizeof(scrThreadContext) == 0xA8);
	#endif

			virtual ~scrThread()                                                               = default;
			virtual void Reset(std::uint64_t script_hash, void* args, std::uint32_t arg_count) = 0;
			virtual ::rage::eThreadState RunImpl()                                             = 0;
			virtual ::rage::eThreadState Run()                                                 = 0;
			virtual void Kill()                                                                = 0;
	#if ENHANCED
			virtual void GetInfo(void* info) = 0; // new in Enhanced, more research needed
				                                  // I'm not sure what's going on with this func, best to not touch it
	#endif

			scrThreadContext m_context; // 0x08
			void* m_stack;              // 0xB8
			char m_padding[0x4];        // 0xC0
			std::uint32_t m_arg_size;   // 0xC4
			std::uint32_t m_arg_loc;    // 0xC8
			char m_padding2[0x4];       // 0xCC
	#if ENHANCED
			char m_exit_message[128]; // 0xD0 finally works now (size 124, 4 padding)
	#else
			const char* m_exit_message;
	#endif
			std::uint32_t m_script_hash; // 0x150
			char m_name[64];             // 0x154
		};
	#if ENHANCED
		static_assert(sizeof(scrThread) == 0x198);
	#else
		static_assert(sizeof(scrThread) == 0x118);
	#endif
	}

	class scriptHandler;
	class scriptHandlerNetComponent;

	class GtaThread : public rage::scrThread
	{
	public:
		scriptHandler* m_handler;
		scriptHandlerNetComponent* m_net_component;
		::rage::joaat_t m_script_hash;
		int m_force_cleanup_ip;                     // 0x12C
		int m_force_cleanup_fp;                     // 0x130
		int m_force_cleanup_sp;                     // 0x134
		int m_force_cleanup_filter;                 // 0x138
		int m_force_cleanup_cause;                  // 0x13C
		std::int32_t m_instance_id;                 // 0x140
		char m_padding4[0x04];                      // 0x144
		std::uint8_t m_flag1;                       // 0x148
		bool m_safe_for_network_game;               // 0x149
		char m_padding5[0x02];                      // 0x14A
		bool m_is_minigame_script;                  // 0x14C
		char m_padding6[0x02];                      // 0x14D
		bool m_can_be_paused;                       // 0x14F
		bool m_can_remove_blips_from_other_scripts; // 0x150
		char m_padding7[0x2];                       // 0x151
		std::uint8_t m_force_cleanup_state;         // 0x153
		char m_padding8[0xC];                       // 0x154
	};
	#if ENHANCED
		static_assert(sizeof(GtaThread) == 0x1E0);
	#else
		static_assert(sizeof(GtaThread) == 0x160);
	#endif


}

#endif
