#ifndef COMPONENT_TANK_HPP
#define COMPONENT_TANK_HPP

#include "core/ecs/base_component.hpp"
#include "utility/indexing/unique_id.hpp"

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
		UniqueID _nextComponent;
	};
}

#include "core/ecs/component_tank.inl"

#endif // COMPONENT_TANK_HPP
