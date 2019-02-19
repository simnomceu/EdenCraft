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
			Framebuffer::Framebuffer() noexcept : _handle(NULL_HANDLE)
			{
				this->_handle = OpenGL::genFramebuffers(1)[0];
			}

			Framebuffer::~Framebuffer() noexcept
			{
				auto handles = std::vector<Handle>({ this->_handle });
				OpenGL::deleteFramebuffers(handles);
			}

			void Framebuffer::bind()
			{
				OpenGL::bindFramebuffer(getFramebufferTarget(this->_target), this->_handle);
			}

			void Framebuffer::unbind()
			{
				OpenGL::bindFramebuffer(getFramebufferTarget(this->_target), NULL_HANDLE);
			}

			void Framebuffer::terminate()
			{
				auto framebuffers = std::vector<Handle>({ this->_handle });
				OpenGL::deleteFramebuffers(framebuffers);
			}

			auto Framebuffer::checkStatus() -> bool
			{
				this->bind();
				auto status = OpenGL::checkFramebufferStatus(getFramebufferTarget(this->_target));
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

			void Framebuffer::blit(Rectangle<int> area, Framebuffer & dst, Rectangle<int> dstArea, FramebufferBufferBit mask, InterpolationFilter filter)
			{
				this->setTarget(Target::READ);
				this->bind();
				dst.setTarget(Target::DRAW);
				dst.bind();
				OpenGL::blitFramebuffer(area.x, area.y, area.width, area.height, dstArea.x, dstArea.y, dstArea.width, dstArea.height, getBufferBit(mask), getInterpolationFilter(filter));
				
			}

			std::shared_ptr<Framebuffer> Framebuffer::getFramebuffer(Handle handle)
			{
				if (OpenGL::isFramebuffer(handle)) {
					return std::shared_ptr<Framebuffer>();
				}
				return std::make_shared<Framebuffer>(handle);
			}

			void Framebuffer::attach(AttachmentChannel channel, Texture & attachment)
			{
				this->bind();
				attachment.bind();

				const auto level = 0;
				OpenGL::framebufferTexture(getFramebufferTarget(this->_target), getFramebufferAttachmentChannel(channel), attachment.getHandle(), level);
			}

		} // namespace rendering
	} // namespace renderer
} // namespace ece