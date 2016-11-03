#ifndef LOGGER_HPP
#define LOGGER_HPP


#include "Core\Util\BaseLogger.hpp"

namespace ece
{	
	class Logger: public BaseLogger
	{
	public:
		Logger();

		virtual void logError(const std::string & data);
		virtual void logWarning(const std::string & data) ;
		virtual void logInfo(const std::string & data);
	};
}

#endif // LOGGER_HPP