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

console.cpp

*******************************************************************************/

#include "console.hpp"
#include "cvar.hpp"

namespace coreLib
{

namespace console
{

// System CVARs. This is populated with the names of all the hard coded CVARs,
// but is not assigned the pointers yet. This is to avoid trying to assign the
// address of an object that might not exist yet. Addresses are filled in by
// each system's init() function.
std::map<std::string_view, CVAR *> systemCVARs =
{
	// Audio CVARs.

	// Console CVARs.
	{ "con_alpha",		nullptr },
	{ "con_bdralpha",	nullptr },
	{ "con_height",		nullptr },
	{ "con_textscale",	nullptr },
	{ "con_width",		nullptr },
	{ "con_xpos",		nullptr },
	{ "con_ypos",		nullptr },

	// Video CVARs.
	{ "vid_customheight",	nullptr },
	{ "vid_customwidth",	nullptr },
	{ "vid_display",		nullptr },
	{ "vid_driver",			nullptr },
	{ "vid_fullscreen",		nullptr },
	{ "vid_mode",			nullptr },
	{ "vid_renderer",		nullptr }
};


std::map<std::string_view, std::string_view>	customCVARs;
std::map<std::string_view, void(*)()>			CCMDs;

static FloatCVAR
	alpha(0.75, 0.0, 1.0, "consoleAlphaDesc"),
	borderAlpha(1.0, 0.0, 1.0, "consoleBorderAlphaDesc"),
	xPos(0.0, -0.9, 0.9, "consoleXPosDesc"),
	yPos(0.0, -0.9, 0.9, "consoleYPosDesc"),
	width(0.75, 0.1, 1.0, "consoleWidthDesc"),
	height(0.75, 0.1, 1.0, "consoleHeightDesc"),
	textScale(1.0, 0.1, 0.5, "consoleTextScaleDesc");

/**
 * Changes the width and height of the console.
 */

bool setWidth(const float val)
{
	return true;
}

bool setHeight(const float val)
{
	return true;
}

/**
 * Draws console. This is done on top of the rendered scene, to allow for
 * any transparency.
 */

void draw()
{

}

/**
 *
 */

uint8_t init()
{
	systemCVARs["con_alpha"]		= &alpha;
	systemCVARs["con_bdralpha"]		= &borderAlpha;
	systemCVARs["con_xpos"]			= &xPos;
	systemCVARs["con_ypos"]			= &yPos;
	systemCVARs["con_width"]		= &width;
	systemCVARs["con_height"]		= &height;
	systemCVARs["con_textscale"]	= &textScale;

	return 0;
}

/**
 *
 */

void quit()
{

}

} // namespace console

} // namespace coreLib
