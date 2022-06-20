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

localization.cpp

*******************************************************************************/

#include <iostream>
#include <locale>
#include <regex>
#include <SDL2/SDL.h>
#include "console.hpp"
#include "cvar.hpp"
#include "localization.hpp"

namespace coreLib
{

namespace localization
{

// System locale.
const char *LanguageFile::systemLocale = std::setlocale(LC_ALL, "");

// Locale directory.
const std::filesystem::path				LanguageFile::localePath("./locale");
const std::filesystem::directory_entry	LanguageFile::localeDir(localePath);

// Message format.
const std::regex LanguageFile::messageFormat("^\\s*([a-zA-Z]+)\\s+\"(\\w+)\"\\s*$", std::regex_constants::icase);

// Default.
const std::string_view LanguageFile::defStrNotFoundMsg = "Error: Message '%s' not found in language file '%s'!";

// Languages.
const std::map<std::string_view, std::string_view> LanguageFile::languages =
{
	{ "English_United States", "en_us" }
};

// Messages.
std::map<std::string_view, LanguageFile::message> LanguageFile::messages =
{
	//
};

// This will be filled in once the locale directory is scanned for language
// files.
console::Uint8CVAR language;

/**
 * Constructor
 */

LanguageFile::LanguageFile(const std::string_view &filename) :
	locFilePath(localePath.string() + "/" + filename.data() + ".ini")
{
	std::smatch rm;

	// Open language file. If it does not exist, do nothing, as there is nothing
	// to do, obviously.
	locFile.open(locFilePath.string(), std::ios::in);
	if(!locFile.is_open())
	{

		return;
	}

	std::string line;

	while(std::getline(locFile, line))
	{
		std::regex_match(line, rm, messageFormat);
		if(rm.size())
		{
			for(auto &m : rm) printf("%s\n", m.str().c_str());
		}
	}

	locFile.close();

}

/**
 * Move Constructor
 */

LanguageFile::LanguageFile(LanguageFile &&lf)
{
	locFilePath = lf.locFilePath;
}

/**
 * Move Assignment
 */

LanguageFile & LanguageFile::operator = (LanguageFile &&lf)
{
	locFilePath = lf.locFilePath;
	return *this;
}

/**
 * Gets the list of language files from the ./locale directory. If there are
 * none or the folder doesn't exist at all, it's a fatal error. Can't really do
 * anything if you can't display text to the user at all, can you?
 */

uint8_t init()
{
	if(!LanguageFile::localeDir.exists())
	{
		SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "FATAL ERROR!", "Directory 'locale' does not exist.\nPlease reinstall the program.", nullptr);
		return 1;
	}

	std::filesystem::directory_iterator localeDirIt(LanguageFile::localePath);

	// No files in directory.
	if(std::filesystem::begin(localeDirIt) == std::filesystem::end(localeDirIt))
	{
		SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "FATAL ERROR!", "Directory 'locale' contains no language files.\nPlease reinstall the program.", nullptr);
		return 2;
	}

	uint8_t numLangFiles = 0;

	for(auto &langFile : localeDirIt)
	{
		numLangFiles++;
		std::cout << "Found language file: '" << langFile << ".'\n";
	}

	// CVAR to select language file.
	// The files are numbered 1 to the number of files, in alphabetical order.
	// 0 can be used to select the language automatically (system language).
	language = { 0, 0, numLangFiles, "locLanguageDesc" };

	return 0;
}

} // namespace localization

} // namespace coreLib
