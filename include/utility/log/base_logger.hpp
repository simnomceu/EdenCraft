#ifndef BASE_LOGGER_HPP
#define BASE_LOGGER_HPP

#include <string>
#include <iostream>

namespace ece
{
	class BaseLogger
	{
	public:
		inline BaseLogger();
		inline virtual ~BaseLogger() = 0;
		
		virtual void logError(const std::string & data) = 0;
		virtual void logWarning(const std::string & data) = 0;
		virtual void logInfo(const std::string & data) = 0;

	protected:
		std::ostream & target;
	};
}

#include "log/base_logger.inl"

#endif // BASE_LOGGER_HPP
