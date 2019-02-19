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
#include "renderer/opengl/enum/framebuffer_attachment_channel.hpp"

namespace ece
{
	namespace renderer
	{
		namespace opengl
		{
			FramebufferAttachmentChannel getFramebufferAttachmentChannel(Framebuffer::AttachmentChannel channel)
			{
				switch (channel) {
				case Framebuffer::AttachmentChannel::COLOR0: return FramebufferAttachmentChannel::COLOR_ATTACHMENT0; break;
				case Framebuffer::AttachmentChannel::COLOR1: return FramebufferAttachmentChannel::COLOR_ATTACHMENT1; break;
				case Framebuffer::AttachmentChannel::COLOR2: return FramebufferAttachmentChannel::COLOR_ATTACHMENT2; break;
				case Framebuffer::AttachmentChannel::COLOR3: return FramebufferAttachmentChannel::COLOR_ATTACHMENT3; break;
				case Framebuffer::AttachmentChannel::COLOR4: return FramebufferAttachmentChannel::COLOR_ATTACHMENT4; break;
				case Framebuffer::AttachmentChannel::COLOR5: return FramebufferAttachmentChannel::COLOR_ATTACHMENT5; break;
				case Framebuffer::AttachmentChannel::COLOR6: return FramebufferAttachmentChannel::COLOR_ATTACHMENT6; break;
				case Framebuffer::AttachmentChannel::COLOR7: return FramebufferAttachmentChannel::COLOR_ATTACHMENT7; break;
				case Framebuffer::AttachmentChannel::COLOR8: return FramebufferAttachmentChannel::COLOR_ATTACHMENT8; break;
				case Framebuffer::AttachmentChannel::COLOR9: return FramebufferAttachmentChannel::COLOR_ATTACHMENT9; break;
				case Framebuffer::AttachmentChannel::COLOR10: return FramebufferAttachmentChannel::COLOR_ATTACHMENT10; break;
				case Framebuffer::AttachmentChannel::COLOR11: return FramebufferAttachmentChannel::COLOR_ATTACHMENT11; break;
				case Framebuffer::AttachmentChannel::COLOR12: return FramebufferAttachmentChannel::COLOR_ATTACHMENT12; break;
				case Framebuffer::AttachmentChannel::COLOR13: return FramebufferAttachmentChannel::COLOR_ATTACHMENT13; break;
				case Framebuffer::AttachmentChannel::COLOR14: return FramebufferAttachmentChannel::COLOR_ATTACHMENT14; break;
				case Framebuffer::AttachmentChannel::COLOR15: return FramebufferAttachmentChannel::COLOR_ATTACHMENT15; break;
				case Framebuffer::AttachmentChannel::COLOR16: return FramebufferAttachmentChannel::COLOR_ATTACHMENT16; break;
				case Framebuffer::AttachmentChannel::COLOR17: return FramebufferAttachmentChannel::COLOR_ATTACHMENT17; break;
				case Framebuffer::AttachmentChannel::COLOR18: return FramebufferAttachmentChannel::COLOR_ATTACHMENT18; break;
				case Framebuffer::AttachmentChannel::COLOR19: return FramebufferAttachmentChannel::COLOR_ATTACHMENT19; break;
				case Framebuffer::AttachmentChannel::COLOR20: return FramebufferAttachmentChannel::COLOR_ATTACHMENT20; break;
				case Framebuffer::AttachmentChannel::COLOR21: return FramebufferAttachmentChannel::COLOR_ATTACHMENT21; break;
				case Framebuffer::AttachmentChannel::COLOR22: return FramebufferAttachmentChannel::COLOR_ATTACHMENT22; break;
				case Framebuffer::AttachmentChannel::COLOR23: return FramebufferAttachmentChannel::COLOR_ATTACHMENT23; break;
				case Framebuffer::AttachmentChannel::COLOR24: return FramebufferAttachmentChannel::COLOR_ATTACHMENT24; break;
				case Framebuffer::AttachmentChannel::COLOR25: return FramebufferAttachmentChannel::COLOR_ATTACHMENT25; break;
				case Framebuffer::AttachmentChannel::COLOR26: return FramebufferAttachmentChannel::COLOR_ATTACHMENT26; break;
				case Framebuffer::AttachmentChannel::COLOR27: return FramebufferAttachmentChannel::COLOR_ATTACHMENT27; break;
				case Framebuffer::AttachmentChannel::COLOR28: return FramebufferAttachmentChannel::COLOR_ATTACHMENT28; break;
				case Framebuffer::AttachmentChannel::COLOR29: return FramebufferAttachmentChannel::COLOR_ATTACHMENT29; break;
				case Framebuffer::AttachmentChannel::COLOR30: return FramebufferAttachmentChannel::COLOR_ATTACHMENT30; break;
				case Framebuffer::AttachmentChannel::COLOR31: return FramebufferAttachmentChannel::COLOR_ATTACHMENT31; break;
				case Framebuffer::AttachmentChannel::DEPTH: return FramebufferAttachmentChannel::DEPTH_ATTACHMENT; break;
				case Framebuffer::AttachmentChannel::STENCIL: return FramebufferAttachmentChannel::STENCIL_ATTACHMENT; break;
				case Framebuffer::AttachmentChannel::DEPTH_STENCIL: return FramebufferAttachmentChannel::DEPTH_STENCIL_ATTACHMENT; break;
				default: throw std::runtime_error("Unknown value for FramebufferAttachmentChannel enumeration."); break;
				}
			}

