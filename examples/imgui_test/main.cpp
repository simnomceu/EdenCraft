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

std::weak_ptr<ece::RenderWindow> createMainWindow(ece::WindowedApplication & app);

int main()
{
	std::srand(static_cast<unsigned int>(time(nullptr)));

	try {
		ece::WindowedApplication app;
		auto window = createMainWindow(app);

		auto& world = app.addWorld();
		world.addSystem<ece::ImguiSystem>(window.lock());

		world.createEntity().addComponent<ece::ImguiComponent>([]() {
			bool show_demo_window = true;
			ImGui::ShowDemoWindow(&show_demo_window);
		});

		world.createEntity().addComponent<ece::ImguiComponent>([]() {

			static bool show_demo_window = true;
			static bool show_another_window = false;
			static ImVec4 clear_color = ImVec4(0.45f, 0.55f, 0.60f, 1.00f);
			
			if (show_demo_window)
				ImGui::ShowDemoWindow(&show_demo_window);

			// 2. Show a simple window that we create ourselves. We use a Begin/End pair to created a named window.
			{
				static float f = 0.0f;
				static int counter = 0;

				ImGui::Begin("Hello, world!");                          // Create a window called "Hello, world!" and append into it.

				ImGui::Text("This is some useful text.");               // Display some text (you can use a format strings too)
				ImGui::Checkbox("Demo Window", &show_demo_window);      // Edit bools storing our window open/close state
				ImGui::Checkbox("Another Window", &show_another_window);

				ImGui::SliderFloat("float", &f, 0.0f, 1.0f);            // Edit 1 float using a slider from 0.0f to 1.0f
				ImGui::ColorEdit3("clear color", (float*)&clear_color); // Edit 3 floats representing a color

				if (ImGui::Button("Button"))                            // Buttons return true when clicked (most widgets return true when edited/activated)
					counter++;
				ImGui::SameLine();
				ImGui::Text("counter = %d", counter);

				ImGui::Text("Application average %.3f ms/frame (%.1f FPS)", 1000.0f / ImGui::GetIO().Framerate, ImGui::GetIO().Framerate);
				ImGui::End();
			}

			// 3. Show another simple window.
			if (show_another_window)
			{
				ImGui::Begin("Another Window", &show_another_window);   // Pass a pointer to our bool variable (the window will have a closing button that will clear the bool when clicked)
				ImGui::Text("Hello from another window!");
				if (ImGui::Button("Close Me"))
					show_another_window = false;
				ImGui::End();
			}
		});
		
		window.lock()->onWindowClosed.connect([&app]() {
			app.stop();
		});

		ece::FramePerSecond fps(ece::FramePerSecond::FPSrate::FRAME_NO_LIMIT);

		app.onPreUpdate.connect([&window, &fps]() {
			if (fps.isReadyToUpdate()) {
				window.lock()->setTitle("IMGUI Test ... - Frame " + std::to_string(fps.getNumberOfFrames()) + " - " + std::to_string(fps.getFPS()) + "FPS - " + std::to_string(fps.getAverage()) + "ms");
			}
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