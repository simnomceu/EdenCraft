/*

	oooooooooooo       .o8                          .oooooo.                       .o88o.     .
	`888'     `8      "888                         d8P'  `Y8b                      888 `"   .o8
	 888          .oooo888   .ooooo.  ooo. .oo.   888          oooo d8b  .oooo.   o888oo  .o888oo
	 888oooo8    d88' `888  d88' `88b `888P"Y88b  888          `888""8P `P  )88b   888      888
	 888    "    888   888  888ooo888  888   888  888           888      .oP"888   888      888
	 888       o 888   888  888    .o  888   888  `88b    ooo   888     d8(  888   888      888 .
	o888ooooood8 `Y8bod88P" `Y8bod8P' o888o o888o  `Y8bood8P'  d888b    `Y888""8o o888o     "888"

															oooooooooo.               .o8        .o8       oooo            oooooo     oooo           oooo  oooo
															`888'   `Y8b             "888       "888       `888             `888.     .8'            `888  `888
															 888     888 oooo  oooo   888oooo.   888oooo.   888   .ooooo.    `888.   .8'    .ooooo.   888   888   .ooooo.  oooo    ooo
															 888oooo888' `888  `888   d88' `88b  d88' `88b  888  d88' `88b    `888. .8'    d88' `88b  888   888  d88' `88b  `88.  .8'
															 888    `88b  888   888   888   888  888   888  888  888ooo888     `888.8'     888   888  888   888  888ooo888   `88..8'
															 888    .88P  888   888   888   888  888   888  888  888    .o      `888'      888   888  888   888  888    .o    `888'
															o888bood8P'   `V88V"V8P'  `Y8bod8P'  `Y8bod8P' o888o `Y8bod8P'       `8'       `Y8bod8P' o888o o888o `Y8bod8P'     .8'
																																										   .o..P'
																																										   `Y8P'



				This file is part of EdenCraft Engine - MoreCube sample.
				Copyright(C) 2018 Pierre Casati (@IsilinBN)

				This program is free software : you can redistribute it and/or modify
				it under the terms of the GNU General Public License as published by
				the Free Software Foundation, either version 3 of the License, or
				(at your option) any later version.

				This program is distributed in the hope that it will be useful,
				but WITHOUT ANY WARRANTY; without even the implied warranty of
				MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.See the
				GNU General Public License for more details.

				You should have received a copy of the GNU General Public License
				along with this program.If not, see <http://www.gnu.org/licenses/>.

*/

#include <iostream>

#include "window/common.hpp"
#include "renderer/rendering.hpp"
#include "utility/log.hpp"
#include "assets.hpp"
#include "game.hpp"

int main()
{
	try {
		ece::WindowedApplication app;
		auto window = app.addWindow<ece::RenderWindow>();
		auto & contextSettings = window.lock()->getContextSettings();
		contextSettings.maxVersion = { 4, 6 };

		std::shared_ptr<Game> game;

		window.lock()->onWindowClosed.connect([&app]() {
			app.stop();
		});
		window.lock()->onWindowOpened.connect([&window, &game]() {
			window.lock()->setTitle("Bubble Volley");
			window.lock()->maximize();

			ece::Viewport viewport;
			viewport.resetViewport(ece::Rectangle<float>(0.0f, 0.0f, 1920.0f, 1080.0f));
			viewport.setViewportRatio(ece::Rectangle<float>(0.0f, 0.0f, 1.0f, 1.0f));
			window.lock()->setViewport(viewport);

			Assets::loadAssets();

			game = std::make_shared<Game>();
		});

		auto & eventHandler = window.lock()->getEventHandler();
		eventHandler.onKeyPressed.connect([](const ece::InputEvent & event, ece::Window & window) {
			if (event._key == ece::Keyboard::Key::ESCAPE) {
				window.close();
			}
		});

		app.onPostUpdate.connect([&window]() {
			window.lock()->clear(ece::BLACK);
		});
		app.onPostRender.connect([&window, &game]() {
			game->draw();
			window.lock()->display();
		});

		app.run();
	}
	catch (std::runtime_error & e) {
		ece::ServiceLoggerLocator::getService().logError(e.what());
	}
	catch (std::exception & e) {
		ece::ServiceLoggerLocator::getService().logError(e.what());
	}

	return EXIT_SUCCESS;
}