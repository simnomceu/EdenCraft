#ifndef EVENTSERVICE_HPP
#define EVENTSERVICE_HPP

#include "Service\ServiceFactory.hpp"
#include "Service\ServiceLocator.hpp"
#include "System\Event\EventManagerNone.hpp"


namespace ece
{
	class EventManagerConsumer;

	typedef ServiceFactory<BaseEventManager> EventServiceFactory;

	class EventServiceLocator : public ServiceLocator<BaseEventManager, EventManagerNone>
	{
	public:
//		using ServiceLocator<BaseEventManager, EventManagerNone>::provide;
//		using ServiceLocator<BaseEventManager, EventManagerNone>::stop;
//		using ServiceLocator<BaseEventManager, EventManagerNone>::getService;
//		using ServiceLocator<BaseEventManager, EventManagerNone>::getServicePtr;

		static std::weak_ptr<BaseEventManager> getServicePtr(EventManagerConsumer & consumer);
	};
}

#endif // EVENTSERVICE_HPP