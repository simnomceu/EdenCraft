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

#ifndef BASE_BUFFER_HPP
#define BASE_BUFFER_HPP

#include "renderer/config.hpp"
#include "renderer/buffer/buffer_usage.hpp"
#include "renderer/buffer/buffer_type.hpp"

#include <cstddef>

namespace ece
{
	namespace renderer
	{
		namespace buffer
		{
			struct BufferDataDescriptor;

			/**
			 * @class BaseBuffer
			 * @brief
			 */
			class ECE_RENDERER_API BaseBuffer
			{
			public:
				/**
				 * @fn constexpr BaseBuffer() noexcept
				 * @brief Default constructor.
				 * @throw noexcept
				 */
				inline constexpr BaseBuffer() noexcept = default;

				/**
				 * @fn BaseBuffer(const BaseBuffer & copy) noexcept
				 * @param[in] copy The BaseBuffer to copy from.
				 * @brief Default copy constructor.
				 * @throw noexcept
				 */
				BaseBuffer(const BaseBuffer & copy) noexcept = default;

				/**
				 * @fn BaseBuffer(BaseBuffer && move) noexcept
				 * @param[in] move The BaseBuffer to move.
				 * @brief Default move constructor.
				 * @throw noexcept
				 */
				BaseBuffer(BaseBuffer && move) noexcept = default;

				/**
				 * @fn ~BaseBuffer() noexcept
				 * @brief Default destructor.
				 * @throw noexcept
				 */
				~BaseBuffer() noexcept = default;

				/**
				 * @fn BaseBuffer & operator=(const BaseBuffer & copy) noexcept
				 * @param[in] copy The BaseBuffer to copy from.
				 * @return The BaseBuffer copied.
				 * @brief Default copy assignment operator.
				 * @throw noexcept
				 */
				BaseBuffer & operator=(const BaseBuffer & copy) noexcept = default;

				/**
				 * @fn BaseBuffer & operator=(BaseBuffer && move) noexcept
				 * @param[in] move The BaseBuffer to move.
				 * @return The BaseBuffer moved.
				 * @brief Default move assignment operator.
				 * @throw noexcept
				 */
				BaseBuffer & operator=(BaseBuffer && move) noexcept = default;

				virtual void setDataDescriptor(const BufferDataDescriptor & descriptor) noexcept = 0;
				virtual const BufferDataDescriptor & getDataDescriptor() const noexcept = 0;

				virtual std::size_t size() const noexcept = 0;
				virtual BufferType & getType() const = 0;
				virtual BufferFrequency getFrequency() const = 0;
			};
		} // namespace buffer
	} // namespace renderer
} // namespace ece

#endif // BASE_BUFFER_HPP