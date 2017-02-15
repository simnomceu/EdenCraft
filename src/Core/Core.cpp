#include "Core\Core.hpp"

#include "Core\Util\LogService.hpp"
#include "Core\System\SystemModule.hpp"
#include "Core\Window\WindowModule.hpp"
#include "Core\Graphic\GraphicModule.hpp"

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

		std::cout << "core init" << std::endl;
		GraphicModule graphicModule;
		if ((modules & GRAPHIC) == GRAPHIC) {
			graphicModule.init(Mode::DEFAULT);
			std::cout << "core init end" << std::endl;
		}
		else {
			graphicModule.init(Mode::NOT_INIT);
		}

		if ((modules & ECS) == ECS) {
		}
		else {
		}
	}
}
