#include "BaseComponent.hpp"

ECS::BaseComponent::~BaseComponent()
{
}

void ECS::BaseComponent::setOwner(ECS::EntityUUID ownerID)
{
	_ownerID = ownerID;
}

void ECS::BaseComponent::SetRelativeID(ECS::ComponentID relativeID)
{
	_relativeID = relativeID;
}

const ECS::EntityUUID ECS::BaseComponent::getOwner()
{
	return _ownerID;
}

const ECS::ComponentID ECS::BaseComponent::getRelativeID()
{
	return _relativeID;
}

void ECS::BaseComponent::onLinked()
{
}

void ECS::BaseComponent::onUnlinked()
{
}

void ECS::BaseComponent::onUpdate()
{
}
