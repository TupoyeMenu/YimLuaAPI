#pragma once

#include "pointers.hpp"
#if _WIN32
#include <intrin.h>
#endif

namespace rage
{
	class badTLSContext
	{
	public:
		rage::sysMemAllocator* getAllocator()
		{
			return *(::rage::sysMemAllocator**)((intptr_t)this + big::g_pointers->m_tls_context_allocator_offset);
		}
		rage::sysMemAllocator** getAllocatorPtr()
		{
			return (::rage::sysMemAllocator**)((intptr_t)this + big::g_pointers->m_tls_context_allocator_offset);
		}
		void** getScriptThreadPtr()
		{
			return (void**)((intptr_t)this + big::g_pointers->m_tls_context_thread_offset);
		}
		bool* getScriptThreadActivePtr()
		{
			return (bool*)((intptr_t)this + big::g_pointers->m_tls_context_thread_offset + sizeof(void*));
		}

		static badTLSContext* get()
		{
			constexpr std::uint32_t TlsIndex = 0x0;
			return *reinterpret_cast<badTLSContext**>(__readgsqword(0x58) + TlsIndex);
		}
	};
}