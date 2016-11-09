#include "Core\Core.hpp"

#include "Core\Util\LogService.hpp"
#include "Core\System\SystemModule.hpp"
#include "Core\Window\WindowModule.hpp"

namespace ece
{
	void Core::init(const ServiceID services, const ModuleID modules)
	{
		LogService logService;
		if ((services & LOG) == LOG) {
			logService.init(Mode::CONSOLE);
		}
		else {
			logService.init(Mode::NOT_INIT);
		}

		SystemModule systemModule;
		if ((modules & SYSTEM) == SYSTEM) {
			systemModule.init(Mode::DEFAULT);
		}
		else {
			systemModule.init(Mode::NOT_INIT);
		}

		WindowModule windowModule;
		if ((modules & WINDOW) == WINDOW) {
			windowModule.init(Mode::DEFAULT);
		}
		else {
			windowModule.init(Mode::NOT_INIT);
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
