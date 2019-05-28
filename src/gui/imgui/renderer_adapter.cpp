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
#include "renderer/opengl.hpp"
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
			}

			void RendererAdapter::newFrame()
			{
				if (!this->_fontTexture) {
					Renderer::saveState();
					this->createDeviceObjects();
					this->createFontsTexture();
					Renderer::restoreState();
				}
			}

			void RendererAdapter::shutdown()
			{
				this->destroyDeviceObjects();
			}

			void RendererAdapter::render()
			{
			//	OpenGL::clearColor(0.45f, 0.55f, 0.60f, 1.00f);
			//	OpenGL::clear(Bitfield::COLOR_BUFFER_BIT);
				this->renderDrawLists(ImGui::GetDrawData());
			}

			void RendererAdapter::renderDrawLists(ImDrawData* draw_data)
			{
				// Avoid rendering when minimized, scale coordinates for retina displays (screen coordinates != framebuffer coordinates)
				int fb_width = (int)(draw_data->DisplaySize.x * draw_data->FramebufferScale.x);
				int fb_height = (int)(draw_data->DisplaySize.y * draw_data->FramebufferScale.y);
				if (fb_width <= 0 || fb_height <= 0) {
					return;
				}

				// Backup GL state
				Renderer::saveState();

				// Setup desired GL state
				// Recreate the VAO every time (this is to easily allow multiple GL contexts to be rendered to. VAO are not shared among GL contexts)
				// The renderer would actually work without any VAO bound, but then our VertexAttrib calls would overwrite the default one currently bound.
				auto vao = OpenGL::genVertexArrays();
				this->setupRenderState(draw_data, fb_width, fb_height, vao);

				// Will project scissor/clipping rectangles into framebuffer space
				ImVec2 clip_off = draw_data->DisplayPos;         // (0,0) unless using multi-viewports
				ImVec2 clip_scale = draw_data->FramebufferScale; // (1,1) unless using retina display which are often (2,2)

				// Render command lists
				for (int n = 0; n < draw_data->CmdListsCount; n++) {
					const ImDrawList* cmd_list = draw_data->CmdLists[n];
					size_t idx_buffer_offset = 0;

					// Upload vertex/index buffers
					glBufferData(GL_ARRAY_BUFFER, (GLsizeiptr)cmd_list->VtxBuffer.Size * sizeof(ImDrawVert), (const GLvoid*)cmd_list->VtxBuffer.Data, GL_STREAM_DRAW);
					glBufferData(GL_ELEMENT_ARRAY_BUFFER, (GLsizeiptr)cmd_list->IdxBuffer.Size * sizeof(ImDrawIdx), (const GLvoid*)cmd_list->IdxBuffer.Data, GL_STREAM_DRAW);

					for (int cmd_i = 0; cmd_i < cmd_list->CmdBuffer.Size; cmd_i++) {
						const ImDrawCmd* pcmd = &cmd_list->CmdBuffer[cmd_i];
						if (pcmd->UserCallback) {
							// User callback, registered via ImDrawList::AddCallback()
							// (ImDrawCallback_ResetRenderState is a special callback value used by the user to request the renderer to reset render state.)
							if (pcmd->UserCallback == ImDrawCallback_ResetRenderState) {
								this->setupRenderState(draw_data, fb_width, fb_height, vao);
							}
							else {
								pcmd->UserCallback(cmd_list, pcmd);
							}
						}
						else {
							// Project scissor/clipping rectangles into framebuffer space
							ImVec4 clip_rect;
							clip_rect.x = (pcmd->ClipRect.x - clip_off.x) * clip_scale.x;
							clip_rect.y = (pcmd->ClipRect.y - clip_off.y) * clip_scale.y;
							clip_rect.z = (pcmd->ClipRect.z - clip_off.x) * clip_scale.x;
							clip_rect.w = (pcmd->ClipRect.w - clip_off.y) * clip_scale.y;

							if (clip_rect.x < fb_width && clip_rect.y < fb_height && clip_rect.z >= 0.0f && clip_rect.w >= 0.0f) {
								// Apply scissor/clipping rectangle
								if (Renderer::getBackupState().clipOriginLowerLeft) {
									glScissor((int)clip_rect.x, (int)(fb_height - clip_rect.w), (int)(clip_rect.z - clip_rect.x), (int)(clip_rect.w - clip_rect.y));
								}
								else {
									glScissor((int)clip_rect.x, (int)clip_rect.y, (int)clip_rect.z, (int)clip_rect.w); // Support for GL 4.5 rarely used glClipControl(GL_UPPER_LEFT)
								}

								// Bind texture, Draw
								glBindTexture(GL_TEXTURE_2D, (GLuint)(intptr_t)pcmd->TextureId);
								glDrawElements(GL_TRIANGLES, (GLsizei)pcmd->ElemCount, sizeof(ImDrawIdx) == 2 ? GL_UNSIGNED_SHORT : GL_UNSIGNED_INT, reinterpret_cast<void *>((unsigned long long)idx_buffer_offset));
							}
						}
						idx_buffer_offset += pcmd->ElemCount * sizeof(ImDrawIdx);
					}
				}

				// Destroy the temporary VAO
				OpenGL::deleteVertexArrays(1, { vao });

				// Restore modified GL state
				Renderer::restoreState();
			}

			void RendererAdapter::setupRenderState(ImDrawData * draw_data, int fb_width, int fb_height, Handle vao)
			{
				// Setup render state: alpha-blending enabled, no face culling, no depth testing, scissor enabled, polygon fill
				OpenGL::enable(Capability::BLEND);
				OpenGL::blendEquation(BlendEquationMode::FUNC_ADD);
				OpenGL::blendFunc(BlendingFactor::SRC_ALPHA, BlendingFactor::ONE_MINUS_SRC_ALPHA);
				OpenGL::disable(Capability::CULL_FACE);
				OpenGL::disable(Capability::DEPTH_TEST);
				OpenGL::enable(Capability::SCISSOR_TEST);

#ifdef GL_POLYGON_MODE
				OpenGL::polygonMode(PolygonMode::FILL);
#endif

				// Setup viewport, orthographic projection matrix
				// Our visible imgui space lies from draw_data->DisplayPos (top left) to draw_data->DisplayPos+data_data->DisplaySize (bottom right). DisplayMin is typically (0,0) for single viewport apps.
				OpenGL::viewport(0, 0, fb_width, fb_height);
				float L = draw_data->DisplayPos.x;
				float R = draw_data->DisplayPos.x + draw_data->DisplaySize.x;
				float T = draw_data->DisplayPos.y;
				float B = draw_data->DisplayPos.y + draw_data->DisplaySize.y;
				auto projection = orthographic({ L, B, R - L, T - B }, 1.0f, -1.0f); 
				this->_program->use();
				OpenGL::uniform<int, 1>(this->_attribLocationTex, { 0 });
				OpenGL::uniform<float, 4, 4>(this->_attribLocationProjMtx, false, projection);
#ifdef GL_SAMPLER_BINDING
				OpenGL::bindSampler(0, 0); // We use combined texture/sampler state. Applications using GL 3.3 may set that otherwise.
#endif
				OpenGL::bindVertexArray(vao);

				// Bind vertex/index buffers and setup attributes for ImDrawVert
				OpenGL::bindBuffer(BufferType::ARRAY_BUFFER, this->_vbo);
				OpenGL::bindBuffer(BufferType::ELEMENT_ARRAY_BUFFER, this->_ibo);
				OpenGL::enableVertexAttribArray(this->_attribLocationVtxPos);
				OpenGL::enableVertexAttribArray(this->_attribLocationVtxUV);
				OpenGL::enableVertexAttribArray(this->_attribLocationVtxColor);
				OpenGL::vertexAttribPointer(this->_attribLocationVtxPos, 2, DataType::FLOAT, false, sizeof(ImDrawVert), reinterpret_cast<unsigned long long>(&(((ImDrawVert*)0)->pos)));
				OpenGL::vertexAttribPointer(this->_attribLocationVtxUV, 2, DataType::FLOAT, false, sizeof(ImDrawVert), reinterpret_cast<unsigned long long>(&(((ImDrawVert*)0)->uv)));
				OpenGL::vertexAttribPointer(this->_attribLocationVtxColor, 4, DataType::UNSIGNED_BYTE, true, sizeof(ImDrawVert), reinterpret_cast<unsigned long long>(&(((ImDrawVert*)0)->col)));
			}

			bool RendererAdapter::createFontsTexture()
			{
				// Build texture atlas
				ImGuiIO& io = ImGui::GetIO();
				unsigned char* pixels;
				int width, height;
				io.Fonts->GetTexDataAsRGBA32(&pixels, &width, &height);   // Load as RGBA 32-bits (75% of the memory is wasted, but default font is so small) because it is more likely to be compatible with user's existing shaders. If your ImTextureId represent a higher-level concept than just a GL texture id, consider calling GetTexDataAsAlpha8() instead to save on GPU memory.

				// Upload texture to graphics system
				this->_fontTexture = OpenGL::genTexture();
				OpenGL::bindTexture(TextureTarget::TEXTURE_2D, this->_fontTexture);
				OpenGL::texParameter(TextureTarget::TEXTURE_2D, TextureParameter::TEXTURE_MIN_FILTER, GL_LINEAR);
				OpenGL::texParameter(TextureTarget::TEXTURE_2D, TextureParameter::TEXTURE_MAG_FILTER, GL_LINEAR);
#ifdef GL_UNPACK_ROW_LENGTH
				OpenGL::pixelStore(PixelParameter::UNPACK_ROW_LENGTH, 0);
#endif
				OpenGL::texImage2D(TextureTypeTarget::TEXTURE_2D, 0, PixelInternalFormat::RGBA, width, height, PixelFormat::RGBA, PixelDataType::UNSIGNED_BYTE, pixels);

				// Store our identifier
				io.Fonts->TexID = reinterpret_cast<ImTextureID>((unsigned long long)this->_fontTexture);

				return true;
			}

			void RendererAdapter::destroyFontsTexture()
			{
				if (this->_fontTexture) {
					ImGuiIO& io = ImGui::GetIO();
					OpenGL::deleteTextures({ this->_fontTexture });
					io.Fonts->TexID = 0;
					this->_fontTexture = 0;
				}
			}

			bool RendererAdapter::createDeviceObjects()
			{
				{
					ece::ShaderStage fsSource;
					fsSource.loadFromFile(ece::ShaderStage::Type::FRAGMENT, "../../resource/shader/imgui.frag");
					ece::ShaderStage vsSource;
					vsSource.loadFromFile(ece::ShaderStage::Type::VERTEX, "../../resource/shader/imgui.vert");

					this->_program = std::make_shared<ece::EnhancedShader>();
					this->_program->setStage(fsSource);
					this->_program->setStage(vsSource);
					this->_program->link();
				}

				this->_attribLocationTex = this->_program->getLocation("Texture");
				this->_attribLocationProjMtx = this->_program->getLocation("ProjMtx");
				this->_attribLocationVtxPos = 0;
				this->_attribLocationVtxUV = 1;
				this->_attribLocationVtxColor = 2;

				// Create buffers
				this->_vbo = OpenGL::genBuffers();
				this->_ibo = OpenGL::genBuffers();

				return true;
			}

			void RendererAdapter::destroyDeviceObjects()
			{
				OpenGL::deleteBuffers({ this->_vbo, this->_ibo });
				this->_vbo = 0;
				this->_ibo = 0;

				this->_program->terminate();

				this->destroyFontsTexture();
			}
		} // namespace imgui
	} // namespace gui
} // namespace ece
