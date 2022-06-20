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

object.hpp

Abstract base class for OpenGL objects.

*******************************************************************************/

#pragma once

#include <memory>
#include "glad.h"

namespace glLib
{

/**
 * Base object class. Abstract.
 */

class Object
{
	protected:
		GLuint numObjects;
		std::unique_ptr<GLuint []> names;	// Because OpenGL works with pointers.

	public:
		Object() = default;
		Object(const GLuint &numObjects, void (*createFunc)(GLsizei, GLuint *));
		virtual ~Object();

		// Copy semantics deleted. No two OpenGL objects can share the same
		// resources. Would be bad if one deleted them and another tried to use
		// them after. Maybe.
		Object(const Object &) = delete;
		Object & operator = (const Object &) = delete;

		// Move semantics.
		Object(Object &&obj);
		Object & operator = (Object &&obj);
};

} // namespace glLib
