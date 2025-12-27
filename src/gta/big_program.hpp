#pragma once

#include "script/scrProgram.hpp"

namespace big
{
	class big_program : public rage::scrProgram
	{
	public:
		big_program(const char* name);
		~big_program();

	private:
		int return_zero() { return 0; }
		void error() {}
	};

	void create_script_thread(const char* name);
	void destroy_script_thread();

	inline big_program* g_main_program;
	inline void* g_main_script_thread;
}

