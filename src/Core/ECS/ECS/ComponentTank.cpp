#include "Core\ECS\ECS\ComponentTank.hpp"

namespace ece
{
	ComponentTank::ComponentTank(): nextComponent()
	{
	}

	ComponentTank::~ComponentTank()
	{
	}

	void ComponentTank::addComponent(const std::shared_ptr<BaseComponent>& component)
	{
	}
}
