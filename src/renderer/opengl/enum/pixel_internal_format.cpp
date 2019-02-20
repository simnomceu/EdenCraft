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
#include "renderer/opengl/enum/pixel_internal_format.hpp"

namespace ece
{
	namespace renderer
	{
		namespace opengl
		{
			PixelInternalFormat getPixelInternalFormat(PixelData::InternalFormat format)
			{
				switch (format) {
				case PixelData::InternalFormat::DEPTH_COMPONENT: return PixelInternalFormat::DEPTH_COMPONENT; break;
				case PixelData::InternalFormat::DEPTH_STENCIL: return PixelInternalFormat::DEPTH_STENCIL; break;
				case PixelData::InternalFormat::RED: return PixelInternalFormat::RED; break;
				case PixelData::InternalFormat::RG: return PixelInternalFormat::RG; break;
				case PixelData::InternalFormat::RGB: return PixelInternalFormat::RGB; break;
				case PixelData::InternalFormat::RGBA: return PixelInternalFormat::RGBA; break;
				case PixelData::InternalFormat::R8: return PixelInternalFormat::R8; break;
				case PixelData::InternalFormat::R8_SNORM: return PixelInternalFormat::R8_SNORM; break;
				case PixelData::InternalFormat::R16: return PixelInternalFormat::R16; break;
				case PixelData::InternalFormat::R16_SNORM: return PixelInternalFormat::R16_SNORM; break;
				case PixelData::InternalFormat::RG8: return PixelInternalFormat::RG8; break;
				case PixelData::InternalFormat::RG8_SNORM: return PixelInternalFormat::RG8_SNORM; break;
				case PixelData::InternalFormat::RG16: return PixelInternalFormat::RG16; break;
				case PixelData::InternalFormat::RG16_SNORM: return PixelInternalFormat::RG16_SNORM; break;
				case PixelData::InternalFormat::R3_G3_B2: return PixelInternalFormat::R3_G3_B2; break;
				case PixelData::InternalFormat::RGB4: return PixelInternalFormat::RGB4; break;
				case PixelData::InternalFormat::RGB5: return PixelInternalFormat::RGB5; break;
				case PixelData::InternalFormat::RGB8: return PixelInternalFormat::RGB8; break;
				case PixelData::InternalFormat::RGB8_SNORM: return PixelInternalFormat::RGB8_SNORM; break;
				case PixelData::InternalFormat::RGB10: return PixelInternalFormat::RGB10; break;
				case PixelData::InternalFormat::RGB12: return PixelInternalFormat::RGB12; break;
				case PixelData::InternalFormat::RGB16_SNORM: return PixelInternalFormat::RGB16_SNORM; break;
				case PixelData::InternalFormat::RGBA2: return PixelInternalFormat::RGBA2; break;
				case PixelData::InternalFormat::RGBA4: return PixelInternalFormat::RGBA4; break;
				case PixelData::InternalFormat::RGB5_A1: return PixelInternalFormat::RGB5_A1; break;
				case PixelData::InternalFormat::RGBA8: return PixelInternalFormat::RGBA8; break;
				case PixelData::InternalFormat::RGBA8_SNORM: return PixelInternalFormat::RGBA8_SNORM; break;
				case PixelData::InternalFormat::RGB10_A2: return PixelInternalFormat::RGB10_A2; break;
				case PixelData::InternalFormat::RGB10_A2UI: return PixelInternalFormat::RGB10_A2UI; break;
				case PixelData::InternalFormat::RGBA12: return PixelInternalFormat::RGBA12; break;
				case PixelData::InternalFormat::RGBA16: return PixelInternalFormat::RGBA16; break;
				case PixelData::InternalFormat::SRGB8: return PixelInternalFormat::SRGB8; break;
				case PixelData::InternalFormat::SRGB8_ALPHA8: return PixelInternalFormat::SRGB8_ALPHA8; break;
				case PixelData::InternalFormat::R16F: return PixelInternalFormat::R16F; break;
				case PixelData::InternalFormat::RG16F: return PixelInternalFormat::RG16F; break;
				case PixelData::InternalFormat::RGB16F: return PixelInternalFormat::RGB16F; break;
				case PixelData::InternalFormat::RGBA16F: return PixelInternalFormat::RGBA16F; break;
				case PixelData::InternalFormat::R32F: return PixelInternalFormat::R32F; break;
				case PixelData::InternalFormat::RG32F: return PixelInternalFormat::RG32F; break;
				case PixelData::InternalFormat::RGB32F: return PixelInternalFormat::RGB32F; break;
				case PixelData::InternalFormat::RGBA32F: return PixelInternalFormat::RGBA32F; break;
				case PixelData::InternalFormat::R11F_G11F_B10F: return PixelInternalFormat::R11F_G11F_B10F; break;
				case PixelData::InternalFormat::RGB9_E5: return PixelInternalFormat::RGB9_E5; break;
				case PixelData::InternalFormat::R8I: return PixelInternalFormat::R8I; break;
				case PixelData::InternalFormat::R8UI: return PixelInternalFormat::R8UI; break;
				case PixelData::InternalFormat::R16I: return PixelInternalFormat::R16I; break;
				case PixelData::InternalFormat::R16UI: return PixelInternalFormat::R16UI; break;
				case PixelData::InternalFormat::R32I: return PixelInternalFormat::R32I; break;
				case PixelData::InternalFormat::R32UI: return PixelInternalFormat::R32UI; break;
				case PixelData::InternalFormat::RG8I: return PixelInternalFormat::RG8I; break;
				case PixelData::InternalFormat::RG8UI: return PixelInternalFormat::RG8UI; break;
				case PixelData::InternalFormat::RG16I: return PixelInternalFormat::RG16I; break;
				case PixelData::InternalFormat::RG16UI: return PixelInternalFormat::RG16UI; break;
				case PixelData::InternalFormat::RG32I: return PixelInternalFormat::RG32I; break;
				case PixelData::InternalFormat::RG32UI: return PixelInternalFormat::RG32UI; break;
				case PixelData::InternalFormat::RGB8I: return PixelInternalFormat::RGB8I; break;
				case PixelData::InternalFormat::RGB8UI: return PixelInternalFormat::RGB8UI; break;
				case PixelData::InternalFormat::RGB16I: return PixelInternalFormat::RGB16I; break;
				case PixelData::InternalFormat::RGB16UI: return PixelInternalFormat::RGB16UI; break;
				case PixelData::InternalFormat::RGB32I: return PixelInternalFormat::RGB32I; break;
				case PixelData::InternalFormat::RGB32UI: return PixelInternalFormat::RGB32UI; break;
				case PixelData::InternalFormat::RGBA8I: return PixelInternalFormat::RGBA8I; break;
				case PixelData::InternalFormat::RGBA8UI: return PixelInternalFormat::RGBA8UI; break;
				case PixelData::InternalFormat::RGBA16I: return PixelInternalFormat::RGBA16I; break;
				case PixelData::InternalFormat::RGBA16UI: return PixelInternalFormat::RGBA16UI; break;
				case PixelData::InternalFormat::RGBA32I: return PixelInternalFormat::RGBA32I; break;
				case PixelData::InternalFormat::RGBA32UI: return PixelInternalFormat::RGBA32UI; break;
				case PixelData::InternalFormat::COMPRESSED_RED: return PixelInternalFormat::COMPRESSED_RED; break;
				case PixelData::InternalFormat::COMPRESSED_RG: return PixelInternalFormat::COMPRESSED_RG; break;
				case PixelData::InternalFormat::COMPRESSED_RGB: return PixelInternalFormat::COMPRESSED_RGB; break;
				case PixelData::InternalFormat::COMPRESSED_RGBA: return PixelInternalFormat::COMPRESSED_RGBA; break;
				case PixelData::InternalFormat::COMPRESSED_SRGB: return PixelInternalFormat::COMPRESSED_SRGB; break;
				case PixelData::InternalFormat::COMPRESSED_SRGB_ALPHA: return PixelInternalFormat::COMPRESSED_SRGB_ALPHA; break;
				case PixelData::InternalFormat::COMPRESSED_RED_RGTC1: return PixelInternalFormat::COMPRESSED_RED_RGTC1; break;
				case PixelData::InternalFormat::COMPRESSED_SIGNED_RED_RGTC1: return PixelInternalFormat::COMPRESSED_SIGNED_RED_RGTC1; break;
				case PixelData::InternalFormat::COMPRESSED_RG_RGTC2: return PixelInternalFormat::COMPRESSED_RG_RGTC2; break;
				case PixelData::InternalFormat::COMPRESSED_SIGNED_RG_RGTC2: return PixelInternalFormat::COMPRESSED_SIGNED_RG_RGTC2; break;
				case PixelData::InternalFormat::COMPRESSED_RGBA_BPTC_UNORM: return PixelInternalFormat::COMPRESSED_RGBA_BPTC_UNORM; break;
				case PixelData::InternalFormat::COMPRESSED_SRGB_ALPHA_BPTC_UNORM: return PixelInternalFormat::COMPRESSED_SRGB_ALPHA_BPTC_UNORM; break;
				case PixelData::InternalFormat::COMPRESSED_RGB_BPTC_SIGNED_FLOAT: return PixelInternalFormat::COMPRESSED_RGB_BPTC_SIGNED_FLOAT; break;
				case PixelData::InternalFormat::COMPRESSED_RGB_BPTC_UNSIGNED_FLOAT: return PixelInternalFormat::COMPRESSED_RGB_BPTC_UNSIGNED_FLOAT; break;
				default: throw std::runtime_error("Unknown value for PixelInternalFormat enumeration."); break;
				}
			}

