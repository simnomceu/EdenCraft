#include "Core\ECS\ECS\BaseComponent.hpp"

namespace ece
{
	BaseComponent::BaseComponent(const ComponentID id): type(), id(id), owner()
	{
	}

	BaseComponent::~BaseComponent()
	{
	}

	const BaseComponent::ComponentType BaseComponent::getType() const
	{
		return this->type;
	}

	const BaseComponent::ComponentID BaseComponent::getID() const
	{
		return this->id;
	}
	const unsigned int BaseComponent::getOwner() const
	{
		return this->owner;
	}
}