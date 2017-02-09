#ifndef LOGGERNONE_HPP
#define LOGGERNONE_HPP

#include "Core\Util\Log\BaseLogger.hpp"

namespace ece
{
	class LoggerNone: public BaseLogger
	{
	public:
		virtual void logError(const std::string & data) ;
		virtual void logWarning(const std::string & data);
		virtual void logInfo(const std::string & data);
	};
}

#endif // LOGGERNONE_HPP
