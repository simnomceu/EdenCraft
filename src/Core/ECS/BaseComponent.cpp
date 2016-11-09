#include "Core\ECS\BaseComponent.hpp"

namespace ece
{
	BaseComponent::BaseComponent(const ComponentID id)
	{
	}

	BaseComponent::~BaseComponent()
	{
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