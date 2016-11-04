#include "Core\Core.hpp"

#include "Core\Util\LogService.hpp"
#include "Core\System\SystemModule.hpp"
#include "Core\Window\WindowModule.hpp"

namespace ece
{
	void Core::init(const ServiceID services, const ModuleID modules)
	{
		if ((services & LOG) == LOG) {
			LogService logService;
			logService.init(Mode::CONSOLE);
		}
		else {
		}

		if ((modules & SYSTEM) == SYSTEM) {
			SystemModule systemModule;
			systemModule.init(Mode::DEFAULT);
		}
		else {
			SystemModule systemModule;
			systemModule.init(Mode::DEFAULT);
		}

		if ((modules & WINDOW) == WINDOW) {
			WindowModule windowModule;
			windowModule.init(Mode::DEFAULT);
		}
		else {
		}

		if ((modules & GRAPHIC) == GRAPHIC) {
		}
		else {
		}

		if ((modules & ECS) == ECS) {
		}
		else {
		}
	}
}
