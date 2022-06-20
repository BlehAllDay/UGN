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

buffer.hpp

Wrappers for the various OpenGL buffer objects.

*******************************************************************************/

#pragma once

#include <type_traits>

namespace glLib
{

template<typename T>
concept isValidBufferType = (std::is_integral_v<T>);

/**
 * Base buffer class. Abstract.
 */

class Buffer : public Object
{
	public:
		Buffer() = default;
		Buffer(const GLuint &numBuffers);
		virtual ~Buffer() = default;

		// Copy semantics deleted.
		Buffer(const Buffer &) = delete;
		Buffer & operator = (const Buffer &) = delete;

		// Move semantics.
		Buffer(Buffer &&b);
		Buffer & operator = (Buffer &&b);

		// Bind object to context.
		virtual inline GLvoid bind(GLuint index) = 0;

		/**
		 * Replaces data in the buffer, either in part or in whole.
		 * If the buffer was created with glBufferData(), this can reallocate
		 * the data store, where as if it was created with glBufferStorage(),
		 * relocation is not possible. So only an update on the buffer may be
		 * performed.
		 */

		template<typename T> requires isValidBufferType<T>
		void operator = (const T *data)
		{

		}
};

/**
 * Vertex buffer.
 */

class VertexBuffer : public Buffer
{

	public:
		inline GLvoid bind(GLuint index)
		{
			glBindBuffer(GL_ARRAY_BUFFER, names[index]);
		}
};

} // namespace glLib
