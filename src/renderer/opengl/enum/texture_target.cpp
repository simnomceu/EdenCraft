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
#include "renderer/opengl/enum/texture_target.hpp"

namespace ece
{
	namespace renderer
	{
		namespace opengl
		{
			TextureTarget getTextureTarget(Texture::Target type)
			{
				switch (type) {
				case Texture::Target::TEXTURE_1D: return TextureTarget::TEXTURE_1D; break;
				case Texture::Target::TEXTURE_2D: return TextureTarget::TEXTURE_2D; break;
				case Texture::Target::TEXTURE_3D: return TextureTarget::TEXTURE_3D; break;
				case Texture::Target::TEXTURE_1D_ARRAY: return TextureTarget::TEXTURE_1D_ARRAY; break;
				case Texture::Target::TEXTURE_2D_ARRAY: return TextureTarget::TEXTURE_2D_ARRAY; break;
				case Texture::Target::RECTANGLE: return TextureTarget::TEXTURE_RECTANGLE; break;
				case Texture::Target::CUBE_MAP: return TextureTarget::TEXTURE_CUBE_MAP; break;
				case Texture::Target::CUBE_MAP_ARRAY: return TextureTarget::TEXTURE_CUBE_MAP_ARRAY; break;
				case Texture::Target::BUFFER: return TextureTarget::TEXTURE_BUFFER; break;
				case Texture::Target::TEXTURE_2D_MULTISAMPLE: return TextureTarget::TEXTURE_2D_MULTISAMPLE; break;
				case Texture::Target::TEXTURE_2D_MULTISAMPLE_ARRAY: return TextureTarget::TEXTURE_2D_MULTISAMPLE_ARRAY; break;
				default: throw std::runtime_error("Unknown value for TextureTarget enumeration."); break;
				}
			}

			std::string to_string(TextureTarget type)
			{
				switch (type) {
				case TextureTarget::TEXTURE_1D: return "GL_TEXTURE_1D"; break;
				case TextureTarget::TEXTURE_2D: return "GL_TEXTURE_2D"; break;
				case TextureTarget::TEXTURE_3D: return "GL_TEXTURE_3D"; break;
				case TextureTarget::TEXTURE_1D_ARRAY: return "GL_TEXTURE_1D_ARRAY"; break;
				case TextureTarget::TEXTURE_2D_ARRAY: return "GL_TEXTURE_2D_ARRAY"; break;
				case TextureTarget::TEXTURE_RECTANGLE: return "GL_TEXTURE_RECTANGLE"; break;
				case TextureTarget::TEXTURE_CUBE_MAP: return "GL_TEXTURE_CUBE_MAP"; break;
				case TextureTarget::TEXTURE_CUBE_MAP_ARRAY: return "GL_TEXTURE_CUBE_MAP_ARRAY"; break;
				case TextureTarget::TEXTURE_BUFFER: return "GL_TEXTURE_BUFFER"; break;
				case TextureTarget::TEXTURE_2D_MULTISAMPLE: return "GL_TEXTURE_2D_MULTISAMPLE"; break;
				case TextureTarget::TEXTURE_2D_MULTISAMPLE_ARRAY: return "GL_TEXTURE_2D_MULTISAMPLE_ARRAY"; break;
				default: throw std::runtime_error("Unknown value for TextureTarget enumeration."); break;
				}
			}
		} // namespace opengl
	} // namespace renderer
} // namespace ece