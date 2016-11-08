#ifndef WORLD_HPP
#define WORLD_HPP

#include "Core\ECS\ECS\BaseSystem.hpp"
#include "Core\ECS\ECS\ComponentTank.hpp"
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

		void addSystem(const std::shared_ptr<BaseSystem> & system);
		const Entity addEntity();
		void deleteEntity(const Entity entity);
		ComponentTank & getComponents();


	private:
		std::vector<std::unique_ptr<BaseSystem>> systems;
		ComponentTank components;
		std::vector<Entity> entities;
		UniqueID entityGenerator;
	};
}

#endif // WORLD_HPP
