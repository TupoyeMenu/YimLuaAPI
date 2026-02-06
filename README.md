# YimLuaAPI
A standalone YimMenu lua runtime for Legacy/Enhanced.
Strictly for educational purposes.

## Usage
1. Inject YimLuaAPI without YimMenu(V2) and load into Single Player
2. Press insert, go to debug -> GTA Cache -> Rebuild Cache
3. Wait for it to build the cache
4. Close the game
5. Restart inject YimLuaAPI and YimMenu(V2)

You only need to do steps 1-4 once.

> [!CAUTION]
> This does **NOT** bypass the Anti-Cheat!
> You must inject YimMenu or YimMenuV2 to join online.


## API Changes
This API is not 1 to 1 compatible with YimMenu's but it's pretty close.


### Missing features
- `network.set_player_coords` Only works on local player
- `network.set_all_player_coords` Only works on local player
- `network.get_selected_player` Always returns -1
- `network.get_selected_database_player_rockstar_id` Always returns -1
- `network.flag_player_as_modder` Does nothing
- `network.flag_player_as_modder_custom_reason` Does nothing, returns false
- `network.is_player_friend` Always returns false
- `network.get_flagged_modder_reason` Returns an empty string
- `network.force_script_on_player` Complains about not being implemented, then does nothing
- `network.send_chat_message` Complains about not being implemented, then does nothing
- `network.send_chat_message_to_player` Complains about not being implemented, then does nothing
- `script.start_launcher_script` Complains about not being implemented, then does nothing

### API Extentions
- `FAKE_YIMAPI` A global variable that is always true, a simple way to check that you are running on YimLuaAPI
- `get_game_branch` Returns a number corresponding to the current game branch.
- `game_branch.Legacy` May be returned by `get_game_branch`
- `game_branch.Enhanced` May be returned by `get_game_branch`
- `game_branch.DontCare` Not used for anything
- Updated ImGui: YimLuaAPI uses ImGui bindings from BadAPI (ImGui v1.92.0)

## Building

### Windows
To build BigBaseV2 you need:

* Visual Studio 2019 or higher
* [CMake](https://cmake.org/download)

To set up the build environment, run the following commands in a terminal:
```bash
git clone https://github.com/TupoyeMenu/YimLuaAPI.git
cd YimLuaAPI
mkdir build
cd build
cmake ..
```
Now, you will be able to open the solution, and simply build it in Visual Studio.


## Credits
| Credits                                                      |                                                                           |
| ------------------------------------------------------------ | ------------------------------------------------------------------------- |
| [Mr-X-GTA](https://github.com/Mr-X-GTA)                      | Updates for newer GTA V versions                                          |
| [YimMenu](https://github.com/YimMenu/YimMenu) contributors   | Updates for newer GTA V versions, most of the code is stolen from them    |
| [YimMenu](https://github.com/YimMenu/YimMenuV2) contributors | Updates for GTA V Enhanced versions, a lot of code is stolen from them    |
| Pocakking                                                    | [BigBaseV2](https://github.com/Pocakking/BigBaseV2)                       |
| spankerincrease(gir489)                                      | [BigBaseV2-fix](https://bitbucket.org/gir489/bigbasev2-fix)               |
| tupoy-ya                                                     | Being stupid                                                              |

## License
This project is licensed under [GNU GENERAL PUBLIC LICENSE Version 2](https://www.gnu.org/licenses/old-licenses/gpl-2.0.txt) because almost all code is stolen from YimMenu.