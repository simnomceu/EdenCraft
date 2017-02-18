#ifndef BASESYSTEM_HPP
#define BASESYSTEM_HPP

namespace ece
{
	class BaseSystem
	{
	public:
		inline virtual ~BaseSystem() = 0;
	};
}

#include "ECS\BaseSystem.inl"

#endif // BASESYSTEM
