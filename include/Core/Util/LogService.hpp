#ifndef LOGSERVICE_HPP
#define LOGSERVICE_HPP

#include "Core\Util\Module\ServiceFactory.hpp"
#include "Core\Util\Module\ServiceLocator.hpp"
#include "Core\Util\Module\Service.hpp"
#include "Core\Util\Log\BaseLogger.hpp"
#include "Core\Util\Log\LoggerNone.hpp"

namespace ece
{
	typedef ServiceFactory<BaseLogger> LogServiceFactory;

	typedef ServiceLocator<BaseLogger, LoggerNone> LogServiceLocator;

	class LogService : public Service
	{
	public:
		LogService();

		virtual void init(Mode mode = Mode::NONE);

		virtual void setMode(Mode mode);
	};
}

#endif // LOGSERVICE_HPP
