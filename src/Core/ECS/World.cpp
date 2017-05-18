#include "ECS\World.hpp"

#include "ECS\ComponentTank.hpp"

namespace ece
{
	World::World(): systems(), components(), entities(), entityGenerator()
	{
	}

	World::~World()
	{
	}

	void World::addSystem(const std::shared_ptr<BaseSystem>& system)
	{
		// BUG: probably an error of reference counting here
		this->systems.push_back(std::unique_ptr<BaseSystem>(system.get()));
	}

	const World::Entity World::addEntity()
	{
		this->entities.push_back(this->entityGenerator.next());
		return this->entities.back();
	}

	void World::deleteEntity(const Entity entity)
	{
		auto pos = std::find(this->entities.begin(), this->entities.end(), entity);
		if (pos != this->entities.end()) {
			this->entityGenerator.restack(*pos);
			this->entities.erase(pos);
		}
	}

	std::vector<std::shared_ptr<BaseComponent>>& World::getComponents(BaseComponent::ComponentType type)
	{
		return this->components->getComponents(type);
	}

	void World::addComponent(const std::shared_ptr<BaseComponent>& component)
	{
		this->components->addComponent(component);
	}

	void World::removeComponent(const std::shared_ptr<BaseComponent>& component)
	{
		this->components->removeComponent(component);
	}
}
