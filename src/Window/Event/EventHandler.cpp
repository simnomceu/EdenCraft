#include "Event\EventHandler.hpp"

#include "Window\BaseWindow.hpp"
#include "Window\WindowService.hpp"

#include <iostream>

#include "GLFW\glfw3.h"

namespace ece
{
	EventHandler & EventHandler::getInstance()
	{
		static EventHandler handler;
		return handler;
	}

<<<<<<< develop:src/Window/Event/EventHandler.cpp
=======
	EventHandler::EventHandler()
	{
		this->addSignal(KEY_PRESSED);
		this->addSignal(KEY_RELEASED);
		this->addSignal(MOUSE_BUTTON_PRESSED);
		this->addSignal(MOUSE_BUTTON_RELEASED);
		this->addSignal(MOUSE_WHEEL_SCROLLED);
	}

	EventHandler::~EventHandler()
	{
	}

>>>>>>> Add some improvements for windows.:src/Core/Window/Event/EventHandler.cpp
	void EventHandler::produceKeyEvent(const int key, const int scancode, const int action, const int mods)
	{
		std::cerr << "key: " << key << std::endl;
		switch (action) {
		case GLFW_PRESS:
			this->emit(KEY_PRESSED);
			break;
		case GLFW_RELEASE:
			this->emit(KEY_RELEASED);
			break;
		default:
			break;
		}
	}

	void EventHandler::produceMouseButtonEvent(const int button, const int action, const int mods)
	{
		std::cerr << "button: " << button << std::endl;
	}
}