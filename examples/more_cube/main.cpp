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
#include "graphic/scene.hpp"
#include "renderer/resource.hpp"
#include "graphic/model/obj_loader.hpp"
#include "graphic/renderable/object.hpp"
#include "utility/mathematics/vector3u.hpp"
#include "core/resource/make_resource.hpp"
#include "utility/time.hpp"
#include "graphic/model/primitives.hpp"
#include "graphic/model/phong_material.hpp"
#include "graphic/model/make_light.hpp"

#include <ctime>
#include <string>

namespace ece
{
	using namespace renderer;

	using window::common::WindowSetting;
	using window::event::InputEvent;
	using utility::mathematics::rotate;
	using utility::mathematics::translate;
	using graphic::model::OBJLoader;
    using graphic::model::Mesh;
	using graphic::model::PhongMaterial;
	using graphic::model::makeSpotLight;
    using graphic::renderable::Object;
    using utility::mathematics::FloatVector3u;
	using core::resource::makeResource;
	using core::resource::ResourceHandler;
	using utility::time::FramePerSecond;
	using graphic::model::makeCube;
	using window::event::InputEvent;
}

int main()
{
	std::srand(static_cast<unsigned int>(time(nullptr)));

	try {
		ece::Application app;

		ece::RenderWindow window;

		ece::WindowSetting settings;
		settings._position = ece::IntVector2u{ 10, 10 };
		settings._title = "Test";

		window.setContextMaximumVersion(ece::Version<2>{4, 0});

		window.open();
		window.getVideoMode().setSamples(0);
		window.updateVideoMode();
		window.setSettings(settings);
		window.maximize();
		window.limitUPS(100);

		ece::Viewport viewport;
		//viewport.setViewportRatio(ece::Rectangle<float>(0.0f, 0.0f, 0.99f, 0.99f));
		viewport.resetViewport(ece::Rectangle<float>(0.0f, 0.0f, 1920.0f, 1080.0f));
		window.setViewport(viewport);

		ece::Scene scene;

		// ####################
		ece::OBJLoader loader;
		loader.loadFromFile("../../examples/more_cube/cube.obj");
		//auto mesh = std::make_shared<ece::Mesh>(loader.getMesh());
		auto mesh = std::make_shared<ece::Mesh>(ece::makeCube(0.5f));

		auto material = std::make_shared<ece::PhongMaterial>();
		//material->setAmbient({ 0.24725f, 0.1995f, 0.0745f });
		//material->setDiffuse({ 0.75164f, 0.60648f, 0.22648f });
		//material->setSpecular({ 0.628281f, 0.555802f, 0.366065f });
		material->setShininess(41.5f);

		auto light = ece::makeSpotLight(1.0f, 0.8f, 1.0f, { 1.0f, 1.0f, 1.0f }, { 0.0f, 0.0f, 3.0f }, { 0.0f, 0.0f, -1.0f }, 1.0f, 0.14f, 0.07f, 10.0f, 15.0f);
		scene.addLight(light);
		//light->setColor({ std::sin(std::rand() * 2.0f), std::sin(std::rand() * 0.7f), std::sin(std::rand() * 1.3f) });
		// ####################

		auto & camera = scene.getCamera();
		//		camera.setOrthographic(ece::Rectangle<float>(0, 0, window.getSize()[0] * 0.5f, window.getSize()[1] * 1.0f), 0.0f, 100.0f); // TODO: using window.getViewportSize() ?
		camera.setPerspective(45, /*window.getSize()[0] / window.getSize()[1]*/1920.0f/1080.0f, 0.1, 100.0);
		camera.moveTo(ece::FloatVector3u{ 0.0f, 0.0f, 10.0f });
		camera.lookAt(ece::FloatVector3u{ 0.0f, 0.0f, 0.0f });
		scene.updateCamera();

		auto box = ece::makeResource<ece::Texture2D>("box");
		box->loadFromFile(ece::TextureTypeTarget::TEXTURE_2D, "../../examples/more_cube/box.bmp");
		material->setDiffuseMap(box);

		auto box_specular = ece::makeResource<ece::Texture2D>("box_specular");
		box_specular->loadFromFile(ece::TextureTypeTarget::TEXTURE_2D, "../../examples/more_cube/box_specular.bmp");
		material->setSpecularMap(box_specular);

		// ece::RenderQueue queue;
        auto element = scene.addObject();
        element->setMesh(mesh);
		element->setMaterial(material);

        for (size_t i = 0; i < 100; ++i) {
            for (size_t j = 0; j < 100; ++j) {
                for (size_t k = 0; k < 100; ++k) {
                    element->addInstance(ece::translate(ece::FloatVector3u{-50.0f + i * 1.5f, -50.0f + j * 1.5f, -50.0f + k * 1.5f}));
                }
            }
        }
        scene.prepare();
//		element->applyTransformation(ece::translate(cubePositions[i]));
		// queue.insert(sprite)

		// ForwardRendering technique;

		//ece::InputEvent event;
		auto & eventHandler = window.getEventHandler();
		eventHandler.onKeyPressed.connect([](const ece::InputEvent & event, ece::Window & window) {
			if (event._key == ece::Keyboard::Key::A) {
				std::cerr << 'A' << std::endl;
			}
			else if (event._key == ece::Keyboard::Key::ESCAPE) {
				window.close();
			}
		});

		ece::FramePerSecond fps(ece::FramePerSecond::FPSrate::FRAME_60);
		while (window.isOpened()) { // Still need to make it working on Xlib and XCB
			window.setTitle("Test - Frame " + std::to_string(fps.getFPS()));
			//if (fps.isReadyToUpdate()) { // BIG BUG HERE !!!
				window.clear(ece::BLACK);

				element->applyTransformation(ece::rotate(ece::FloatVector3u{ 0.0f, 1.0f, 1.0f }, 0.005f));
				//camera.moveIn({ 0.0f, 0.0f, 0.05f });
				//scene.updateCamera();

				//light->setColor({ std::sin(std::rand() * 2.0f), std::sin(std::rand() * 0.7f), std::sin(std::rand() * 1.3f) });

				scene.draw();
				//window.draw(**element);
				// technique.draw(queue)
				window.display();
			//}

			//if (window.pollEvent(event)) {
			//}
			window.processEvents();
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
