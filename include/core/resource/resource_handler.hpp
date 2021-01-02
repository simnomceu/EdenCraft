/*

	oooooooooooo       .o8                          .oooooo.                       .o88o.     .
	`888'     `8      "888                         d8P'  `Y8b                      888 `"   .o8
	 888          .oooo888   .ooooo.  ooo. .oo.   888          oooo d8b  .oooo.   o888oo  .o888oo
	 888oooo8    d88' `888  d88' `88b `888P"Y88b  888          `888""8P `P  )88b   888      888
	 888    "    888   888  888ooo888  888   888  888           888      .oP"888   888      888
	 888       o 888   888  888    .o  888   888  `88b    ooo   888     d8(  888   888      888 .
	o888ooooood8 `Y8bod88P" `Y8bod8P' o888o o888o  `Y8bood8P'  d888b    `Y888""8o o888o     "888"

															  .oooooo.
															 d8P'  `Y8b
															888           .ooooo.  oooo d8b  .ooooo.
															888          d88' `88b `888""8P d88' `88b
															888          888   888  888     888ooo888
															`88b    ooo  888   888  888     888    .o
															 `Y8bood8P'  `Y8bod8P' d888b    `Y8bod8P'



				This file is part of EdenCraft Engine - Core module.
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

#ifndef RESOURCE_HANDLER_HPP
#define RESOURCE_HANDLER_HPP

#include "core/config.hpp"
#include "core/pch.hpp"
#include "utility/types.hpp"
#include "core/resource/resource.hpp"

namespace ece
{
	namespace core
	{
		namespace resource
		{
			class ResourceManager;

			/**
			 * @class ResourceHandler
			 * @brief
			 */
			class ECE_CORE_API ResourceHandler
			{
			public:
				template <class T> inline ResourceHandler(const Resource<T> & resource) noexcept;
				inline ResourceHandler(ece::size_t id, std::size_t typeId, const std::string & path) noexcept;

				inline ResourceHandler() noexcept;

				/**
				 * @fn ResourceHandler(const ResourceHandler & copy) noexcept
				 * @param[in] copy The ResourceHandler to copy from.
				 * @brief Default copy constructor.
				 * @throw noexcept
				 */
				inline ResourceHandler(const ResourceHandler & copy) noexcept;

				/**
				 * @fn ResourceHandler(ResourceHandler && move) noexcept
				 * @param[in] move The ResourceHandler to move.
				 * @brief Default move constructor.
				 * @throw noexcept
				 */
				inline ResourceHandler(ResourceHandler && move) noexcept;

				/**
				 * @fn ~ResourceHandler() noexcept
				 * @brief Default destructor.
				 * @throw noexcept
				 */
				inline ~ResourceHandler() noexcept;

				/**
				 * @fn ResourceHandler & operator=(const ResourceHandler & copy) noexcept
				 * @param[in] copy The ResourceHandler to copy from.
				 * @return The ResourceHandler copied.
				 * @brief Default copy assignment operator.
				 * @throw noexcept
				 */
				inline ResourceHandler & operator=(const ResourceHandler & copy) noexcept;

				/**
				 * @fn ResourceHandler & operator=(ResourceHandler && move) noexcept
				 * @param[in] move The ResourceHandler to move.
				 * @return The ResourceHandler moved.
				 * @brief Default move assignment operator.
				 * @throw noexcept
				 */
				inline ResourceHandler & operator=(ResourceHandler && move) noexcept;

				template <class T>
				inline auto is() const noexcept -> bool;

				template <class T>
				inline auto get() const -> Resource<T>;

				inline auto getID() const noexcept -> ece::size_t;
				inline auto getTypeID() const noexcept -> std::size_t;
				inline auto getPath() const noexcept -> const std::string &;

				inline auto isDirty() const noexcept -> bool;

			protected:
				ece::size_t _id;
				std::size_t _typeId;
				std::string _path;
			};
		} // namespace resource
	} // namespace core
} // namespace ece

#include "core/resource/resource_handler.inl"

#endif // RESOURCE_HANDLER_HPP