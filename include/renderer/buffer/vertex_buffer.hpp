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

#ifndef VERTEX_BUFFER_HPP
#define VERTEX_BUFFER_HPP

#include "renderer/config.hpp"
#include "renderer/buffer/buffer.hpp"

namespace ece
{
	namespace renderer
	{
		namespace buffer
		{
			/**
			 * @class VertexBuffer
			 * @brief
			 */
			template <template <class> class Storage, class Data>
			class ECE_RENDERER_API VertexBuffer : public Buffer<Storage, Data>
			{
			public:
				/**
				 * @fn constexpr VertexBuffer() noexcept
				 * @brief Default constructor.
				 * @throw noexcept
				 */
				VertexBuffer() noexcept;

				/**
				 * @fn VertexBuffer(const VertexBuffer & copy) noexcept
				 * @param[in] copy The VertexBuffer to copy from.
				 * @brief Default copy constructor.
				 * @throw noexcept
				 */
				VertexBuffer(const VertexBuffer & copy) noexcept = default;

				/**
				 * @fn VertexBuffer(VertexBuffer && move) noexcept
				 * @param[in] move The VertexBuffer to move.
				 * @brief Default move constructor.
				 * @throw noexcept
				 */
				VertexBuffer(VertexBuffer && move) noexcept = default;

				/**
				 * @fn ~VertexBuffer() noexcept
				 * @brief Default destructor.
				 * @throw noexcept
				 */
				~VertexBuffer() noexcept = default;

				/**
				 * @fn VertexBuffer & operator=(const VertexBuffer & copy) noexcept
				 * @param[in] copy The VertexBuffer to copy from.
				 * @return The VertexBuffer copied.
				 * @brief Default copy assignment operator.
				 * @throw noexcept
				 */
				VertexBuffer & operator=(const VertexBuffer & copy) noexcept = default;

				/**
				 * @fn VertexBuffer & operator=(VertexBuffer && move) noexcept
				 * @param[in] move The VertexBuffer to move.
				 * @return The VertexBuffer moved.
				 * @brief Default move assignment operator.
				 * @throw noexcept
				 */
				VertexBuffer & operator=(VertexBuffer && move) noexcept = default;
			};
		} // namespace buffer
	} // namespace renderer
} // namespace ece

#include "renderer/buffer/vertex_buffer.inl"

#endif // VERTEX_BUFFER_HPP