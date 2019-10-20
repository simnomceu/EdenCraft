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

#ifndef RESOURCE_REF_HPP
#define RESOURCE_REF_HPP

#include "core/config.hpp"
#include "core/pch.hpp"

namespace ece
{
	namespace core
	{
		namespace resource
		{
			/**
			 * @class ResourceRef
			 * @brief
			 */
			class ECE_CORE_API ResourceRef
			{
			public:
				inline ResourceRef(const std::string & identifier, std::size_t typeId) noexcept;

				ResourceRef() noexcept = delete;

				/**
				 * @fn ResourceRef(const ResourceRef & copy) noexcept
				 * @param[in] copy The ResourceRef to copy from.
				 * @brief Default copy constructor.
				 * @throw noexcept
				 */
				inline ResourceRef(const ResourceRef & copy) noexcept;

				/**
				 * @fn ResourceRef(ResourceRef && move) noexcept
				 * @param[in] move The ResourceRef to move.
				 * @brief Default move constructor.
				 * @throw noexcept
				 */
				inline ResourceRef(ResourceRef && move) noexcept;

				/**
				 * @fn ~ResourceRef() noexcept
				 * @brief Default destructor.
				 * @throw noexcept
				 */
				inline virtual ~ResourceRef() noexcept;

				/**
				 * @fn ResourceRef & operator=(const ResourceRef & copy) noexcept
				 * @param[in] copy The ResourceRef to copy from.
				 * @return The ResourceRef copied.
				 * @brief Default copy assignment operator.
				 * @throw noexcept
				 */
				inline ResourceRef & operator=(const ResourceRef & copy) noexcept;

				/**
				 * @fn ResourceRef & operator=(ResourceRef && move) noexcept
				 * @param[in] move The ResourceRef to move.
				 * @return The ResourceRef moved.
				 * @brief Default move assignment operator.
				 * @throw noexcept
				 */
				inline ResourceRef & operator=(ResourceRef && move) noexcept;

				template <class T>
				auto is() const -> bool;

				/*template <class T>
				auto & to();

				template <class T>
				const auto & to() const;*/

				template <class T>
				auto to() const;

				inline auto getIdentifier() const noexcept -> const std::string &; 

			protected:
				std::string _identifier;
				std::size_t _typeId;
			};
		} // namespace resource
	} // namespace core
} // namespace ece

#include "core/resource/resource_ref.inl"

#endif // RESOURCE_REF_HPP