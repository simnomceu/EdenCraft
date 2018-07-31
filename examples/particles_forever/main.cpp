#include <iostream>

#include "core/application.hpp"
#include "renderer/common.hpp"
#include "window/window_event.hpp"
#include "graphic/scene.hpp"

int main()
{
	ece::Application app;

	ece::RenderWindow window;

	window.open();

	ece::Scene scene;

	ece::InputEvent event;
	while (window.isOpened()) {
		window.clear(ece::BLACK);
		scene.draw();
		window.display();

		if (window.pollEvent(event)) {

		}
	}

	return EXIT_SUCCESS;
}