#include "Core\Util\Log.hpp"

#include "Core\Util\LoggerNone.hpp"

namespace ece
{
	std::shared_ptr<BaseLogger> Log::service(new LoggerNone());
	
	void Log::provide(BaseLogger * service)
	{
		Log::service = std::shared_ptr<BaseLogger>(service);
	}

	BaseLogger & Log::getService()
	{
		return *Log::service;
	}

	void Log::stopService()
	{
		Log::service = std::shared_ptr<BaseLogger>(new LoggerNone());
	}
}
