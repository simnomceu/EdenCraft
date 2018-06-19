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
#include "graphic/scene.hpp"
#include "renderer/resource.hpp"
#include "graphic/model/obj_loader.hpp"

namespace ece
{
	using namespace renderer;

	using window::common::WindowSetting;
	using window::window_event::InputEvent;
	using utility::mathematics::rotate;
	using utility::mathematics::translate;
	using graphic::model::OBJLoader;
}

class Cube : public ece::Renderable
{
public:
	Cube() : Renderable()
	{
		this->_mode = ece::PrimitiveMode::TRIANGLES;

		const std::vector<float> points{
        -0.5f, -0.5f, -0.5f,
         0.5f, -0.5f, -0.5f,
         0.5f,  0.5f, -0.5f,
        -0.5f,  0.5f, -0.5f,

        -0.5f, -0.5f,  0.5f,
         0.5f, -0.5f,  0.5f,
         0.5f,  0.5f,  0.5f,
        -0.5f,  0.5f,  0.5f,
		}; 
		
		const std::vector<float> colors{
			1.0f, 0.0f, 0.0f,
			0.0f, 1.0f, 0.0f,
			0.0f, 0.0f, 1.0f,
			1.0f, 1.0f, 0.0f,

			0.0f, 1.0f, 1.0f,
			1.0f, 0.0f, 1.0f,
			0.0f, 0.0f, 0.0f,
			1.0f, 1.0f, 1.0f,
		};

		const std::vector<unsigned int> index{ 0, 2, 1,
			0, 3, 2,

			1,2,6,
			6,5,1,

			4,5,6,
			6,7,4,

			2,3,6,
			6,3,7,

			0,7,3,
			0,4,7,

			0,1,5,
			0,5,4
		};

		this->_vao.addAttribute(0, 3, false, 0, ece::BufferType::ARRAY_BUFFER, points, ece::BufferUsage::STATIC_DRAW);
		this->_vao.addAttribute(1, 3, false, 0, ece::BufferType::ARRAY_BUFFER, colors, ece::BufferUsage::STATIC_DRAW);
		this->_vao.addIndices(index, ece::BufferUsage::STATIC_DRAW);

		ece::ShaderStage fsSource, vsSource;
		fsSource.loadFromFile(ece::ShaderType::FRAGMENT_SHADER, "../../examples/more_cube/cube.frag");
		vsSource.loadFromFile(ece::ShaderType::VERTEX_SHADER, "../../examples/more_cube/cube.vert");

		this->_program.setStage(fsSource);
		this->_program.setStage(vsSource);
		this->_program.link();
		this->_program.use();
	}

private:
	ece::Texture2D _texture;
};

int main()
{
	try {
		ece::Application app;

		// ####################
		ece::OBJLoader loader;
		loader.loadFromFile("../../examples/more_cube/cube.obj");
		auto mesh = loader.getMesh();
		// ####################

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

		/*ece::Viewport viewport;
		viewport.setViewportRatio(ece::Rectangle<float>(0.0f, 0.0f, 0.5f, 1.0f));
		window.setViewport(viewport);*/

		ece::Camera camera;
//		camera.setOrthographic(ece::Rectangle<float>(0, 0, window.getSize()[0] * 0.5f, window.getSize()[1] * 1.0f), 0.0f, 100.0f); // TODO: using window.getViewportSize() ?
		camera.setPerspective(45, window.getSize()[0] / window.getSize()[1], 0.1, 100.0);
        camera.moveTo(ece::FloatVector3u{0.0f, 0.0f, 10.0f});
        camera.lookAt(ece::FloatVector3u{0.0f, 0.0f, 0.0f});

		ece::Texture2D texture;
		texture.loadFromFile(ece::TextureTypeTarget::TEXTURE_2D, "../../examples/more_cube/emma_watson.bmp");

		// ece::RenderQueue queue;
		//std::vector<std::shared_ptr<ece::Sprite>> elements(10);
		std::vector<std::shared_ptr<Cube>> elements(10);
		ece::FloatVector3u cubePositions[] = {
			ece::FloatVector3u{0.0f,  0.0f,  0.0f},
			ece::FloatVector3u{2.0f,  5.0f, -15.0f},
			ece::FloatVector3u{-1.5f, -2.2f, -2.5f},
			ece::FloatVector3u{-3.8f, -2.0f, -12.3f},
			ece::FloatVector3u{2.4f, -0.4f, -3.5f},
			ece::FloatVector3u{-1.7f,  3.0f, -7.5f},
			ece::FloatVector3u{1.3f, -2.0f, -2.5f},
			ece::FloatVector3u{1.5f,  2.0f, -2.5f},
			ece::FloatVector3u{1.5f,  0.2f, -1.5f},
			ece::FloatVector3u{-1.3f,  1.0f, -1.5f}
		};

		for (unsigned short int i = 0; i < 10; ++i) {
			// ece::Sprite sprite;
			//elements[i] = std::make_shared<ece::Sprite>(texture, ece::Rectangle<float>(i * 50.0f, i * 50.0f, static_cast<float>(texture.getWidth()), static_cast<float>(texture.getHeight())), ece::Rectangle<float>(50.0f, 50.0f, 150.0f, 150.0f));
			elements[i] = std::make_shared<Cube>();
			elements[i]->applyTransformation(ece::translate(cubePositions[i]));
			elements[i]->setCamera(camera.getView(), camera.getProjection());
			// queue.insert(sprite)
		}

		// ForwardRendering technique;

		ece::InputEvent event;
		while (window.isOpened()) { // Still need to make it working on Xlib and XCB
			window.clear(ece::FUSHIA);

			for (unsigned short int i = 0; i < 10; ++i) {
				elements[i]->applyTransformation(ece::rotate(ece::FloatVector3u{ 0.0f, 1.0f, 1.0f }, i * 0.001f));
				window.draw(*elements[i]);
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
