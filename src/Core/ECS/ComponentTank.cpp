#include "ECS\ComponentTank.hpp"

namespace ece
{
	void ComponentTank::addComponent(const std::shared_ptr<BaseComponent>& component)
	{
		if (this->components.find(component->getType()) == this->components.end()) {
			this->components[component->getType()] = std::vector<std::shared_ptr<BaseComponent>>();
		}

		const auto & entity = this->entityBodies[component->getOwner()];
		if (std::find(entity.begin(), entity.end(), component->getType()) == entity.end()) {
			this->components[component->getType()].push_back(component);
			this->entityBodies[component->getOwner()].push_back(component->getType());
		}
	}
}
