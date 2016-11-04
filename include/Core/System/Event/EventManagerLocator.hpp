#ifndef EVENTMANAGERLOCATOR_HPP
#define EVENTMANAGERLOCATOR_HPP

#include "Core\System\Event\BaseEventManager.hpp"

#include <memory>

namespace ece
{
	class EventManagerLocator
	{
	public:
		static void provide(const std::shared_ptr<BaseEventManager> & service);
		static BaseEventManager & getService();
		static void stop();

	private:
		static std::shared_ptr<BaseEventManager> service;
	};
}

#endif // EVENTMANAGERLOCATOR_HPP
