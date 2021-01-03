/*

	oooooooooooo       .o8                          .oooooo.                       .o88o.     .
	`888'     `8      "888                         d8P'  `Y8b                      888 `"   .o8
	 888          .oooo888   .ooooo.  ooo. .oo.   888          oooo d8b  .oooo.   o888oo  .o888oo
	 888oooo8    d88' `888  d88' `88b `888P"Y88b  888          `888""8P `P  )88b   888      888
	 888    "    888   888  888ooo888  888   888  888           888      .oP"888   888      888
	 888       o 888   888  888    .o  888   888  `88b    ooo   888     d8(  888   888      888 .
	o888ooooood8 `Y8bod88P" `Y8bod8P' o888o o888o  `Y8bood8P'  d888b    `Y888""8o o888o     "888"

							oooooo   oooooo     oooo  o8o                    .o8                             ooooooooooooo                        .    o8o
							 `888.    `888.     .8'   `"'                   "888                             8'   888   `8                      .o8    `"'
							  `888.   .8888.   .8'   oooo  ooo. .oo.    .oooo888   .ooooo.  oooo oooo    ooo      888       .ooooo.   .oooo.o .o888oo oooo  ooo. .oo.    .oooooooo
							   `888  .8'`888. .8'    `888  `888P"Y88b  d88' `888  d88' `88b  `88. `88.  .8'       888      d88' `88b d88(  "8   888   `888  `888P"Y88b  888' `88b
								`888.8'  `888.8'      888   888   888  888   888  888   888   `88..]88..8'        888      888ooo888 `"Y88b.    888    888   888   888  888   888
								 `888'    `888'       888   888   888  888   888  888   888    `888'`888'         888      888    .o o.  )88b   888 .  888   888   888  `88bod8P'
								  `8'      `8'       o888o o888o o888o `Y8bod88P" `Y8bod8P'     `8'  `8'         o888o     `Y8bod8P' 8""888P'   "888" o888o o888o o888o `8oooooo.
																																										d"     YD
																																										"Y88888P'


				This file is part of EdenCraft Engine - WindowTesting sample.
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

#include "core/application.hpp"
#include "window/common.hpp"

#include <iostream>

std::weak_ptr<ece::Window> createMainWindow(ece::WindowedApplication & app);

int main()
{
	try {
		ece::WindowedApplication app;

		std::array<std::weak_ptr<ece::Window>, 2> windows;

		for (auto & window : windows) {
			window = createMainWindow(app);

			auto & eventHandler = window.lock()->getEventHandler();
			eventHandler.onKeyPressed.connect([](const ece::InputEvent & event, ece::Window & window) {
				if (event.key == ece::Keyboard::Key::ESCAPE) {
					window.close();
				}
			});
			window.lock()->onWindowClosed.connect([&app]() {
				app.stop();
			});

			ece::FramePerSecond fps(ece::FramePerSecond::FPSrate::FRAME_NO_LIMIT);

			app.onPreUpdate.connect([&window, &fps]() {
				if (fps.isReadyToUpdate()) {
					window.lock()->setTitle("WFL window testing " + std::to_string(fps.getNumberOfFrames()) + " - " + std::to_string(fps.getFPS()) + "FPS - " + std::to_string(fps.getAverage()) + "ms");
				}
			});
		}

		app.run();
	}
	catch (std::runtime_error & e) {
		ece::ERROR << e.what() << ece::flush;
	}
	catch (std::exception & e) {
		ece::ERROR << e.what() << ece::flush;
	}

	return EXIT_SUCCESS;
}


std::weak_ptr<ece::Window> createMainWindow(ece::WindowedApplication & app)
{
	static int count = 0;

	auto window = app.addWindow<ece::Window>();

	ece::WindowSetting settings;
	settings.title = "WFL window testing" + std::to_string(count);
	settings.position += ece::IntVector2u{ 10, 10 } * count;
	++count;
	window.lock()->open();
	window.lock()->setSettings(settings);
//	window.lock()->maximize();
	window.lock()->limitUPS(60);

	return std::move(window);
}