#include "Core\Window\Event\EventHandler.hpp"

#include "Core\Window\Window\BaseWindow.hpp"
#include "Core\Window\WindowService.hpp"

#include <iostream>

namespace ece
{
	EventHandler::EventHandler(BaseWindow & window): Emitter(), windowAttached(window)
	{
		WindowServiceLocator::getService().registerEventHandler(this);
	}

	EventHandler::~EventHandler()
	{
	}

	const WindowID EventHandler::getWindowAttached() const
	{
		return WindowID();
	}

	void EventHandler::produceEvent(const int key, const int scancode, const int action, const int mods)
	{
		std::cerr << "key: " << key << std::endl;
	}
}