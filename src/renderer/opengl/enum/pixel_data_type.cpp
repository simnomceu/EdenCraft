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
#include "renderer/opengl/enum/pixel_data_type.hpp"

namespace ece
{
	namespace renderer
	{
		namespace opengl
		{
			PixelDataType getPixelDataType(PixelData::DataType type)
			{
				switch (type) {
				case PixelData::DataType::UNSIGNED_BYTE: return PixelDataType::UNSIGNED_BYTE; break;
				case PixelData::DataType::BYTE: return PixelDataType::BYTE; break;
				case PixelData::DataType::UNSIGNED_SHORT: return PixelDataType::UNSIGNED_SHORT; break;
				case PixelData::DataType::SHORT: return PixelDataType::SHORT; break;
				case PixelData::DataType::UNSIGNED_INT: return PixelDataType::UNSIGNED_INT; break;
				case PixelData::DataType::INT: return PixelDataType::INT; break;
				case PixelData::DataType::FLOAT: return PixelDataType::FLOAT; break;
				case PixelData::DataType::UNSIGNED_BYTE_3_3_2: return PixelDataType::UNSIGNED_BYTE_3_3_2; break;
				case PixelData::DataType::UNSIGNED_BYTE_2_3_3_REV: return PixelDataType::UNSIGNED_BYTE_2_3_3_REV; break;
				case PixelData::DataType::UNSIGNED_SHORT_5_6_5: return PixelDataType::UNSIGNED_SHORT_5_6_5; break;
				case PixelData::DataType::UNSIGNED_SHORT_5_6_5_REV: return PixelDataType::UNSIGNED_SHORT_5_6_5_REV; break;
				case PixelData::DataType::UNSIGNED_SHORT_4_4_4_4: return PixelDataType::UNSIGNED_SHORT_4_4_4_4; break;
				case PixelData::DataType::UNSIGNED_SHORT_4_4_4_4_REV: return PixelDataType::UNSIGNED_SHORT_4_4_4_4_REV; break;
				case PixelData::DataType::UNSIGNED_SHORT_5_5_5_1: return PixelDataType::UNSIGNED_SHORT_5_5_5_1; break;
				case PixelData::DataType::UNSIGNED_SHORT_1_5_5_5_REV: return PixelDataType::UNSIGNED_SHORT_1_5_5_5_REV; break;
				case PixelData::DataType::UNSIGNED_INT_8_8_8_8: return PixelDataType::UNSIGNED_INT_8_8_8_8; break;
				case PixelData::DataType::UNSIGNED_INT_8_8_8_8_REV: return PixelDataType::UNSIGNED_INT_8_8_8_8_REV; break;
				case PixelData::DataType::UNSIGNED_INT_10_10_10_2: return PixelDataType::UNSIGNED_INT_10_10_10_2; break;
				case PixelData::DataType::UNSIGNED_INT_2_10_10_10_REV: return PixelDataType::UNSIGNED_INT_2_10_10_10_REV; break;
				default: throw std::runtime_error("Unknown value for PixelDataType enumeration."); break;
				}
			}

			std::string to_string(PixelDataType type)
			{
				switch (type) {
				case PixelDataType::UNSIGNED_BYTE: return "GL_UNSIGNED_BYTE"; break;
				case PixelDataType::BYTE: return "GL_BYTE"; break;
				case PixelDataType::UNSIGNED_SHORT: return "GL_UNSIGNED_SHORT"; break;
				case PixelDataType::SHORT: return "GL_SHORT"; break;
				case PixelDataType::UNSIGNED_INT: return "GL_UNSIGNED_INT"; break;
				case PixelDataType::INT: return "GL_INT"; break;
				case PixelDataType::FLOAT: return "GL_FLOAT"; break;
				case PixelDataType::UNSIGNED_BYTE_3_3_2: return "GL_UNSIGNED_BYTE_3_3_2"; break;
				case PixelDataType::UNSIGNED_BYTE_2_3_3_REV: return "GL_UNSIGNED_BYTE_2_3_3_REV"; break;
				case PixelDataType::UNSIGNED_SHORT_5_6_5: return "GL_UNSIGNED_SHORT_5_6_5"; break;
				case PixelDataType::UNSIGNED_SHORT_5_6_5_REV: return "GL_UNSIGNED_SHORT_5_6_5_REV"; break;
				case PixelDataType::UNSIGNED_SHORT_4_4_4_4: return "GL_UNSIGNED_SHORT_4_4_4_4"; break;
				case PixelDataType::UNSIGNED_SHORT_4_4_4_4_REV: return "GL_UNSIGNED_SHORT_4_4_4_4_REV"; break;
				case PixelDataType::UNSIGNED_SHORT_5_5_5_1: return "GL_UNSIGNED_SHORT_5_5_5_1"; break;
				case PixelDataType::UNSIGNED_SHORT_1_5_5_5_REV: return "GL_UNSIGNED_SHORT_1_5_5_5_REV"; break;
				case PixelDataType::UNSIGNED_INT_8_8_8_8: return "GL_UNSIGNED_INT_8_8_8_8"; break;
				case PixelDataType::UNSIGNED_INT_8_8_8_8_REV: return "GL_UNSIGNED_INT_8_8_8_8_REV"; break;
				case PixelDataType::UNSIGNED_INT_10_10_10_2: return "GL_UNSIGNED_INT_10_10_10_2"; break;
				case PixelDataType::UNSIGNED_INT_2_10_10_10_REV: return "GL_UNSIGNED_INT_2_10_10_10_REV"; break;
				default: throw std::runtime_error("Unknown value for PixelFormat enumeration."); break;
				}
			}
		} // namespace opengl
	} // namespace renderer
} // namespace ece