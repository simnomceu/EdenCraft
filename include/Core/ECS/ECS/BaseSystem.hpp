#ifndef BASESYSTEM_HPP
#define BASESYSTEM_HPP

#include "Core\Util\Module\ServiceFactory.hpp"

namespace ece
{
	typedef ServiceFactory<BaseSystem> SystemFactory;

	class BaseSystem
	{
	public:
		inline virtual ~BaseSystem() = 0;
	};
}

#include "ECS\BaseSystem.inl"

#endif // BASESYSTEM