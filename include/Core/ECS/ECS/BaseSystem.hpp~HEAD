#ifndef BASESYSTEM_HPP
#define BASESYSTEM_HPP

#include "Core\Util\Module\ServiceFactory.hpp"

#include <iostream>

namespace ece
{
	class World;

	typedef ServiceFactory<BaseSystem> SystemFactory;

	class BaseSystem
	{
	public:
		BaseSystem();
		virtual ~BaseSystem() = 0;

		void initialize();
		void update();
		void terminate();

		void attachWorld(const std::weak_ptr<World> & world);

	protected:
		std::weak_ptr<World> world;
	};
}

#include "ECS\BaseSystem.inl"

#endif // BASESYSTEM
