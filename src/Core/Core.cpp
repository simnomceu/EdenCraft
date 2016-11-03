#include "Core\Core.hpp"

#include <iostream>

#include "Core\System\EventManagerLocator.hpp"
#include "Core\System\EventManagerBuilder.hpp"
#include "Core\System\EventManager.hpp"
#include "Core\System\EventManagerNone.hpp"

#include "Core\Window\WindowServiceLocator.hpp"
#include "Core\Window\WindowManagerBuilder.hpp"
#include "Core\Window\WindowManagerGLFW.hpp"
#include "Core\Window\WindowManagerNone.hpp"

#include "Core\Util\Log.hpp"
#include "Core\Util\LoggerBuilder.hpp"
#include "Core\Util\Logger.hpp"
#include "Core\Util\LoggerNone.hpp"

namespace ece
{
	bool Core::systemInit = false;
	bool Core::windowInit = false;
	bool Core::graphicInit = false;
	bool Core::ecsInit = false;

	void Core::init(const ece::Module & modules)
	{
		Core::initLog();

		if ((modules & SYSTEM) == SYSTEM) {
			Core::dispenser(SYSTEM);
		}
		if ((modules & WINDOW) == WINDOW) {
			Core::dispenser(SYSTEM);
			Core::dispenser(WINDOW);
		}
	}

	void Core::setModuleMode(const ece::Module & module, const ece::Mode & mode)
	{
		Core::dispenser(module, mode);
	}

	void Core::dispenser(const ece::Module & module, const ece::Mode & mode)
	{
		switch (module)
		{
		case SYSTEM:
			if (!Core::systemInit || mode != DEFAULT) {
				Core::initEventManager();

				Core::systemInit = true;
			}
			break;
		case WINDOW:
			if (!Core::windowInit || mode != DEFAULT) {
				Core::initWindowManager();

				Core::windowInit = true;
			}
		default:
			break;
		}
	}

	void Core::initEventManager(const ece::Mode & mode)
	{
		try {
			if (mode == DEFAULT) {
				EventManagerLocator::provide(EventManagerBuilder::makeEventManager<EventManager>());
			}
			else if (mode == OFF) {
				EventManagerLocator::provide(EventManagerBuilder::makeEventManager<EventManagerNone>());
			}
			Log::getService().logInfo("Events management service started ...");
		}
		catch (std::exception & e) {
			std::cerr << e.what() << std::endl;
		}
	}

	void Core::initWindowManager(const ece::Mode & mode)
	{
		try {
			if (mode == DEFAULT) {
				WindowServiceLocator::provide(WindowManagerBuilder::makeWindowManager<WindowManagerGLFW>());
			}
			else if (mode == OFF) {
				WindowServiceLocator::provide(WindowManagerBuilder::makeWindowManager<WindowManagerNone>());
			}
			Log::getService().logInfo("Window management service started ...");
		}
		catch (std::exception & e) {
			std::cerr << e.what() << std::endl;
		}
	}

	void Core::initLog(const ece::Mode & mode)
	{
		try {
			if (mode == DEFAULT) {
				Log::provide(LoggerBuilder::makeLogger<Logger>());
			}
			else if (mode == OFF) {
				Log::provide(LoggerBuilder::makeLogger<LoggerNone>());
			}
			Log::getService().logInfo("Logger service started ...");
		}
		catch (std::exception & e) {
			std::cerr << e.what() << std::endl;
		}
	}
}
