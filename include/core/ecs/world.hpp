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

#ifndef WORLD_HPP
#define WORLD_HPP

#include "core/config.hpp"
#include "core/pch.hpp"
#include "core/ecs/system.hpp"
#include "utility/indexing.hpp"
#include "core/ecs/base_component_tank.hpp"
#include "core/ecs/base_component.hpp"
#include "core/ecs/tank_view.hpp"
#include "core/signal.hpp"
#include "utility/time.hpp"
#include "utility/types.hpp"

namespace ece
{
	namespace core
	{
		namespace ecs
		{
			template <class ComponentType> class ComponentTank;
			class EntityHandler;

			/**
			 * @class World
			 * @brief
			 */
			class ECE_CORE_API World
			{
			public:
				using Prototype = std::function<auto (World &) -> EntityHandler>;

				/**
				 * @fn constexpr World() noexcept
				 * @brief Default constructor.
				 * @throw noexcept
				 */
				inline World() noexcept;

				/**
				 * @fn World(const World & copy) noexcept
				 * @param[in] copy The World to copy from.
				 * @brief Default copy constructor.
				 * @throw noexcept
				 */
				World(const World & copy) noexcept = delete;

				/**
				 * @fn World(World && move) noexcept
				 * @param[in] move The World to move.
				 * @brief Default move constructor.
				 * @throw noexcept
				 */
				World(World && move) = default;

				/**
				 * @fn ~World() noexcept
				 * @brief Default destructor.
				 * @throw noexcept
				 */
				inline ~World() noexcept;

				/**
				 * @fn World & operator=(const World & copy) noexcept
				 * @param[in] copy The World to copy from.
				 * @return The World copied.
				 * @brief Default copy assignment operator.
				 * @throw noexcept
				 */
				World & operator=(const World & copy) = default;

				/**
				 * @fn World & operator=(World && move) noexcept
				 * @param[in] move The World to move.
				 * @return The World moved.
				 * @brief Default move assignment operator.
				 * @throw noexcept
				 */
				World & operator=(World && move) noexcept = default;

				void update();

				template <class ComponentType> auto getComponents() -> TankView<ComponentType>;

				template <class SystemType, class... Args> auto addSystem(Args&&... args) -> SystemType &;

				template <class SystemType> auto hasSystem() const -> bool;

				auto createEntity() -> EntityHandler;
				auto createEntity(Prototype prototype) -> EntityHandler;

				void forEachEntity(const std::function<void(EntityHandler)>& routine);
				void forEachEntity(std::function<void(EntityHandler)>&& routine);
				template <class T> void forEachEntity(T& object, void (T::* routine)(EntityHandler));
				template <class T> void forEachEntity(std::weak_ptr<T>& object, void (T::* routine)(EntityHandler));
				template <class T> void forEachEntity(const T& object, void (T::* routine)(EntityHandler) const);
				template <class T> void forEachEntity(const std::weak_ptr<T>& object, void (T::* routine)(EntityHandler) const);

				inline auto getNumberofEntities() const -> std::size_t;

				template <class ComponentType> auto hasComponent(Handle entityID) -> bool;
				template <class... ComponentTypes> auto hasComponents(Handle EntityID) -> bool;

				template <class ComponentType> auto getComponent(Handle entityID) -> ComponentType &;
				template <class... ComponentTypes> auto getComponents(Handle entityID) -> std::tuple<ComponentTypes & ...>;

				template <class ComponentType, class ... Args> auto addComponent(Handle entityID, Args&&... args) -> ComponentType &;

				template <class ComponentType> void removeComponent(Handle entityID);
				template <class... ComponentTypes> void removeComponents(Handle entityID);
				void destroy(Handle entityID);

				Signal<EntityHandler &> onEntityCreated;
				Signal<BaseComponent &> onComponentCreated;

			private:
				template <class ComponentType>
				void addTank();

				template <class ComponentType>
				auto getTank()->ComponentTank<ComponentType>&;

				/**
				 * @typedef Entity
				 * @brief Define an entity of the world.
				 */
				struct Entity
				{
					Handle id;
					bool dirty;
				};

				/**
				* @property _systems
				* @brief The list of system running in the world.
				*/
				std::map<std::type_index, std::shared_ptr<System>> _systems;

				/**
				* @property _components
				* @brief The list of components composing all the entities of the world.
				*/
				std::unordered_map<std::type_index, std::shared_ptr<BaseComponentTank>> _tanks;

				/**
				* @property _entities
				* @brief The list of entities being in the world.
				*/
				std::vector<Entity> _entities;

				/**
				* @property _entityGenerator
				* @brief To create a new entity.
				*/
				UniqueID<Handle> _entityGenerator;

				Chrono _chrono;
			};
		} // namespace ecs
	} // namespace core
} // namespace ece

#include "core/ecs/world.inl"

#endif // WORLD_HPP
