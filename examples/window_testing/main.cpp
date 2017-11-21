#include "core/application/application.hpp"
#include "window/common/window.hpp"

#include <iostream>

int main()
{
	ece::Application app;

	std::array<ece::Window, 2> windows;

	ece::WindowSetting settings;
	settings.position = ece::IntVertex2u(200, 200);
	int count = 0;
	for (auto & window : windows) {
		settings.title = "WFL window testing" + std::to_string(count);
		settings.position += ece::IntVertex2u(10, 10);
		++count;
		window.open();
		window.setSettings(settings);
		window.limitUPS(100);
		window.enableKeyRepeat(true);
	}

	ece::InputEvent event;
	while (1) {
		for (auto & window : windows) {
			while (window.pollEvent(event)) {
				if (event.doubleTap != ece::InputEvent::ECE_TAP_NONE) {
					std::cout << "double click !";
				}
				if (event.type == ece::InputEvent::ECE_KEY_PRESSED && event.key >= ece::Keyboard::A && event.key <= ece::Keyboard::Z) {
					std::cout << char(event.key + 34);
				}
			}
		}
	}
//	app.run();

	return 0;
}