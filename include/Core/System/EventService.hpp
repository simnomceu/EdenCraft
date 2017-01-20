#ifndef EVENTSERVICE_HPP
#define EVENTSERVICE_HPP

#include "Core\Util\Module\ServiceFactory.hpp"
#include "Core\Util\Module\ServiceLocator.hpp"
#include "Core\Util\Module\Service.hpp"
#include "Core\System\Event\BaseEventManager.hpp"
#include "Core\System\Event\EventManagerNone.hpp"

namespace ece
{	
	typedef ServiceFactory<BaseEventManager> EventServiceFactory;

	class EventServiceLocator : private ServiceLocator<BaseEventManager, EventManagerNone>
	{
	public:
		using ServiceLocator<BaseEventManager, EventManagerNone>::provide;
		using ServiceLocator<BaseEventManager, EventManagerNone>::stop;

		static std::weak_ptr<BaseEventManager> getServicePtr(EventManagerConsumer & consumer);
	};

	class EventService: public Service
	{
	public:
		EventService();

		virtual void init(Mode mode = Mode::NONE);

		virtual void setMode(Mode mode);
	};
}

#endif // EVENTSERVICE_HPP
