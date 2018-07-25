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

#include "renderer/resource/buffer_layout.hpp"

namespace ece
{
	namespace graphic
	{
		namespace renderable
		{
			using namespace renderer;

			using renderer::resource::ShaderStage;
			using renderer::opengl::OpenGL;
            using renderer::resource::BufferLayout;

			Sprite::Sprite(const Texture2D & texture, const Rectangle<float> & bounds, const Rectangle<float> & textureClip) : Renderable(), _texture(texture), _textureClip(textureClip), _bounds(bounds)
			{
				if (this->_bounds == Rectangle<float>()) {
					this->_bounds = Rectangle<float>(0.0f, 0.0f, static_cast<float>(this->_texture.getWidth()), static_cast<float>(this->_texture.getHeight()));
				}

				if (this->_textureClip == Rectangle<float>()) {
					this->_textureClip = Rectangle<float>(0.0f, 0.0f, static_cast<float>(this->_texture.getWidth()), static_cast<float>(this->_texture.getHeight()));
				}

				this->_texture.bind(TextureTarget::TEXTURE_2D);
				this->_texture.update();

				this->_mode = PrimitiveMode::TRIANGLES;

				const std::vector<float> points{ this->_bounds.getX(), this->_bounds.getY(),
					this->_bounds.getX(), this->_bounds.getY() + this->_bounds.getHeight(),
					this->_bounds.getX() + this->_bounds.getWidth(), this->_bounds.getY() + this->_bounds.getHeight(),
					this->_bounds.getX() + this->_bounds.getWidth(), this->_bounds.getY()
				};

				const std::vector<float> texPos{ this->_textureClip.getX() / this->_bounds.getWidth(), this->_textureClip.getY() / this->_bounds.getHeight(),
												 this->_textureClip.getX() / this->_bounds.getWidth(), (this->_textureClip.getY() + this->_textureClip.getHeight()) / this->_bounds.getHeight(),
												 (this->_textureClip.getX() + this->_textureClip.getWidth()) / this->_bounds.getWidth(), (this->_textureClip.getY() + this->_textureClip.getHeight()) / this->_bounds.getHeight(),
												 (this->_textureClip.getX() + this->_textureClip.getWidth()) / this->_bounds.getWidth(), this->_textureClip.getY() / this->_bounds.getHeight()
				};

				const std::vector<unsigned int> index{ 0, 1, 2, 2, 3, 0 };

                BufferLayout layout;
                layout.add<float>(2, false);
                layout.add<float>(2, false);

				this->_vao.sendData(layout, BufferType::ARRAY_BUFFER, points, BufferUsage::STATIC_DRAW);
				this->_vao.addIndices(index, BufferUsage::STATIC_DRAW);

				ShaderStage fsSource, vsSource;
				fsSource.loadFromFile(ShaderType::FRAGMENT_SHADER, "../../examples/more_cube/sprite.frag");
				vsSource.loadFromFile(ShaderType::VERTEX_SHADER, "../../examples/more_cube/sprite.vert");

				this->_program.setStage(fsSource);
				this->_program.setStage(vsSource);
				this->_program.link();
				this->_program.use();

				this->_program.uniform("theTexture", 0);
			}
		} //namespace renderable
	} // namespace graphic
} // namespace ece
