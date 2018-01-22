#include "core/application/application.hpp"
#include "window/common/window.hpp"

#include <iostream>

int main()
{
	ece::Application app;

	std::array<ece::Window, 2> windows;

	ece::WindowSetting settings;
	settings._position = ece::IntVector2u{ 200, 200 };
	int count = 0;
	for (auto & window : windows) {
		settings._title = "WFL window testing" + std::to_string(count);
		settings._position += ece::IntVector2u{ 10, 10 };
		++count;
		window.open();
		window.setSettings(settings);
		window.limitUPS(100);
//		window.enableKeyRepeat(false);
	}

	ece::InputEvent event;
	while (1) {
		for (auto & window : windows) {
			while (window.pollEvent(event)) {
				if (event._doubleTap != ece::InputEvent::ECE_TAP_NONE) {
					std::cout << "double click !";
				}
				if (event._type == ece::InputEvent::ECE_KEY_PRESSED && event._key >= ece::Keyboard::A && event._key <= ece::Keyboard::Z) {
					std::cout << char(event._key + 34);
				}
				if (event._type == ece::InputEvent::ECE_MOUSE_MOVED) {
					std::cout << event._mousePosition[0] << "|" << event._mousePosition[1] << "  ";
					std::cout << ece::Mouse::getPosition()[0] << "|" << ece::Mouse::getPosition()[1] << std::endl;
				}
			}
		}
	}
//	app.run();

	return 0;
}