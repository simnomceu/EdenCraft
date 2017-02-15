#include "Core\Window\WindowService.hpp"

#include "Core\Window\Window\WindowManagerGLFW.hpp"
#include "Core\Util\LogService.hpp"

namespace ece
{
	WindowService::WindowService() : Service()
	{
	}

	void WindowService::init(Mode mode)
	{
		if (!this->isInitialized()) {
			switch (mode)
			{
			case ece::Mode::NOT_INIT:
				break;
			case ece::Mode::NONE:
				WindowServiceLocator::provide(WindowServiceFactory::build<WindowManagerNone>());
				break;
			case ece::Mode::DEFAULT:
				WindowServiceLocator::provide(WindowServiceFactory::build<WindowManagerGLFW>());
				break;
			case ece::Mode::CONSOLE:
				break;
			default:
				break;
			}
			this->initialized = true;
			this->modeInitialized = mode;
			LogServiceLocator::getService().logInfo("Window service started.");
		}
	}

	void WindowService::setMode(Mode mode)
	{
	}
}
