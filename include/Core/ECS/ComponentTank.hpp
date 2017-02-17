#ifndef COMPONENTTANK_HPP
#define COMPONENTTANK_HPP

#include "ECS\BaseComponent.hpp"
#include "Util\UniqueID.hpp"

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

#include "ECS\Component.inl"

#endif // COMPONENTTANK_HPP
