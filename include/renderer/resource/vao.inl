/*

	oooooooooooo       .o8                          .oooooo.                       .o88o.     .   
	`888'     `8      "888                         d8P'  `Y8b                      888 `"   .o8   
	 888          .oooo888   .ooooo.  ooo. .oo.   888          oooo d8b  .oooo.   o888oo  .o888oo 
	 888oooo8    d88' `888  d88' `88b `888P"Y88b  888          `888""8P `P  )88b   888      888   
	 888    "    888   888  888ooo888  888   888  888           888      .oP"888   888      888   
	 888       o 888   888  888    .o  888   888  `88b    ooo   888     d8(  888   888      888 . 
	o888ooooood8 `Y8bod88P" `Y8bod8P' o888o o888o  `Y8bood8P'  d888b    `Y888""8o o888o     "888" 

															ooooooooo.                               .o8                                        
															`888   `Y88.                            "888                                        
															 888   .d88'  .ooooo.  ooo. .oo.    .oooo888   .ooooo.  oooo d8b  .ooooo.  oooo d8b 
															 888ooo88P'  d88' `88b `888P"Y88b  d88' `888  d88' `88b `888""8P d88' `88b `888""8P 
															 888`88b.    888ooo888  888   888  888   888  888ooo888  888     888ooo888  888     
															 888  `88b.  888    .o  888   888  888   888  888    .o  888     888    .o  888     
															o888o  o888o `Y8bod8P' o888o o888o `Y8bod88P" `Y8bod8P' d888b    `Y8bod8P' d888b   
                                                                       
                                          
                                     
				This file is part of EdenCraft Engine - Renderer module.
				Copyright(C) 2018 Pierre Casati (@IsilinBN)

				This program is free software : you can redistribute it and/or modify
				it under the terms of the GNU General Public License as published by
				the Free Software Foundation, either version 3 of the License, or
				(at your option) any later version.

				This program is distributed in the hope that it will be useful,
				but WITHOUT ANY WARRANTY; without even the implied warranty of
				MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.See the
				GNU General Public License for more details.

				You should have received a copy of the GNU General Public License
				along with this program.If not, see <http://www.gnu.org/licenses/>.

*/

#include "renderer/resource/vbo.hpp"

namespace ece
{
	namespace renderer
	{
		namespace resource
		{
			inline VAO::VAO() : ObjectOpenGL(), _nbVertices(0), _ibo() { OpenGL::genVertexArrays(this->_handle); }

			inline void VAO::bind() const { OpenGL::bindVertexArray(this->_handle); }

			inline void VAO::bindIndexBuffer() const { this->_ibo.bind(); }

			template<class T, class U>
			void VAO::addAttribute(const int location, const int size, const bool normalized, const int stride, const BufferType type, const std::vector<U> & data, const BufferUsage usage, const int offset)
			{
				this->bind();
				OpenGL::enableVertexAttribArray(location);

				VBO vbo(type);
				vbo.bufferData<T, U>(data, usage, offset);
				OpenGL::vertexAttribPointer<T>(location, size, normalized, stride);
			}

			template<class T, class U>
			void VAO::addAttributeWithoutBuffer(const int location, const int size, const bool normalized, const int stride, const BufferType type, std::vector<U> & data, const BufferUsage usage, const int offset)
			{
				// BUG: somewhere here
				this->bind();
				OpenGL::enableVertexAttribArray(location);

				OpenGL::vertexAttribPointer<T, U>(location, size, normalized, stride, data, offset);
			}

			template <class T>
			void VAO::addIndices(const std::vector<T> & data, const BufferUsage usage)
			{
				if (this->_nbVertices == 0) {
					this->_nbVertices = data.size();
				}

				this->bind();
				this->_ibo.bufferData<T>(data, usage);
			}


			inline unsigned int VAO::getNbVertices() const { return this->_nbVertices; }
		} // namespace resource
	} // namespace renderer
} // namespace ece