#pragma once

#include <vector>
#include <queue>

#include "Entity.hpp"

namespace ECS
{
	class World
	{
	public:
		World();

		Entity& createEntity();
		std::vector<Entity&> createEntities(int number);

		void killEntity(int index);
		void killEntities(std::vector<int> index);
		void killAllEntities();

		void clear();

		std::shared_ptr<Index<BaseComponent>> getComponentIndex();

		void init();

	private:
		std::vector<Entity> _entities;
		std::queue<int> _freeEntityID;
		
		std::shared_ptr<Index<BaseComponent>> _componentIndex;
	};
}