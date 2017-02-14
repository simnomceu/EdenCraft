#include "Core\Graphic\RenderingService.hpp"

namespace ece
{
	RenderingService::RenderingService(): Service()
	{
	}

	void RenderingService::init(Mode mode)
	{
		switch (mode)
		{
		case Mode::NOT_INIT:
			RenderingServiceLocator::provide(RenderingServiceFactory::build<RenderFactoryGL>());
			break;
		case Mode::NONE:
			RenderingServiceLocator::provide(RenderingServiceFactory::build<RenderFactoryGL>());
			break;
		case Mode::DEFAULT:
			RenderingServiceLocator::provide(RenderingServiceFactory::build<RenderFactoryGL>());
			break;
		case Mode::CONSOLE:
			break;
		default:
			break;
		}
	}

	void RenderingService::setMode(Mode mode)
	{
	}
}