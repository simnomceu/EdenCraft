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

#ifndef COMPONENT_TANK_HPP
#define COMPONENT_TANK_HPP

#include "core/config.hpp"
#include "core/ecs/base_component_tank.hpp"
#include "core/ecs/component.hpp"
#include "utility/indexing/unique_id.hpp"

#include <memory>
#include <vector>

namespace ece
{
	namespace core
	{
		namespace ecs
		{
			using utility::indexing::UniqueID;

			/**
			 * @class ComponentTank
			 * @brief
			 */
			template <class ComponentType>
			class ECE_CORE_API ComponentTank: public BaseComponentTank
			{
			public:
				using TankIterator = std::vector<ComponentType>::iterator;
				using TankConstIterator = std::vector<ComponentType>::const_iterator;

				/**
				 * @fn constexpr ComponentTank() noexcept
				 * @brief Default constructor.
				 * @throw noexcept
				 */
				constexpr ComponentTank() noexcept = default;

				/**
				 * @fn ComponentTank(const ComponentTank & copy) noexcept
				 * @param[in] copy The ComponentTank to copy from.
				 * @brief Default copy constructor.
				 * @throw noexcept
				 */
				ComponentTank(const ComponentTank & copy) noexcept = default;

				/**
				 * @fn ComponentTank(ComponentTank && move) noexcept
				 * @param[in] move The ComponentTank to move.
				 * @brief Default move constructor.
				 * @throw noexcept
				 */
				ComponentTank(ComponentTank && move) noexcept = default;

				/**
				 * @fn ~ComponentTank() noexcept
				 * @brief Default destructor.
				 * @throw noexcept
				 */
				~ComponentTank() noexcept = default;

				/**
				 * @fn ComponentTank & operator=(const ComponentTank & copy) noexcept
				 * @param[in] copy The ComponentTank to copy from.
				 * @return The ComponentTank copied.
				 * @brief Default copy assignment operator.
				 * @throw noexcept
				 */
				ComponentTank & operator=(const ComponentTank & copy) noexcept = default;

				/**
				 * @fn ComponentTank & operator=(ComponentTank && move) noexcept
				 * @param[in] move The ComponentTank to move.
				 * @return The ComponentTank moved.
				 * @brief Default move assignment operator.
				 * @throw noexcept
				 */
				ComponentTank & operator=(ComponentTank && move) noexcept = default;

				inline virtual size_t getSize() const override;

				inline virtual bool isEmpty() const override;

				virtual void update() = override;

				inline TankIterator begin() noexcept;
				inline TankConstIterator begin() const noexcept;

				inline TankIterator end() noexcept;
				inline TankConstIterator end() const noexcept;
			private:
				std::vector<ComponentType> _components;
			};
		} // namespace ecs
	} // namespace core
} // namespace ece

#include "core/ecs/component_tank.inl"

#endif // COMPONENT_TANK_HPP
