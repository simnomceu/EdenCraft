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

#ifndef BUFFER_HPP
#define BUFFER_HPP

#include "renderer/config.hpp"
#include "renderer/resource/object_opengl.hpp"
#include "renderer/buffer/base_buffer.hpp"
#include "renderer/buffer/is_buffer_storage.hpp"
#include "renderer/buffer/buffer_data_descriptor.hpp"
#include "renderer/buffer/buffer_type.hpp"
#include "renderer/buffer/buffer_usage.hpp"

#include <memory>

namespace ece
{
	namespace renderer
	{
		namespace buffer
		{
			using resource::ObjectOpenGL;

			/**
			 * @class Buffer
			 * @brief
			 */
			template <class Storage, class Data, typename enabled = std::enable_if_t<is_buffer_storage_v<Storage, Data>>>
			class ECE_RENDERER_API Buffer: public BaseBuffer, public ObjectOpenGL, public std::enable_shared_from_this<Buffer<Storage, enabled>>
			{
			public:
				/**
				 * @fn Buffer(const BufferFrequency frequency) noexcept
				 * @brief Default constructor.
				 * @throw noexcept
				 */
				inline Buffer(const BufferFrequency frequency) noexcept;

				/**
				 * @fn Buffer(const Buffer & copy) noexcept
				 * @param[in] copy The Buffer to copy from.
				 * @brief Default copy constructor.
				 * @throw noexcept
				 */
				Buffer(const Buffer & copy) noexcept = default;

				/**
				 * @fn Buffer(Buffer && move) noexcept
				 * @param[in] move The Buffer to move.
				 * @brief Default move constructor.
				 * @throw noexcept
				 */
				Buffer(Buffer && move) noexcept = default;

				/**
				 * @fn ~Buffer() noexcept
				 * @brief Default destructor.
				 * @throw noexcept
				 */
				~Buffer() noexcept = default;

				/**
				 * @fn Buffer & operator=(const Buffer & copy) noexcept
				 * @param[in] copy The Buffer to copy from.
				 * @return The Buffer copied.
				 * @brief Default copy assignment operator.
				 * @throw noexcept
				 */
				Buffer & operator=(const Buffer & copy) noexcept = default;

				/**
				 * @fn Buffer & operator=(Buffer && move) noexcept
				 * @param[in] move The Buffer to move.
				 * @return The Buffer moved.
				 * @brief Default move assignment operator.
				 * @throw noexcept
				 */
				Buffer & operator=(Buffer && move) noexcept = default;

				virtual void bind() const override;

				virtual void terminate() override;

				template<template <class...> class T, class... TT, typename enabledBis = std::enable_if_t<contiguous_container_v<T<TT...>> && can_access_data_v<T<TT...>> && has_size_v<T<TT...>>>>
				T<TT...> read() const;

				template<template <class...> class T, class... TT, typename enabledBis = std::enable_if_t<contiguous_container_v<T<TT...>> && can_access_data_v<T<TT...>> && has_size_v<T<TT...>>>>
				void write(const T<TT...> & data);

				void copy(const Buffer & rhs);

				inline virtual void setDataDescriptor(const BufferDataDescriptor & descriptor) noexcept override;
				inline virtual const BufferDataDescriptor & getDataDescriptor() const noexcept override;

				inline virtual std::size_t size() const noexcept override;
				inline virtual BufferType & getType() const override;
				inline virtual BufferFrequency getFrequency() const override;

			protected:
				BufferDataDescriptor _descriptor;
				BufferType _type;
				BufferFrequency _frequency;
				std::unique_ptr<Storage> _storage;
			};
		} // namespace buffer
	} // namespace renderer
} // namespace ece

#include "renderer/buffer/buffer.inl"

#endif // BUFFER_HPP