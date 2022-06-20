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

cvar.cpp

*******************************************************************************/

#include "cvar.hpp"

namespace coreLib
{

namespace console
{

/**
 * CVAR class.
 */

// Constructor.
CVAR::CVAR(const std::string_view &defVal, const std::string_view &descID) :
	defaultValue	(defVal),
	descriptionID	(descID)
{}

// Move constructor.
CVAR::CVAR(CVAR &&cv)
{
	defaultValue.swap(cv.defaultValue);
	descriptionID.swap(cv.descriptionID);
}

// Move assignment.
CVAR & CVAR::operator = (CVAR &&cv)
{
	defaultValue.swap(cv.defaultValue);
	descriptionID.swap(cv.descriptionID);
	return *this;
}

/**
 * Boolean CVAR.
 */

// Constructor.
NumericCVAR<bool>::NumericCVAR(const bool defVal, const std::string_view &descID) :
	CVAR(std::to_string(defVal), descID)
{}

// Move constructor.
NumericCVAR<bool>::NumericCVAR(NumericCVAR &&cv) :
	CVAR(std::move(cv))
{
	defaultValue.swap(cv.defaultValue);
	descriptionID.swap(cv.descriptionID);
	numDefaultValue	= cv.numDefaultValue;
	numValue		= cv.numValue;
}

// Move assignment.
NumericCVAR<bool> & NumericCVAR<bool>::operator = (NumericCVAR &&cv)
{
	defaultValue.swap(cv.defaultValue);
	descriptionID.swap(cv.descriptionID);
	numDefaultValue	= cv.numDefaultValue;
	numValue		= cv.numValue;
	return *this;
}

} // namespace console

} // namespace coreLib
