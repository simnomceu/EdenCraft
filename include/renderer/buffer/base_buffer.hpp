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
#include "renderer/resource/object_opengl.hpp"

#include <cstddef>

namespace ece
{
	namespace renderer
	{
		namespace buffer
		{
			using resource::ObjectOpenGL;

			/**
			 * @class BaseBuffer
			 * @brief
			 */
			class ECE_RENDERER_API BaseBuffer: public ObjectOpenGL
			{
			public:
				struct DataDescriptor
				{
					int offset;
					int stride;
				};

				/**
				 * @fn constexpr BaseBuffer() noexcept
				 * @brief Default constructor.
				 * @throw noexcept
				 */
				inline BaseBuffer() noexcept;

				/**
				 * @fn BaseBuffer(const BaseBuffer & copy) noexcept
				 * @param[in] copy The BaseBuffer to copy from.
				 * @brief Default copy constructor.
				 * @throw noexcept
				 */
				BaseBuffer(const BaseBuffer & copy) = default;

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
				BaseBuffer & operator=(const BaseBuffer & copy);

				/**
				 * @fn BaseBuffer & operator=(BaseBuffer && move) noexcept
				 * @param[in] move The BaseBuffer to move.
				 * @return The BaseBuffer moved.
				 * @brief Default move assignment operator.
				 * @throw noexcept
				 */
				BaseBuffer & operator=(BaseBuffer && move) noexcept;

				inline virtual void bind() const override;
				inline virtual void terminate() override;

				virtual std::size_t size() const noexcept = 0;
				virtual BufferFrequency getFrequency() const = 0;

				inline BufferType getType() const;

				inline void setDataDescriptor(const DataDescriptor & descriptor) noexcept;
				inline const DataDescriptor & getDataDescriptor() const noexcept;

			protected:
				DataDescriptor _descriptor;
				BufferType _type;
			};
		} // namespace buffer
	} // namespace renderer
} // namespace ece

#include "renderer/buffer/base_buffer.inl"

#endif // BASE_BUFFER_HPP