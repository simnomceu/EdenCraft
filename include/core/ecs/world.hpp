#ifndef WORLD_HPP
#define WORLD_HPP

#include "core/ecs/base_system.hpp"
#include "core/ecs/component_tank.hpp"
#include "utility/indexing/unique_id.hpp"

#include <memory>
#include <vector>

namespace ece
{
	class World
	{
	public:
		using Entity = unsigned int;

		inline World();
		inline ~World();

	private:
		std::vector<std::unique_ptr<BaseSystem>> _systems;
		ComponentTank _components;
		std::vector<Entity> _entities;
		UniqueID _entityGenerator;
	};
}

#include "core/ecs/world.inl"

#endif // WORLD_HPP
