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
#include "graphic/renderable/sprite.hpp"
#include "graphic/scene.hpp"
#include "renderer/resource.hpp"
#include "graphic/model/obj_loader.hpp"
#include "renderer/resource/buffer_layout.hpp"
#include "graphic/renderable/object.hpp"
#include "utility/mathematics/vector3u.hpp"
#include "core/resource/make_resource.hpp"
#include "utility/time.hpp"
#include "graphic/model/primitives.hpp"

#include <ctime>
#include <string>

namespace ece
{
	using namespace renderer;

	using window::common::WindowSetting;
	using window::window_event::InputEvent;
	using utility::mathematics::rotate;
	using utility::mathematics::translate;
	using graphic::model::OBJLoader;
    using graphic::model::Mesh;
    using graphic::renderable::Object;
    using utility::mathematics::FloatVector3u;
	using core::resource::makeResource;
	using core::resource::ResourceHandler;
	using graphic::renderable::Sprite;
	using utility::time::FramePerSecond;
	using graphic::model::makeSphere;
}

int main()
{
	std::srand(static_cast<unsigned int>(time(nullptr)));

	try {
		ece::Application app;

		// ####################
		ece::OBJLoader loader;
		loader.loadFromFile("../../examples/more_cube/cube.obj");
		//auto mesh = ece::makeResource<ece::Mesh>("OBJ cube", loader.getMesh());
		auto mesh = ece::makeResource<ece::Mesh>("Circle", ece::makeSphere(1.0f, 16));
		// ####################

		ece::RenderWindow window;

		ece::WindowSetting settings;
		settings._position = ece::IntVector2u{ 10, 10 };
		settings._title = "Test";

		window.setContextMaximumVersion(ece::Version<2>{4, 0});

		window.open();
		window.getVideoMode().setSamples(0);
		window.updateVideoMode();
		window.setSettings(settings);
		window.limitUPS(100);

		/*ece::Viewport viewport;
		viewport.setViewportRatio(ece::Rectangle<float>(0.0f, 0.0f, 0.5f, 1.0f));
		window.setViewport(viewport);*/

		ece::Camera camera;
		//		camera.setOrthographic(ece::Rectangle<float>(0, 0, window.getSize()[0] * 0.5f, window.getSize()[1] * 1.0f), 0.0f, 100.0f); // TODO: using window.getViewportSize() ?
		camera.setPerspective(45, window.getSize()[0] / window.getSize()[1], 0.1, 100.0);
		camera.moveTo(ece::FloatVector3u{ 0.0f, 0.0f, 10.0f });
		camera.lookAt(ece::FloatVector3u{ 0.0f, 0.0f, 0.0f });

		auto texture = ece::makeResource<ece::Texture2D>("Emma Watson");
		texture->loadFromFile(ece::TextureTypeTarget::TEXTURE_2D, "../../examples/more_cube/emma_watson.bmp");

		// ece::RenderQueue queue;
		//std::vector<std::shared_ptr<ece::Sprite>> elements(10);
        auto element = ece::makeResource<ece::Object>("cube");

		auto sprite = ece::makeResource<ece::Sprite>("Emma Watson", texture, ece::Rectangle<float>(50.0f, 50.0f, static_cast<float>(texture->getWidth()), static_cast<float>(texture->getHeight())), ece::Rectangle<float>(50.0f, 50.0f, 150.0f, 150.0f));

		element->setMesh(mesh);
		for (size_t i = 0; i < 10; ++i) {
			for (size_t j = 0; j < 10; ++j) {
				for (size_t k = 0; k < 10; ++k) {
					element->addInstance(ece::FloatVector3u{ -50.0f + i * 1.5f, -50.0f + j * 1.5f, -50.0f + k * 1.5f });
				}
			}
		}
		element->prepare();
		//		element->applyTransformation(ece::translate(cubePositions[i]));
		element->setCamera(camera.getView(), camera.getProjection());
		// queue.insert(sprite)

		// ForwardRendering technique;

		ece::InputEvent event;
		ece::FramePerSecond fps(ece::FramePerSecond::FPSrate::FRAME_60);
		while (window.isOpened()) { // Still need to make it working on Xlib and XCB
			if (fps.isReadyToUpdate()) {
				window.setTitle("Test - Frame " + std::to_string(fps.getFPS()));
				window.clear(ece::FUSHIA);

			element->applyTransformation(ece::rotate(ece::FloatVector3u{ 0.0f, 1.0f, 1.0f }, 0.005f));
			window.draw(**element);
			// technique.draw(queue)

				if (window.pollEvent(event)) {
				}
				window.display();
			}
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
