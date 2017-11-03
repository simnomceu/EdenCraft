#ifndef LOGGER_HPP
#define LOGGER_HPP

#include <string>

#include "utility/log/base_logger.hpp"

namespace ece
{	
	class Logger: public BaseLogger
	{
	public:
		inline Logger();

		virtual void logError(const std::string & data) override;
		virtual void logWarning(const std::string & data) override;
		virtual void logInfo(const std::string & data) override;
	};
}

#include "utility/log/logger.inl"

#endif // LOGGER_HPP