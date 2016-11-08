#ifndef COMPONENTTANK_HPP
#define COMPONENTTANK_HPP

#include "Core\ECS\BaseComponent.hpp"
#include "Core\Util\UniqueID.hpp"

#include <memory>
#include <vector>

namespace ece
{
	class ComponentTank
	{
	public:
		ComponentTank();
		~ComponentTank();

	private:
		UniqueID nextComponent;
	};
}

#endif // COMPONENTTANK_HPP
