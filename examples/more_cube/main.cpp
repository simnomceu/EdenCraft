/*

	oooooooooooo       .o8                          .oooooo.                       .o88o.     .
	`888'     `8      "888                         d8P'  `Y8b                      888 `"   .o8
	 888          .oooo888   .ooooo.  ooo. .oo.   888          oooo d8b  .oooo.   o888oo  .o888oo
	 888oooo8    d88' `888  d88' `88b `888P"Y88b  888          `888""8P `P  )88b   888      888
	 888    "    888   888  888ooo888  888   888  888           888      .oP"888   888      888
	 888       o 888   888  888    .o  888   888  `88b    ooo   888     d8(  888   888      888 .
	o888ooooood8 `Y8bod88P" `Y8bod8P' o888o o888o  `Y8bood8P'  d888b    `Y888""8o o888o     "888"

															ooo        ooooo                                .oooooo.                .o8
															`88.       .888'                               d8P'  `Y8b              "888
															 888b     d'888   .ooooo.  oooo d8b  .ooooo.  888          oooo  oooo   888oooo.   .ooooo.
															 8 Y88. .P  888  d88' `88b `888""8P d88' `88b 888          `888  `888   d88' `88b d88' `88b
															 8  `888'   888  888   888  888     888ooo888 888           888   888   888   888 888ooo888
															 8    Y     888  888   888  888     888    .o `88b    ooo   888   888   888   888 888    .o
															o8o        o888o `Y8bod8P' d888b    `Y8bod8P'  `Y8bood8P'   `V88V"V8P'  `Y8bod8P' `Y8bod8P'



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

#include "core/application.hpp"

#include "renderer/common.hpp"
#include "utility/log.hpp"
#include "renderer/image.hpp"
#include "graphic/renderable.hpp"
#include "renderer/resource.hpp"

namespace ece
{
	using namespace renderer;

	using window::common::WindowSetting;
	using window::window_event::InputEvent;
}

int main()
{
	try {
		ece::Application app;

		ece::RenderWindow window;

		ece::WindowSetting settings;
		settings._position = ece::IntVector2u{ 10, 10 };
		settings._title = "WGL window testing";

		window.setContextMaximumVersion(ece::Version<2>{4, 0});

		window.open();
		window.getVideoMode().setSamples(0);
		window.updateVideoMode();
		window.setSettings(settings);
		window.limitUPS(100);

		ece::Viewport viewport;
		viewport.setViewportRatio(ece::Rectangle<float>(0.0f, 0.0f, 0.5f, 1.0f));
		window.setViewport(viewport);

		ece::Projection projection;
		projection.setOrthographic(ece::Rectangle<float>(0, 0, window.getSize()[0] * 0.5f, window.getSize()[1] * 1.0f), -1.0f, 1.0f); // TODO: using window.getViewportSize() ?

		ece::Texture2D texture;
		texture.loadFromFile(ece::TextureTypeTarget::TEXTURE_2D, "../../examples/more_cube/emma_watson.bmp");

		// ece::RenderQueue queue;
		std::vector<std::shared_ptr<ece::Sprite>> sprites(10);
		for (unsigned short int i = 0; i < 10; ++i) {
			// ece::Sprite sprite;
			sprites[i] = std::make_shared<ece::Sprite>(texture, ece::Rectangle<float>(i * 50.0f, i * 50.0f, static_cast<float>(texture.getWidth()), static_cast<float>(texture.getHeight())), ece::Rectangle<float>(50.0f, 50.0f, 150.0f, 150.0f));
			sprites[i]->setProjection(projection);
			// queue.insert(sprite)
		}

		// ForwardRendering technique;

		ece::InputEvent event;
		while (window.isOpened()) { // Still need to make it working on Xlib and XCB
			window.clear(ece::FUSHIA);

			for (unsigned short int i = 0; i < 10; ++i) {
				window.draw(*sprites[i]);
			}
			// technique.draw(queue)

			if (window.pollEvent(event)) {
			}
			window.display();
		}
	}
	catch (std::runtime_error & e) {
		ece::ServiceLoggerLocator::getService().logError(e.what());
	}
	catch (std::exception & e) {
		ece::ServiceLoggerLocator::getService().logError(e.what());
	}

	return 0;
}
