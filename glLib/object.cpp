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

object.cpp

*******************************************************************************/



namespace glLib
{

// Constructor.
Object::Object(const GLuint &numObjs, void (*createFunc)(GLsizei, GLuint *)) :
	numObjects	(numObjs),
	names		(new GLuint[numObjects])
{
	(*createFunc)(numObjects, names.get());
}

// Move consructor.
Object::Object(Object &&obj)
{
	numObjects = obj.numObjects;
	names.swap(obj.names);
}

// Move assignment.
Object & Object::operator = (Object &&obj)
{
	numObjects = obj.numObjects;
	names.swap(obj.names);
	return *this;
}

} // namespace glLib
