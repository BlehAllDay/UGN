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

windows.cpp

*******************************************************************************/

#include <SDL2/SDL.h>
#include "main.hpp"

static SDL_GLContext context;

#ifdef __cplusplus
extern "C"
{
#endif

// Windows.
#ifdef _WIN64

/**
 * Does nothing other than be the entry point for the DLL.
 */

BOOL WINAPI DllMain(HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpReserved)
{
    switch(fdwReason)
    {
        case DLL_PROCESS_ATTACH:	break;
        case DLL_THREAD_ATTACH:		break;
        case DLL_THREAD_DETACH:		break;
        case DLL_PROCESS_DETACH:	break;
    }

    return TRUE;
}

#endif

/**

 */

uint8_t LIB_FUNC_CALL libInit(SDL_Window *window)
{
	context = SDL_GL_CreateContext(window);

	return true;
}

/**
 *
 */

void LIB_FUNC_CALL libQuit()
{
	SDL_GL_DeleteContext(context);
}

#ifdef __cplusplus
} // extern "C"
#endif
