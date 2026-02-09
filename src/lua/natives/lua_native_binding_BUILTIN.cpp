#include "lua_native_binding.hpp"
#include "natives.hpp"

namespace lua::native
{
	static void LUA_NATIVE_BUILTIN_WAIT(int ms)
	{
		BUILTIN::WAIT(ms);
	}

	static int LUA_NATIVE_BUILTIN_START_NEW_SCRIPT(sol::stack_object scriptName, int stackSize)
	{
		auto retval = BUILTIN::START_NEW_SCRIPT(scriptName.is<const char*>() ? scriptName.as<const char*>() : nullptr, stackSize);
		return retval;
	}

	static int LUA_NATIVE_BUILTIN_START_NEW_SCRIPT_WITH_ARGS(sol::stack_object scriptName, uintptr_t args, int argCount, int stackSize)
	{
		auto retval = BUILTIN::START_NEW_SCRIPT_WITH_ARGS(scriptName.is<const char*>() ? scriptName.as<const char*>() : nullptr, (Any*)args, argCount, stackSize);
		return retval;
	}

	static int LUA_NATIVE_BUILTIN_START_NEW_SCRIPT_WITH_NAME_HASH(Hash scriptHash, int stackSize)
	{
		auto retval = BUILTIN::START_NEW_SCRIPT_WITH_NAME_HASH(scriptHash, stackSize);
		return retval;
	}

	static int LUA_NATIVE_BUILTIN_START_NEW_SCRIPT_WITH_NAME_HASH_AND_ARGS(Hash scriptHash, uintptr_t args, int argCount, int stackSize)
	{
		auto retval = BUILTIN::START_NEW_SCRIPT_WITH_NAME_HASH_AND_ARGS(scriptHash, (Any*)args, argCount, stackSize);
		return retval;
	}

	static int LUA_NATIVE_BUILTIN_TIMERA()
	{
		auto retval = BUILTIN::TIMERA();
		return retval;
	}

	static int LUA_NATIVE_BUILTIN_TIMERB()
	{
		auto retval = BUILTIN::TIMERB();
		return retval;
	}

	static void LUA_NATIVE_BUILTIN_SETTIMERA(int value)
	{
		BUILTIN::SETTIMERA(value);
	}

	static void LUA_NATIVE_BUILTIN_SETTIMERB(int value)
	{
		BUILTIN::SETTIMERB(value);
	}

	static float LUA_NATIVE_BUILTIN_TIMESTEP()
	{
		auto retval = BUILTIN::TIMESTEP();
		return retval;
	}

	static float LUA_NATIVE_BUILTIN_SIN(float value)
	{
		auto retval = BUILTIN::SIN(value);
		return retval;
	}

	static float LUA_NATIVE_BUILTIN_COS(float value)
	{
		auto retval = BUILTIN::COS(value);
		return retval;
	}

	static float LUA_NATIVE_BUILTIN_SQRT(float value)
	{
		auto retval = BUILTIN::SQRT(value);
		return retval;
	}

	static float LUA_NATIVE_BUILTIN_POW(float base, float exponent)
	{
		auto retval = BUILTIN::POW(base, exponent);
		return retval;
	}

	static float LUA_NATIVE_BUILTIN_LOG10(float value)
	{
		auto retval = BUILTIN::LOG10(value);
		return retval;
	}

	static float LUA_NATIVE_BUILTIN_VMAG(float x, float y, float z)
	{
		auto retval = BUILTIN::VMAG(x, y, z);
		return retval;
	}

	static float LUA_NATIVE_BUILTIN_VMAG2(float x, float y, float z)
	{
		auto retval = BUILTIN::VMAG2(x, y, z);
		return retval;
	}

	static float LUA_NATIVE_BUILTIN_VDIST(float x1, float y1, float z1, float x2, float y2, float z2)
	{
		auto retval = BUILTIN::VDIST(x1, y1, z1, x2, y2, z2);
		return retval;
	}

	static float LUA_NATIVE_BUILTIN_VDIST2(float x1, float y1, float z1, float x2, float y2, float z2)
	{
		auto retval = BUILTIN::VDIST2(x1, y1, z1, x2, y2, z2);
		return retval;
	}

	static int LUA_NATIVE_BUILTIN_SHIFT_LEFT(int value, int bitShift)
	{
		auto retval = BUILTIN::SHIFT_LEFT(value, bitShift);
		return retval;
	}

