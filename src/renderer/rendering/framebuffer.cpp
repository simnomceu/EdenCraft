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
#include "renderer/rendering/framebuffer.hpp"
#include "renderer/opengl.hpp"

namespace ece
{
	namespace renderer
	{
		namespace rendering
		{
			Framebuffer::Framebuffer(const Specification & specification) noexcept : _handle(NULL_HANDLE), _specification(specification)
			{
			}

			Framebuffer::~Framebuffer() noexcept
			{
				this->terminate();
			}

			void Framebuffer::bind()
			{
				OpenGL::bindFramebuffer(getFramebufferTarget(this->_specification.target), this->_handle);
				OpenGL::viewport(0, 0, this->_specification.width, this->_specification.height);
				this->setCurrent();
			}

			void Framebuffer::unbind()
			{
				OpenGL::bindFramebuffer(getFramebufferTarget(this->_specification.target), NULL_HANDLE);
			}

			void Framebuffer::invalidate()
			{
				this->terminate();

				this->_handle = OpenGL::createFramebuffers(1)[0];
				this->bind();

				// Color attachments
				auto it = unsigned short int{ 0 };
				for (auto & color : this->_specification.colors) {
					this->_colors.emplace_back();
					this->_colors.back()->bind();
					this->_colors.back()->create();
					this->_colors.back()->setParameter<int>(Texture::Parameter::MIN_FILTER, GL_LINEAR);
					this->_colors.back()->setParameter<int>(Texture::Parameter::MAG_FILTER, GL_LINEAR);
					this->_colors.back()->setParameter<int>(Texture::Parameter::WRAP_R, GL_CLAMP_TO_EDGE);
					this->_colors.back()->setParameter<int>(Texture::Parameter::WRAP_S, GL_CLAMP_TO_EDGE);
					this->_colors.back()->setParameter<int>(Texture::Parameter::WRAP_T, GL_CLAMP_TO_EDGE);
					OpenGL::framebufferTexture2D(getFramebufferTarget(this->_specification.target),
						getFramebufferAttachmentChannel(AttachmentChannel::COLOR0 + it),
						getFramebufferTargetTexture(color.target),
						this->_colors.back()->getHandle(),
						0);
					++it;
				}

				// Depth attachment
				if (this->_specification.depth) {
					this->_depth.emplace();
					this->_depth.value()->bind();
					this->_depth.value()->create();
					this->_depth.value()->setParameter<int>(Texture::Parameter::MIN_FILTER, GL_LINEAR);
					this->_depth.value()->setParameter<int>(Texture::Parameter::MAG_FILTER, GL_LINEAR);
					this->_depth.value()->setParameter<int>(Texture::Parameter::WRAP_R, GL_CLAMP_TO_EDGE);
					this->_depth.value()->setParameter<int>(Texture::Parameter::WRAP_S, GL_CLAMP_TO_EDGE);
					this->_depth.value()->setParameter<int>(Texture::Parameter::WRAP_T, GL_CLAMP_TO_EDGE);
					OpenGL::framebufferTexture2D(getFramebufferTarget(this->_specification.target),
						getFramebufferAttachmentChannel(AttachmentChannel::DEPTH),
						getFramebufferTargetTexture(this->_specification.depth->target),
						this->_depth.value()->getHandle(),
						0);
				}

				// Stencil attachment
				if (this->_specification.stencil) {
					this->_stencil.emplace();
					this->_stencil.value()->bind();
					this->_stencil.value()->create();
					this->_stencil.value()->setParameter<int>(Texture::Parameter::MIN_FILTER, GL_LINEAR);
					this->_stencil.value()->setParameter<int>(Texture::Parameter::MAG_FILTER, GL_LINEAR);
					this->_stencil.value()->setParameter<int>(Texture::Parameter::WRAP_R, GL_CLAMP_TO_EDGE);
					this->_stencil.value()->setParameter<int>(Texture::Parameter::WRAP_S, GL_CLAMP_TO_EDGE);
					this->_stencil.value()->setParameter<int>(Texture::Parameter::WRAP_T, GL_CLAMP_TO_EDGE);
					OpenGL::framebufferTexture2D(getFramebufferTarget(this->_specification.target),
						getFramebufferAttachmentChannel(AttachmentChannel::STENCIL),
						getFramebufferTargetTexture(this->_specification.stencil->target),
						this->_stencil.value()->getHandle(),
						0);
				}

				// Depth-Stencil attachment
				if (this->_specification.depthStencil) {
					this->_depthStencil.emplace();
					this->_depthStencil.value()->bind();
					this->_depthStencil.value()->create();
					this->_depthStencil.value()->setParameter<int>(Texture::Parameter::MIN_FILTER, GL_LINEAR);
					this->_depthStencil.value()->setParameter<int>(Texture::Parameter::MAG_FILTER, GL_LINEAR);
					this->_depthStencil.value()->setParameter<int>(Texture::Parameter::WRAP_R, GL_CLAMP_TO_EDGE);
					this->_depthStencil.value()->setParameter<int>(Texture::Parameter::WRAP_S, GL_CLAMP_TO_EDGE);
					this->_depthStencil.value()->setParameter<int>(Texture::Parameter::WRAP_T, GL_CLAMP_TO_EDGE);
					OpenGL::framebufferTexture2D(getFramebufferTarget(this->_specification.target),
						getFramebufferAttachmentChannel(AttachmentChannel::DEPTH_STENCIL),
						getFramebufferTargetTexture(this->_specification.depthStencil->target),
						this->_depthStencil.value()->getHandle(),
						0);
				}

				if (this->_colors.size() > 0) {
					auto buffers = std::vector<ColorBuffer>{};
					for (auto i = std::size_t{ 0 }; i < this->_colors.size(); ++i) {
						// TODO : ColorBuffer to define with operator+(int) method
						buffers.push_back(static_cast<ColorBuffer>(static_cast<int>(ColorBuffer::COLOR_ATTACHMENT0) + i));
					}
					OpenGL::drawBuffers(buffers);
				}
				else {
					OpenGL::drawBuffer(ColorBuffer::NONE);
				}

				this->checkStatus();
				this->unbind();
			}

