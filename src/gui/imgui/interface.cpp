/*

	oooooooooooo       .o8                          .oooooo.                       .o88o.     .
	`888'     `8      "888                         d8P'  `Y8b                      888 `"   .o8
	 888          .oooo888   .ooooo.  ooo. .oo.   888          oooo d8b  .oooo.   o888oo  .o888oo
	 888oooo8    d88' `888  d88' `88b `888P"Y88b  888          `888""8P `P  )88b   888      888
	 888    "    888   888  888ooo888  888   888  888           888      .oP"888   888      888
	 888       o 888   888  888    .o  888   888  `88b    ooo   888     d8(  888   888      888 .
	o888ooooood8 `Y8bod88P" `Y8bod8P' o888o o888o  `Y8bood8P'  d888b    `Y888""8o o888o     "888"

															  .oooooo.    ooooo     ooo ooooo
															 d8P'  `Y8b   `888'     `8' `888'
															888            888       8   888
															888            888       8   888
															888     ooooo  888       8   888
															`88.    .88'   `88.    .8'   888
															 `Y8bood8P'      `YbodP'    o888o


				This file is part of EdenCraft Engine - GUI module.
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

#include "gui/pch.hpp"
#include "gui/imgui/interface.hpp"
#include "imgui.h"

namespace ece
{
	namespace gui
	{
		namespace imgui
		{
			Interface::Interface() noexcept: Renderable(), /*_vbo(), _ibo(), */_displaySize(), _projection()
			{
				this->_mode = PrimitiveMode::TRIANGLES;

				this->_state.blending = true;
				this->_state.blendEquation = BlendEquationMode::FUNC_ADD;
				this->_state.sourceBlend = BlendingFactor::SRC_ALPHA;
				this->_state.destinationBlend = BlendingFactor::ONE_MINUS_SRC_ALPHA;
				this->_state.faceCulling = false;
				this->_state.depthTest = false;
				this->_state.scissorTest = false;
				this->_state.polygonMode = PolygonMode::FILL;
			}
			
			Interface::~Interface() noexcept
			{
			}

			void Interface::prepare()
			{
				auto layout = BufferLayout();
				layout.add<float>(2, false, false, false);
				layout.add<float>(2, false, false, false);
				layout.add<unsigned char>(4, false, false, false);

			//	this->_vertexArray.attach(this->_vbo, layout);
			}
			
			void Interface::draw(std::shared_ptr<Shader> program)
			{
				this->update();
				if (this->_displaySize[0] <= 0 || this->_displaySize[1] <= 0) {
					return;
				}

				// Backup GL state
				Renderer::saveState();

				this->_state.apply();
				OpenGL::viewport(0, 0, this->_displaySize[0], this->_displaySize[1]);
				program->use();
				OpenGL::uniform<int, 1>(program->getLocation("Texture"), { 0 });
				OpenGL::uniform<float, 4, 4>(program->getLocation("ProjMtx"), false, this->_projection);
				OpenGL::bindSampler(0, 0);

				// DRAW
				this->_vertexArray.bind();
			//	this->_ibo.bind();

				// Restore modified GL state
				Renderer::restoreState();
			}

			void Interface::update()
			{
				auto draw_data = ImGui::GetDrawData();

				this->_displaySize = { static_cast<int>(draw_data->DisplaySize.x), static_cast<int>(draw_data->DisplaySize.y) };

				float L = draw_data->DisplayPos.x;
				float R = draw_data->DisplayPos.x + this->_displaySize[0];
				float T = draw_data->DisplayPos.y;
				float B = draw_data->DisplayPos.y + this->_displaySize[1];
				this->_projection = orthographic({ L, B, R - L, T - B }, 1.0f, -1.0f);
			}
		} // namespace imgui
	} // namespace gui
} // namespace ece