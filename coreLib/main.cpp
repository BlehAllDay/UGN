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

windows.hpp

Windows DLL header.

*******************************************************************************/

#include <locale>
#include <SDL2/SDL.h>
#include "config.hpp"
#include "localization.hpp"
#include "main.hpp"

namespace coreLib
{

std::string_view errorMessage;

/**
 * Set global error message.
 * This uses a string in the language file to parse the message.
 */

void setError(std::string_view message)
{
	errorMessage = message.data();
}

} // namespace coreLib

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
 * Initializes core library and systems, which in turn initialize SDL and its
 * systems.
 *
 * If anything goes wrong, sets an internal error code and message (similar to
 * how other libraries handle errors), and returns false. The calling program
 * should retrieve the code and message and handle it on its own accord.
 */

uint8_t LIB_FUNC_CALL coreInit()
{
	// Should stay 0.
	uint8_t errCode = 0;

	// Get system language.


	printf("Loading core library...");

	errCode = coreLib::config::init();

	errCode = coreLib::localization::init();
	if(errCode)
		return errCode;

	if(SDL_Init(SDL_INIT_TIMER) < 0)
	{
		SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "X", SDL_GetError(), NULL);
		return 1;
	}

	printf("Done.\n");

	// All good. Assuming.
	return 0;
}

/**
 * Shuts down core library and systems. Includes SDL's stuff too.
 */

void LIB_FUNC_CALL coreQuit()
{
	printf("Unloading core library...\n");
	SDL_Quit();
}

/**
 * Gives the currently set error message to the calling program.
 */

const char * LIB_FUNC_CALL getCoreError()
{
	return coreLib::errorMessage.data();
}

#ifdef __cplusplus
} // extern "C"
#endif
