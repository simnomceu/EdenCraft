#include "Entity.hpp"

#include <iostream>

ECS::Entity::Entity(std::weak_ptr<World> world, const EntityUUID uuid): 
	_uuid(uuid), _components(), _listedComponents(), _listedSystems(), _world(world), _alive(false), _dirty(false)
{
}

ECS::Entity::~Entity()
{
}

void ECS::Entity::removeComponent(const ComponentID id)
{
	_components.erase(_components.begin() + id);
}

void ECS::Entity::removeAllComponents()
{
	_components.clear();
	_listedComponents.reset();
}

const ECS::EntityUUID ECS::Entity::getUUID() const
{
	return _uuid;
}

ECS::BaseComponent & ECS::Entity::getComponent(const ComponentID index) const
{
	auto component = _components[index].get();
	return *component;
}

const ECS::ListComponents& ECS::Entity::getAllComponents() const
{
	return _components;
}

const ECS::Bitset& ECS::Entity::getListedComponents() const
{
	return _listedComponents;
}

const ECS::Bitset & ECS::Entity::getListedSystems() const
{
	return _listedSystems;
}

std::weak_ptr<ECS::World> ECS::Entity::getWorld() const
{
	return _world;
}

const bool ECS::Entity::isAlive() const
{
	return _alive;
}

const bool ECS::Entity::isDirty() const
{
	return _dirty;
}

void ECS::Entity::kill()
{
	_alive = false;
}

const std::string ECS::Entity::toString() const
{
	std::string stringID = "Entity " + std::to_string(_uuid) + " with " + std::to_string(_listedComponents.count()) + " components.";
	return stringID;
}