			void Framebuffer::terminate()
			{
				if (this->_handle != NULL_HANDLE) {
					auto buffers = std::vector<Handle>{ this->_handle };
					OpenGL::deleteFramebuffers(buffers);
					this->_handle = NULL_HANDLE;

					for (auto & color : this->_colors) {
						color->terminate();
					}
					this->_colors.clear();
					
					this->_depth.reset();
					this->_stencil.reset();
					this->_depthStencil.reset();
				}
			}

			auto Framebuffer::checkStatus() -> bool
			{
				this->bind();
				auto status = OpenGL::checkFramebufferStatus(getFramebufferTarget(this->_specification.target));
				switch (status) {
				case FramebufferStatus::COMPLETE:
					INFO << "Framebuffer completed." << flush;
					break;
				case FramebufferStatus::UNDEFINED:
					WARNING << "Default framebuffer doesn't exist." << flush;
					break;
				case FramebufferStatus::INCOMPLETE_ATTACHMENT:
					WARNING << "One of the framebuffer attachment points is framebuffer incomplete." << flush;
					break;
				case FramebufferStatus::INCOMPLETE_MISSING_ATTACHMENT:
					WARNING << "Framebuffer does not have any image attached to it." << flush;
					break;
				case FramebufferStatus::INCOMPLETE_DRAW_BUFFER:
					WARNING << "None of the color attachment points are typed in draw buffers." << flush;
					break;
				case FramebufferStatus::INCOMPLETE_READ_BUFFER:
					WARNING << "None of the color attachment points are typed in read buffers" << flush;
					break;
				case FramebufferStatus::UNSUPPORTED:
					WARNING << "Combination of internal formats of the attached images violates an implementation-dependent set of restrictions." << flush;
					break;
				case FramebufferStatus::INCOMPLETE_MULTISAMPLE:
					WARNING << "Error with texture sample parameter not matching between the framebuffer and the attachment." << flush;
					break;
				case FramebufferStatus::INCOMPLETE_LAYER_TARGETS:
					WARNING << "One of the framebuffer attachments is layered, and one of the populated attachment is not layered, or if populated color attachments are not from textures of the same target." << flush;
					break;
				default: break;
				}

				return status == FramebufferStatus::COMPLETE;
			}

			auto Framebuffer::getSize() const -> IntVector2u
			{
				return { static_cast<int>(this->_specification.width), static_cast<int>(this->_specification.height) };
			}

		} // namespace rendering
	} // namespace renderer
} // namespace ece