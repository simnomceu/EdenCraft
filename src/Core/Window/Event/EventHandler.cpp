#include "Core\Window\Event\EventHandler.hpp"

#include "Core\Window\Window\BaseWindow.hpp"
#include "Core\Window\WindowService.hpp"

#include <iostream>

namespace ece
{
	EventHandler & EventHandler::getInstance()
	{
		static EventHandler handler;
		return handler;
	}

	EventHandler::~EventHandler()
	{
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