#include "application/application.hpp"
#include "window_refactor/window.hpp"

#include <iostream>

int main()
{
	ece::Application app;

	std::array<ece::Window, 50> windows;

	ece::WindowSetting settings;
	settings.position = ece::IntVertex2u(200, 200);
	int count = 0;
	for (auto window : windows) {
		settings.title = "WFL window testing" + std::to_string(count);
		settings.position += ece::IntVertex2u(10, 10);
		++count;
		window.open();
		window.setSettings(settings);
	}

	ece::InputEvent event;
	while (1) {
		for (auto window : windows) {
			while (window.waitEvent(event)) {
				if (event.doubleTap != ece::InputEvent::ECE_TAP_NONE) {
					std::cout << "double click !";
				}
			}
		}
	}
//	app.run();

	return 0;
}