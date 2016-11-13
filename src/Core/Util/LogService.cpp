#include "Core\Util\LogService.hpp"

#include "Core\Util\Log\Logger.hpp"
#include "Core\Core.hpp"

namespace ece
{
	LogService::LogService() : Service()
	{
	}

	void LogService::init(Mode mode)
	{
		if (!ece::Core::isServiceInit(ece::LOG)) {
			switch (mode)
			{
			case ece::Mode::NOT_INIT:
				break;
			case ece::Mode::NONE:
				LogServiceLocator::provide(LogServiceFactory::build<LoggerNone>());
				break;
			case ece::Mode::DEFAULT:
				break;
			case ece::Mode::CONSOLE:
				LogServiceLocator::provide(LogServiceFactory::build<Logger>());
				break;
			default:
				break;
			}
			LogServiceLocator::getService().logInfo("Log service started.");
			ece::Core::initService(ece::LOG);
		}
	}

	void LogService::setMode(Mode mode)
	{
	}
}
