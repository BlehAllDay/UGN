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

localization.hpp

Handles files containing translations for various text strings in various
languages. Currently this only applies to English but maybe it'll get expanded
to other languages. One day.

Each line in a language file supplies a string in the format:

<identifier>="<string>"

The identifiers are the same for each language file, and consist of Latin
characters only. The strings themselves are Unicode. Language files should be
UTF-8 format to accommodate this.

If a specific message cannot be found in a language file, the default English
string will be used, and a warning in the selected language displayed in the
console. If this message itself cannot be found, a hard coded warning in English
will be used instead. None of this should actually happen in practice.

*******************************************************************************/

#pragma once

#include <filesystem>
#include <fstream>
#include <initializer_list>
#include <map>
#include <regex>
#include <string_view>

namespace coreLib
{

namespace localization
{

class LanguageFile
{
	friend uint8_t init();

	// Default.
	static const char *systemLocale;

	// Directory for locale files. Should be "./locale".
	static const std::filesystem::path				localePath;
	static const std::filesystem::directory_entry	localeDir;

	// Message format.
	static const std::regex messageFormat;

	// Default string not found error message.
	static const std::string_view defStrNotFoundMsg;

	// Map of supported languages and filenames. This is in case a system
	// returns a long name for the default locale instead of a short one,
	// this is used to get the name of the language file.
	static const std::map<std::string_view, std::string_view> languages;

	// Locale file path.
	std::filesystem::path locFilePath;
	std::fstream locFile;

	// Information about the strings in a language file.
	typedef struct _message
	{
		std::string_view	msg;		// Message string.
		const uint8_t		numTokens;	// Number of tokens (%s) in string.
		const uint16_t		modLength;	// Length of string minus tokens.
	}
	message;

	// List of messages. Since there can only be one language loaded at any
	// time, this is shared between all that get used. Not const-qualified
	// to allow the user to add messages for their program alongside the ones
	// supplied by the engine.
	static std::map<std::string_view, message> messages;

	public:
		LanguageFile() = delete;
		LanguageFile(const std::string_view &filename);
		~LanguageFile() = default;

		// Copy semantics deleted.
		LanguageFile(const LanguageFile &) = delete;
		LanguageFile & operator = (const LanguageFile &) = delete;

		// Move semantics.
		LanguageFile(LanguageFile &&lf);
		LanguageFile & operator = (LanguageFile &&lf);

		/**
		 * Parses a message, replacing tokens in the string with values if
		 * necessary.
		 *
		 * Similar to functions like printf and sprintf, except this function
		 * takes an initializer list containing the values to replace tokens
		 * with.
		 */

		//template<typename T>
		//concept isPrintable =

		template<typename T>
		std::string parseMessage(const std::string_view &id, const std::initializer_list<T> &values = {})
		{
			switch(values.size())
			{

			}
			std::string str;
			const uint16_t strLength = messages[id].modLength;
			return str;
		}
};

uint8_t	init();
void	quit();

} // namespace localization

} // namespace coreLib
