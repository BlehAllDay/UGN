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

texture.cpp

*******************************************************************************/

#include "texture.hpp"

namespace glLib
{

Texture::Texture(const GLenum target, const GLuint &numTextures)
{
	glCreateTextures(target, numTextures, names.get());
}

Texture1D::Texture1D(const GLuint numTextures) :
	Texture(GL_TEXTURE_1D, numTextures)
{
}


Texture2D::Texture2D(const GLuint numTextures) :
	Texture(GL_TEXTURE_2D, numTextures)
{

}



Texture3D::Texture3D(const GLuint numTextures) :
	Texture(GL_TEXTURE_3D, numTextures)
{

}

}