	static int LUA_NATIVE_BUILTIN_SHIFT_RIGHT(int value, int bitShift)
	{
		auto retval = BUILTIN::SHIFT_RIGHT(value, bitShift);
		return retval;
	}

	static int LUA_NATIVE_BUILTIN_FLOOR(float value)
	{
		auto retval = BUILTIN::FLOOR(value);
		return retval;
	}

	static int LUA_NATIVE_BUILTIN_CEIL(float value)
	{
		auto retval = BUILTIN::CEIL(value);
		return retval;
	}

	static int LUA_NATIVE_BUILTIN_ROUND(float value)
	{
		auto retval = BUILTIN::ROUND(value);
		return retval;
	}

	static float LUA_NATIVE_BUILTIN_TO_FLOAT(int value)
	{
		auto retval = BUILTIN::TO_FLOAT(value);
		return retval;
	}

	static void LUA_NATIVE_BUILTIN_SET_THIS_THREAD_PRIORITY(int priority)
	{
		BUILTIN::SET_THIS_THREAD_PRIORITY(priority);
	}

	void init_native_binding_BUILTIN(sol::state& L)
	{
		auto BUILTIN = L["BUILTIN"].get_or_create<sol::table>();
		BUILTIN.set_function("WAIT", LUA_NATIVE_BUILTIN_WAIT);
		BUILTIN.set_function("START_NEW_SCRIPT", LUA_NATIVE_BUILTIN_START_NEW_SCRIPT);
		BUILTIN.set_function("START_NEW_SCRIPT_WITH_ARGS", LUA_NATIVE_BUILTIN_START_NEW_SCRIPT_WITH_ARGS);
		BUILTIN.set_function("START_NEW_SCRIPT_WITH_NAME_HASH", LUA_NATIVE_BUILTIN_START_NEW_SCRIPT_WITH_NAME_HASH);
		BUILTIN.set_function("START_NEW_SCRIPT_WITH_NAME_HASH_AND_ARGS", LUA_NATIVE_BUILTIN_START_NEW_SCRIPT_WITH_NAME_HASH_AND_ARGS);
		BUILTIN.set_function("TIMERA", LUA_NATIVE_BUILTIN_TIMERA);
		BUILTIN.set_function("TIMERB", LUA_NATIVE_BUILTIN_TIMERB);
		BUILTIN.set_function("SETTIMERA", LUA_NATIVE_BUILTIN_SETTIMERA);
		BUILTIN.set_function("SETTIMERB", LUA_NATIVE_BUILTIN_SETTIMERB);
		BUILTIN.set_function("TIMESTEP", LUA_NATIVE_BUILTIN_TIMESTEP);
		BUILTIN.set_function("SIN", LUA_NATIVE_BUILTIN_SIN);
		BUILTIN.set_function("COS", LUA_NATIVE_BUILTIN_COS);
		BUILTIN.set_function("SQRT", LUA_NATIVE_BUILTIN_SQRT);
		BUILTIN.set_function("POW", LUA_NATIVE_BUILTIN_POW);
		BUILTIN.set_function("LOG10", LUA_NATIVE_BUILTIN_LOG10);
		BUILTIN.set_function("VMAG", LUA_NATIVE_BUILTIN_VMAG);
		BUILTIN.set_function("VMAG2", LUA_NATIVE_BUILTIN_VMAG2);
		BUILTIN.set_function("VDIST", LUA_NATIVE_BUILTIN_VDIST);
		BUILTIN.set_function("VDIST2", LUA_NATIVE_BUILTIN_VDIST2);
		BUILTIN.set_function("SHIFT_LEFT", LUA_NATIVE_BUILTIN_SHIFT_LEFT);
		BUILTIN.set_function("SHIFT_RIGHT", LUA_NATIVE_BUILTIN_SHIFT_RIGHT);
		BUILTIN.set_function("FLOOR", LUA_NATIVE_BUILTIN_FLOOR);
		BUILTIN.set_function("CEIL", LUA_NATIVE_BUILTIN_CEIL);
		BUILTIN.set_function("ROUND", LUA_NATIVE_BUILTIN_ROUND);
		BUILTIN.set_function("TO_FLOAT", LUA_NATIVE_BUILTIN_TO_FLOAT);
		BUILTIN.set_function("SET_THIS_THREAD_PRIORITY", LUA_NATIVE_BUILTIN_SET_THIS_THREAD_PRIORITY);
		L["SYSTEM"] = L["BUILTIN"];
	}
}
