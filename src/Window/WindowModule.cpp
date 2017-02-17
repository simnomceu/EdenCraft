#include "Core\Window\WindowModule.hpp"

#include "Core\System\SystemModule.hpp"
#include "Core\Window\WindowService.hpp"

namespace ece
{
	WindowModule::WindowModule() : Module(WINDOW)
	{
		this->dependencies.push_back(new SystemModule());

		this->services.push_back(new WindowService());
	}
}
