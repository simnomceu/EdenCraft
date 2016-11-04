#include "Core\Util\Module\Service.hpp"

namespace ece
{
	Service::Service(): initialized(false), modeInitialized(Mode::NOT_INIT)
	{
	}

	bool Service::isInitialized() const
	{
		return this->initialized;
	}
}
