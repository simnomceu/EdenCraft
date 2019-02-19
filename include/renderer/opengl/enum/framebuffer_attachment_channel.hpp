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

#ifndef FRAMEBUFFER_ATTACHMENT_CHANNEL_HPP
#define FRAMEBUFFER_ATTACHMENT_CHANNEL_HPP

#include "renderer/config.hpp"
#include "renderer/pch.hpp"
#include "GL/glcorearb.h"
#include "GL/glext.h"
#include "renderer/rendering/framebuffer.hpp"

namespace ece
{
	namespace renderer
	{
		namespace opengl
		{
			using rendering::Framebuffer;

			enum class FramebufferAttachmentChannel : unsigned short int
			{
				COLOR_ATTACHMENT0 = GL_COLOR_ATTACHMENT0,
				COLOR_ATTACHMENT1 = GL_COLOR_ATTACHMENT1,
				COLOR_ATTACHMENT2 = GL_COLOR_ATTACHMENT2,
				COLOR_ATTACHMENT3 = GL_COLOR_ATTACHMENT3,
				COLOR_ATTACHMENT4 = GL_COLOR_ATTACHMENT4,
				COLOR_ATTACHMENT5 = GL_COLOR_ATTACHMENT5,
				COLOR_ATTACHMENT6 = GL_COLOR_ATTACHMENT6,
				COLOR_ATTACHMENT7 = GL_COLOR_ATTACHMENT7,
				COLOR_ATTACHMENT8 = GL_COLOR_ATTACHMENT8,
				COLOR_ATTACHMENT9 = GL_COLOR_ATTACHMENT9,
				COLOR_ATTACHMENT10 = GL_COLOR_ATTACHMENT10,
				COLOR_ATTACHMENT11 = GL_COLOR_ATTACHMENT11,
				COLOR_ATTACHMENT12 = GL_COLOR_ATTACHMENT12,
				COLOR_ATTACHMENT13 = GL_COLOR_ATTACHMENT13,
				COLOR_ATTACHMENT14 = GL_COLOR_ATTACHMENT14,
				COLOR_ATTACHMENT15 = GL_COLOR_ATTACHMENT15,
				COLOR_ATTACHMENT16 = GL_COLOR_ATTACHMENT16,
				COLOR_ATTACHMENT17 = GL_COLOR_ATTACHMENT17,
				COLOR_ATTACHMENT18 = GL_COLOR_ATTACHMENT18,
				COLOR_ATTACHMENT19 = GL_COLOR_ATTACHMENT19,
				COLOR_ATTACHMENT20 = GL_COLOR_ATTACHMENT20,
				COLOR_ATTACHMENT21 = GL_COLOR_ATTACHMENT21,
				COLOR_ATTACHMENT22 = GL_COLOR_ATTACHMENT22,
				COLOR_ATTACHMENT23 = GL_COLOR_ATTACHMENT23,
				COLOR_ATTACHMENT24 = GL_COLOR_ATTACHMENT24,
				COLOR_ATTACHMENT25 = GL_COLOR_ATTACHMENT25,
				COLOR_ATTACHMENT26 = GL_COLOR_ATTACHMENT26,
				COLOR_ATTACHMENT27 = GL_COLOR_ATTACHMENT27,
				COLOR_ATTACHMENT28 = GL_COLOR_ATTACHMENT28,
				COLOR_ATTACHMENT29 = GL_COLOR_ATTACHMENT29,
				COLOR_ATTACHMENT30 = GL_COLOR_ATTACHMENT30,
				COLOR_ATTACHMENT31 = GL_COLOR_ATTACHMENT31,
				DEPTH_ATTACHMENT = GL_DEPTH_ATTACHMENT,
				STENCIL_ATTACHMENT = GL_STENCIL_ATTACHMENT,
				DEPTH_STENCIL_ATTACHMENT = GL_DEPTH_STENCIL_ATTACHMENT
			};

			ECE_RENDERER_API FramebufferAttachmentChannel getFramebufferAttachmentChannel(Framebuffer::AttachmentChannel channel);

			ECE_RENDERER_API std::string to_string(FramebufferAttachmentChannel channel);

		} // namespace opengl
	} // namespace renderer
} // namespace ece

#endif // FRAMEBUFFER_ATTACHMENT_CHANNEL_HPP