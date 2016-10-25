#ifndef EVENTMANAGERLOCATOR_HPP
#define EVENTMANAGERLOCATOR_HPP

#include "Core\System\BaseEventManager.hpp"

namespace ece
{
	class EventManagerLocator
	{
	public:
		static void provide(BaseEventManager & service);
		static BaseEventManager & getService();
		static void stop();

	private:
		static BaseEventManager & service;
	};
}

#endif // EVENTMANAGERLOCATOR_HPP
