#ifndef COMPONENTTANK_HPP
#define COMPONENTTANK_HPP

#include "ECS\BaseComponent.hpp"
#include "ECS\World.hpp"
#include "UniqueID.hpp"

#include <memory>
#include <vector>
#include <map>

namespace ece
{
	class ComponentTank
	{
	public:
		ComponentTank();
		~ComponentTank();

		void addComponent(const std::shared_ptr<BaseComponent> & component);
		void removeComponent(const std::shared_ptr<BaseComponent> & component);
		std::vector<std::shared_ptr<BaseComponent>> & getComponents(BaseComponent::ComponentType);

	private:
		UniqueID nextComponent;
		std::map<BaseComponent::ComponentType, std::vector<std::shared_ptr<BaseComponent>>> components;
		std::map<World::Entity, std::vector<BaseComponent::ComponentType>> entityBodies;
	};
}

#include "ECS\ComponentTank.inl"

#endif // COMPONENTTANK_HPP
