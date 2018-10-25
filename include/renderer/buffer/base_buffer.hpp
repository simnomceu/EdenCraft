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
#include "utility/types.hpp"

#include <cstddef>

namespace ece
{
	namespace renderer
	{
		namespace buffer
		{
			/**
			 * @class BaseBuffer
			 * @brief
			 */
			class ECE_RENDERER_API BaseBuffer
			{
			public:
				using size_type = std::size_t;

				struct DataDescriptor
				{
					int offset;
					int stride;
				};

				enum class Type : unsigned short int
				{
					ARRAY = 0x00,
					ATOMIC_COUNTER = 0x01,
					COPY_READ = 0x02,
					COPY_WRITE = 0x03,
					DISPATCH_INDIRECT = 0x04,
					DRAW_INDIRECT = 0x05,
					ELEMENT_ARRAY = 0x06,
					PIXEL_PACK= 0x07,
					PIXEL_UNPACK = 0x08,
					QUERY = 0x09,
					SHADER_STORAGE = 0x10,
					TEXTURE = 0x11,
					TRANSFORM_FEEDBACK = 0x12,
					UNIFORM = 0x13
				};

				enum class Frequency : unsigned short int
				{
					STATIC	= 0x0,
					DYNAMIC	= 0x1,
					STREAM	= 0x2
				};

				enum class Method : unsigned short int
				{
					DRAW = 0x0,
					READ = 0x1,
					COPY = 0x2
				};

				/**
				 * @fn constexpr BaseBuffer() noexcept
				 * @brief Default constructor.
				 * @throw noexcept
				 */
				inline constexpr BaseBuffer() noexcept;

				BaseBuffer(const BaseBuffer & copy) = delete;

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

				BaseBuffer & operator=(const BaseBuffer & copy) = delete;

				/**
				 * @fn BaseBuffer & operator=(BaseBuffer && move) noexcept
				 * @param[in] move The BaseBuffer to move.
				 * @return The BaseBuffer moved.
				 * @brief Default move assignment operator.
				 * @throw noexcept
				 */
				BaseBuffer & operator=(BaseBuffer && move) noexcept;

				void bind() const;
				void terminate();

				virtual size_type size() const noexcept = 0;

				inline Type getType() const noexcept;
				inline Frequency getFrequency() const noexcept;

				inline void setDataDescriptor(const DataDescriptor & descriptor) noexcept;
				inline const DataDescriptor & getDataDescriptor() const noexcept;

			protected:
				Handle _handle;
				DataDescriptor _descriptor;
				Type _type;
				Frequency _frequency;
			};
		} // namespace buffer
	} // namespace renderer
} // namespace ece

#include "renderer/buffer/base_buffer.inl"

#endif // BASE_BUFFER_HPP