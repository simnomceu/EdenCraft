/*

	oooooooooooo       .o8                          .oooooo.                       .o88o.     .
	`888'     `8      "888                         d8P'  `Y8b                      888 `"   .o8
	 888          .oooo888   .ooooo.  ooo. .oo.   888          oooo d8b  .oooo.   o888oo  .o888oo
	 888oooo8    d88' `888  d88' `88b `888P"Y88b  888          `888""8P `P  )88b   888      888
	 888    "    888   888  888ooo888  888   888  888           888      .oP"888   888      888
	 888       o 888   888  888    .o  888   888  `88b    ooo   888     d8(  888   888      888 .
	o888ooooood8 `Y8bod88P" `Y8bod8P' o888o o888o  `Y8bood8P'  d888b    `Y888""8o o888o     "888"

															ooooooooo.                               .o8
															`888   `Y88.                            "888
															 888   .d88'  .ooooo.  ooo. .oo.    .oooo888   .ooooo.  oooo d8b  .ooooo.  oooo d8b
															 888ooo88P'  d88' `88b `888P"Y88b  d88' `888  d88' `88b `888""8P d88' `88b `888""8P
															 888`88b.    888ooo888  888   888  888   888  888ooo888  888     888ooo888  888
															 888  `88b.  888    .o  888   888  888   888  888    .o  888     888    .o  888
															o888o  o888o `Y8bod8P' o888o o888o `Y8bod88P" `Y8bod8P' d888b    `Y8bod8P' d888b



				This file is part of EdenCraft Engine - Renderer module.
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

#include "renderer/pch.hpp"
#include "renderer/rendering/renderer.hpp"
#include "renderer/opengl.hpp"

namespace ece
{
	namespace renderer
	{
		namespace rendering
		{
			std::weak_ptr<RenderTarget> Renderer::_currentTarget;
			std::weak_ptr<RenderContext> Renderer::_currentContext;
			std::map<TextureTarget, std::weak_ptr<Texture>> Renderer::_currentTextures;
			Renderer::State Renderer::_backup;

			void Renderer::setCurrentTarget(const std::weak_ptr<RenderTarget> & target) { Renderer::_currentTarget = target; }

			auto Renderer::getCurrentTarget() -> std::weak_ptr<RenderTarget> { return Renderer::_currentTarget; }

			void Renderer::setCurrentContext(const std::weak_ptr<RenderContext> & context) { Renderer::_currentContext = context; }

			auto Renderer::getCurrentContext() -> std::weak_ptr<RenderContext> { return Renderer::_currentContext; }

			void Renderer::setCurrentTexture(TextureTarget target, const std::weak_ptr<Texture> & texture) { Renderer::_currentTextures[target] = texture; }

			auto Renderer::getCurrentTexture(TextureTarget target) -> std::weak_ptr<Texture> { return Renderer::_currentTextures[target]; }

			auto Renderer::isInitialized() noexcept -> bool { return !Renderer::_currentContext.expired(); }

			void Renderer::saveState()
			{
				Renderer::_backup.activeTexture = OpenGL::getInteger(Parameter::ACTIVE_TEXTURE)[0] - static_cast<int>(TextureUnit::TEXTURE0);
				OpenGL::activeTexture(0);
				Renderer::_backup.currentProgram = OpenGL::getInteger(Parameter::CURRENT_PROGRAM)[0];
				Renderer::_backup.textureBinding2D = OpenGL::getInteger(Parameter::TEXTURE_BINDING_2D)[0];
#ifdef GL_SAMPLER_BINDING
				Renderer::_backup.samplerBinding = OpenGL::getInteger(Parameter::SAMPLER_BINDING)[0];
#endif
				Renderer::_backup.arrayBufferBinding = OpenGL::getInteger(Parameter::ARRAY_BUFFER_BINDING)[0];
				Renderer::_backup.vertexArrayBinding = OpenGL::getInteger(Parameter::VERTEX_ARRAY_BINDING)[0];

				auto viewport = OpenGL::getInteger(Parameter::VIEWPORT); std::copy(viewport.begin(), viewport.end(), Renderer::_backup.viewport.begin());
				auto scissorBox = OpenGL::getInteger(Parameter::SCISSOR_BOX); std::copy(scissorBox.begin(), scissorBox.end(), Renderer::_backup.scissorBox.begin());
				Renderer::_backup.blendSrcRGB = static_cast<BlendingFactor>(OpenGL::getInteger(Parameter::BLEND_SRC_RGB)[0]);
				Renderer::_backup.blendDstRGB = static_cast<BlendingFactor>(OpenGL::getInteger(Parameter::BLEND_DST_RGB)[0]);
				Renderer::_backup.blendSrcAlpha = static_cast<BlendingFactor>(OpenGL::getInteger(Parameter::BLEND_SRC_ALPHA)[0]);
				Renderer::_backup.blendDstAlpha = static_cast<BlendingFactor>(OpenGL::getInteger(Parameter::BLEND_DST_ALPHA)[0]);
				Renderer::_backup.blendEquationRGB = static_cast<BlendEquationMode>(OpenGL::getInteger(Parameter::BLEND_EQUATION_RGB)[0]);
				Renderer::_backup.blendEquationAlpha = static_cast<BlendEquationMode>(OpenGL::getInteger(Parameter::BLEND_EQUATION_ALPHA)[0]);
				Renderer::_backup.clipOriginLowerLeft = true;
#if defined(GL_CLIP_ORIGIN) && !defined(__APPLE__)
				Renderer::_backup.clipOrigin = static_cast<ClipControl>(OpenGL::getInteger(Parameter::CLIP_ORIGIN)[0]); // Support for GL 4.5's glClipControl(GL_UPPER_LEFT)
				if (Renderer::_backup.clipOrigin == ClipControl::UPPER_LEFT) {
					Renderer::_backup.clipOriginLowerLeft = false;
				}
#endif
				Renderer::_backup.renderState = RenderState::getCurrentstate();
			}

			void Renderer::restoreState()
			{
				OpenGL::useProgram(Renderer::_backup.currentProgram);
				OpenGL::bindTexture(TextureTarget::TEXTURE_2D, Renderer::_backup.textureBinding2D);
#ifdef GL_SAMPLER_BINDING
				OpenGL::bindSampler(0, Renderer::_backup.samplerBinding);
#endif
				OpenGL::activeTexture(Renderer::_backup.activeTexture);
#ifndef IMGUI_IMPL_OPENGL_ES2
				OpenGL::bindVertexArray(Renderer::_backup.vertexArrayBinding);
#endif
				OpenGL::bindBuffer(BufferType::ARRAY_BUFFER, Renderer::_backup.arrayBufferBinding);
				OpenGL::blendEquationSeparate(Renderer::_backup.blendEquationRGB, Renderer::_backup.blendEquationAlpha);
				OpenGL::blendFuncSeparate(Renderer::_backup.blendSrcRGB, Renderer::_backup.blendDstRGB, Renderer::_backup.blendSrcAlpha, Renderer::_backup.blendDstAlpha);

				OpenGL::viewport(Renderer::_backup.viewport[0], Renderer::_backup.viewport[1], (GLsizei)Renderer::_backup.viewport[2], (GLsizei)Renderer::_backup.viewport[3]);
				OpenGL::scissor(Renderer::_backup.scissorBox[0], Renderer::_backup.scissorBox[1], (GLsizei)Renderer::_backup.scissorBox[2], (GLsizei)Renderer::_backup.scissorBox[3]);
			
				Renderer::_backup.renderState.apply();
			}

			auto Renderer::getBackupState() -> Renderer::State { return Renderer::_backup; }
		} // rendering
	} // renderer
} // ece
