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

#ifndef BUFFER_OBJECT_HPP
#define BUFFER_OBJECT_HPP

#include "renderer/config.hpp"
#include "renderer/resource/object_opengl.hpp"

namespace ece
{
	namespace renderer
	{
		namespace resource
		{
			/**
			 * @class BufferObject
			 * @brief
			 */
			class ECE_RENDERER_API BufferObject: public ObjectOpenGL
			{
			public:
				enum class Usage : unsigned short int
				{
					STATIC,
					DYNAMIC,
					STREAM
				};

				enum class Method : unsigned short int
				{
					DRAW,
					READ,
					COPY
				};

				/**
				 * @fn BufferObject() noexcept
				 * @brief Default constructor.
				 * @throw noexcept
				 */
				inline BufferObject(const BufferType type, const Usage usage) noexcept;

				/**
				 * @fn BufferObject(const BufferObject & copy) noexcept
				 * @param[in] copy The BufferObject to copy from.
				 * @brief Default copy constructor.
				 * @throw noexcept
				 */
				BufferObject(const BufferObject & copy) noexcept = default;

				/**
				 * @fn BufferObject(BufferObject && move) noexcept
				 * @param[in] move The BufferObject to move.
				 * @brief Default move constructor.
				 * @throw noexcept
				 */
				BufferObject(BufferObject && move) noexcept = default;

				/**
				 * @fn ~BufferObject() noexcept
				 * @brief Default destructor.
				 * @throw noexcept
				 */
				~BufferObject() noexcept = default;

				/**
				 * @fn BufferObject & operator=(const BufferObject & copy) noexcept
				 * @param[in] copy The BufferObject to copy from.
				 * @return The BufferObject copied.
				 * @brief Default copy assignment operator.
				 * @throw noexcept
				 */
				BufferObject & operator=(const BufferObject & copy) noexcept = default;

				/**
				 * @fn BufferObject & operator=(BufferObject && move) noexcept
				 * @param[in] move The BufferObject to move.
				 * @return The BufferObject moved.
				 * @brief Default move assignment operator.
				 * @throw noexcept
				 */
				BufferObject & operator=(BufferObject && move) noexcept = default;

				inline BufferUsage getDrawMode() const noexcept;
				inline BufferUsage getReadMode() const noexcept;
				inline BufferUsage getCopyMode() const noexcept;
				inline BufferUsage getBufferUsage(const Method method) const noexcept;


				/**
				* @fn void bind()
				* @brief Put the VBO in a buffer to be used.
				* @throw
				*/
				inline virtual void bind() const override;

				/**
				* @fn void bufferData(const std::vector<T> & data, const BufferUsage usage)
				* @tparam T The type of data to set.
				* @param[in] data The data to set.
				* @param[in] usage The kind of usage the buffer.
				* @brief Set data in the VBO.
				*/
				template<template <class...> class T, class... TT, typename enabled = std::enable_if_t<contiguous_container_v<T<TT...>> && can_access_data_v<T<TT...>> && has_size_v<T<TT...>>>>
				void bufferData(const T<TT...> & data, const Method method, const int offset = 0);
				// invalidateBufferData
				// clearBufferData
				// bufferStorage

				// bufferSubData
				// invalidateBufferSubData
				// clearBufferSubData

				inline virtual void terminate() override;

			private:
				BufferType _type;
				Usage _usage;
			};
		} // namespace resource
	} // namespace renderer
} // namespace ece

#include "renderer/resource/buffer_object.inl"

#endif // BUFFER_OBJECT_HPP