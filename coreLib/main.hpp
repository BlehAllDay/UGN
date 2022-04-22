/*******************************************************************************

<one line to give the program's name and a brief idea of what it does.>
Copyright (C) <year>  <name of author>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.
This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <https://www.gnu.org/licenses/>.

********************************************************************************

main.hpp

Main DLL header. OS dependent stuff.

TODO: Add Linux functionality once I learn it. Possible just separate this into
individual OSD dependent files as more are supported. Maybe do nothing. I dunno.

*******************************************************************************/

#pragma once

#include <string_view>

/**
 * OS-dependent defines.
 */

#ifdef _WIN64
	#include <windows.h>

	#ifdef BUILD_LIB
		#define LIB_FUNC_CALL __declspec(dllexport)
	#else
		#define LIB_FUNC_CALL __declspec(dllimport)
	#endif
#endif

/**
 * Non-exported error handling stuff. These are set internally in case something
 * goes wrong. Which I'm pretty sure is your fault, not mine.
 */

namespace coreLib
{

extern std::string_view errorMessage;
void setErrorMessage();

} // namespace coreLib

/**
 * Exported functions.
 */

#ifdef __cplusplus
extern "C"
{
#endif

uint8_t			LIB_FUNC_CALL coreInit();
void			LIB_FUNC_CALL coreQuit();
const char *	LIB_FUNC_CALL getCoreError();

#ifdef __cplusplus
} // extern "C"
#endif
