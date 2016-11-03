#ifndef LOGGERBUILDER_HPP
#define LOGGERBUILDR_HPP

#include "Core\Util\BaseLogger.hpp"

namespace ece
{
	class LoggerBuilder
	{
	public:
		template<class T>
		static BaseLogger *  makeLogger();
	};

	template<class T>
	BaseLogger * LoggerBuilder::makeLogger()
	{
		if(!std::is_base_of<BaseLogger, T>()) {
			throw std::exception("This class cannot be instantiate as a BaseLogger service. Check again.");
		}
		return new T();
	}
}

#endif // LOGGERBUILDER_HPP
