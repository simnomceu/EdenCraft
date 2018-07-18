#ifndef BASESYSTEM_HPP
#define BASESYSTEM_HPP

#include "Service\ServiceFactory.hpp"

#include <iostream>

namespace ece
{
	class World;
	
	class BaseSystem
	{
	public:
		BaseSystem();
		inline virtual ~BaseSystem() = 0;

		void initialize();
		void update();
		void terminate();

		void attachWorld(const std::weak_ptr<World> & world);

	protected:
		std::weak_ptr<World> world;
	};

	typedef ServiceFactory<BaseSystem> SystemFactory;
}

#include "ECS\BaseSystem.inl"

#endif // BASESYSTEM
