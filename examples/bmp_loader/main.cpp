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
#include "systems/render.hpp"
#include "assets.hpp"
#include "core/format.hpp"

std::weak_ptr<ece::RenderWindow> createMainWindow(ece::WindowedApplication & app);

int main()
{
	try {
		ece::WindowedApplication app;
		auto window = createMainWindow(app);

		ece::ServiceFormatLocator::getService().registerLoader<ece::LoaderBMP>("bmp");

		auto & world = app.addWorld();
		world.addSystem<Render>();

		app.onPostInit.connect([&window]() {
			Assets::loadAssets();
		});

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
				window.lock()->setTitle("BMP Loader - Frame " + std::to_string(fps.getNumberOfFrames()) + " - " + std::to_string(fps.getFPS()) + "FPS - " + std::to_string(fps.getAverage()) + "ms");
			}
		});

		app.onPostUpdate.connect([&window]() {
			window.lock()->display();
		});

		app.run();
	}
	catch (std::runtime_error & e) {
		ece::ERROR << e.what() << ece::flushing;
	}
	catch (std::exception & e) {
		ece::ERROR << e.what() << ece::flushing;
	}

	return EXIT_SUCCESS;
}

std::weak_ptr<ece::RenderWindow> createMainWindow(ece::WindowedApplication & app)
{
	auto window = app.addWindow<ece::RenderWindow>();

	ece::WindowSetting settings;
	settings.title = "BMP Loader";

	auto & contextSettings = window.lock()->getContextSettings();
	contextSettings.maxVersion = { 4, 0 };

	window.lock()->open();
	contextSettings.antialiasingSamples = 0;
	contextSettings.maxVersion = { 4, 6 };
	window.lock()->updateContext();
	window.lock()->setSettings(settings);
	window.lock()->maximize();
	window.lock()->limitUPS(100000);

	return std::move(window);
}
