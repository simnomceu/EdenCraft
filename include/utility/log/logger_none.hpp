#ifndef LOGGER_NONE_HPP
#define LOGGER_NONE_HPP

#include "utility/log/base_logger.hpp"

namespace ece
{
	class LoggerNone: public BaseLogger
	{
	public:
		inline virtual void logError(const std::string & data) override;
		inline virtual void logWarning(const std::string & data) override;
		inline virtual void logInfo(const std::string & data) override;
	};
}

#include "utility/log/logger_none.inl"

#endif // LOGGER_NONE_HPP
