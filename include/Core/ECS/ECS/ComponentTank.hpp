#ifndef COMPONENTTANK_HPP
#define COMPONENTTANK_HPP

#include "Core\ECS\ECS\BaseComponent.hpp"
#include "Core\ECS\ECS\World.hpp"
#include "Core\Util\UniqueID.hpp"

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

	private:
		UniqueID nextComponent;
		std::map<BaseComponent::ComponentType, std::vector<std::shared_ptr<BaseComponent>>> components;
		std::map <World::Entity, std::vector<unsigned int>> entityBodies;
	};
}

#endif // COMPONENTTANK_HPP
