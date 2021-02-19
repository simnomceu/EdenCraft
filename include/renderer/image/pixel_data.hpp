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

#ifndef PIXEL_DATA_HPP
#define PIXEL_DATA_HPP

#include "renderer/config.hpp"
#include "renderer/pch.hpp"
#include "utility/types.hpp"

namespace ece
{
	namespace renderer
	{
		namespace image
		{
			struct ECE_RENDERER_API PixelData
			{
			public:
				enum class DataType
				{
					UNSIGNED_BYTE				= 0x00,
					BYTE						= 0x01,
					UNSIGNED_SHORT				= 0x02,
					SHORT						= 0x03,
					UNSIGNED_INT				= 0x04,
					INT							= 0x05,
					FLOAT						= 0x06,
					UNSIGNED_BYTE_3_3_2			= 0x07,
					UNSIGNED_BYTE_2_3_3_REV		= 0x08,
					UNSIGNED_SHORT_5_6_5		= 0x09,
					UNSIGNED_SHORT_5_6_5_REV	= 0x10,
					UNSIGNED_SHORT_4_4_4_4		= 0x11,
					UNSIGNED_SHORT_4_4_4_4_REV	= 0x12,
					UNSIGNED_SHORT_5_5_5_1		= 0x13,
					UNSIGNED_SHORT_1_5_5_5_REV	= 0x14,
					UNSIGNED_INT_8_8_8_8		= 0x15,
					UNSIGNED_INT_8_8_8_8_REV	= 0x16,
					UNSIGNED_INT_10_10_10_2		= 0x17,
					UNSIGNED_INT_2_10_10_10_REV = 0x18
				};

				enum class Format
				{
					RED				= 0x00,
					RG				= 0x01,
					RGB				= 0x02,
					BGR				= 0x03,
					RGBA			= 0x04,
					BGRA			= 0x05,
					RED_INTEGER		= 0x06,
					RG_INTEGER		= 0x07,
					RGB_INTEGER		= 0x08,
					BGR_INTEGER		= 0x09,
					RGBA_INTEGER	= 0x10,
					BGRA_INTEGER	= 0x11,
					STENCIL_INDEX	= 0x12,
					DEPTH_COMPONENT = 0x13,
					DEPTH_STENCIL	= 0x14
				};

				enum class InternalFormat
				{
					DEPTH_COMPONENT						= 0x00,
					DEPTH_STENCIL						= 0x01,
					RED									= 0x02,
					RG									= 0x03,
					RGB									= 0x04,
					RGBA								= 0x05,
					R8									= 0x06,
					R8_SNORM							= 0x07,
					R16									= 0x08,
					R16_SNORM							= 0x09,
					RG8									= 0x10,
					RG8_SNORM							= 0x11,
					RG16								= 0x12,
					RG16_SNORM							= 0x13,
					R3_G3_B2							= 0x14,
					RGB4								= 0x15,
					RGB5								= 0x16,
					RGB8								= 0x17,
					RGB8_SNORM							= 0x18,
					RGB10								= 0x19,
					RGB12								= 0x20,
					RGB16_SNORM							= 0x21,
					RGBA2								= 0x22,
					RGBA4								= 0x23,
					RGB5_A1								= 0x24,
					RGBA8								= 0x25,
					RGBA8_SNORM							= 0x26,
					RGB10_A2							= 0x27,
					RGB10_A2UI							= 0x28,
					RGBA12								= 0x29,
					RGBA16								= 0x30,
					SRGB8								= 0x31,
					SRGB8_ALPHA8						= 0x32,
					R16F								= 0x33,
					RG16F								= 0x34,
					RGB16F								= 0x35,
					RGBA16F								= 0x36,
					R32F								= 0x37,
					RG32F								= 0x38,
					RGB32F								= 0x39,
					RGBA32F								= 0x40,
					R11F_G11F_B10F						= 0x41,
					RGB9_E5								= 0x42,
					R8I									= 0x43,
					R8UI								= 0x44,
					R16I								= 0x45,
					R16UI								= 0x46,
					R32I								= 0x47,
					R32UI								= 0x48,
					RG8I								= 0x49,
					RG8UI								= 0x50,
					RG16I								= 0x51,
					RG16UI								= 0x52,
					RG32I								= 0x53,
					RG32UI								= 0x54,
					RGB8I								= 0x55,
					RGB8UI								= 0x56,
					RGB16I								= 0x57,
					RGB16UI								= 0x58,
					RGB32I								= 0x59,
					RGB32UI								= 0x60,
					RGBA8I								= 0x61,
					RGBA8UI								= 0x62,
					RGBA16I								= 0x63,
					RGBA16UI							= 0x64,
					RGBA32I								= 0x65,
					RGBA32UI							= 0x66,
					COMPRESSED_RED						= 0x67,
					COMPRESSED_RG						= 0x68,
					COMPRESSED_RGB						= 0x69,
					COMPRESSED_RGBA						= 0x70,
					COMPRESSED_SRGB						= 0x71,
					COMPRESSED_SRGB_ALPHA				= 0x72,
					COMPRESSED_RED_RGTC1				= 0x73,
					COMPRESSED_SIGNED_RED_RGTC1			= 0x74,
					COMPRESSED_RG_RGTC2					= 0x75,
					COMPRESSED_SIGNED_RG_RGTC2			= 0x76,
					COMPRESSED_RGBA_BPTC_UNORM			= 0x77,
					COMPRESSED_SRGB_ALPHA_BPTC_UNORM	= 0x78,
					COMPRESSED_RGB_BPTC_SIGNED_FLOAT	= 0x79,
					COMPRESSED_RGB_BPTC_UNSIGNED_FLOAT	= 0x80,
					DEPTH_COMPONENT16					= 0x81,
					DEPTH_COMPONENT24					= 0x82,
					DEPTH_COMPONENT32					= 0x83,
					DEPTH_COMPONENT32F					= 0x84,
					DEPTH24_STENCIL8					= 0x85,
					DEPTH32F_STENCIL8					= 0x86,
					STENCIL_INDEX1						= 0x87,
					STENCIL_INDEX4						= 0x88,
					STENCIL_INDEX8						= 0x89,
					STENCIL_INDEX16						= 0x90
				};

				inline PixelData();
				PixelData(const PixelData & copy) = default;
				PixelData(PixelData && move) = default;

				~PixelData() = default;

				PixelData & operator=(const PixelData & copy) = default;
				PixelData & operator=(PixelData && move) = default;

				std::bitset<8> redMask;
				std::bitset<8> greenMask;
				std::bitset<8> blueMask;
				std::bitset<8> alphaMask;
				ece::size_t bpp;

				DataType type;
				Format format;
				InternalFormat internalFormat;
			};
		} // namespace image
	} // namespace renderer
} // namespace ece

#include "renderer/image/pixel_data.inl"

#endif // PIXEL_DATA_HPP
