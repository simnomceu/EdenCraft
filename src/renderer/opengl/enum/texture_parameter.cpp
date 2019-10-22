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
#include "renderer/opengl/enum/texture_parameter.hpp"

namespace ece
{
	namespace renderer
	{
		namespace opengl
		{
			TextureParameter getTextureParameter(Texture::Parameter type)
			{
				switch (type) {
				case Texture::Parameter::DEPTH_STENCIL_MODE: return TextureParameter::DEPTH_STENCIL_TEXTURE_MODE; break;
				case Texture::Parameter::BASE_LEVEL: return TextureParameter::TEXTURE_BASE_LEVEL; break;
				case Texture::Parameter::COMPARE_FUNC: return TextureParameter::TEXTURE_COMPARE_FUNC; break;
				case Texture::Parameter::COMPARE_MODE: return TextureParameter::TEXTURE_COMPARE_MODE; break;
				case Texture::Parameter::LOD_BIAS: return TextureParameter::TEXTURE_LOD_BIAS; break;
				case Texture::Parameter::MIN_FILTER: return TextureParameter::TEXTURE_MIN_FILTER; break;
				case Texture::Parameter::MAG_FILTER: return TextureParameter::TEXTURE_MAG_FILTER; break;
				case Texture::Parameter::MIN_LOD: return TextureParameter::TEXTURE_MIN_LOD; break;
				case Texture::Parameter::MAX_LOD: return TextureParameter::TEXTURE_MAX_LOD; break;
				case Texture::Parameter::MAX_LEVEL: return TextureParameter::TEXTURE_MAX_LEVEL; break;
				case Texture::Parameter::SWIZZLE_R: return TextureParameter::TEXTURE_SWIZZLE_R; break;
				case Texture::Parameter::SWIZZLE_G: return TextureParameter::TEXTURE_SWIZZLE_G; break;
				case Texture::Parameter::SWIZZLE_B: return TextureParameter::TEXTURE_SWIZZLE_B; break;
				case Texture::Parameter::SWIZZLE_A: return TextureParameter::TEXTURE_SWIZZLE_A; break;
				case Texture::Parameter::WRAP_S: return TextureParameter::TEXTURE_WRAP_S; break;
				case Texture::Parameter::WRAP_T: return TextureParameter::TEXTURE_WRAP_T; break;
				case Texture::Parameter::WRAP_R: return TextureParameter::TEXTURE_WRAP_R; break;
				default: throw std::runtime_error("Unknown value for TextureParameter enumeration."); break;
				}
			}

			Texture::Parameter getTextureParameter(TextureParameter type)
			{
				switch (type) {
				case TextureParameter::DEPTH_STENCIL_TEXTURE_MODE: return Texture::Parameter::DEPTH_STENCIL_MODE; break;
				case TextureParameter::TEXTURE_BASE_LEVEL: return Texture::Parameter::BASE_LEVEL; break;
				case TextureParameter::TEXTURE_COMPARE_FUNC: return Texture::Parameter::COMPARE_FUNC; break;
				case TextureParameter::TEXTURE_COMPARE_MODE: return Texture::Parameter::COMPARE_MODE; break;
				case TextureParameter::TEXTURE_LOD_BIAS: return Texture::Parameter::LOD_BIAS; break;
				case TextureParameter::TEXTURE_MIN_FILTER: return Texture::Parameter::MIN_FILTER; break;
				case TextureParameter::TEXTURE_MAG_FILTER: return Texture::Parameter::MAG_FILTER; break;
				case TextureParameter::TEXTURE_MIN_LOD: return Texture::Parameter::MIN_LOD; break;
				case TextureParameter::TEXTURE_MAX_LOD: return Texture::Parameter::MAX_LOD; break;
				case TextureParameter::TEXTURE_MAX_LEVEL: return Texture::Parameter::MAX_LEVEL; break;
				case TextureParameter::TEXTURE_SWIZZLE_R: return Texture::Parameter::SWIZZLE_R; break;
				case TextureParameter::TEXTURE_SWIZZLE_G: return Texture::Parameter::SWIZZLE_G; break;
				case TextureParameter::TEXTURE_SWIZZLE_B: return Texture::Parameter::SWIZZLE_B; break;
				case TextureParameter::TEXTURE_SWIZZLE_A: return Texture::Parameter::SWIZZLE_A; break;
				case TextureParameter::TEXTURE_WRAP_S: return Texture::Parameter::WRAP_S; break;
				case TextureParameter::TEXTURE_WRAP_T: return Texture::Parameter::WRAP_T; break;
				case TextureParameter::TEXTURE_WRAP_R: return Texture::Parameter::WRAP_R; break;
				default: throw std::runtime_error("Unknown value for Texture::Parameter enumeration."); break;
				}
			}

			std::string to_string(TextureParameter type)
			{
				switch (type) {
				case TextureParameter::DEPTH_STENCIL_TEXTURE_MODE: return "GL_DEPTH_STENCIL_TEXTURE_MODE"; break;
				case TextureParameter::TEXTURE_BASE_LEVEL: return "GL_TEXTURE_BASE_LEVEL"; break;
				case TextureParameter::TEXTURE_COMPARE_FUNC: return "GL_TEXTURE_COMPARE_FUNC"; break;
				case TextureParameter::TEXTURE_COMPARE_MODE: return "GL_TEXTURE_COMPARE_MODE"; break;
				case TextureParameter::TEXTURE_LOD_BIAS: return "GL_TEXTURE_LOD_BIAS"; break;
				case TextureParameter::TEXTURE_MIN_FILTER: return "GL_TEXTURE_MIN_FILTER"; break;
				case TextureParameter::TEXTURE_MAG_FILTER: return "GL_TEXTURE_MAG_FILTER"; break;
				case TextureParameter::TEXTURE_MIN_LOD: return "GL_TEXTURE_MIN_LOD"; break;
				case TextureParameter::TEXTURE_MAX_LOD: return "GL_TEXTURE_MAX_LOD"; break;
				case TextureParameter::TEXTURE_MAX_LEVEL: return "GL_TEXTURE_MAX_LEVEL"; break;
				case TextureParameter::TEXTURE_SWIZZLE_R: return "GL_TEXTURE_SWIZZLE_R"; break;
				case TextureParameter::TEXTURE_SWIZZLE_G: return "GL_TEXTURE_SWIZZLE_G"; break;
				case TextureParameter::TEXTURE_SWIZZLE_B: return "GL_TEXTURE_SWIZZLE_B"; break;
				case TextureParameter::TEXTURE_SWIZZLE_A: return "GL_TEXTURE_SWIZZLE_A"; break;
				case TextureParameter::TEXTURE_WRAP_S: return "GL_TEXTURE_WRAP_S"; break;
				case TextureParameter::TEXTURE_WRAP_T: return "GL_TEXTURE_WRAP_T"; break;
				case TextureParameter::TEXTURE_WRAP_R: return "GL_TEXTURE_WRAP_R"; break;
				default: throw std::runtime_error("Unknown value for TextureParameter enumeration."); break;
				}
			}
		} // namespace opengl
	} // namespace renderer
} // namespace ece