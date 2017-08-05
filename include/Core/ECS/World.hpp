#ifndef WORLD_HPP
#define WORLD_HPP

#include "ECS\BaseSystem.hpp"
#include "ECS\ComponentTank.hpp"
#include "Indexing\UniqueID.hpp"

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

#include "ECS\World.inl"

#endif // WORLD_HPP
