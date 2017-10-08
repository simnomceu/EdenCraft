#ifndef EVENT_SERVICE_HPP
#define EVENT_SERVICE_HPP

#include "service/service_factory.hpp"
#include "service/service_locator.hpp"
#include "event/event_manager_none.hpp"


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

#endif // EVENT_SERVICE_HPP