			std::string to_string(PixelInternalFormat format)
			{
				switch (format) {
				case PixelInternalFormat::DEPTH_COMPONENT: return "GL_DEPTH_COMPONENT"; break;
				case PixelInternalFormat::DEPTH_STENCIL: return "GL_DEPTH_STENCIL"; break;
				case PixelInternalFormat::RED: return "GL_RED"; break;
				case PixelInternalFormat::RG: return "GL_RG"; break;
				case PixelInternalFormat::RGB: return "GL_RGB"; break;
				case PixelInternalFormat::RGBA: return "GL_RGBA"; break;
				case PixelInternalFormat::R8: return "GL_R8"; break;
				case PixelInternalFormat::R8_SNORM: return "GL_R8_SNORM"; break;
				case PixelInternalFormat::R16: return "GL_R16"; break;
				case PixelInternalFormat::R16_SNORM: return "GL_R16_SNORM"; break;
				case PixelInternalFormat::RG8: return "GL_RG8"; break;
				case PixelInternalFormat::RG8_SNORM: return "GL_RG8_SNORM"; break;
				case PixelInternalFormat::RG16: return "GL_RG16"; break;
				case PixelInternalFormat::RG16_SNORM: return "GL_RG16_SNORM"; break;
				case PixelInternalFormat::R3_G3_B2: return "GL_R3_G3_B2"; break;
				case PixelInternalFormat::RGB4: return "GL_RGB4"; break;
				case PixelInternalFormat::RGB5: return "GL_RGB5"; break;
				case PixelInternalFormat::RGB8: return "GL_RGB8"; break;
				case PixelInternalFormat::RGB8_SNORM: return "GL_RGB8_SNORM"; break;
				case PixelInternalFormat::RGB10: return "GL_RGB10"; break;
				case PixelInternalFormat::RGB12: return "GL_RGB12"; break;
				case PixelInternalFormat::RGB16_SNORM: return "GL_RGB16_SNORM"; break;
				case PixelInternalFormat::RGBA2: return "GL_RGBA2"; break;
				case PixelInternalFormat::RGBA4: return "GL_RGBA4"; break;
				case PixelInternalFormat::RGB5_A1: return "GL_RGB5_A1"; break;
				case PixelInternalFormat::RGBA8: return "GL_RGBA8"; break;
				case PixelInternalFormat::RGBA8_SNORM: return "GL_RGBA8_SNORM"; break;
				case PixelInternalFormat::RGB10_A2: return "GL_RGB10_A2"; break;
				case PixelInternalFormat::RGB10_A2UI: return "GL_RGB10_A2UI"; break;
				case PixelInternalFormat::RGBA12: return "GL_RGBA12"; break;
				case PixelInternalFormat::RGBA16: return "GL_RGBA16"; break;
				case PixelInternalFormat::SRGB8: return "GL_SRGB8"; break;
				case PixelInternalFormat::SRGB8_ALPHA8: return "GL_SRGB8_ALPHA8"; break;
				case PixelInternalFormat::R16F: return "GL_R16F"; break;
				case PixelInternalFormat::RG16F: return "GL_RG16F"; break;
				case PixelInternalFormat::RGB16F: return "GL_RGB16F"; break;
				case PixelInternalFormat::RGBA16F: return "GL_RGBA16F"; break;
				case PixelInternalFormat::R32F: return "GL_R32F"; break;
				case PixelInternalFormat::RG32F: return "GL_RG32F"; break;
				case PixelInternalFormat::RGB32F: return "GL_RGB32F"; break;
				case PixelInternalFormat::RGBA32F: return "GL_RGBA32F"; break;
				case PixelInternalFormat::R11F_G11F_B10F: return "GL_R11F_G11F_B10F"; break;
				case PixelInternalFormat::RGB9_E5: return "GL_RGB9_E5"; break;
				case PixelInternalFormat::R8I: return "GL_R8I"; break;
				case PixelInternalFormat::R8UI: return "GL_R8UI"; break;
				case PixelInternalFormat::R16I: return "GL_R16I"; break;
				case PixelInternalFormat::R16UI: return "GL_R16UI"; break;
				case PixelInternalFormat::R32I: return "GL_R32I"; break;
				case PixelInternalFormat::R32UI: return "GL_R32UI"; break;
				case PixelInternalFormat::RG8I: return "GL_RG8I"; break;
				case PixelInternalFormat::RG8UI: return "GL_RG8UI"; break;
				case PixelInternalFormat::RG16I: return "GL_RG16I"; break;
				case PixelInternalFormat::RG16UI: return "GL_RG16UI"; break;
				case PixelInternalFormat::RG32I: return "GL_RG32I"; break;
				case PixelInternalFormat::RG32UI: return "GL_RG32UI"; break;
				case PixelInternalFormat::RGB8I: return "GL_RGB8I"; break;
				case PixelInternalFormat::RGB8UI: return "GL_RGB8UI"; break;
				case PixelInternalFormat::RGB16I: return "GL_RGB16I"; break;
				case PixelInternalFormat::RGB16UI: return "GL_RGB16UI"; break;
				case PixelInternalFormat::RGB32I: return "GL_RGB32I"; break;
				case PixelInternalFormat::RGB32UI: return "GL_RGB32UI"; break;
				case PixelInternalFormat::RGBA8I: return "GL_RGBA8I"; break;
				case PixelInternalFormat::RGBA8UI: return "GL_RGBA8UI"; break;
				case PixelInternalFormat::RGBA16I: return "GL_RGBA16I"; break;
				case PixelInternalFormat::RGBA16UI: return "GL_RGBA16UI"; break;
				case PixelInternalFormat::RGBA32I: return "GL_RGBA32I"; break;
				case PixelInternalFormat::RGBA32UI: return "GL_RGBA32UI"; break;
				case PixelInternalFormat::COMPRESSED_RED: return "GL_COMPRESSED_RED"; break;
				case PixelInternalFormat::COMPRESSED_RG: return "GL_COMPRESSED_RG"; break;
				case PixelInternalFormat::COMPRESSED_RGB: return "GL_COMPRESSED_RGB"; break;
				case PixelInternalFormat::COMPRESSED_RGBA: return "GL_COMPRESSED_RGBA"; break;
				case PixelInternalFormat::COMPRESSED_SRGB: return "GL_COMPRESSED_SRGB"; break;
				case PixelInternalFormat::COMPRESSED_SRGB_ALPHA: return "GL_COMPRESSED_SRGB_ALPHA"; break;
				case PixelInternalFormat::COMPRESSED_RED_RGTC1: return "GL_COMPRESSED_RED_RGTC1"; break;
				case PixelInternalFormat::COMPRESSED_SIGNED_RED_RGTC1: return "GL_COMPRESSED_SIGNED_RED_RGTC1"; break;
				case PixelInternalFormat::COMPRESSED_RG_RGTC2: return "GL_COMPRESSED_RG_RGTC2"; break;
				case PixelInternalFormat::COMPRESSED_SIGNED_RG_RGTC2: return "GL_COMPRESSED_SIGNED_RG_RGTC2"; break;
				case PixelInternalFormat::COMPRESSED_RGBA_BPTC_UNORM: return "GL_COMPRESSED_RGBA_BPTC_UNORM"; break;
				case PixelInternalFormat::COMPRESSED_SRGB_ALPHA_BPTC_UNORM: return "GL_COMPRESSED_SRGB_ALPHA_BPTC_UNORM"; break;
				case PixelInternalFormat::COMPRESSED_RGB_BPTC_SIGNED_FLOAT: return "GL_COMPRESSED_RGB_BPTC_SIGNED_FLOAT"; break;
				case PixelInternalFormat::COMPRESSED_RGB_BPTC_UNSIGNED_FLOAT: return "GL_COMPRESSED_RGB_BPTC_UNSIGNED_FLOAT"; break;
				default: throw std::runtime_error("Unknown value for PixelInternalFormat enumeration."); break;
				}
			}
		} // namespace opengl
	} // namespace renderer
} // namespace ece