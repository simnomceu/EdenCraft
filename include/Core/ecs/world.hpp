#ifndef WORLD_HPP
#define WORLD_HPP

#include "ecs/base_system.hpp"
#include "ecs/component_tank.hpp"
#include "indexing/unique_id.hpp"

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
		std::vector<std::unique_ptr<BaseSystem>> systems;
		ComponentTank components;
		std::vector<Entity> entities;
		UniqueID entityGenerator;
	};
}

#include "ecs/world.inl"

#endif // WORLD_HPP
