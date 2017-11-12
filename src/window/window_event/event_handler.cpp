#include "window/window_event/event_handler.hpp"

#include "window/window/base_window.hpp"
//#include "window/window_service.hpp"

#include <iostream>

//#include "GLFW\glfw3.h"

namespace ece
{
	EventHandler & EventHandler::getInstance()
	{
		static EventHandler handler;
		return handler;
	}

	EventHandler::EventHandler()
	{
		this->addSignal(KEY_PRESSED);
		this->addSignal(KEY_RELEASED);
		this->addSignal(MOUSE_BUTTON_PRESSED);
		this->addSignal(MOUSE_BUTTON_RELEASED);
		this->addSignal(MOUSE_WHEEL_SCROLLED);
	}

	void EventHandler::produceKeyEvent(const int key, const int scancode, const int action, const int mods)
	{
		std::cerr << "key: " << key << std::endl;
/*		switch (action) {
		case GLFW_PRESS:
			this->emit(KEY_PRESSED);
			break;
		case GLFW_RELEASE:
			this->emit(KEY_RELEASED);
			break;
		default:
			break;
		}*/
	}

	void EventHandler::produceMouseButtonEvent(const int button, const int action, const int mods)
	{
		std::cerr << "button: " << button << std::endl;
	}
}