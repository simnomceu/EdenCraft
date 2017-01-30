#include "Core\System\SystemModule.hpp"

#include "Core\System\EventService.hpp"

#include <iostream>

namespace ece
{
	SystemModule::SystemModule(): Module()
	{
		this->services.push_back(new EventService());
	}
}
