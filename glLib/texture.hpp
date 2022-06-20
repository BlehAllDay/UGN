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

texture.hpp

*******************************************************************************/

#pragma once

namespace glLib
{

/**

Texture class. Abstract.

**/

class Texture : public Object
{
	public:
		Texture() = default;
		Texture(const GLenum target, const GLuint &numTextures);
		virtual ~Texture();

		inline void makeActive(const GLuint n)
		{
			glActiveTexture(names[n]);
		}
};

class Texture1D : public Texture
{
	public:
		Texture1D() = default;
		Texture1D(const GLuint numTextures);
		~Texture1D();
};

class Texture2D : public Texture
{
	public:
		Texture2D() = default;
		Texture2D(const GLuint numTextures);
		~Texture2D();
};

class Texture3D : public Texture
{
	public:
		Texture3D() = default;
		Texture3D(const GLuint numTextures);
		~Texture3D();
};

}
