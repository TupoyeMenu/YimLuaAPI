#include "common.hpp"
#include "util/is_enhanced.hpp"

namespace lua::global_table
{
	// Lua API: Table
	// Name: game_branch
	// Table containing all possible branches that get_game_branch can return.

	// Lua API: Field
	// Table: game_branch
	// Field: Legacy: integer

	// Lua API: Field
	// Table: game_branch
	// Field: Enhanced: integer

	// Lua API: Field
	// Table: game_branch
	// Field: DontCare: integer
	// Internal branch, this will never be returned get_game_branch.

	// Lua API: Table
	// Name: Global Table
	// Custom fields, functions, etc added to The Lua [Global Table](https://www.lua.org/pil/15.4.html).

	// Lua API: Function
	// Table: Global Table
	// Name: joaat
	// Param: str: string: The string that needs to be joaat hashed.
	// Returns: integer: The joaat hashed input string.

	// Lua API: Function
	// Table: Global Table
	// Name: get_game_branch
	// Returns: integer: The current game branch, can be `game_branch.Legacy` or `game_branch.Enhanced`.

	// Lua API: Field
	// Table: Global Table
	// Name: FAKE_YIMAPI: boolean
	// Always true, can be used to check if we are using YimLuaAPI instead of real YimMenu


	void bind(sol::state& state)
	{
		state.new_enum<eGameBranch>("game_branch",
		{
			{"Legacy", eGameBranch::Legacy},
			{"Enhanced", eGameBranch::Enhanced},
			{"DontCare", eGameBranch::DontCare},
		});

		state["FAKE_YIMAPI"] = true;
		state["get_game_branch"] = big::get_game_branch;
		state["joaat"] = rage::joaat;
	}
}