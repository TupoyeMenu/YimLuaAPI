# YimLuaAPI
A standalone YimMenu lua runtime for Legacy/Enhanced.
Strictly for educational purposes.

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
- `vehicles.get_vehicle_display_name` Return an empty string
- `vehicles.get_vehicle_display_name_string` Return an empty string
- `vehicles.get_all_vehicles_by_class` Return an empty table
- `vehicles.get_all_vehicles_by_mfr` Return an empty table
- `weapons.get_weapon_display_name` Return an empty string
- `weapons.get_weapon_display_name_string` Return an empty string
- `weapons.get_all_weapons_of_group_type` Return an empty table
- `weapons.get_all_weapons_of_group_type_string` Return an empty table
- `weapons.get_all_weapon_components` Return an empty table
- `weapons.get_all_weapon_components_string` Return an empty table
- `weapons.get_weapon_component_display_name` Return an empty string
- `weapons.get_weapon_component_display_name_string` Return an empty string
- `weapons.get_weapon_component_display_desc` Return an empty string
- `weapons.get_weapon_component_display_desc_string` Return an empty string
- `script.start_launcher_script` Complains about not being implemented, then does nothing

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