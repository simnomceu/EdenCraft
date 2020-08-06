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

namespace ece
{
	namespace core
	{
		namespace ecs
		{
			inline World::World() noexcept : onEntityCreated(), onComponentCreated(), _systems(), _tanks(), _entities(), _entityGenerator(), _chrono()
			{
				this->_chrono.start();
			}

			inline World::World(const World& copy) noexcept : onEntityCreated(copy.onEntityCreated), onComponentCreated(copy.onComponentCreated), _systems(copy._systems), _tanks(copy._tanks), 
															_entities(copy._entities), _entityGenerator(copy._entityGenerator), _chrono(copy._chrono)
			{
			}

			inline World::~World() noexcept {}

			template <class ComponentType>
			auto & World::getTank()
			{
				if (this->_tanks.find(std::type_index(typeid(ComponentType))) == this->_tanks.end()) {
					this->addTank<ComponentType>();
				}
				return *std::static_pointer_cast<ComponentTank<ComponentType>>(this->_tanks[std::type_index(typeid(ComponentType))]);
			}

			template <class SystemType, class... Args>
			auto World::addSystem(Args&&... args)
			{
				static_assert(std::is_base_of_v<System, SystemType>, "You are trying to register as a system something which is not.");
				this->_systems.emplace(std::type_index(typeid(SystemType)), std::make_shared<SystemType>(*this, std::forward<Args>(args)...));
                return std::static_pointer_cast<SystemType>(this->_systems[std::type_index(typeid(SystemType))]);
			}

			template <class SystemType>
			auto World::hasSystem() const
			{
				static_assert(std::is_base_of_v<System, SystemType>, "You are trying to register as a system something which is not.");
				return this->_systems.find(std::type_index(typeid(SystemType))) != this->_systems.end();
			}

			template <class ComponentType>
			void World::addTank()
			{
				this->_tanks.emplace(std::type_index(typeid(ComponentType)), std::make_shared<ComponentTank<ComponentType>>());
			}

			template <class ComponentType>
			auto World::hasComponent(Handle entityID)
			{
				auto & tank = this->getTank<ComponentType>();
				auto it = std::find_if(tank.begin(), tank.end(), [entityID](auto & element) {return element.getOwner() == entityID; });
				return it != tank.end();
			}

			template <class... ComponentTypes>
			auto World::hasComponents(Handle entityID)
			{
				return (this->hasComponent<ComponentTypes>(entityID) && ...);
			}

			template <class ComponentType>
			auto & World::getComponent(Handle entityID)
			{
				auto & tank = this->getTank<ComponentType>();
				auto it = std::find_if(tank.begin(), tank.end(), [entityID](auto & element) {return element.getOwner() == entityID; });
				if (it == tank.end()) {
					throw std::runtime_error("This entity does not have a component of this type");
				}
				return *it;
			}

			template <class... ComponentTypes>
			auto World::getComponents(Handle entityID) -> std::tuple<ComponentTypes& ...>
			{
				return std::forward_as_tuple(this->getComponent<ComponentTypes>(entityID)...);
			}
		} // namespace ecs
	} // namespace core
} // namespace ece
