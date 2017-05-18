#include "ECS\BaseSystem.hpp"

#include "ECS\World.hpp"

namespace ece
{
	BaseSystem::BaseSystem(): world()
	{
	}

	void BaseSystem::initialize()
	{
	}

	void BaseSystem::update()
	{
	}

	void BaseSystem::terminate()
	{
	}

	void BaseSystem::attachWorld(const std::weak_ptr<World>& world)
	{
		this->world = world;
	}
}
