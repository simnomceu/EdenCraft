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

namespace ece
{
	namespace renderer
	{
		namespace resource
		{
			inline VAO::VAO() : ObjectOpenGL(), _numberOfVertices(0), _numberOfIndices(0), _vbos(), _ibo(nullptr), _globalLocation(0) { this->_handle = OpenGL::genVertexArrays(); }

			inline void VAO::bind() const { OpenGL::bindVertexArray(this->_handle); }

			inline void VAO::bindIndexBuffer() const
            {
                if (this->_ibo) {
                    this->_ibo->bind();
                }
            }

			template<template <class...> class T, class... TT, typename enabled>
			size_t VAO::sendData(const buffer::BufferLayout & layout, const T<TT...> & data, const buffer::BufferFrequency frequency)
            {
                this->bind();
				this->_vbos.emplace_back(layout, frequency);
				this->_vbos.back().bufferData(data, buffer::BufferMethod::DRAW);
                for (size_t i = 0; i < layout.size(); ++i) {
					auto elementLayout = this->_vbos.back().getElementLayout(i);
					if (!elementLayout._ignored) {
						OpenGL::enableVertexAttribArray(this->_globalLocation);
						OpenGL::vertexAttribPointer(this->_globalLocation,
													elementLayout._count,
													elementLayout._type,
													elementLayout._normalized,
													this->_vbos.back().getLayoutStride(),
													(this->_vbos.back().getLayoutStrategy() == buffer::BufferLayout::Strategy::STRUCTURED) ? elementLayout._offset : data.size() / layout.size());
						if (elementLayout._instanced) {
							OpenGL::vertexAttribDivisor(this->_globalLocation, this->_vbos.back().getInstanceBlockSize());
						}
						++this->_globalLocation;
					}
                }
                if (this->_numberOfVertices == 0) {
                    this->_numberOfVertices = data.size(); // ERROR: Here, if not indexed, it works only if vertices are send first ... if the first vbo is not the vertices, it does not work.
                }
				return this->_vbos.size() - 1;
            }

			template<template <class...> class T, class... TT, typename enabled>
			void VAO::updateData(const std::size_t index, const T<TT...> & data)
			{
				this->bind();
				this->_vbos[index].bufferData(data, buffer::BufferMethod::DRAW);
			}

			template<template <class, class...> class T, class E, class... TT, typename enabled>
			void VAO::addIndices(const T<E, TT...> & data)
			{
                if (!this->_ibo) {
                    this->_ibo = std::make_unique<IBO>(buffer::BufferFrequency::STATIC);
                }
				if (this->_numberOfIndices == 0) {
					this->_numberOfIndices = data.size() * sizeof(E) / sizeof(unsigned int);
				}

				this->bind();
				this->_ibo->bufferData(data, buffer::BufferMethod::DRAW);
			}

			inline std::size_t VAO::getNumberOfVertices() const { return this->_numberOfVertices; }

			inline std::size_t VAO::getNumberIndices() const { return this->_numberOfIndices; }

            inline bool VAO::isIndexed() const noexcept {return !!this->_ibo; }
		} // namespace resource
	} // namespace renderer
} // namespace ece
