#ifndef SERVICELOGGER_HPP
#define SERVICELOGGER_HPP

#include "Util\Module\ServiceFactory.hpp"
#include "Util\Module\ServiceLocator.hpp"
#include "Util\Log\LoggerNone.hpp"

namespace ece
{
	typedef ServiceFactory<BaseLogger> ServiceLoggerFactory;
	typedef ServiceLocator<BaseLogger, LoggerNone> ServiceLoggerLocator;
}

#endif