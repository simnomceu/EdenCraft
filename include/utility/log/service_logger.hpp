#ifndef SERVICE_LOGGER_HPP
#define SERVICE_LOGGER_HPP

#include "service/service_factory.hpp"
#include "service/service_locator.hpp"
#include "log/logger_none.hpp"

namespace ece
{
	typedef ServiceFactory<BaseLogger> ServiceLoggerFactory;
	typedef ServiceLocator<BaseLogger, LoggerNone> ServiceLoggerLocator;
}

#endif