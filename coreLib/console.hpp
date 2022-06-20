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

console.hpp

*******************************************************************************/

#pragma once

#include <map>
#include <string_view>
#include "cvar.hpp"

namespace coreLib
{

namespace console
{

// System and custom CVARs. The former are hard coded, of course. The latter
// can be used for aliases, batch commands, or such.
extern std::map<std::string_view, CVAR *>			systemCVARs;
extern std::map<std::string_view, std::string_view>	customCVARs;

// Console Commands. Commands you can input into the console and execute.
// If the program will let you.
extern std::map<std::string_view, void(*)()> CCMDs;

uint8_t	init();
void	quit();

} // namespace console

} // namespace coreLib
