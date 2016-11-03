#ifndef LOG_HPP
#define LOG_HPP

#include "Core\Util\Baselogger.hpp"

#include <memory>

namespace ece
{
	class Log
	{
	public:
		static void provide(BaseLogger * service);

		static BaseLogger & getService();

		static void stopService();

	private:
		static std::shared_ptr<BaseLogger> service;
	};
}

#endif // LOG_HPP
