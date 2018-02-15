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

#include "core/application/application.hpp"

#include "renderer/common/render_window.hpp"
#include "renderer/common/enhanced_shader.hpp"
#include "utility/log/service_logger.hpp"
#include "renderer/opengl/vao.hpp"
#include "renderer/common/renderer.hpp"
#include "utility/file_system/parser_bmp.hpp"
#include "renderer/common/texture2d.hpp"

#include <iostream>

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

		ece::Renderer renderer;
		//renderer.setPolygonMode(ece::PolygonMode::LINE);

		/*const std::vector<float> points{ 0.0f, 0.5f,
										 0.5f, -0.5f,
										-0.5f, -0.5f };

		const std::vector<float> colours{ 1.0f, 0.0f, 0.0f,
										  0.0f, 1.0f, 0.0f,
										  0.0f, 0.0f, 1.0f };
										  
		const std::vector<unsigned int> index{ 0, 1, 2 };*/

		const std::vector<float> points{ -0.5f, -0.5f,
										 -0.5f,  0.5f,
										  0.5f,  0.5f,
										  0.5f, -0.5f
		};

		const std::vector<float> colours{ 1.0f, 0.0f, 0.0f,
										  0.0f, 1.0f, 0.0f,
										  0.0f, 0.0f, 1.0f,
										  0.0f, 1.0f, 1.0f
		};

		const std::vector<float> texPos{ 1.0f, 1.0f, 
											1.0f, 0.0f,
											0.0f, 0.0f,
											0.0f, 1.0f
		};

		const std::vector<unsigned int> index{ 0, 1, 2, 2, 3, 0 };

		/*const std::vector<float> points{ -0.5f, -0.5f, 0.5,
										-0.5f,  0.5f, 0.5,
										0.5f,  0.5f, 0.5,
										0.5f, -0.5f,  0.5,
										0.0f, 0.0f, -0.5,
										0.0f,  1.0f, -0.5,
										1.0f,  1.0f, -0.5,
										1.0f, 0.0f,  -0.5,
		};

		const std::vector<float> colours{ 1.0f, 0.0f, 0.0f,
										  0.0f, 1.0f, 0.0f,
										  0.0f, 0.0f, 1.0f,
										  0.0f, 1.0f, 1.0f,
										  1.0f, 0.0f, 0.0f,
										  0.0f, 1.0f, 0.0f,
										  0.0f, 0.0f, 1.0f,
										  0.0f, 1.0f, 1.0f
		};

		const std::vector<unsigned int> index{ 0, 1, 2, 
											   2, 3, 0,
											   2, 7, 3,
											   2, 6, 3,
											   4, 5, 6,
											   6, 7, 4,
											   4, 5, 0,
											   5, 1, 0,
											   1, 5, 6,
											   6, 2, 1,
											   0, 4, 7,
											   7, 3, 0
		};*/

		ece::VAO vao;
		vao.addAttribute(0, 2, false, 0, ece::BufferType::ARRAY_BUFFER, points, ece::BufferUsage::STATIC_DRAW);
		vao.addAttribute(1, 3, false, 0, ece::BufferType::ARRAY_BUFFER, colours, ece::BufferUsage::STATIC_DRAW);
		vao.addAttribute(2, 2, false, 0, ece::BufferType::ARRAY_BUFFER, texPos, ece::BufferUsage::STATIC_DRAW);
		vao.addIndices(index, ece::BufferUsage::STATIC_DRAW);

		ece::ShaderStage fsSource, vsSource;
		fsSource.loadFromFile(ece::ShaderType::FRAGMENT_SHADER, "../examples/more_cube/shader.frag");
		vsSource.loadFromFile(ece::ShaderType::VERTEX_SHADER, "../examples/more_cube/shader.vert");
		ece::EnhancedShader program;
		program.setStage(fsSource);
		program.setStage(vsSource);
		program.link();
		renderer.setProgram(program);

		ece::Texture2D texture;
		texture.loadFromFile(ece::TextureTypeTarget::TEXTURE_2D, "../examples/more_cube/emma_watson.bmp");
		texture.bind(ece::TextureTarget::TEXTURE_2D);
		texture.update();

		ece::OpenGL::uniform(glGetUniformLocation(program.getHandle(), "theTexture"), std::array<int, 1>{0});

		ece::InputEvent event;
		while (1) {
			window.clear();

			renderer.drawPrimitives(ece::PrimitiveMode::TRIANGLES, vao);
			if (window.pollEvent(event)) {
			}
			window.display();
		}
	}
	catch (std::runtime_error & e) {
		ece::ServiceLoggerLocator::getService().logError(e.what());
	}

	return 0;
}