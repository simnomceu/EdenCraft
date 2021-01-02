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

#include "core/ecs/world.hpp"

namespace ece
{
	namespace core
	{
		namespace ecs
		{
			inline EntityHandler::EntityHandler(Handle id, World & world) noexcept: _id(id), _world(world) {}

			template <class ComponentType, class ... Args>
			auto & EntityHandler::addComponent(Args&&... args)
			{
				return this->_world.addComponent<ComponentType, Args...>(this->_id, std::forward<Args>(args)...);
			}

			template <class ComponentType>
			auto EntityHandler::hasComponent() const
			{
				return this->_world.hasComponent<ComponentType>(this->_id);
			}

			template <class... ComponentTypes>
			auto EntityHandler::hasComponents() const
			{
				return this->_world.hasComponents<ComponentTypes...>(this->_id);
			}

			template <class ComponentType>
			auto & EntityHandler::getComponent()
			{
				return this->_world.getComponent<ComponentType>(this->_id);
			}

			template <class... ComponentTypes>
			auto EntityHandler::getComponents()
			{
				return this->_world.getComponents<ComponentTypes...>(this->_id);
			}

			template <class ComponentType>
			void EntityHandler::removeComponent()
			{
				this->_world.removeComponent<ComponentType>(this->_id);
			}

			template <class... ComponentTypes>
			void EntityHandler::removeComponents()
			{
				this->_world.removeComponents<ComponentTypes...>(this->_id);
			}
			
			inline void EntityHandler::destroy()
			{
				this->_world.destroy(this->_id);
			}

			inline auto operator==(const EntityHandler & lhs, const EntityHandler & rhs) -> bool
			{
				return lhs._id == rhs._id;
			}

			inline auto operator!=(const EntityHandler & lhs, const EntityHandler & rhs) -> bool
			{
				return lhs._id != rhs._id;
			}
		} // namespace ecs
	} // namespace core
} // namespace ece