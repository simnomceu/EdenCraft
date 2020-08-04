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

#ifndef COMPONENT_HPP
#define COMPONENT_HPP

#include "core/config.hpp"
#include "core/pch.hpp"
#include "core/ecs/base_component.hpp"

namespace ece
{
	namespace core
	{
		namespace ecs
		{
			/**
			 * @class Component
			 * @extends BaseComponent
			 * @tparam T The type of attribute that the component define.
			 * @brief A component define an attribute of an entity.
			 */
			template<class T>
			class ECE_CORE_API Component: public BaseComponent
			{
			public:
				/**
				 * @fn Component()
				 * @brief Default constructor.
				 * @throw
				 */
				Component();

				/**
				 * @fn ~Component()
				 * @brief Default destructor.
				 * @throw
				 */
				~Component();

				/**
				 * @fn ComponentID getID() const
				 * @return The id to handle the component.
				 * @brief Get The component id.
				 * @throw
				 */
				inline virtual auto getID() const -> ComponentID override;

				inline virtual void setOwner(const Handle owner) override;

				/**
				 * @fn unsigned int getOwner() const
				 * @return The entity owner.
				 */
				inline virtual auto getOwner() const ->Handle override;

				inline virtual auto isDirty() const -> bool override;

				inline virtual void setDirty(bool dirty) override;

			protected:
				/**
				 * @property _id
				 * @brief The id to handle the component.
				 */
				ComponentID _id;

				/**
				 * @property _owner
				 * @brief The entity which own the component.
				 */
				Handle _owner;

				bool _dirty;
			};
		} // namespace ecs
	} // namespace core
} // namespace ece

#include "core/ecs/component.inl"

#endif // COMPONENT_HPP
