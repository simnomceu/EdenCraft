#include "Core\ECS\World.hpp"

namespace ece
{
	World::World(): systems(), components(), entities(), entityGenerator()
	{
	}

	World::~World()
	{
	}
}
