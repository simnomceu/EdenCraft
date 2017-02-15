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
		if (!this->isInitialized()) {
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
			this->initialized = true;
			this->modeInitialized = mode;
			LogServiceLocator::getService().logInfo("Log service started.");
		}
	}

	void LogService::setMode(Mode mode)
	{
	}
}
