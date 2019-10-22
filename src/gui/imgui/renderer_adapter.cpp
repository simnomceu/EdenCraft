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
#include "gui/imgui/renderer_adapter.hpp"

#include "imgui.h"
#include "utility/mathematics.hpp"

namespace ece
{
	namespace gui
	{
		namespace imgui
		{
			void RendererAdapter::init()
			{
				ImGuiIO & io = ImGui::GetIO();
				io.BackendRendererName = "imgui_impl_edencraft";

				this->_mode = PrimitiveMode::TRIANGLES;

				this->_state.blending = true;
				this->_state.blendEquation = RenderState::BlendEquationMode::FUNC_ADD;
				this->_state.sourceBlend = RenderState::BlendingFactor::SRC_ALPHA;
				this->_state.destinationBlend = RenderState::BlendingFactor::ONE_MINUS_SRC_ALPHA;
				this->_state.faceCulling = false;
				this->_state.depthTest = false;
				this->_state.scissorTest = false;
				this->_state.polygonMode = RenderState::PolygonMode::FILL;
			}

			void RendererAdapter::newFrame()
			{
				if (!this->_initialized) {
					Renderer::saveState();
					this->createDeviceObjects();
					this->_font.load();
					Renderer::restoreState();
					this->_initialized = true;
				}
			}

			void RendererAdapter::shutdown()
			{
				this->destroyDeviceObjects();
			}

			void RendererAdapter::render()
			{
				this->renderDrawLists();
			}

			void RendererAdapter::renderDrawLists()
			{
				auto draw_data = ImGui::GetDrawData();

				// Avoid rendering when minimized
				if (draw_data->DisplaySize.x <= 0 || draw_data->DisplaySize.y <= 0) {
					return;
				}

				// Backup GL state
				Renderer::saveState();

				// Setup desired GL state
				// Recreate the VAO every time (this is to easily allow multiple GL contexts to be rendered to. VAO are not shared among GL contexts)
				// The renderer would actually work without any VAO bound, but then our VertexAttrib calls would overwrite the default one currently bound.
				this->setupRenderState(draw_data);

				// Will project scissor/clipping rectangles into framebuffer space
				ImVec2 clip_off = draw_data->DisplayPos;         // (0,0) unless using multi-viewports

				// Render command lists
				for (auto n = 0; n < draw_data->CmdListsCount; ++n) {
					const ImDrawList* cmd_list = draw_data->CmdLists[n];
					std::size_t idx_buffer_offset = 0;

					// Upload vertex/index buffers
					glBufferData(GL_ARRAY_BUFFER, (GLsizeiptr)cmd_list->VtxBuffer.Size * sizeof(ImDrawVert), (const GLvoid*)cmd_list->VtxBuffer.Data, GL_STREAM_DRAW);
					glBufferData(GL_ELEMENT_ARRAY_BUFFER, (GLsizeiptr)cmd_list->IdxBuffer.Size * sizeof(ImDrawIdx), (const GLvoid*)cmd_list->IdxBuffer.Data, GL_STREAM_DRAW);

					for (auto cmd_i = 0; cmd_i < cmd_list->CmdBuffer.Size; ++cmd_i) {
						auto & pcmd = cmd_list->CmdBuffer[cmd_i];
						if (pcmd.UserCallback) {
							// User callback, registered via ImDrawList::AddCallback()
							// (ImDrawCallback_ResetRenderState is a special callback value used by the user to request the renderer to reset render state.)
							if (pcmd.UserCallback == ImDrawCallback_ResetRenderState) {
								this->setupRenderState(draw_data);
							}
							else {
								pcmd.UserCallback(cmd_list, &pcmd);
							}
						}
						else {
							// Project scissor/clipping rectangles into framebuffer space
							auto clip = ece::Rectangle<unsigned int>{ static_cast<unsigned int>(pcmd.ClipRect.x - clip_off.x), 
																	  static_cast<unsigned int>(pcmd.ClipRect.y - clip_off.y), 
																	  static_cast<unsigned int>(pcmd.ClipRect.z - clip_off.x),
																	  static_cast<unsigned int>(pcmd.ClipRect.w - clip_off.y) };

							// Apply scissor/clipping rectangle
							if (Renderer::getBackupState().clipOriginLowerLeft) {
								OpenGL::scissor(clip.x, static_cast<int>(draw_data->DisplaySize.y) - clip.height, clip.width - clip.x, clip.height - clip.y);
							}
							else {
								OpenGL::scissor(clip.x, clip.y, clip.width, clip.height); // Support for GL 4.5 rarely used glClipControl(GL_UPPER_LEFT)
							}

							// Bind texture, Draw
							OpenGL::bindTexture(TextureTarget::TEXTURE_2D, reinterpret_cast<Handle>(pcmd.TextureId));
							if constexpr (sizeof(ImDrawIdx) == 2) {
								OpenGL::drawElements<unsigned short>(this->_mode, pcmd.ElemCount, idx_buffer_offset);
							}
							else {
								OpenGL::drawElements<unsigned int>(this->_mode, pcmd.ElemCount, idx_buffer_offset);
							}
						}
						idx_buffer_offset += pcmd.ElemCount;
					}
				}

				// Restore modified GL state
				Renderer::restoreState();
			}

