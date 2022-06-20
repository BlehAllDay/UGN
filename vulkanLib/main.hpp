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



*******************************************************************************/

#pragma once

#include <SDL2/SDL.h>

#ifdef _WIN64
	#include <windows.h>

	#ifdef BUILD_LIB
		#define LIB_FUNC_CALL __stdcall __declspec(dllexport)
	#else
		#define LIB_FUNC_CALL __stdcall __declspec(dllimport)
	#endif
#endif

#ifdef __cplusplus
extern "C"
{
#endif

uint8_t	LIB_FUNC_CALL libInit(SDL_Window *window);
void	LIB_FUNC_CALL libQuit();

#ifdef __cplusplus
} // extern "C"
#endif

