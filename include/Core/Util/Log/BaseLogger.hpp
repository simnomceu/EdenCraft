#ifndef BASELOGGER_HPP
#define BASELOGGER_HPP

#include <string>
#include <iostream>

namespace ece
{
	class BaseLogger
	{
	public:
		BaseLogger(): target(std::cerr) {}
		virtual ~BaseLogger() {}
		
		virtual void logError(const std::string & data) = 0;
		virtual void logWarning(const std::string & data) = 0;
		virtual void logInfo(const std::string & data) = 0;

	protected:
		std::ostream & target;
	};
}

#endif // BASELOGGER_HPP
