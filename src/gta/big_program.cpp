#include "big_program.hpp"
#include "common.hpp"
#include "gta_util.hpp"
#include "pointers.hpp"


namespace big
{
	big_program::big_program(const char* name)
	{
		m_name = name;
		m_hash = rage::joaat(name);
		m_name_hash = rage::joaat(name);

		m_code_blocks = nullptr;
		m_code_size = 0;
		m_arg_count = 0;
		m_local_count = 0;
		m_global_count = 0;
		m_native_count = 0;
		m_local_data = nullptr;
		m_global_data = nullptr;
		m_native_entrypoints = nullptr;
		m_proc_count = 0;
		m_proc_names = nullptr;
		m_ref_count = 0;
		m_strings_data = nullptr;
		m_strings_count = 0;

		g_main_program = this;
	}

	big_program::~big_program()
	{
		g_main_program = nullptr;
	}

	void create_script_thread(const char* name)
	{
		void* thread = nullptr;
		if(g_is_enhanced)
		{
			thread = calloc(1, sizeof(enhanced::GtaThread));
		}
		else
		{
			thread = calloc(1, sizeof(legacy::GtaThread));
		}

		*(void**)thread = g_pointers->m_gta_thread_vtable;

		CROSS_CLASS_ACCESS(legacy::GtaThread, enhanced::GtaThread, thread, ->m_can_remove_blips_from_other_scripts) = true;
		CROSS_CLASS_ACCESS(legacy::GtaThread, enhanced::GtaThread, thread, ->m_safe_for_network_game) = true;
		strcpy_s(CROSS_CLASS_ACCESS(legacy::GtaThread, enhanced::GtaThread, thread, ->m_name), name);
		CROSS_CLASS_ACCESS(legacy::GtaThread, enhanced::GtaThread, thread, ->m_script_hash) = rage::joaat(name);

		if (g_is_enhanced)
		{
			strcpy_s(((enhanced::GtaThread*)thread)->m_exit_message, "Not aborted yet?");
		}
		else
		{
			((legacy::GtaThread*)thread)->m_exit_message = "Not aborted yet?";
		}
		
		g_main_script_thread = thread;
	}

	void destroy_script_thread()
	{
		free(g_main_script_thread);
		g_main_script_thread = nullptr;
	}
}

