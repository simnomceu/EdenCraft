#include "Core\Graphic\RenderingService.hpp"

#include "Core\Util\LogService.hpp"
#include "Core\Graphic\Rendering\RenderFactoryGL.hpp"

namespace ece
{
	RenderingService::RenderingService(): Service()
	{
		std::cout << "rendering service constructor" << std::endl;
	}

	void RenderingService::init(Mode mode)
	{
		if (!this->isInitialized()) {
			switch (mode)
			{
			case Mode::NOT_INIT:
				break;
			case Mode::NONE:
				RenderingServiceLocator::provide(RenderingServiceFactory::build<RenderFactoryNull>());
				break;
			case Mode::DEFAULT:
				RenderingServiceLocator::provide(RenderingServiceFactory::build<RenderFactoryGL>());
				break;
			case Mode::CONSOLE:
				break;
			default:
				break;
			}
			this->initialized = true;
			this->modeInitialized = mode;

			LogServiceLocator::getService().logInfo("Rendering service started.");
		}
	}

	void RenderingService::setMode(Mode mode)
	{
	}
}