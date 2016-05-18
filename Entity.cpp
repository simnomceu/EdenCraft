#include "pch.h"
#include "Entity.hpp"

ECS::Entity::Entity(std::weak_ptr<World> world, const EntityUUID uuid): 
	_uuid(uuid), _components(), _listedComponents(), _listedSystems(), _world(world), _alive(false), _dirty(false)
{
}

ECS::Entity::~Entity()
{
}
