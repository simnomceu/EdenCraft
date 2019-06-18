/*

	oooooooooooo       .o8                          .oooooo.                       .o88o.     .
	`888'     `8      "888                         d8P'  `Y8b                      888 `"   .o8
	 888          .oooo888   .ooooo.  ooo. .oo.   888          oooo d8b  .oooo.   o888oo  .o888oo
	 888oooo8    d88' `888  d88' `88b `888P"Y88b  888          `888""8P `P  )88b   888      888
	 888    "    888   888  888ooo888  888   888  888           888      .oP"888   888      888
	 888       o 888   888  888    .o  888   888  `88b    ooo   888     d8(  888   888      888 .
	o888ooooood8 `Y8bod88P" `Y8bod8P' o888o o888o  `Y8bood8P'  d888b    `Y888""8o o888o     "888"

															oooooo     oooo  o8o
															 `888.     .8'   `"'
															  `888.   .8'   oooo   .ooooo.  oooo oooo    ooo  .ooooo.  oooo d8b
															   `888. .8'    `888  d88' `88b  `88. `88.  .8'  d88' `88b `888""8P
																`888.8'      888  888ooo888   `88..]88..8'   888ooo888  888
																 `888'       888  888    .o    `888'`888'    888    .o  888
																  `8'       o888o `Y8bod8P'     `8'  `8'     `Y8bod8P' d888b
																  																   
				This file is part of EdenCraft Engine - Viewer sample.
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

#include "core/format.hpp"

#include "systems/render.hpp"
#include "prototypes/model.hpp"

#include "renderer/buffer.hpp"
#include "renderer/rendering.hpp"
#include "renderer/image.hpp"

std::weak_ptr<ece::RenderWindow> createMainWindow(ece::WindowedApplication & app);

int main(int argc, char *argv[])
{
	std::srand(static_cast<unsigned int>(time(nullptr)));

	try {
		ece::WindowedApplication app(argc, argv);
		auto window = createMainWindow(app);

		ece::ServiceFormatLocator::getService().registerLoader<ece::LoaderBMP>("bmp");
		ece::ServiceFormatLocator::getService().registerLoader<ece::OBJLoader>("obj");
		ece::ServiceFormatLocator::getService().registerSaver<ece::OBJSaver>("obj");

        auto & world = app.addWorld();
        auto renderSystem = world.addSystem<RenderSystem>(window);

		auto & scene = renderSystem->getScene();
		auto & camera = scene.getCamera();

		Model model(world);
		app.getArgumentAnalyzer().addOption(ece::Option("file", std::make_shared<ece::StringOptionValue>(), [&model](const std::string & value) {
			if (!value.empty()) {
				model.loadFrom(value);
			}
		}));

 		auto & eventHandler = window.lock()->getEventHandler();
		eventHandler.onKeyPressed.connect([&camera, &scene, &model](const ece::InputEvent & event, ece::Window & window) {
			if (event.key == ece::Keyboard::Key::ESCAPE) {
				window.close();
			}
			else if (event.key == ece::Keyboard::Key::LEFT) {
				camera.moveIn({ -1.0f, 0.0f, 0.0f });
				scene.updateCamera();
			}
			else if (event.key == ece::Keyboard::Key::RIGHT) {
				camera.moveIn({ 1.0f, 0.0f, 0.0f });
				scene.updateCamera();
			}
			else if (event.key == ece::Keyboard::Key::UP) {
				camera.moveIn({ 0.0f, 0.0f, -1.0f });
				scene.updateCamera();
			}
			else if (event.key == ece::Keyboard::Key::DOWN) {
				camera.moveIn({ 0.0f, 0.0f, 1.0f });
				scene.updateCamera();
			}
			else if (event.key == ece::Keyboard::Key::S && ece::Keyboard::isKeyPressed(ece::Keyboard::Key::CTRL)) {
				model.save();
			}
		});
		eventHandler.onMouseWheelScrolled.connect([&camera, &scene](const ece::InputEvent & event, ece::Window & /*window*/) {
			if (event.mouseWheel > 0.0f) {
				camera.moveTo(camera.getPosition() / 2.0f);
			}
			else {
				camera.moveTo(camera.getPosition() * 2.0f);
			}
			scene.updateCamera();
		});
		window.lock()->onWindowClosed.connect([&app]() {
			app.stop();
		});

		ece::FramePerSecond fps(ece::FramePerSecond::FPSrate::FRAME_NO_LIMIT);

		app.onPreUpdate.connect([&window, &fps]() {
			if (fps.isReadyToUpdate()) {
				window.lock()->setTitle("Viewer - Frame " +  std::to_string(fps.getNumberOfFrames()) + " - " + std::to_string(fps.getFPS()) + "FPS - " + std::to_string(fps.getAverage()) + "ms");
			}
		});

		app.onPostUpdate.connect([&window, &model]() {
			window.lock()->display();
			model.update();
		});

		app.run();
	}
	catch (const std::runtime_error & e) {
		ece::ERROR << e.what() << ece::flush;
	}
	catch (const std::exception & e) {
		ece::ERROR << e.what() << ece::flush;
	}

	return 0;
}

std::weak_ptr<ece::RenderWindow> createMainWindow(ece::WindowedApplication & app)
{
	auto window = app.addWindow<ece::RenderWindow>();

	auto settings = ece::WindowSetting{};
	settings.position = ece::IntVector2u{ 10, 10 };
	settings.title = "Viewer ...";

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