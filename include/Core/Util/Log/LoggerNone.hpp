#ifndef LOGGERNONE_HPP
#define LOGGERNONE_HPP

#include "Util\Log\BaseLogger.hpp"

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

#include "Util\Log\LoggerNone.inl"

#endif // LOGGERNONE_HPP
