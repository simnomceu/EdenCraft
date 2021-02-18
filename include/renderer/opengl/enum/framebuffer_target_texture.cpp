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
#include "renderer/opengl/enum/framebuffer_target_texture.hpp"

namespace ece
{
	namespace renderer
	{
		namespace opengl
		{
			FramebufferTargetTexture getFramebufferTargetTexture(Framebuffer::TargetTexture targetTexture)
			{
				switch (targetTexture) {
				case Framebuffer::TargetTexture::TEXTURE_RECTANGLE: return FramebufferTargetTexture::TEXTURE_RECTANGLE; break;
				case Framebuffer::TargetTexture::TEXTURE_2D_MULTISAMPLE: return FramebufferTargetTexture::TEXTURE_2D_MULTISAMPLE; break;
				case Framebuffer::TargetTexture::TEXTURE_2D_MULTISAMPLE_ARRAY: return FramebufferTargetTexture::TEXTURE_2D_MULTISAMPLE_ARRAY; break;
				case Framebuffer::TargetTexture::TEXTURE_3D: return FramebufferTargetTexture::TEXTURE_3D; break;
				case Framebuffer::TargetTexture::TEXTURE_CUBE_MAP_POSITIVE_X: return FramebufferTargetTexture::TEXTURE_CUBE_MAP_POSITIVE_X; break;
				case Framebuffer::TargetTexture::TEXTURE_CUBE_MAP_POSITIVE_Y: return FramebufferTargetTexture::TEXTURE_CUBE_MAP_POSITIVE_Y; break;
				case Framebuffer::TargetTexture::TEXTURE_CUBE_MAP_POSITIVE_Z: return FramebufferTargetTexture::TEXTURE_CUBE_MAP_POSITIVE_Z; break;
				case Framebuffer::TargetTexture::TEXTURE_CUBE_MAP_NEGATIVE_X: return FramebufferTargetTexture::TEXTURE_CUBE_MAP_NEGATIVE_X; break;
				case Framebuffer::TargetTexture::TEXTURE_CUBE_MAP_NEGATIVE_Y: return FramebufferTargetTexture::TEXTURE_CUBE_MAP_NEGATIVE_Y; break;
				case Framebuffer::TargetTexture::TEXTURE_CUBE_MAP_NEGATIVE_Z: return FramebufferTargetTexture::TEXTURE_CUBE_MAP_NEGATIVE_Z; break;
				default: throw std::runtime_error("Unknown value for FramebufferTargetTexture enumeration."); break;
				}
			}

			std::string to_string(FramebufferTargetTexture target)
			{
				switch (target) {
				case FramebufferTargetTexture::TEXTURE_RECTANGLE: return "GL_TEXTURE_RECTANGLE"; break;
				case FramebufferTargetTexture::TEXTURE_2D_MULTISAMPLE: return "GL_TEXTURE_2D_MULTISAMPLE"; break;
				case FramebufferTargetTexture::TEXTURE_2D_MULTISAMPLE_ARRAY: return "GL_TEXTURE_2D_MULTISAMPLE_ARRAY"; break;
				case FramebufferTargetTexture::TEXTURE_3D: return "GL_TEXTURE_3D"; break;
				case FramebufferTargetTexture::TEXTURE_CUBE_MAP_POSITIVE_X: return "GL_TEXTURE_CUBE_MAP_POSITIVE_X"; break;
				case FramebufferTargetTexture::TEXTURE_CUBE_MAP_POSITIVE_Y: return "GL_TEXTURE_CUBE_MAP_POSITIVE_Y"; break;
				case FramebufferTargetTexture::TEXTURE_CUBE_MAP_POSITIVE_Z: return "GL_TEXTURE_CUBE_MAP_POSITIVE_Z"; break;
				case FramebufferTargetTexture::TEXTURE_CUBE_MAP_NEGATIVE_X: return "GL_TEXTURE_CUBE_MAP_NEGATIVE_X"; break;
				case FramebufferTargetTexture::TEXTURE_CUBE_MAP_NEGATIVE_Y: return "GL_TEXTURE_CUBE_MAP_NEGATIVE_Y"; break;
				case FramebufferTargetTexture::TEXTURE_CUBE_MAP_NEGATIVE_Z: return "GL_TEXTURE_CUBE_MAP_NEGATIVE_Z"; break;
				default: throw std::runtime_error("Unknown value for FramebufferTargetTexture enumeration."); break;
				}
			}
		} // namespace opengl
	} // namespace renderer
} // namespace ece