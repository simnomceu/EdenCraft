#include "World.hpp"

#include <memory>

ECS::World::World(): _entities(), _freeEntityID(), _componentIndex()
{
	_componentIndex = ECS::Index<BaseComponent>::getInstance();
	_freeEntityID.push(0);
}

ECS::Entity & ECS::World::createEntity()
{
	auto worldPtr = std::make_shared<ECS::World>(*this);

	int id = _freeEntityID.front();
	_freeEntityID.pop();
	if (_freeEntityID.empty()) {
		_freeEntityID.push(id + 1);
	}

	Entity entity(worldPtr, id);

	if (id >= _entities.size()) {
		_entities.resize(id + 1);
	}

	_entities[id] = std::move(entity);
	return _entities[id];
}

std::shared_ptr<ECS::Index<ECS::BaseComponent>> ECS::World::getComponentIndex()
{
	return _componentIndex;
}

