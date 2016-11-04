#include "Core\System\SystemModule.hpp"

#include "Core\System\Event\EventService.hpp"

namespace ece
{
	SystemModule::SystemModule(): Module()
	{
		this->services.push_back(new EventService());
	}
}
