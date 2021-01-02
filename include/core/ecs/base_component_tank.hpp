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

#ifndef BASE_COMPONENT_TANK_HPP
#define BASE_COMPONENT_TANK_HPP

#include "core/config.hpp"
#include "core/pch.hpp"

namespace ece
{
	namespace core
	{
		namespace ecs
		{
			/**
			 * @class BaseComponentTank
			 * @brief
			 */
			class BaseComponentTank
			{
			public:
				/**
				 * @fn constexpr BaseComponentTank() noexcept
				 * @brief Default constructor.
				 * @throw noexcept
				 */
				constexpr BaseComponentTank() noexcept = default;

				/**
				 * @fn BaseComponentTank(const BaseComponentTank & copy) noexcept
				 * @param[in] copy The BaseComponentTank to copy from.
				 * @brief Default copy constructor.
				 * @throw noexcept
				 */
				BaseComponentTank(const BaseComponentTank & copy) noexcept = default;

				/**
				 * @fn BaseComponentTank(BaseComponentTank && move) noexcept
				 * @param[in] move The BaseComponentTank to move.
				 * @brief Default move constructor.
				 * @throw noexcept
				 */
				BaseComponentTank(BaseComponentTank && move) noexcept = default;

				/**
				 * @fn ~BaseComponentTank() noexcept
				 * @brief Default destructor.
				 * @throw noexcept
				 */
				~BaseComponentTank() noexcept = default;

				/**
				 * @fn BaseComponentTank & operator=(const BaseComponentTank & copy) noexcept
				 * @param[in] copy The BaseComponentTank to copy from.
				 * @return The BaseComponentTank copied.
				 * @brief Default copy assignment operator.
				 * @throw noexcept
				 */
				BaseComponentTank & operator=(const BaseComponentTank & copy) noexcept = default;

				/**
				 * @fn BaseComponentTank & operator=(BaseComponentTank && move) noexcept
				 * @param[in] move The BaseComponentTank to move.
				 * @return The BaseComponentTank moved.
				 * @brief Default move assignment operator.
				 * @throw noexcept
				 */
				BaseComponentTank & operator=(BaseComponentTank && move) noexcept = default;

				virtual auto size() const noexcept -> std::size_t = 0;

				virtual auto empty() const noexcept -> bool = 0;

				virtual void update() = 0;

				virtual void destroy(Handle entityID) = 0;
			};
		} // namespace ecs
	} // namespace core
} // namespace ece

#endif // BASE_COMPONENT_TANK_HPP
