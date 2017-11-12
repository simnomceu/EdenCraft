#ifndef SERVICE_LOGGER_HPP
#define SERVICE_LOGGER_HPP

#include "utility/service/service_factory.hpp"
#include "utility/service/service_locator.hpp"
#include "utility/log/logger_none.hpp"

namespace ece
{
	typedef ServiceFactory<BaseLogger> ServiceLoggerFactory;
	typedef ServiceLocator<BaseLogger, LoggerNone> ServiceLoggerLocator;
}

#endif