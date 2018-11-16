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

#include "renderer/opengl/enum/data_type.hpp"

#include <stdexcept>

namespace ece
{
	namespace renderer
	{
		namespace opengl
		{

			DataType getDataType(buffer::DataType type)
			{
				switch (type) {
				case buffer::DataType::BYTE: return DataType::BYTE; break;
				case buffer::DataType::UNSIGNED_BYTE: return DataType::UNSIGNED_BYTE; break;
				case buffer::DataType::SHORT: return DataType::SHORT; break;
				case buffer::DataType::UNSIGNED_SHORT: return DataType::UNSIGNED_SHORT; break;
				case buffer::DataType::INT: return DataType::INT; break;
				case buffer::DataType::UNSIGNED_INT: return DataType::UNSIGNED_INT; break;
				case buffer::DataType::HALF_FLOAT: return DataType::HALF_FLOAT; break;
				case buffer::DataType::FLOAT: return DataType::FLOAT; break;
				case buffer::DataType::DOUBLE: return DataType::DOUBLE; break;
				case buffer::DataType::FIXED: return DataType::FIXED; break;
				case buffer::DataType::INT_2_10_10_10_REV: return DataType::INT_2_10_10_10_REV; break;
				case buffer::DataType::UNSIGNED_INT_2_10_10_10_REV: return DataType::UNSIGNED_INT_2_10_10_10_REV; break;
				case buffer::DataType::UNSIGNED_INT_10F_11F_11F_REV: return DataType::UNSIGNED_INT_10F_11F_11F_REV; break;
				default: throw std::runtime_error("Unknown value for DataType enumeration."); break;
				}
			}

			std::string to_string(DataType type)
			{
				switch (type) {
				case DataType::BYTE: return "GL_BYTE"; break;
				case DataType::UNSIGNED_BYTE: return "GL_UNSIGNED_BYTE"; break;
				case DataType::SHORT: return "GL_SHORT"; break;
				case DataType::UNSIGNED_SHORT: return "GL_UNSIGNED_SHORT"; break;
				case DataType::INT: return "GL_INT"; break;
				case DataType::UNSIGNED_INT: return "GL_UNSIGNED_INT"; break;
				case DataType::HALF_FLOAT: return "GL_HALF_FLOAT"; break;
				case DataType::FLOAT: return "GL_FLOAT"; break;
				case DataType::DOUBLE: return "GL_DOUBLE"; break;
				case DataType::FIXED: return "GL_FIXED"; break;
				case DataType::INT_2_10_10_10_REV: return "GL_INT_2_10_10_10_REV"; break;
				case DataType::UNSIGNED_INT_2_10_10_10_REV: return "GL_UNSIGNED_INT_2_10_10_10_REV"; break;
				case DataType::UNSIGNED_INT_10F_11F_11F_REV: return "GL_UNSIGNED_INT_10F_11F_11F_REV"; break;
				default: throw std::runtime_error("Unknown value for DataType enumeration."); break;
				}
			}
		} // namespace opengl
	} // namespace renderer
} // namespace ece