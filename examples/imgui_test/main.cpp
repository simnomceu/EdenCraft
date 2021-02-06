/*

	oooooooooooo       .o8                          .oooooo.                       .o88o.     .
	`888'     `8      "888                         d8P'  `Y8b                      888 `"   .o8
	 888          .oooo888   .ooooo.  ooo. .oo.   888          oooo d8b  .oooo.   o888oo  .o888oo
	 888oooo8    d88' `888  d88' `88b `888P"Y88b  888          `888""8P `P  )88b   888      888
	 888    "    888   888  888ooo888  888   888  888           888      .oP"888   888      888
	 888       o 888   888  888    .o  888   888  `88b    ooo   888     d8(  888   888      888 .
	o888ooooood8 `Y8bod88P" `Y8bod8P' o888o o888o  `Y8bood8P'  d888b    `Y888""8o o888o     "888"

															ooooo                     .oooooo.    ooooo     ooo ooooo ooooooooooooo                        .
															`888'                    d8P'  `Y8b   `888'     `8' `888' 8'   888   `8                      .o8
															 888  ooo. .oo.  .oo.   888            888       8   888       888       .ooooo.   .oooo.o .o888oo
															 888  `888P"Y88bP"Y88b  888            888       8   888       888      d88' `88b d88(  "8   888
															 888   888   888   888  888     ooooo  888       8   888       888      888ooo888 `"Y88b.    888
															 888   888   888   888  `88.    .88'   `88.    .8'   888       888      888    .o o.  )88b   888 .
															o888o o888o o888o o888o  `Y8bood8P'      `YbodP'    o888o     o888o     `Y8bod8P' 8""888P'   "888"



				This file is part of EdenCraft Engine - ImGUITest sample.
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

#include "renderer/rendering.hpp"
#include "gui/imgui.hpp"
#include "imgui.h"
#include "renderer/opengl.hpp"

std::weak_ptr<ece::RenderWindow> createMainWindow(ece::WindowedApplication & app);

int main()
{
	std::srand(static_cast<unsigned int>(time(nullptr)));

	try {
		ece::WindowedApplication app;
		auto window = createMainWindow(app);

		auto imgui = ece::Adapter();
		imgui.init(window.lock());
		
		window.lock()->onWindowClosed.connect([&app]() {
			app.stop();
		});

		ece::FramePerSecond fps(ece::FramePerSecond::FPSrate::FRAME_NO_LIMIT);

		app.onPreUpdate.connect([&window, &fps, &imgui]() {
			if (fps.isReadyToUpdate()) {
				window.lock()->setTitle("IMGUI Test ... - Frame " + std::to_string(fps.getNumberOfFrames()) + " - " + std::to_string(fps.getFPS()) + "FPS - " + std::to_string(fps.getAverage()) + "ms");
			}
			ece::OpenGL::clearColor(0.0f, 0.0f, 0.0f, 0.0f);
			ece::OpenGL::clear(ece::Bitfield::COLOR_BUFFER_BIT);
			bool show_demo_window = true;
			imgui.newFrame();
			ImGui::ShowDemoWindow(&show_demo_window);
			imgui.render();
		});

		app.onPostUpdate.connect([&window]() {
			window.lock()->display();
		});
		window.lock()->onWindowClosed.connect([&app]() {
			app.stop();
		});

		auto & eventHandler = window.lock()->getEventHandler();
		eventHandler.onKeyPressed.connect([](const ece::InputEvent & event, ece::Window & window) {
			if (event.key == ece::Keyboard::Key::ESCAPE) {
				window.close();
			}
		});

		app.run();

		imgui.shutdown();
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
	settings.title = "ImGUI Test ...";

	auto & contextSettings = window.lock()->getContextSettings();
	contextSettings.maxVersion = { 4, 5 };

	window.lock()->open();
	window.lock()->setSettings(settings);
	window.lock()->maximize();
	window.lock()->limitUPS(100000);

	return std::move(window);
}