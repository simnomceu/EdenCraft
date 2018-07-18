#ifndef WORLD_HPP
#define WORLD_HPP

#include "ECS\BaseSystem.hpp"
#include "UniqueID.hpp"
#include "ECS\BaseComponent.hpp"

#include <memory>
#include <vector>

namespace ece
{
	class ComponentTank;

	class World
	{
	public:
		using Entity = unsigned int;

		World();
		~World();

		void addSystem(const std::shared_ptr<BaseSystem> & system);
		const Entity addEntity();
		void deleteEntity(const Entity entity);
		std::vector<std::shared_ptr<BaseComponent>> & getComponents(BaseComponent::ComponentType type);
		void addComponent(const std::shared_ptr<BaseComponent> & component);
		void removeComponent(const std::shared_ptr<BaseComponent> & component);

	private:
		std::vector<std::unique_ptr<BaseSystem>> systems;
		std::shared_ptr<ComponentTank> components;
		std::vector<Entity> entities;
		UniqueID entityGenerator;
	};
}

#endif // WORLD_HPP
