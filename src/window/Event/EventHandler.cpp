#include "Event\EventHandler.hpp"

#include "Window\BaseWindow.hpp"
#include "Window\WindowService.hpp"

#include <iostream>

namespace ece
{
	EventHandler & EventHandler::getInstance()
	{
		static EventHandler handler;
		return handler;
	}

	void EventHandler::produceKeyEvent(const int key, const int scancode, const int action, const int mods)
	{
		std::cerr << "key: " << key << std::endl;
	}

	void EventHandler::produceMouseButtonEvent(const int button, const int action, const int mods)
	{
		std::cerr << "button: " << button << std::endl;
	}
}