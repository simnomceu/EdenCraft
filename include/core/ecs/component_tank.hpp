#ifndef COMPONENT_TANK_HPP
#define COMPONENT_TANK_HPP

#include "ecs/base_component.hpp"
#include "indexing/unique_id.hpp"

#include <memory>
#include <vector>

namespace ece
{
	class ComponentTank
	{
	public:
		inline ComponentTank();
		inline ~ComponentTank();

	private:
		UniqueID nextComponent;
	};
}

#include "ecs/component_tank.inl"

#endif // COMPONENT_TANK_HPP
