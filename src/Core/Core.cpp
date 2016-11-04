#include "Core\Core.hpp"

#include "Core\System\SystemModule.hpp"

namespace ece
{
	void Core::init(const ServiceID services, const ModuleID modules)
	{
		if ((services & LOG) == LOG) {
		}
		else {
		}

		if ((modules & SYSTEM) == SYSTEM) {
			SystemModule systemModule;
			//systemModule.init(Mode::DEFAULT);
		}
		else {
		}

		if ((modules & WINDOW) == WINDOW) {
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
