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

#include "core/pch.hpp"
#include "core/ecs/world.hpp"
#include "core/ecs/entity_handler.hpp"

namespace ece
{
	namespace core
	{
		namespace ecs
		{
			void World::update()
			{
				for (auto & system : this->_systems) {
					system.second->update(this->_chrono.getElapsedTime() / 1000.0f);
				}

				for (auto & tank : this->_tanks) {
					tank.second->update();
				}

				this->_entities.erase(std::remove_if(this->_entities.begin(), this->_entities.end(), [](auto & lhs) { return lhs.dirty; }), this->_entities.end());
				this->_chrono.reset();
			}

			auto World::createEntity() -> EntityHandler
			{
				auto entity = World::Entity{ this->_entityGenerator.next(), false };
				auto handler = EntityHandler(entity.id, *this);
				this->_entities.push_back(std::move(entity));
				this->onEntityCreated(handler);
				return handler;
			}

			auto World::createEntity(World::Prototype prototype) -> EntityHandler
			{
				return prototype(*this);
			}

			void World::forEachEntity(const std::function<void(EntityHandler)>& routine)
			{
				for (auto & entity : this->_entities) {
					if (!entity.dirty) {
						routine(EntityHandler(entity.id, *this));
					}
				}
			}

			void World::forEachEntity(std::function<void(EntityHandler)>&& routine)
			{
				for (auto& entity : this->_entities) {
					if (!entity.dirty) {
						routine(EntityHandler(entity.id, *this));
					}
				}
			}

			void World::destroy(Handle entityID)
			{
				std::find_if(this->_entities.begin(), this->_entities.end(), [entityID](const auto& entity) -> bool { return entity.id == entityID; })->dirty = true;
				for (auto & tank : this->_tanks) {
					tank.second->destroy(entityID);
				}
			}
		} // namespace ecs
	} // namespace core
} // namespace ece