			std::string to_string(FramebufferAttachmentChannel channel)
			{
				switch (channel) {
				case FramebufferAttachmentChannel::COLOR_ATTACHMENT0: return "COLOR_ATTACHMENT0"; break;
				case FramebufferAttachmentChannel::COLOR_ATTACHMENT1: return "COLOR_ATTACHMENT1"; break;
				case FramebufferAttachmentChannel::COLOR_ATTACHMENT2: return "COLOR_ATTACHMENT2"; break;
				case FramebufferAttachmentChannel::COLOR_ATTACHMENT3: return "COLOR_ATTACHMENT3"; break;
				case FramebufferAttachmentChannel::COLOR_ATTACHMENT4: return "COLOR_ATTACHMENT4"; break;
				case FramebufferAttachmentChannel::COLOR_ATTACHMENT5: return "COLOR_ATTACHMENT5"; break;
				case FramebufferAttachmentChannel::COLOR_ATTACHMENT6: return "COLOR_ATTACHMENT6"; break;
				case FramebufferAttachmentChannel::COLOR_ATTACHMENT7: return "COLOR_ATTACHMENT7"; break;
				case FramebufferAttachmentChannel::COLOR_ATTACHMENT8: return "COLOR_ATTACHMENT8"; break;
				case FramebufferAttachmentChannel::COLOR_ATTACHMENT9: return "COLOR_ATTACHMENT9"; break;
				case FramebufferAttachmentChannel::COLOR_ATTACHMENT10: return "COLOR_ATTACHMENT10"; break;
				case FramebufferAttachmentChannel::COLOR_ATTACHMENT11: return "COLOR_ATTACHMENT11"; break;
				case FramebufferAttachmentChannel::COLOR_ATTACHMENT12: return "COLOR_ATTACHMENT12"; break;
				case FramebufferAttachmentChannel::COLOR_ATTACHMENT13: return "COLOR_ATTACHMENT13"; break;
				case FramebufferAttachmentChannel::COLOR_ATTACHMENT14: return "COLOR_ATTACHMENT14"; break;
				case FramebufferAttachmentChannel::COLOR_ATTACHMENT15: return "COLOR_ATTACHMENT15"; break;
				case FramebufferAttachmentChannel::COLOR_ATTACHMENT16: return "COLOR_ATTACHMENT16"; break;
				case FramebufferAttachmentChannel::COLOR_ATTACHMENT17: return "COLOR_ATTACHMENT17"; break;
				case FramebufferAttachmentChannel::COLOR_ATTACHMENT18: return "COLOR_ATTACHMENT18"; break;
				case FramebufferAttachmentChannel::COLOR_ATTACHMENT19: return "COLOR_ATTACHMENT19"; break;
				case FramebufferAttachmentChannel::COLOR_ATTACHMENT20: return "COLOR_ATTACHMENT20"; break;
				case FramebufferAttachmentChannel::COLOR_ATTACHMENT21: return "COLOR_ATTACHMENT21"; break;
				case FramebufferAttachmentChannel::COLOR_ATTACHMENT22: return "COLOR_ATTACHMENT22"; break;
				case FramebufferAttachmentChannel::COLOR_ATTACHMENT23: return "COLOR_ATTACHMENT23"; break;
				case FramebufferAttachmentChannel::COLOR_ATTACHMENT24: return "COLOR_ATTACHMENT24"; break;
				case FramebufferAttachmentChannel::COLOR_ATTACHMENT25: return "COLOR_ATTACHMENT25"; break;
				case FramebufferAttachmentChannel::COLOR_ATTACHMENT26: return "COLOR_ATTACHMENT26"; break;
				case FramebufferAttachmentChannel::COLOR_ATTACHMENT27: return "COLOR_ATTACHMENT27"; break;
				case FramebufferAttachmentChannel::COLOR_ATTACHMENT28: return "COLOR_ATTACHMENT28"; break;
				case FramebufferAttachmentChannel::COLOR_ATTACHMENT29: return "COLOR_ATTACHMENT29"; break;
				case FramebufferAttachmentChannel::COLOR_ATTACHMENT30: return "COLOR_ATTACHMENT30"; break;
				case FramebufferAttachmentChannel::COLOR_ATTACHMENT31: return "COLOR_ATTACHMENT31"; break;
				case FramebufferAttachmentChannel::DEPTH_ATTACHMENT: return "DEPTH_ATTACHMENT"; break;
				case FramebufferAttachmentChannel::STENCIL_ATTACHMENT: return "STENCIL_ATTACHMENT"; break;
				case FramebufferAttachmentChannel::DEPTH_STENCIL_ATTACHMENT: return "DEPTH_STENCIL_ATTACHMENT"; break;
				default: throw std::runtime_error("Unknown value for FramebufferAttachmentChannel enumeration."); break;
				}
			}
		} // namespace opengl
	} // namespace renderer
} // namespace ece