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

#ifndef IMAGE_FORMAT_HPP
#define IMAGE_FORMAT_HPP

#include "renderer/config.hpp"
#include "renderer/pch.hpp"

namespace ece
{
	namespace renderer
	{
		namespace image
		{
			struct ECE_RENDERER_API RGB24
			{
				std::byte red;
				std::byte green;
				std::byte blue;

				inline RGB24(): red(), green(), blue() {}

				inline RGB24(const unsigned short int r, const unsigned short int g, const unsigned short int b):
					red(static_cast<std::byte>(r)), green(static_cast<std::byte>(g)), blue(static_cast<std::byte>(b)) {}
			};

			struct ECE_RENDERER_API RGBA32 : public RGB24
			{
				std::byte alpha;

				inline RGBA32(): RGB24(), alpha() {}

				inline RGBA32(const unsigned short int r, const unsigned short int g, const unsigned short int b, const unsigned short int a):
					RGB24(r, g, b), alpha(static_cast<std::byte>(a)) {}
			};

			struct ECE_RENDERER_API HSV
			{
				unsigned short int hue;
				unsigned short int saturation;
				unsigned short int value;
			};

			struct ECE_RENDERER_API HSL
			{
				unsigned short int hue;
				unsigned short int saturation;
				unsigned short int lightness;
			};

			struct ECE_RENDERER_API CMYK
			{
				unsigned short int cyan;
				unsigned short int magenta;
				unsigned short int yellow;
				unsigned short int key;
			};

			struct PixelData
			{
				enum class Format : unsigned short int
				{
					RED = 0,
					RG = 1,
					RGB = 2,
					BGR = 3,
					RGBA = 4,
					BGRA = 5,
					RED_INTEGER = 6,
					RG_INTEGER = 7,
					RGB_INTEGER = 8,
					BGR_INTEGER = 9,
					RGBA_INTEGER = 10,
					BGRA_INTEGER = 11,
					STENCIL_INDEX = 12,
					DEPTH_COMPONENT = 13,
					DEPTH_STENCIL = 14
				};

				enum class InternalFormat : unsigned short int
				{
					DEPTH_COMPONENT = 0,
					DEPTH_STENCIL = 1,
					RED = 2,
					RG = 3,
					RGB = 4,
					RGBA = 5,
					R8 = 6,
					R8_SNORM = 7,
					R16 = 8,
					R16_SNORM = 9,
					RG8 = 10,
					RG8_SNORM = 11,
					RG16 = 12,
					RG16_SNORM = 13,
					R3_G3_B2 = 14,
					RGB4 = 15,
					RGB5 = 16,
					RGB8 = 17,
					RGB8_SNORM = 18,
					RGB10 = 19,
					RGB12 = 20,
					RGB16_SNORM = 21,
					RGBA2 = 22,
					RGBA4 = 23,
					RGB5_A1 = 24,
					RGBA8 = 25,
					RGBA8_SNORM = 26,
					RGB10_A2 = 27,
					RGB10_A2UI = 28,
					RGBA12 = 29,
					RGBA16 = 30,
					SRGB8 = 31,
					SRGB8_ALPHA8 = 32,
					R16F = 33,
					RG16F = 34,
					RGB16F = 35,
					RGBA16F = 36,
					R32F = 37,
					RG32F = 38,
					RGB32F = 39,
					RGBA32F = 40,
					R11F_G11F_B10F = 41,
					RGB9_E5 = 42,
					R8I = 43,
					R8UI = 44,
					R16I = 45,
					R16UI = 46,
					R32I = 47,
					R32UI = 48,
					RG8I = 49,
					RG8UI = 50,
					RG16I = 51,
					RG16UI = 52,
					RG32I = 53,
					RG32UI = 54,
					RGB8I = 55,
					RGB8UI = 56,
					RGB16I = 57,
					RGB16UI = 58,
					RGB32I = 59,
					RGB32UI = 60,
					RGBA8I = 61,
					RGBA8UI = 62,
					RGBA16I = 63,
					RGBA16UI = 64,
					RGBA32I = 65,
					RGBA32UI = 66,
					COMPRESSED_RED = 67,
					COMPRESSED_RG = 68,
					COMPRESSED_RGB = 69,
					COMPRESSED_RGBA = 70,
					COMPRESSED_SRGB = 71,
					COMPRESSED_SRGB_ALPHA = 72,
					COMPRESSED_RED_RGTC1 = 73,
					COMPRESSED_SIGNED_RED_RGTC1 = 74,
					COMPRESSED_RG_RGTC2 = 75,
					COMPRESSED_SIGNED_RG_RGTC2 = 76,
					COMPRESSED_RGBA_BPTC_UNORM = 77,
					COMPRESSED_SRGB_ALPHA_BPTC_UNORM = 78,
					COMPRESSED_RGB_BPTC_SIGNED_FLOAT = 79,
					COMPRESSED_RGB_BPTC_UNSIGNED_FLOAT = 80
				};

				enum class DataType : unsigned short int
				{
					UNSIGNED_BYTE = 0,
					BYTE = 1,
					UNSIGNED_SHORT = 2,
					SHORT = 3,
					UNSIGNED_INT = 4,
					INT = 5,
					FLOAT = 6,
					UNSIGNED_BYTE_3_3_2 = 7,
					UNSIGNED_BYTE_2_3_3_REV = 8,
					UNSIGNED_SHORT_5_6_5 = 9,
					UNSIGNED_SHORT_5_6_5_REV = 10,
					UNSIGNED_SHORT_4_4_4_4 = 11,
					UNSIGNED_SHORT_4_4_4_4_REV = 12,
					UNSIGNED_SHORT_5_5_5_1 = 13,
					UNSIGNED_SHORT_1_5_5_5_REV = 14,
					UNSIGNED_INT_8_8_8_8 = 15,
					UNSIGNED_INT_8_8_8_8_REV = 16,
					UNSIGNED_INT_10_10_10_2 = 17,
					UNSIGNED_INT_2_10_10_10_REV = 18
				};

				Format format;
				InternalFormat internalFormat;
				DataType type;
			};
		} // namespace image
	} // namespace renderer
} // namespace ece

#endif // IMAGE_FORMAT_HPP
