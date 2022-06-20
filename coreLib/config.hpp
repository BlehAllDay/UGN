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

config.hpp

Handles configuration files. Any number of these files may be stored and used by
a program using these libraries. Files are stored in the "config" directory, and
the default "config.cfg" is loaded at program start. During runtime, files may
be created and read by using the "cfg_save" and "cfg_load" commands in console.

*******************************************************************************/

#pragma once

#include <filesystem>
#include <fstream>
#include <regex>
#include <string_view>

namespace coreLib
{

namespace config
{

void load();
void save();


class CFGFile
{
	friend uint8_t init();

	// Directory config files are stored in. Default is "./config".
	static const std::filesystem::path				cfgDirPath;
	static const std::filesystem::directory_entry	cfgDirectory;

	// CVAR string format.
	static const std::regex cvarFormat;

	std::filesystem::path cfgFilePath;
	std::fstream cfgFile;

	public:
		CFGFile() = delete;
		CFGFile(const std::string_view &filename);
		~CFGFile() = default;

		// Copy semantics deleted.
		CFGFile(const CFGFile &) = delete;
		CFGFile & operator = (const CFGFile &) = delete;

		// Move semantics.
		CFGFile(CFGFile &&cf);
		CFGFile & operator = (CFGFile &&cf);

		// Operator overloads.
		inline bool operator ! ()
		{
			return !cfgFile.is_open();
		}

		void load();
		void save();
};

uint8_t	init();
void	quit();

} // namespace config

} // namespace coreLib
