#ifndef BASE_SYSTEM_HPP
#define BASE_SYSTEM_HPP

namespace ece
{
	class BaseSystem
	{
	public:
		inline virtual ~BaseSystem() = 0;
	};
}

#include "core/ecs/base_system.inl"

#endif // BASE_SYSTEM