			void RendererAdapter::setupRenderState(ImDrawData * draw_data)
			{
				// Setup render state: alpha-blending enabled, no face culling, no depth testing, scissor enabled, polygon fill
				this->_state.apply();

				// Setup viewport, orthographic projection matrix
				// Our visible imgui space lies from draw_data->DisplayPos (top left) to draw_data->DisplayPos+data_data->DisplaySize (bottom right). DisplayMin is typically (0,0) for single viewport apps.
				OpenGL::viewport(0, 0, static_cast<int>(draw_data->DisplaySize.x), static_cast<int>(draw_data->DisplaySize.y));
				float L = draw_data->DisplayPos.x;
				float R = draw_data->DisplayPos.x + draw_data->DisplaySize.x;
				float T = draw_data->DisplayPos.y;
				float B = draw_data->DisplayPos.y + draw_data->DisplaySize.y;
				auto projection = orthographic({ L, B, R - L, T - B }, 1.0f, -1.0f); 
				this->_program->use();
				OpenGL::uniform<int, 1>(this->_program->getLocation("Texture"), { 0 });
				OpenGL::uniform<float, 4, 4>(this->_program->getLocation("ProjMtx"), false, projection);
#ifdef GL_SAMPLER_BINDING
				OpenGL::bindSampler(0, 0); // We use combined texture/sampler state. Applications using GL 3.3 may set that otherwise.
#endif
				this->_vertexArray.bind();

				// Bind vertex/index buffers and setup attributes for ImDrawVert
				OpenGL::bindBuffer(BufferType::ARRAY_BUFFER, this->_vbo);
				OpenGL::bindBuffer(BufferType::ELEMENT_ARRAY_BUFFER, this->_ibo);
				OpenGL::enableVertexAttribArray(0);
				OpenGL::enableVertexAttribArray(1);
				OpenGL::enableVertexAttribArray(2);
				OpenGL::vertexAttribPointer(0, 2, ece::renderer::opengl::DataType::FLOAT, false, sizeof(ImDrawVert), offsetof(ImDrawVert, pos));
				OpenGL::vertexAttribPointer(1, 2, ece::renderer::opengl::DataType::FLOAT, false, sizeof(ImDrawVert), offsetof(ImDrawVert, uv));
				OpenGL::vertexAttribPointer(2, 4, ece::renderer::opengl::DataType::UNSIGNED_BYTE, true, sizeof(ImDrawVert), offsetof(ImDrawVert, col));
			}

			bool RendererAdapter::createDeviceObjects()
			{
				{
					ece::ShaderStage fsSource;
					fsSource.loadFromFile(ece::ShaderStage::Type::FRAGMENT, "../../resource/shader/imgui.frag");
					ece::ShaderStage vsSource;
					vsSource.loadFromFile(ece::ShaderStage::Type::VERTEX, "../../resource/shader/imgui.vert");

					this->_program = ece::makeResource<ece::EnhancedShader>("ImGuiShader");
					this->_program->setStage(fsSource);
					this->_program->setStage(vsSource);
					this->_program->link();
				}

				// Create buffers
				this->_vbo = OpenGL::genBuffers();
				this->_ibo = OpenGL::genBuffers();

				return true;
			}

			void RendererAdapter::destroyDeviceObjects()
			{
				this->_vertexArray.terminate();
				OpenGL::deleteBuffers({ this->_vbo, this->_ibo });
				this->_vbo = 0;
				this->_ibo = 0;

				this->_font.terminate();
			}

			void RendererAdapter::draw(std::shared_ptr<Shader> /*program*/)
			{
				this->renderDrawLists();

			}
		} // namespace imgui
	} // namespace gui
} // namespace ece
