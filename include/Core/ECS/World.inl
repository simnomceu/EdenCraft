#include "ECS\ComponentTank.hpp"

namespace ece
{
	inline World::World() : systems(), components(std::make_shared<ComponentTank>()), entities(), entityGenerator() {}

	inline World::~World() {}
}