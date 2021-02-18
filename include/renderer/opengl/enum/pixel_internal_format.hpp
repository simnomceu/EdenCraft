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

#ifndef PIXEL_INTERNAL_FORMAT_HPP
#define PIXEL_INTERNAL_FORMAT_HPP

#include "renderer/config.hpp"
#include "renderer/pch.hpp"
#include "GL/glcorearb.h"
#include "GL/glext.h"
#include "renderer/image/pixel_data.hpp"

namespace ece
{
	namespace renderer
	{
		namespace opengl
		{
			using image::PixelData;

			enum class PixelInternalFormat : unsigned short int
			{
				DEPTH_COMPONENT = GL_DEPTH_COMPONENT,
				DEPTH_STENCIL = GL_DEPTH_STENCIL,
				RED = GL_RED,
				RG = GL_RG,
				RGB = GL_RGB,
				RGBA = GL_RGBA,
				R8 = GL_R8,
				R8_SNORM = GL_R8_SNORM,
				R16 = GL_R16,
				R16_SNORM = GL_R16_SNORM,
				RG8 = GL_RG8,
				RG8_SNORM = GL_RG8_SNORM,
				RG16 = GL_RG16,
				RG16_SNORM = GL_RG16_SNORM,
				R3_G3_B2 = GL_R3_G3_B2,
				RGB4 = GL_RGB4,
				RGB5 = GL_RGB5,
				RGB8 = GL_RGB8,
				RGB8_SNORM = GL_RGB8_SNORM,
				RGB10 = GL_RGB10,
				RGB12 = GL_RGB12,
				RGB16_SNORM = GL_RGB16_SNORM,
				RGBA2 = GL_RGBA2,
				RGBA4 = GL_RGBA4,
				RGB5_A1 = GL_RGB5_A1,
				RGBA8 = GL_RGBA8,
				RGBA8_SNORM = GL_RGBA8_SNORM,
				RGB10_A2 = GL_RGB10_A2,
				RGB10_A2UI = GL_RGB10_A2UI,
				RGBA12 = GL_RGBA12,
				RGBA16 = GL_RGBA16,
				SRGB8 = GL_SRGB8,
				SRGB8_ALPHA8 = GL_SRGB8_ALPHA8,
				R16F = GL_R16F,
				RG16F = GL_RG16F,
				RGB16F = GL_RGB16F,
				RGBA16F = GL_RGBA16F,
				R32F = GL_R32F,
				RG32F = GL_RG32F,
				RGB32F = GL_RGB32F,
				RGBA32F = GL_RGBA32F,
				R11F_G11F_B10F = GL_R11F_G11F_B10F,
				RGB9_E5 = GL_RGB9_E5,
				R8I = GL_R8I,
				R8UI = GL_R8UI,
				R16I = GL_R16I,
				R16UI = GL_R16UI,
				R32I = GL_R32I,
				R32UI = GL_R32UI,
				RG8I = GL_RG8I,
				RG8UI = GL_RG8UI,
				RG16I = GL_RG16I,
				RG16UI = GL_RG16UI,
				RG32I = GL_RG32I,
				RG32UI = GL_RG32UI,
				RGB8I = GL_RGB8I,
				RGB8UI = GL_RGB8UI,
				RGB16I = GL_RGB16I,
				RGB16UI = GL_RGB16UI,
				RGB32I = GL_RGB32I,
				RGB32UI = GL_RGB32UI,
				RGBA8I = GL_RGBA8I,
				RGBA8UI = GL_RGBA8UI,
				RGBA16I = GL_RGBA16I,
				RGBA16UI = GL_RGBA16UI,
				RGBA32I = GL_RGBA32I,
				RGBA32UI = GL_RGBA32UI,
				COMPRESSED_RED = GL_COMPRESSED_RED,
				COMPRESSED_RG = GL_COMPRESSED_RG,
				COMPRESSED_RGB = GL_COMPRESSED_RGB,
				COMPRESSED_RGBA = GL_COMPRESSED_RGBA,
				COMPRESSED_SRGB = GL_COMPRESSED_SRGB,
				COMPRESSED_SRGB_ALPHA = GL_COMPRESSED_SRGB_ALPHA,
				COMPRESSED_RED_RGTC1 = GL_COMPRESSED_RED_RGTC1,
				COMPRESSED_SIGNED_RED_RGTC1 = GL_COMPRESSED_SIGNED_RED_RGTC1,
				COMPRESSED_RG_RGTC2 = GL_COMPRESSED_RG_RGTC2,
				COMPRESSED_SIGNED_RG_RGTC2 = GL_COMPRESSED_SIGNED_RG_RGTC2,
				COMPRESSED_RGBA_BPTC_UNORM = GL_COMPRESSED_RGBA_BPTC_UNORM,
				COMPRESSED_SRGB_ALPHA_BPTC_UNORM = GL_COMPRESSED_SRGB_ALPHA_BPTC_UNORM,
				COMPRESSED_RGB_BPTC_SIGNED_FLOAT = GL_COMPRESSED_RGB_BPTC_SIGNED_FLOAT,
				COMPRESSED_RGB_BPTC_UNSIGNED_FLOAT = GL_COMPRESSED_RGB_BPTC_UNSIGNED_FLOAT
			};

			ECE_RENDERER_API PixelInternalFormat getPixelInternalFormat(PixelData::InternalFormat format);

			ECE_RENDERER_API std::string to_string(PixelInternalFormat format);
		} // namespace opengl
	} // namespace renderer
} // namespace ece

#endif // PIXEL_INTERNAL_FORMAT_HPP