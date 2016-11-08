#ifndef WORLD_HPP
#define WORLD_HPP

#include "Core\ECS\BaseSystem.hpp"
#include "Core\ECS\ComponentTank.hpp"
#include "Core\Util\UniqueID.hpp"

#include <memory>
#include <vector>

namespace ece
{
	class World
	{
	public:
		using Entity = unsigned int;

		World();
		~World();

	private:
		std::vector<std::unique_ptr<BaseSystem>> systems;
		ComponentTank components;
		std::vector<Entity> entities;
		UniqueID entityGenerator;
	};
}

#endif // WORLD_HPP
