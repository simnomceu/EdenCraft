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

#ifndef PIXEL_DATA_TYPE_HPP
#define PIXEL_DATA_TYPE_HPP

#include "renderer/config.hpp"
#include "renderer/pch.hpp"
#include "GL/glcorearb.h"
#include "GL/glext.h"
#include "renderer/image/pixel_format.hpp"

namespace ece
{
	namespace renderer
	{
		namespace opengl
		{
			using image::PixelData;

			enum class PixelDataType : unsigned short int
			{
				UNSIGNED_BYTE = GL_UNSIGNED_BYTE,
				BYTE = GL_BYTE,
				UNSIGNED_SHORT = GL_UNSIGNED_SHORT,
				SHORT = GL_SHORT,
				UNSIGNED_INT = GL_UNSIGNED_INT,
				INT = GL_INT,
				FLOAT = GL_FLOAT,
				UNSIGNED_BYTE_3_3_2 = GL_UNSIGNED_BYTE_3_3_2,
				UNSIGNED_BYTE_2_3_3_REV = GL_UNSIGNED_BYTE_2_3_3_REV,
				UNSIGNED_SHORT_5_6_5 = GL_UNSIGNED_SHORT_5_6_5,
				UNSIGNED_SHORT_5_6_5_REV = GL_UNSIGNED_SHORT_5_6_5_REV,
				UNSIGNED_SHORT_4_4_4_4 = GL_UNSIGNED_SHORT_4_4_4_4,
				UNSIGNED_SHORT_4_4_4_4_REV = GL_UNSIGNED_SHORT_4_4_4_4_REV,
				UNSIGNED_SHORT_5_5_5_1 = GL_UNSIGNED_SHORT_5_5_5_1,
				UNSIGNED_SHORT_1_5_5_5_REV = GL_UNSIGNED_SHORT_1_5_5_5_REV,
				UNSIGNED_INT_8_8_8_8 = GL_UNSIGNED_INT_8_8_8_8,
				UNSIGNED_INT_8_8_8_8_REV = GL_UNSIGNED_INT_8_8_8_8_REV,
				UNSIGNED_INT_10_10_10_2 = GL_UNSIGNED_INT_10_10_10_2,
				UNSIGNED_INT_2_10_10_10_REV = GL_UNSIGNED_INT_2_10_10_10_REV
			};

			ECE_RENDERER_API PixelDataType getPixelDataType(PixelData::DataType type);

			ECE_RENDERER_API std::string to_string(PixelDataType type);
		} // namespace opengl
	} // namespace renderer
} // namespace ece

#endif // PIXEL_DATA_TYPE_HPP