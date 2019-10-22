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

#ifndef OPENGL_DATA_TYPE_HPP
#define OPENGL_DATA_TYPE_HPP

#include "renderer/config.hpp"
#include "GL/glcorearb.h"
#include "GL/glext.h"
#include "renderer/buffer/data_type.hpp"

namespace ece
{
	namespace renderer
	{
		namespace opengl
		{
			enum class DataType : unsigned short int
			{
				BYTE = GL_BYTE,
				UNSIGNED_BYTE = GL_UNSIGNED_BYTE,
				SHORT = GL_SHORT,
				UNSIGNED_SHORT = GL_UNSIGNED_SHORT,
				INT = GL_INT,
				UNSIGNED_INT = GL_UNSIGNED_INT,
				HALF_FLOAT = GL_HALF_FLOAT,
				FLOAT = GL_FLOAT,
				DOUBLE = GL_DOUBLE,
				FIXED = GL_FIXED,
				INT_2_10_10_10_REV = GL_INT_2_10_10_10_REV,
				UNSIGNED_INT_2_10_10_10_REV = GL_UNSIGNED_INT_2_10_10_10_REV,
				UNSIGNED_INT_10F_11F_11F_REV = GL_UNSIGNED_INT_10F_11F_11F_REV
			};

			ECE_RENDERER_API DataType getDataType(buffer::DataType type);
			ECE_RENDERER_API buffer::DataType getDataType(DataType type);

			ECE_RENDERER_API std::string to_string(DataType type);

			template <typename T>
			ECE_RENDERER_API inline constexpr DataType getType();
			template <> ECE_RENDERER_API inline constexpr DataType getType<char>();
			template <> ECE_RENDERER_API inline constexpr DataType getType<unsigned char>();
			template <> ECE_RENDERER_API inline constexpr DataType getType<short>();
			template <> ECE_RENDERER_API inline constexpr DataType getType<unsigned short>();
			template <> ECE_RENDERER_API inline constexpr DataType getType<int>();
			template <> ECE_RENDERER_API inline constexpr DataType getType<unsigned int>();
			template <> ECE_RENDERER_API inline constexpr DataType getType<float>();
			template <> ECE_RENDERER_API inline constexpr DataType getType<double>();
		} // namespace opengl
	} // namespace renderer
} // namespace ece

#include "renderer/opengl/enum/data_type.inl"

#endif // OPENGL_DATA_TYPE_HPP