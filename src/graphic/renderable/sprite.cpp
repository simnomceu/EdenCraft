/*

	oooooooooooo       .o8                          .oooooo.                       .o88o.     .
	`888'     `8      "888                         d8P'  `Y8b                      888 `"   .o8
	 888          .oooo888   .ooooo.  ooo. .oo.   888          oooo d8b  .oooo.   o888oo  .o888oo
	 888oooo8    d88' `888  d88' `88b `888P"Y88b  888          `888""8P `P  )88b   888      888
	 888    "    888   888  888ooo888  888   888  888           888      .oP"888   888      888
	 888       o 888   888  888    .o  888   888  `88b    ooo   888     d8(  888   888      888 .
	o888ooooood8 `Y8bod88P" `Y8bod8P' o888o o888o  `Y8bood8P'  d888b    `Y888""8o o888o     "888"

															  .oooooo.                                  oooo         o8o
															 d8P'  `Y8b                                 `888         `"'
															888           oooo d8b  .oooo.   oo.ooooo.   888 .oo.   oooo   .ooooo.
															888           `888""8P `P  )88b   888' `88b  888P"Y88b  `888  d88' `"Y8
															888     ooooo  888      .oP"888   888   888  888   888   888  888
															`88.    .88'   888     d8(  888   888   888  888   888   888  888   .o8
															 `Y8bood8P'   d888b    `Y888""8o  888bod8P' o888o o888o o888o `Y8bod8P'
																							  888
																							 o888o



				This file is part of EdenCraft Engine - Graphic module.
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

#include "graphic/renderable/sprite.hpp"

namespace ece
{
    Sprite::Sprite(const Texture2D & texture, const Rectangle<float> & bounds): Renderable(), _texture(texture), _bounds(bounds)
    {
        if (this->_bounds == Rectangle<float>()) {
            this->_bounds = Rectangle<float>(0.0f, 0.0f, this->_texture.getWidth(), this->_texture.getHeight());
        }

        this->_texture.bind(ece::TextureTarget::TEXTURE_2D);
		this->_texture.update();

        this->_mode = ece::PrimitiveMode::TRIANGLES;

        // TODO : set size and position according to render_target size.
        const std::vector<float> points{ -0.5f, -0.5f,
										 -0.5f,  0.5f,
										  0.5f,  0.5f,
										  0.5f, -0.5f
		};

		const std::vector<float> texPos{ 1.0f, 1.0f,
											1.0f, 0.0f,
											0.0f, 0.0f,
											0.0f, 1.0f
		};

		const std::vector<unsigned int> index{ 0, 1, 2, 2, 3, 0 };

		this->_vao.addAttribute(0, 2, false, 0, ece::BufferType::ARRAY_BUFFER, points, ece::BufferUsage::STATIC_DRAW);
		this->_vao.addAttribute(1, 2, false, 0, ece::BufferType::ARRAY_BUFFER, texPos, ece::BufferUsage::STATIC_DRAW);
		this->_vao.addIndices(index, ece::BufferUsage::STATIC_DRAW);

		ece::ShaderStage fsSource, vsSource;
		fsSource.loadFromFile(ece::ShaderType::FRAGMENT_SHADER, "../../examples/more_cube/sprite.frag");
		vsSource.loadFromFile(ece::ShaderType::VERTEX_SHADER, "../../examples/more_cube/sprite.vert");

		this->_program.setStage(fsSource);
		this->_program.setStage(vsSource);
		this->_program.link();
        this->_program.use();

        ece::OpenGL::uniform<int, 1>(glGetUniformLocation(this->_program.getHandle(), "theTexture"), std::array<int, 1>{0});
    }
}
