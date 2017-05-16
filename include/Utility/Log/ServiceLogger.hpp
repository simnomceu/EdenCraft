#ifndef SERVICELOGGER_HPP
#define SERVICELOGGER_HPP

#include "Service\ServiceFactory.hpp"
#include "Service\ServiceLocator.hpp"
#include "Log\LoggerNone.hpp"

namespace ece
{
	typedef ServiceFactory<BaseLogger> ServiceLoggerFactory;
	typedef ServiceLocator<BaseLogger, LoggerNone> ServiceLoggerLocator;
}

#endif