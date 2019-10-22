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

#ifndef OPENGL_TEXTURE_PARAMETER_HPP
#define OPENGL_TEXTURE_PARAMETER_HPP

#include "renderer/config.hpp"
#include "GL/glcorearb.h"
#include "GL/glext.h"
#include "renderer/image/texture.hpp"

namespace ece
{
	namespace renderer
	{
		namespace opengl
		{
			using image::Texture;

			enum class TextureParameter : unsigned short int
			{
				DEPTH_STENCIL_TEXTURE_MODE = GL_DEPTH_STENCIL_TEXTURE_MODE,
				IMAGE_FORMAT_COMPATIBILITY_TYPE = GL_IMAGE_FORMAT_COMPATIBILITY_TYPE,
				TEXTURE_BASE_LEVEL = GL_TEXTURE_BASE_LEVEL,
				TEXTURE_BORDER_COLOR = GL_TEXTURE_BORDER_COLOR,
				TEXTURE_COMPARE_FUNC = GL_TEXTURE_COMPARE_FUNC,
				TEXTURE_COMPARE_MODE = GL_TEXTURE_COMPARE_MODE,
				TEXTURE_IMMUTABLE_FORMAT = GL_TEXTURE_IMMUTABLE_FORMAT,
				TEXTURE_IMMUTABLE_LEVELS = GL_TEXTURE_IMMUTABLE_LEVELS,
				TEXTURE_LOD_BIAS = GL_TEXTURE_LOD_BIAS,
				TEXTURE_MIN_FILTER = GL_TEXTURE_MIN_FILTER,
				TEXTURE_MAG_FILTER = GL_TEXTURE_MAG_FILTER,
				TEXTURE_MIN_LOD = GL_TEXTURE_MIN_LOD,
				TEXTURE_MAX_LOD = GL_TEXTURE_MAX_LOD,
				TEXTURE_MAX_LEVEL = GL_TEXTURE_MAX_LEVEL,
				TEXTURE_SWIZZLE_R = GL_TEXTURE_SWIZZLE_R,
				TEXTURE_SWIZZLE_G = GL_TEXTURE_SWIZZLE_G,
				TEXTURE_SWIZZLE_B = GL_TEXTURE_SWIZZLE_B,
				TEXTURE_SWIZZLE_A = GL_TEXTURE_SWIZZLE_A,
				TEXTURE_SWIZZLE_RGBA = GL_TEXTURE_SWIZZLE_RGBA,
				TEXTURE_WRAP_S = GL_TEXTURE_WRAP_S,
				TEXTURE_WRAP_T = GL_TEXTURE_WRAP_T,
				TEXTURE_WRAP_R = GL_TEXTURE_WRAP_R,
				TEXTURE_TARGET = GL_TEXTURE_TARGET,
				TEXTURE_VIEW_MIN_LAYER = GL_TEXTURE_VIEW_MIN_LAYER,
				TEXTURE_VIEW_MIN_LEVEL = GL_TEXTURE_VIEW_MIN_LEVEL,
				TEXTURE_VIEW_NUM_LAYERS = GL_TEXTURE_VIEW_NUM_LAYERS,
				TEXTURE_VIEW_NUM_LEVELS = GL_TEXTURE_VIEW_NUM_LEVELS
			};

			ECE_RENDERER_API TextureParameter getTextureParameter(Texture::Parameter type);
			ECE_RENDERER_API Texture::Parameter getTextureParameter(TextureParameter type);

			ECE_RENDERER_API std::string to_string(TextureParameter type);
		} // namespace opengl
	} // namespace renderer
} // namespace ece

#endif // OPENGL_TEXTURE_PARAMETER_HPP