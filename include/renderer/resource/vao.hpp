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

#ifndef VAO_HPP
#define VAO_HPP

#include "renderer/resource/ibo.hpp"
#include "renderer/resource/object_opengl.hpp"
#include "renderer/resource/buffer_layout.hpp"

namespace ece
{
	namespace renderer
	{
		namespace resource
		{
			/**
			 * @class VAO
			 * @brief A vertex array object as defined in OpenGL.
			 */
			class VAO: public ObjectOpenGL
			{
			public:
				/**
				 * @fn VAO()
				 * @brief Default constructor.
				 * @throw noexcept
				 */
				VAO();

				/**
				 * @fn VAO(const VAO & copy) noexcept
				 * @param[in] copy The VAO to copy from.
				 * @brief Default copy constructor.
				 * @throw noexcept
				 */
				VAO(const VAO & copy) noexcept = default;

				/**
				 * @fn VAO(VAO && move) noexcept
				 * @param[in] move The VAO to move.
				 * @brief Default move constructor.
				 * @throw noexcept
				 */
				VAO(VAO && move) noexcept = default;

				/**
				 * @fn ~VAO()
				 * @brief Default destructor.
				 * @throw noexcept
				 */
				~VAO() noexcept = default;

				/**
				 * @fn VAO & operator=(const VAO & copy) noexcept
				 * @param[in] copy The VAO to copy from.
				 * @return The VAO copied.
				 * @brief Default copy assignment operator.
				 * @throw noexcept
				 */
				VAO & operator=(const VAO & copy) noexcept = default;

				/**
				 * @fn VAO & operator=(VAO && move) noexcept
				 * @param[in] move The VAO to move.
				 * @return The VAO moved.
				 * @brief Default move assignment operator.
				 * @throw noexcept
				 */
				VAO & operator=(VAO && move) noexcept = default;

				/**
				 * @fn void bind() const
				 * @brief Put the vao in a buffer to be used.
				 * @throw
				 */
				virtual inline void bind() const override;

				/**
				 * @fn void bindIndexBuffer() const
				 * @brief Use the index buffer set.
				 * @throw
				 */
				inline void bindIndexBuffer() const;

				/**
				 * @fn void addAttribute(const int location, const int size, const bool normalized, const int offset, const BufferType type, const std::vector<T> & data, const BufferUsage usage)
				 * @tparam T The type of data to add to the vertex array, using a VBO.
				 * @param[in] location The index of the VAO to modify.
				 * @param[in] size The size of a vertex.
				 * @param[in] normalized If fixed-point values has to be normalized or not
				 * @param[in] offset The offset between two vertex.
				 * @param[in] type The type of data.
				 * @param[in] data The array of vertex.
				 * @param[in] usage The usage of the buffer.
				 * @brief Add a list of vertex as a VBO in the vertex array object.
				 * @throw
				 */
				template<class T> void sendData(const BufferLayout & layout, const BufferType type, const std::vector<T> & data, const BufferUsage usage, const bool instancing = false);

				/**
				 * @fn void addAttributeWithoutBuffer(const int location, const int size, const bool normalized, const int offset, const BufferType type, std::vector<T> & data, const BufferUsage usage)
				 * @tparam T The type of data to add to the vertex array without VBO.
				 * @param[in] location The index of the VAO to modify.
				 * @param[in] size The size of a vertex.
				 * @param[in] normalized If fixed-point values has to be normalized or not
				 * @param[in] offset The offset between two vertex.
				 * @param[in] type The type of data.
				 * @param[in] data The array of vertex.
				 * @param[in] usage The usage of the buffer.
				 * @brief Add a list of vertex DIRECTLY in the vertex array object.
				 * @throw
				 */
				template<class T> void sendDataWithoutBuffer(const BufferLayout & layout, const BufferType type, const std::vector<T> & data, const BufferUsage usage);

				/**
				 * @fn void addIndices(const std::vector<unsigned int> & data, const BufferUsage usage)
				 * @param[in] data The list of indices.
				 * @param[in] usage The usage of the buffer.
				 * @brief Add an index buffer object to the VAO.
				 * @throw
				 */
				template <class T> void addIndices(const std::vector<T> & data, const BufferUsage usage);

				/**
				 * @fn unsigned int getNbVertices() const
				 * @return The number of vertices of the object.
				 * @brief Get the number of vertices of the object.
				 * @throw
				 */
				inline unsigned int getNbVertices() const;

				virtual void terminate() override;

			private:
				/**
				 * @property _nbVertices
				 * @brief The number of vertices of the object.
				 */
				unsigned int _nbVertices;

				/**
				 * @property _ibo
				 * @brief The index buffer object to use.
				 */
				IBO _ibo;

                unsigned int _globalLocation;
			};
		} // namespace resource
	} // namespace renderer
} // namespace ece

#include "renderer/resource/vao.inl"

#endif // VAO_HPP
