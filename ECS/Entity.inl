#pragma once

#include "Entity.hpp"

#include <iostream>

template<typename ComponentType>
ComponentType & ECS::Entity::addComponent()
{
	auto useWorld = _world.lock();
	auto index = useWorld->getComponentIndex();
	auto componentPtr = std::make_unique<ComponentType>(index);

	auto id = componentPtr.get()->getID();
	_listedComponents[id] = 1;
	if (id >= _components.size()) {
		_components.resize(id + 1);
	}
	_components[id] = std::move(componentPtr);
	_dirty = true;

	auto component = static_cast<ComponentType*>(_components[id].get());
	return *component;
}

template<typename ComponentType>
void ECS::Entity::removeComponent()
{
	auto useWorld = _world.lock();
	auto index = useWorld->getComponentIndex();
	auto id = index->getIndex<ComponentType>();
	_listedComponents[id] = 0;
	_components.erase(_components.begin() + id);
}

template<typename ComponentType>
ComponentType & ECS::Entity::getComponent() const
{
	auto useWorld = _world.lock();
	auto index = useWorld->getComponentIndex();
	auto id = index->getIndex<ComponentType>();
	auto component = _components[id];

	return *component;
}
