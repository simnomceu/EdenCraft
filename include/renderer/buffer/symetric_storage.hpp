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

#ifndef SYMETRIC_STORAGE_HPP
#define SYMETRIC_STORAGE_HPP

#include "renderer/config.hpp"
#include "renderer/opengl/opengl_container.hpp"

namespace ece
{
	namespace renderer
	{
		namespace buffer
		{
			class BaseBuffer;

			/**
			 * @class SymetricStorage
			 * @brief
			 */
			template<template <class...> class T, class... TT>
			class ECE_RENDERER_API SymetricStorage: public OpenGLContainer<T<TT...>>
			{
			public:
				/**
				 * @fn constexpr SymetricStorage() noexcept
				 * @brief Default constructor.
				 * @throw noexcept
				 */
				constexpr SymetricStorage() noexcept = delete;

				SymetricStorage(const std::weak_ptr<BaseBuffer> & buffer);

				/**
				 * @fn SymetricStorage(const SymetricStorage & copy) noexcept
				 * @param[in] copy The SymetricStorage to copy from.
				 * @brief Default copy constructor.
				 * @throw noexcept
				 */
				SymetricStorage(const SymetricStorage & copy) noexcept = default;

				/**
				 * @fn SymetricStorage(SymetricStorage && move) noexcept
				 * @param[in] move The SymetricStorage to move.
				 * @brief Default move constructor.
				 * @throw noexcept
				 */
				SymetricStorage(SymetricStorage && move) noexcept = default;

				/**
				 * @fn ~SymetricStorage() noexcept
				 * @brief Default destructor.
				 * @throw noexcept
				 */
				~SymetricStorage() noexcept = default;

				/**
				 * @fn SymetricStorage & operator=(const SymetricStorage & copy) noexcept
				 * @param[in] copy The SymetricStorage to copy from.
				 * @return The SymetricStorage copied.
				 * @brief Default copy assignment operator.
				 * @throw noexcept
				 */
				SymetricStorage & operator=(const SymetricStorage & copy) noexcept = default;

				/**
				 * @fn SymetricStorage & operator=(SymetricStorage && move) noexcept
				 * @param[in] move The SymetricStorage to move.
				 * @return The SymetricStorage moved.
				 * @brief Default move assignment operator.
				 * @throw noexcept
				 */
				SymetricStorage & operator=(SymetricStorage && move) noexcept = default;

				inline T<TT...> & data() noexcept;
				inline const T<TT...> & data() const noexcept;

				T<TT...> read() const;

				void write(const T<TT...> & data);

				inline void copy(const BaseBuffer & rhs);

			private:
				std::weak_ptr<BaseBuffer> _buffer;
				T<TT...> _data;
			};
		} // namespace buffer
	} // namespace renderer
} // namespace ece

#include "renderer/buffer/symetric_storage.inl"

#endif // SYMETRIC_STORAGE_HPP