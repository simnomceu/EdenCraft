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
#include "renderer/image.hpp"
#include "renderer/rendering.hpp"

#ifdef _MSC_VER
#undef max
#undef min
#endif

namespace ece
{
	namespace graphic
	{
		namespace renderable
		{
			Sprite::Sprite(const Texture2D::Texture2DReference & texture, const Rectangle<float> & bounds, const Rectangle<float> & textureClip) : Renderable(), _texture(texture), _textureClip(textureClip), _bounds(bounds), _vertices(), _index()
			{
				if (this->_bounds == Rectangle<float>()) {
					this->_bounds = Rectangle<float>(0.0f, 0.0f, static_cast<float>(this->_texture->getWidth()), static_cast<float>(this->_texture->getHeight()));
				}
				if (this->_textureClip == Rectangle<float>()) {
					this->_textureClip = Rectangle<float>(0.0f, 0.0f, static_cast<float>(this->_texture->getWidth()), static_cast<float>(this->_texture->getHeight()));
				}

				this->_mode = PrimitiveMode::TRIANGLES;

				this->_vertexArray.bind();

				renderer::buffer::BufferLayout layout;
				layout.add<float>(2, false, false, false);
				layout.add<float>(2, false, false, false);

				auto & vertices = this->_vertices.data();
				vertices.push_back(Sprite::Vertex{ { 0.0f, 0.0f },																						{ this->_textureClip.getX() / this->_texture->getWidth(), this->_textureClip.getY() / this->_texture->getHeight() } });
				vertices.push_back(Sprite::Vertex{ { 0.0f, static_cast<float>(this->_texture->getHeight()) },											{ this->_textureClip.getX() / this->_texture->getWidth(), (this->_textureClip.getY() + this->_textureClip.getHeight()) / this->_texture->getHeight() } });
				vertices.push_back(Sprite::Vertex{ { static_cast<float>(this->_texture->getWidth()), static_cast<float>(this->_texture->getHeight()) }, { (this->_textureClip.getX() + this->_textureClip.getWidth()) / this->_texture->getWidth(), (this->_textureClip.getY() + this->_textureClip.getHeight()) / this->_texture->getHeight() } });
				vertices.push_back(Sprite::Vertex{ { static_cast<float>(this->_texture->getWidth()), 0.0f },											{ (this->_textureClip.getX() + this->_textureClip.getWidth()) / this->_texture->getWidth(), this->_textureClip.getY() / this->_texture->getHeight() } });
				this->_vertices.update();
				this->_vertexArray.attach(this->_vertices, layout);

				auto & indices = this->_index.data();
				indices.push_back(Sprite::Face{ 0, 3, 1 });
				indices.push_back(Sprite::Face{ 1, 3, 2 });
				this->_index.update();


				// TODO: fix computation of Sprite clipping/transforming.
				// ProjectionMatrix = { BaseResolution => ScreenResolution => [-1 ; 1] }
				// ModelMatrix = Rotate * Translate * Scale (not sure the order ?)
				// Rotate : applied independently
				// Translate = sprites.bounds.xy (before projection)
				// Scale = sprites.bounds.wh / sprite.wh (before projection)
				// sprite.wh = sprite.clip.wh (before projection)
				// TextureCoordinate = sprites.clip.xywh / sprites.textures.xywh (has to be between 0 and 1)
				// Coordinate = sprites.textures.xywh (before everything else)
			}

			void Sprite::draw(std::shared_ptr<Shader> program)
			{
				program->use();
				this->_vertexArray.bind();

				this->_texture->active(0);
				this->_texture->bind(Texture::Target::TEXTURE_2D);
				program->bind(std::make_shared<Uniform<int>>("theTexture", 0), "theTexture");

				auto projection = ece::translate({ -1.0f, -1.0f, 0.0f }) * ece::scale({ 1.0f / this->_texture->getWidth(), 1.0f / this->_texture->getHeight(), 1.0f });
				OpenGL::uniform<float, 4, 4>(glGetUniformLocation(program->getHandle(), "projection"), true, projection);

				this->_model.setIdentity();
				this->applyTransformation(ece::scale({ this->_bounds.getWidth() / this->_textureClip.getWidth(), this->_bounds.getHeight() / this->_textureClip.getHeight(), 1.0f }));
				this->applyTransformation(ece::rotate(FRONT, -static_cast<float>(PI) / 4.0f));
				this->applyTransformation(ece::translate({ this->_bounds.getX(), this->_bounds.getY(), 0.0f }));

				this->_index.bind();
				OpenGL::drawElements(this->_mode, this->_index.size() * 3, renderer::opengl::DataType::UNSIGNED_INT, 0);
			}
		} //namespace renderable
	} // namespace graphic
} // namespace ece
