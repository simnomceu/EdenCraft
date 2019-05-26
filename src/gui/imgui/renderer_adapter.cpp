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

				// dummy call for test
				GLint current_texture;
				glGetIntegerv(GL_TEXTURE_BINDING_2D, &current_texture);
			}

			void RendererAdapter::newFrame()
			{
				if (!this->_fontTexture) {
					this->createDeviceObjects();
				}
			}

			void RendererAdapter::shutdown()
			{
				this->destroyDeviceObjects();
			}

			void RendererAdapter::render()
			{
				ImVec4 clear_color = ImVec4(0.45f, 0.55f, 0.60f, 1.00f);
				glClearColor(clear_color.x, clear_color.y, clear_color.z, clear_color.w);
				glClear(GL_COLOR_BUFFER_BIT);
				this->renderDrawLists(ImGui::GetDrawData());
			}

			void RendererAdapter::renderDrawLists(ImDrawData* draw_data)
			{
				// Avoid rendering when minimized, scale coordinates for retina displays (screen coordinates != framebuffer coordinates)
				int fb_width = (int)(draw_data->DisplaySize.x * draw_data->FramebufferScale.x);
				int fb_height = (int)(draw_data->DisplaySize.y * draw_data->FramebufferScale.y);
				if (fb_width <= 0 || fb_height <= 0)
					return;

				// Backup GL state
				GLenum last_active_texture; glGetIntegerv(GL_ACTIVE_TEXTURE, (GLint*)&last_active_texture);
				glActiveTexture(GL_TEXTURE0);
				GLint last_program; glGetIntegerv(GL_CURRENT_PROGRAM, &last_program);
				GLint last_texture; glGetIntegerv(GL_TEXTURE_BINDING_2D, &last_texture);
#ifdef GL_SAMPLER_BINDING
				GLint last_sampler; glGetIntegerv(GL_SAMPLER_BINDING, &last_sampler);
#endif
				GLint last_array_buffer; glGetIntegerv(GL_ARRAY_BUFFER_BINDING, &last_array_buffer);
#ifndef IMGUI_IMPL_OPENGL_ES2
				GLint last_vertex_array_object; glGetIntegerv(GL_VERTEX_ARRAY_BINDING, &last_vertex_array_object);
#endif
#ifdef GL_POLYGON_MODE
				GLint last_polygon_mode[2]; glGetIntegerv(GL_POLYGON_MODE, last_polygon_mode);
#endif
				GLint last_viewport[4]; glGetIntegerv(GL_VIEWPORT, last_viewport);
				GLint last_scissor_box[4]; glGetIntegerv(GL_SCISSOR_BOX, last_scissor_box);
				GLenum last_blend_src_rgb; glGetIntegerv(GL_BLEND_SRC_RGB, (GLint*)&last_blend_src_rgb);
				GLenum last_blend_dst_rgb; glGetIntegerv(GL_BLEND_DST_RGB, (GLint*)&last_blend_dst_rgb);
				GLenum last_blend_src_alpha; glGetIntegerv(GL_BLEND_SRC_ALPHA, (GLint*)&last_blend_src_alpha);
				GLenum last_blend_dst_alpha; glGetIntegerv(GL_BLEND_DST_ALPHA, (GLint*)&last_blend_dst_alpha);
				GLenum last_blend_equation_rgb; glGetIntegerv(GL_BLEND_EQUATION_RGB, (GLint*)&last_blend_equation_rgb);
				GLenum last_blend_equation_alpha; glGetIntegerv(GL_BLEND_EQUATION_ALPHA, (GLint*)&last_blend_equation_alpha);
				GLboolean last_enable_blend = glIsEnabled(GL_BLEND);
				GLboolean last_enable_cull_face = glIsEnabled(GL_CULL_FACE);
				GLboolean last_enable_depth_test = glIsEnabled(GL_DEPTH_TEST);
				GLboolean last_enable_scissor_test = glIsEnabled(GL_SCISSOR_TEST);
				bool clip_origin_lower_left = true;
#if defined(GL_CLIP_ORIGIN) && !defined(__APPLE__)
				GLenum last_clip_origin = 0; glGetIntegerv(GL_CLIP_ORIGIN, (GLint*)&last_clip_origin); // Support for GL 4.5's glClipControl(GL_UPPER_LEFT)
				if (last_clip_origin == GL_UPPER_LEFT)
					clip_origin_lower_left = false;
#endif

				// Setup desired GL state
				// Recreate the VAO every time (this is to easily allow multiple GL contexts to be rendered to. VAO are not shared among GL contexts)
				// The renderer would actually work without any VAO bound, but then our VertexAttrib calls would overwrite the default one currently bound.
				GLuint vertex_array_object = 0;
#ifndef IMGUI_IMPL_OPENGL_ES2
				glGenVertexArrays(1, &vertex_array_object);
#endif
				this->setupRenderState(draw_data, fb_width, fb_height, vertex_array_object);

				// Will project scissor/clipping rectangles into framebuffer space
				ImVec2 clip_off = draw_data->DisplayPos;         // (0,0) unless using multi-viewports
				ImVec2 clip_scale = draw_data->FramebufferScale; // (1,1) unless using retina display which are often (2,2)

				// Render command lists
				for (int n = 0; n < draw_data->CmdListsCount; n++)
				{
					const ImDrawList* cmd_list = draw_data->CmdLists[n];
					size_t idx_buffer_offset = 0;

					// Upload vertex/index buffers
					glBufferData(GL_ARRAY_BUFFER, (GLsizeiptr)cmd_list->VtxBuffer.Size * sizeof(ImDrawVert), (const GLvoid*)cmd_list->VtxBuffer.Data, GL_STREAM_DRAW);
					glBufferData(GL_ELEMENT_ARRAY_BUFFER, (GLsizeiptr)cmd_list->IdxBuffer.Size * sizeof(ImDrawIdx), (const GLvoid*)cmd_list->IdxBuffer.Data, GL_STREAM_DRAW);

					for (int cmd_i = 0; cmd_i < cmd_list->CmdBuffer.Size; cmd_i++)
					{
						const ImDrawCmd* pcmd = &cmd_list->CmdBuffer[cmd_i];
						if (pcmd->UserCallback != NULL)
						{
							// User callback, registered via ImDrawList::AddCallback()
							// (ImDrawCallback_ResetRenderState is a special callback value used by the user to request the renderer to reset render state.)
							if (pcmd->UserCallback == ImDrawCallback_ResetRenderState)
								this->setupRenderState(draw_data, fb_width, fb_height, vertex_array_object);
							else
								pcmd->UserCallback(cmd_list, pcmd);
						}
						else
						{
							// Project scissor/clipping rectangles into framebuffer space
							ImVec4 clip_rect;
							clip_rect.x = (pcmd->ClipRect.x - clip_off.x) * clip_scale.x;
							clip_rect.y = (pcmd->ClipRect.y - clip_off.y) * clip_scale.y;
							clip_rect.z = (pcmd->ClipRect.z - clip_off.x) * clip_scale.x;
							clip_rect.w = (pcmd->ClipRect.w - clip_off.y) * clip_scale.y;

							if (clip_rect.x < fb_width && clip_rect.y < fb_height && clip_rect.z >= 0.0f && clip_rect.w >= 0.0f)
							{
								// Apply scissor/clipping rectangle
								if (clip_origin_lower_left)
									glScissor((int)clip_rect.x, (int)(fb_height - clip_rect.w), (int)(clip_rect.z - clip_rect.x), (int)(clip_rect.w - clip_rect.y));
								else
									glScissor((int)clip_rect.x, (int)clip_rect.y, (int)clip_rect.z, (int)clip_rect.w); // Support for GL 4.5 rarely used glClipControl(GL_UPPER_LEFT)

								// Bind texture, Draw
								glBindTexture(GL_TEXTURE_2D, (GLuint)(intptr_t)pcmd->TextureId);
								glDrawElements(GL_TRIANGLES, (GLsizei)pcmd->ElemCount, sizeof(ImDrawIdx) == 2 ? GL_UNSIGNED_SHORT : GL_UNSIGNED_INT, reinterpret_cast<void *>(idx_buffer_offset));
							}
						}
						idx_buffer_offset += pcmd->ElemCount * sizeof(ImDrawIdx);
					}
				}

				// Destroy the temporary VAO
#ifndef IMGUI_IMPL_OPENGL_ES2
				glDeleteVertexArrays(1, &vertex_array_object);
#endif

				// Restore modified GL state
				glUseProgram(last_program);
				glBindTexture(GL_TEXTURE_2D, last_texture);
#ifdef GL_SAMPLER_BINDING
				glBindSampler(0, last_sampler);
#endif
				glActiveTexture(last_active_texture);
#ifndef IMGUI_IMPL_OPENGL_ES2
				glBindVertexArray(last_vertex_array_object);
#endif
				glBindBuffer(GL_ARRAY_BUFFER, last_array_buffer);
				glBlendEquationSeparate(last_blend_equation_rgb, last_blend_equation_alpha);
				glBlendFuncSeparate(last_blend_src_rgb, last_blend_dst_rgb, last_blend_src_alpha, last_blend_dst_alpha);
				if (last_enable_blend) glEnable(GL_BLEND); else glDisable(GL_BLEND);
				if (last_enable_cull_face) glEnable(GL_CULL_FACE); else glDisable(GL_CULL_FACE);
				if (last_enable_depth_test) glEnable(GL_DEPTH_TEST); else glDisable(GL_DEPTH_TEST);
				if (last_enable_scissor_test) glEnable(GL_SCISSOR_TEST); else glDisable(GL_SCISSOR_TEST);
#ifdef GL_POLYGON_MODE
				glPolygonMode(GL_FRONT_AND_BACK, (GLenum)last_polygon_mode[0]);
#endif
				glViewport(last_viewport[0], last_viewport[1], (GLsizei)last_viewport[2], (GLsizei)last_viewport[3]);
				glScissor(last_scissor_box[0], last_scissor_box[1], (GLsizei)last_scissor_box[2], (GLsizei)last_scissor_box[3]);
			}

			void RendererAdapter::setupRenderState(ImDrawData * draw_data, int fb_width, int fb_height, unsigned int vertex_array_object)
			{
				// Setup render state: alpha-blending enabled, no face culling, no depth testing, scissor enabled, polygon fill
				glEnable(GL_BLEND);
				glBlendEquation(GL_FUNC_ADD);
				glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
				glDisable(GL_CULL_FACE);
				glDisable(GL_DEPTH_TEST);
				glEnable(GL_SCISSOR_TEST);
#ifdef GL_POLYGON_MODE
				glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
#endif

				// Setup viewport, orthographic projection matrix
				// Our visible imgui space lies from draw_data->DisplayPos (top left) to draw_data->DisplayPos+data_data->DisplaySize (bottom right). DisplayMin is typically (0,0) for single viewport apps.
				glViewport(0, 0, (GLsizei)fb_width, (GLsizei)fb_height);
				float L = draw_data->DisplayPos.x;
				float R = draw_data->DisplayPos.x + draw_data->DisplaySize.x;
				float T = draw_data->DisplayPos.y;
				float B = draw_data->DisplayPos.y + draw_data->DisplaySize.y;
				const float ortho_projection[4][4] =
				{
					{ 2.0f / (R - L),   0.0f,         0.0f,   0.0f },
					{ 0.0f,         2.0f / (T - B),   0.0f,   0.0f },
					{ 0.0f,         0.0f,        -1.0f,   0.0f },
					{ (R + L) / (L - R),  (T + B) / (B - T),  0.0f,   1.0f },
				};
				this->_program->use();
				glUniform1i(this->_attribLocationTex, 0);
				glUniformMatrix4fv(this->_attribLocationProjMtx, 1, GL_FALSE, &ortho_projection[0][0]);
#ifdef GL_SAMPLER_BINDING
				glBindSampler(0, 0); // We use combined texture/sampler state. Applications using GL 3.3 may set that otherwise.
#endif

				(void)vertex_array_object;
#ifndef IMGUI_IMPL_OPENGL_ES2
				glBindVertexArray(vertex_array_object);
#endif

				// Bind vertex/index buffers and setup attributes for ImDrawVert
				glBindBuffer(GL_ARRAY_BUFFER, this->_vboHandle);
				glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, this->_elementsHandle);
				glEnableVertexAttribArray(this->_attribLocationVtxPos);
				glEnableVertexAttribArray(this->_attribLocationVtxUV);
				glEnableVertexAttribArray(this->_attribLocationVtxColor);
				glVertexAttribPointer(this->_attribLocationVtxPos, 2, GL_FLOAT, GL_FALSE, sizeof(ImDrawVert), (GLvoid*)reinterpret_cast<long>(&(((ImDrawVert*)0)->pos)));
				glVertexAttribPointer(this->_attribLocationVtxUV, 2, GL_FLOAT, GL_FALSE, sizeof(ImDrawVert), (GLvoid*)reinterpret_cast<long>(&(((ImDrawVert*)0)->uv)));
				glVertexAttribPointer(this->_attribLocationVtxColor, 4, GL_UNSIGNED_BYTE, GL_TRUE, sizeof(ImDrawVert), (GLvoid*)reinterpret_cast<long>(&(((ImDrawVert*)0)->col)));
			}

			bool RendererAdapter::createFontsTexture()
			{
				// Build texture atlas
				ImGuiIO& io = ImGui::GetIO();
				unsigned char* pixels;
				int width, height;
				io.Fonts->GetTexDataAsRGBA32(&pixels, &width, &height);   // Load as RGBA 32-bits (75% of the memory is wasted, but default font is so small) because it is more likely to be compatible with user's existing shaders. If your ImTextureId represent a higher-level concept than just a GL texture id, consider calling GetTexDataAsAlpha8() instead to save on GPU memory.

				// Upload texture to graphics system
				GLint last_texture;
				glGetIntegerv(GL_TEXTURE_BINDING_2D, &last_texture);
				glGenTextures(1, &this->_fontTexture);
				glBindTexture(GL_TEXTURE_2D, this->_fontTexture);
				glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
				glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
#ifdef GL_UNPACK_ROW_LENGTH
				glPixelStorei(GL_UNPACK_ROW_LENGTH, 0);
#endif
				glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, pixels);

				// Store our identifier
				io.Fonts->TexID = (ImTextureID)(intptr_t)this->_fontTexture;

				// Restore state
				glBindTexture(GL_TEXTURE_2D, last_texture);

				return true;
			}

			void RendererAdapter::destroyFontsTexture()
			{
				if (this->_fontTexture)
				{
					ImGuiIO& io = ImGui::GetIO();
					glDeleteTextures(1, &this->_fontTexture);
					io.Fonts->TexID = 0;
					this->_fontTexture = 0;
				}
			}

			bool RendererAdapter::createDeviceObjects()
			{
				// Backup GL state
				GLint last_texture, last_array_buffer;
				glGetIntegerv(GL_TEXTURE_BINDING_2D, &last_texture);
				glGetIntegerv(GL_ARRAY_BUFFER_BINDING, &last_array_buffer);
#ifndef IMGUI_IMPL_OPENGL_ES2
				GLint last_vertex_array;
				glGetIntegerv(GL_VERTEX_ARRAY_BINDING, &last_vertex_array);
#endif

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
				glGenBuffers(1, &this->_vboHandle);
				glGenBuffers(1, &this->_elementsHandle);

				this->createFontsTexture();

				// Restore modified GL state
				glBindTexture(GL_TEXTURE_2D, last_texture);
				glBindBuffer(GL_ARRAY_BUFFER, last_array_buffer);
#ifndef IMGUI_IMPL_OPENGL_ES2
				glBindVertexArray(last_vertex_array);
#endif

				return true;
			}

			void RendererAdapter::destroyDeviceObjects()
			{
				if (this->_vboHandle) glDeleteBuffers(1, &this->_vboHandle);
				if (this->_elementsHandle) glDeleteBuffers(1, &this->_elementsHandle);
				this->_vboHandle = this->_elementsHandle = 0;

				this->_program->terminate();

				this->destroyFontsTexture();
			}
		} // namespace imgui
	} // namespace gui
} // namespace ece
