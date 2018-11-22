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

#ifndef BASE_COMPONENT_HPP
#define BASE_COMPONENT_HPP

#include "core/config.hpp"

namespace ece
{
	namespace core
	{
		namespace ecs
		{
			/**
			* @typedef ComponentID
			* @brief The id to handle a component.
			*/
			using ComponentID = unsigned int;

			/**
			 * @class BaseComponent
			 * @brief
			 */
			class ECE_CORE_API BaseComponent
			{
			public:
				/**
				 * @fn constexpr BaseComponent() noexcept
				 * @brief Default constructor.
				 * @throw noexcept
				 */
				constexpr BaseComponent() noexcept = default;

				/**
				 * @fn BaseComponent(const BaseComponent & copy) noexcept
				 * @param[in] copy The BaseComponent to copy from.
				 * @brief Default copy constructor.
				 * @throw noexcept
				 */
				BaseComponent(const BaseComponent & copy) noexcept = default;

				/**
				 * @fn BaseComponent(BaseComponent && move) noexcept
				 * @param[in] move The BaseComponent to move.
				 * @brief Default move constructor.
				 * @throw noexcept
				 */
				BaseComponent(BaseComponent && move) noexcept = default;

				/**
				 * @fn ~BaseComponent() noexcept
				 * @brief Default destructor.
				 * @throw noexcept
				 */
				~BaseComponent() noexcept = default;

				/**
				 * @fn BaseComponent & operator=(const BaseComponent & copy) noexcept
				 * @param[in] copy The BaseComponent to copy from.
				 * @return The BaseComponent copied.
				 * @brief Default copy assignment operator.
				 * @throw noexcept
				 */
				BaseComponent & operator=(const BaseComponent & copy) noexcept = default;

				/**
				 * @fn BaseComponent & operator=(BaseComponent && move) noexcept
				 * @param[in] move The BaseComponent to move.
				 * @return The BaseComponent moved.
				 * @brief Default move assignment operator.
				 * @throw noexcept
				 */
				BaseComponent & operator=(BaseComponent && move) noexcept = default;


				/**
				 * @fn ComponentID getID() const
				 * @return The id to handle the component.
				 * @brief Get The component id.
				 * @throw
				 */
				virtual ComponentID getID() const = 0;

				virtual void setOwner(const unsigned int owner) = 0;

				/**
				 * @fn unsigned int getOwner() const
				 * @return The entity owner.
				 */
				virtual unsigned int getOwner() const = 0;

				virtual bool isDirty() const = 0;
			};
		} // namespace ecs
	} // namespace core
} // namespace ece

#endif // BASE_COMPONENT_HPP