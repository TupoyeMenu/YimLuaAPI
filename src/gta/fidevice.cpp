/**
 * @file fidevice.cpp
 * @attention If you want to include this file you will need to add the following pointers: 
 * @code {.cpp}
 * functions::fipackfile_ctor m_fipackfile_ctor;
 * functions::fipackfile_dtor m_fipackfile_dtor;
 * functions::fipackfile_open_archive m_fipackfile_open_archive;
 * functions::fipackfile_mount m_fipackfile_mount;
 * functions::fipackfile_unmount m_fipackfile_unmount;
 * functions::fipackfile_close_archive m_fipackfile_close_archive;
 * @endcode
 * Look at YimMenu source if you need them.
 * https://github.com/YimMenu/YimMenu/blob/16e8e571f04b6d9d94f9be8c0d1823dc1088ae31/src/pointers.cpp#L510-L549
 * Then remove `#if 0` and `endif` from the file
 * 
 * @copyright GNU General Public License Version 2.
 * This file is part of YimMenu.
 * YimMenu is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 2 of the License, or (at your option) any later version.
 * YimMenu is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
 * You should have received a copy of the GNU General Public License along with YimMenu. If not, see <https://www.gnu.org/licenses/>.
 */

#include "hooking/hooking.hpp"
#include "pointers.hpp"

#define PURECALL()                                         \
	LOG(FATAL) << "pure fiDevice call (" << __FUNCTION__ << ")"; \
	return 0

// clang-format off
#include "util/header_wrappers/include_as_enhaced.hpp"
#include "gta/fidevice.hpp"
#include "gta/fidevice_implementation.hpp"
#include "util/header_wrappers/include_as_legacy.hpp"
#include "gta/fidevice.hpp"
#include "gta/fidevice_implementation.hpp"
#include "util/header_wrappers/clear_include.hpp"
// clang-format on
