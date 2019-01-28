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
#include "renderer/opengl/enum/uniform_data_type.hpp"

namespace ece
{
	namespace renderer
	{
		namespace opengl
		{
			UniformDataType getUniformDataType(BaseUniform::DataType type)
			{
				switch (type) {
				case BaseUniform::DataType::FLOAT: return UniformDataType::FLOAT; break;
				case BaseUniform::DataType::FLOAT_VEC2: return UniformDataType::FLOAT_VEC2; break;
				case BaseUniform::DataType::FLOAT_VEC3: return UniformDataType::FLOAT_VEC3; break;
				case BaseUniform::DataType::FLOAT_VEC4: return UniformDataType::FLOAT_VEC4; break;
				case BaseUniform::DataType::DOUBLE: return UniformDataType::DOUBLE; break;
				case BaseUniform::DataType::DOUBLE_VEC2: return UniformDataType::DOUBLE_VEC2; break;
				case BaseUniform::DataType::DOUBLE_VEC3: return UniformDataType::DOUBLE_VEC3; break;
				case BaseUniform::DataType::DOUBLE_VEC4: return UniformDataType::DOUBLE_VEC4; break;
				case BaseUniform::DataType::INT: return UniformDataType::INT; break;
				case BaseUniform::DataType::INT_VEC2: return UniformDataType::INT_VEC2; break;
				case BaseUniform::DataType::INT_VEC3: return UniformDataType::INT_VEC3; break;
				case BaseUniform::DataType::INT_VEC4: return UniformDataType::INT_VEC4; break;
				case BaseUniform::DataType::UNSIGNED_INT: return UniformDataType::UNSIGNED_INT; break;
				case BaseUniform::DataType::UNSIGNED_INT_VEC2: return UniformDataType::UNSIGNED_INT_VEC2; break;
				case BaseUniform::DataType::UNSIGNED_INT_VEC3: return UniformDataType::UNSIGNED_INT_VEC3; break;
				case BaseUniform::DataType::UNSIGNED_INT_VEC4: return UniformDataType::UNSIGNED_INT_VEC4; break;
				case BaseUniform::DataType::BOOL: return UniformDataType::BOOL; break;
				case BaseUniform::DataType::BOOL_VEC2: return UniformDataType::BOOL_VEC2; break;
				case BaseUniform::DataType::BOOL_VEC3: return UniformDataType::BOOL_VEC3; break;
				case BaseUniform::DataType::BOOL_VEC4: return UniformDataType::BOOL_VEC4; break;
				case BaseUniform::DataType::FLOAT_MAT2: return UniformDataType::FLOAT_MAT2; break;
				case BaseUniform::DataType::FLOAT_MAT3: return UniformDataType::FLOAT_MAT3; break;
				case BaseUniform::DataType::FLOAT_MAT4: return UniformDataType::FLOAT_MAT4; break;
				case BaseUniform::DataType::FLOAT_MAT2x3: return UniformDataType::FLOAT_MAT2x3; break;
				case BaseUniform::DataType::FLOAT_MAT2x4: return UniformDataType::FLOAT_MAT2x4; break;
				case BaseUniform::DataType::FLOAT_MAT3x2: return UniformDataType::FLOAT_MAT3x2; break;
				case BaseUniform::DataType::FLOAT_MAT3x4: return UniformDataType::FLOAT_MAT3x4; break;
				case BaseUniform::DataType::FLOAT_MAT4x2: return UniformDataType::FLOAT_MAT4x2; break;
				case BaseUniform::DataType::FLOAT_MAT4x3: return UniformDataType::FLOAT_MAT4x3; break;
				case BaseUniform::DataType::DOUBLE_MAT2: return UniformDataType::DOUBLE_MAT2; break;
				case BaseUniform::DataType::DOUBLE_MAT3: return UniformDataType::DOUBLE_MAT3; break;
				case BaseUniform::DataType::DOUBLE_MAT4: return UniformDataType::DOUBLE_MAT4; break;
				case BaseUniform::DataType::DOUBLE_MAT2x3: return UniformDataType::DOUBLE_MAT2x3; break;
				case BaseUniform::DataType::DOUBLE_MAT2x4: return UniformDataType::DOUBLE_MAT2x4; break;
				case BaseUniform::DataType::DOUBLE_MAT3x2: return UniformDataType::DOUBLE_MAT3x2; break;
				case BaseUniform::DataType::DOUBLE_MAT3x4: return UniformDataType::DOUBLE_MAT3x4; break;
				case BaseUniform::DataType::DOUBLE_MAT4x2: return UniformDataType::DOUBLE_MAT4x2; break;
				case BaseUniform::DataType::DOUBLE_MAT4x3: return UniformDataType::DOUBLE_MAT4x3; break;
				case BaseUniform::DataType::SAMPLER_1D: return UniformDataType::SAMPLER_1D; break;
				case BaseUniform::DataType::SAMPLER_2D: return UniformDataType::SAMPLER_2D; break;
				case BaseUniform::DataType::SAMPLER_3D: return UniformDataType::SAMPLER_3D; break;
				case BaseUniform::DataType::SAMPLER_CUBE: return UniformDataType::SAMPLER_CUBE; break;
				case BaseUniform::DataType::SAMPLER_1D_SHADOW: return UniformDataType::SAMPLER_1D_SHADOW; break;
				case BaseUniform::DataType::SAMPLER_2D_SHADOW: return UniformDataType::SAMPLER_2D_SHADOW; break;
				case BaseUniform::DataType::SAMPLER_1D_ARRAY: return UniformDataType::SAMPLER_1D_ARRAY; break;
				case BaseUniform::DataType::SAMPLER_2D_ARRAY: return UniformDataType::SAMPLER_2D_ARRAY; break;
				case BaseUniform::DataType::SAMPLER_1D_ARRAY_SHADOW: return UniformDataType::SAMPLER_1D_ARRAY_SHADOW; break;
				case BaseUniform::DataType::SAMPLER_2D_ARRAY_SHADOW: return UniformDataType::SAMPLER_2D_ARRAY_SHADOW; break;
				case BaseUniform::DataType::SAMPLER_2D_MULTISAMPLE: return UniformDataType::SAMPLER_2D_MULTISAMPLE; break;
				case BaseUniform::DataType::SAMPLER_2D_MULTISAMPLE_ARRAY: return UniformDataType::SAMPLER_2D_MULTISAMPLE_ARRAY; break;
				case BaseUniform::DataType::SAMPLER_CUBE_SHADOW: return UniformDataType::SAMPLER_CUBE_SHADOW; break;
				case BaseUniform::DataType::SAMPLER_BUFFER: return UniformDataType::SAMPLER_BUFFER; break;
				case BaseUniform::DataType::SAMPLER_2D_RECT: return UniformDataType::SAMPLER_2D_RECT; break;
				case BaseUniform::DataType::SAMPLER_2D_RECT_SHADOW: return UniformDataType::SAMPLER_2D_RECT_SHADOW; break;
				case BaseUniform::DataType::INT_SAMPLER_1D: return UniformDataType::INT_SAMPLER_1D; break;
				case BaseUniform::DataType::INT_SAMPLER_2D: return UniformDataType::INT_SAMPLER_2D; break;
				case BaseUniform::DataType::INT_SAMPLER_3D: return UniformDataType::INT_SAMPLER_3D; break;
				case BaseUniform::DataType::INT_SAMPLER_CUBE: return UniformDataType::INT_SAMPLER_CUBE; break;
				case BaseUniform::DataType::INT_SAMPLER_1D_ARRAY: return UniformDataType::INT_SAMPLER_1D_ARRAY; break;
				case BaseUniform::DataType::INT_SAMPLER_2D_ARRAY: return UniformDataType::INT_SAMPLER_2D_ARRAY; break;
				case BaseUniform::DataType::INT_SAMPLER_2D_MULTISAMPLE: return UniformDataType::INT_SAMPLER_2D_MULTISAMPLE; break;
				case BaseUniform::DataType::INT_SAMPLER_2D_MULTISAMPLE_ARRAY: return UniformDataType::INT_SAMPLER_2D_MULTISAMPLE_ARRAY; break;
				case BaseUniform::DataType::INT_SAMPLER_BUFFER: return UniformDataType::INT_SAMPLER_BUFFER; break;
				case BaseUniform::DataType::INT_SAMPLER_2D_RECT: return UniformDataType::INT_SAMPLER_2D_RECT; break;
				case BaseUniform::DataType::UNSIGNED_INT_SAMPLER_1D: return UniformDataType::UNSIGNED_INT_SAMPLER_1D; break;
				case BaseUniform::DataType::UNSIGNED_INT_SAMPLER_2D: return UniformDataType::UNSIGNED_INT_SAMPLER_2D; break;
				case BaseUniform::DataType::UNSIGNED_INT_SAMPLER_3D: return UniformDataType::UNSIGNED_INT_SAMPLER_3D; break;
				case BaseUniform::DataType::UNSIGNED_INT_SAMPLER_CUBE: return UniformDataType::UNSIGNED_INT_SAMPLER_CUBE; break;
				case BaseUniform::DataType::UNSIGNED_INT_SAMPLER_1D_ARRAY: return UniformDataType::UNSIGNED_INT_SAMPLER_1D_ARRAY; break;
				case BaseUniform::DataType::UNSIGNED_INT_SAMPLER_2D_ARRAY: return UniformDataType::UNSIGNED_INT_SAMPLER_2D_ARRAY; break;
				case BaseUniform::DataType::UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE: return UniformDataType::UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE; break;
				case BaseUniform::DataType::UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE_ARRAY: return UniformDataType::UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE_ARRAY; break;
				case BaseUniform::DataType::UNSIGNED_INT_SAMPLER_BUFFER: return UniformDataType::UNSIGNED_INT_SAMPLER_BUFFER; break;
				case BaseUniform::DataType::UNSIGNED_INT_SAMPLER_2D_RECT: return UniformDataType::UNSIGNED_INT_SAMPLER_2D_RECT; break;
				case BaseUniform::DataType::IMAGE_1D: return UniformDataType::IMAGE_1D; break;
				case BaseUniform::DataType::IMAGE_2D: return UniformDataType::IMAGE_2D; break;
				case BaseUniform::DataType::IMAGE_3D: return UniformDataType::IMAGE_3D; break;
				case BaseUniform::DataType::IMAGE_2D_RECT: return UniformDataType::IMAGE_2D_RECT; break;
				case BaseUniform::DataType::IMAGE_CUBE: return UniformDataType::IMAGE_CUBE; break;
				case BaseUniform::DataType::IMAGE_BUFFER: return UniformDataType::IMAGE_BUFFER; break;
				case BaseUniform::DataType::IMAGE_1D_ARRAY: return UniformDataType::IMAGE_1D_ARRAY; break;
				case BaseUniform::DataType::IMAGE_2D_ARRAY: return UniformDataType::IMAGE_2D_ARRAY; break;
				case BaseUniform::DataType::IMAGE_2D_MULTISAMPLE: return UniformDataType::IMAGE_2D_MULTISAMPLE; break;
				case BaseUniform::DataType::IMAGE_2D_MULTISAMPLE_ARRAY: return UniformDataType::IMAGE_2D_MULTISAMPLE_ARRAY; break;
				case BaseUniform::DataType::INT_IMAGE_1D: return UniformDataType::INT_IMAGE_1D; break;
				case BaseUniform::DataType::INT_IMAGE_2D: return UniformDataType::INT_IMAGE_2D; break;
				case BaseUniform::DataType::INT_IMAGE_3D: return UniformDataType::INT_IMAGE_3D; break;
				case BaseUniform::DataType::INT_IMAGE_2D_RECT: return UniformDataType::INT_IMAGE_2D_RECT; break;
				case BaseUniform::DataType::INT_IMAGE_CUBE: return UniformDataType::INT_IMAGE_CUBE; break;
				case BaseUniform::DataType::INT_IMAGE_BUFFER: return UniformDataType::INT_IMAGE_BUFFER; break;
				case BaseUniform::DataType::INT_IMAGE_1D_ARRAY: return UniformDataType::INT_IMAGE_1D_ARRAY; break;
				case BaseUniform::DataType::INT_IMAGE_2D_ARRAY: return UniformDataType::INT_IMAGE_2D_ARRAY; break;
				case BaseUniform::DataType::INT_IMAGE_2D_MULTISAMPLE: return UniformDataType::INT_IMAGE_2D_MULTISAMPLE; break;
				case BaseUniform::DataType::INT_IMAGE_2D_MULTISAMPLE_ARRAY: return UniformDataType::INT_IMAGE_2D_MULTISAMPLE_ARRAY; break;
				case BaseUniform::DataType::UNSIGNED_INT_IMAGE_1D: return UniformDataType::UNSIGNED_INT_IMAGE_1D; break;
				case BaseUniform::DataType::UNSIGNED_INT_IMAGE_2D: return UniformDataType::UNSIGNED_INT_IMAGE_2D; break;
				case BaseUniform::DataType::UNSIGNED_INT_IMAGE_3D: return UniformDataType::UNSIGNED_INT_IMAGE_3D; break;
				case BaseUniform::DataType::UNSIGNED_INT_IMAGE_2D_RECT: return UniformDataType::UNSIGNED_INT_IMAGE_2D_RECT; break;
				case BaseUniform::DataType::UNSIGNED_INT_IMAGE_CUBE: return UniformDataType::UNSIGNED_INT_IMAGE_CUBE; break;
				case BaseUniform::DataType::UNSIGNED_INT_IMAGE_BUFFER: return UniformDataType::UNSIGNED_INT_IMAGE_BUFFER; break;
				case BaseUniform::DataType::UNSIGNED_INT_IMAGE_1D_ARRAY: return UniformDataType::UNSIGNED_INT_IMAGE_1D_ARRAY; break;
				case BaseUniform::DataType::UNSIGNED_INT_IMAGE_2D_ARRAY: return UniformDataType::UNSIGNED_INT_IMAGE_2D_ARRAY; break;
				case BaseUniform::DataType::UNSIGNED_INT_IMAGE_2D_MULTISAMPLE: return UniformDataType::UNSIGNED_INT_IMAGE_2D_MULTISAMPLE; break;
				case BaseUniform::DataType::UNSIGNED_INT_IMAGE_2D_MULTISAMPLE_ARRAY: return UniformDataType::UNSIGNED_INT_IMAGE_2D_MULTISAMPLE_ARRAY; break;
				case BaseUniform::DataType::UNSIGNED_INT_ATOMIC_COUNTER: return UniformDataType::UNSIGNED_INT_ATOMIC_COUNTER; break;
				default: throw std::runtime_error("Unknown value for UniformDataType enumeration."); break;
				}
			}

			UniformInfo getUniformInfo(BaseUniform::Info type)
			{
				return { type.name, getUniformDataType(type.type), type.size };
			}

			BaseUniform::DataType getUniformDataType(UniformDataType type)
			{
				switch (type) {
				case UniformDataType::FLOAT: return BaseUniform::DataType::FLOAT; break;
				case UniformDataType::FLOAT_VEC2: return BaseUniform::DataType::FLOAT_VEC2; break;
				case UniformDataType::FLOAT_VEC3: return BaseUniform::DataType::FLOAT_VEC3; break;
				case UniformDataType::FLOAT_VEC4: return BaseUniform::DataType::FLOAT_VEC4; break;
				case UniformDataType::DOUBLE: return BaseUniform::DataType::DOUBLE; break;
				case UniformDataType::DOUBLE_VEC2: return BaseUniform::DataType::DOUBLE_VEC2; break;
				case UniformDataType::DOUBLE_VEC3: return BaseUniform::DataType::DOUBLE_VEC3; break;
				case UniformDataType::DOUBLE_VEC4: return BaseUniform::DataType::DOUBLE_VEC4; break;
				case UniformDataType::INT: return BaseUniform::DataType::INT; break;
				case UniformDataType::INT_VEC2: return BaseUniform::DataType::INT_VEC2; break;
				case UniformDataType::INT_VEC3: return BaseUniform::DataType::INT_VEC3; break;
				case UniformDataType::INT_VEC4: return BaseUniform::DataType::INT_VEC4; break;
				case UniformDataType::UNSIGNED_INT: return BaseUniform::DataType::UNSIGNED_INT; break;
				case UniformDataType::UNSIGNED_INT_VEC2: return BaseUniform::DataType::UNSIGNED_INT_VEC2; break;
				case UniformDataType::UNSIGNED_INT_VEC3: return BaseUniform::DataType::UNSIGNED_INT_VEC3; break;
				case UniformDataType::UNSIGNED_INT_VEC4: return BaseUniform::DataType::UNSIGNED_INT_VEC4; break;
				case UniformDataType::BOOL: return BaseUniform::DataType::BOOL; break;
				case UniformDataType::BOOL_VEC2: return BaseUniform::DataType::BOOL_VEC2; break;
				case UniformDataType::BOOL_VEC3: return BaseUniform::DataType::BOOL_VEC3; break;
				case UniformDataType::BOOL_VEC4: return BaseUniform::DataType::BOOL_VEC4; break;
				case UniformDataType::FLOAT_MAT2: return BaseUniform::DataType::FLOAT_MAT2; break;
				case UniformDataType::FLOAT_MAT3: return BaseUniform::DataType::FLOAT_MAT3; break;
				case UniformDataType::FLOAT_MAT4: return BaseUniform::DataType::FLOAT_MAT4; break;
				case UniformDataType::FLOAT_MAT2x3: return BaseUniform::DataType::FLOAT_MAT2x3; break;
				case UniformDataType::FLOAT_MAT2x4: return BaseUniform::DataType::FLOAT_MAT2x4; break;
				case UniformDataType::FLOAT_MAT3x2: return BaseUniform::DataType::FLOAT_MAT3x2; break;
				case UniformDataType::FLOAT_MAT3x4: return BaseUniform::DataType::FLOAT_MAT3x4; break;
				case UniformDataType::FLOAT_MAT4x2: return BaseUniform::DataType::FLOAT_MAT4x2; break;
				case UniformDataType::FLOAT_MAT4x3: return BaseUniform::DataType::FLOAT_MAT4x3; break;
				case UniformDataType::DOUBLE_MAT2: return BaseUniform::DataType::DOUBLE_MAT2; break;
				case UniformDataType::DOUBLE_MAT3: return BaseUniform::DataType::DOUBLE_MAT3; break;
				case UniformDataType::DOUBLE_MAT4: return BaseUniform::DataType::DOUBLE_MAT4; break;
				case UniformDataType::DOUBLE_MAT2x3: return BaseUniform::DataType::DOUBLE_MAT2x3; break;
				case UniformDataType::DOUBLE_MAT2x4: return BaseUniform::DataType::DOUBLE_MAT2x4; break;
				case UniformDataType::DOUBLE_MAT3x2: return BaseUniform::DataType::DOUBLE_MAT3x2; break;
				case UniformDataType::DOUBLE_MAT3x4: return BaseUniform::DataType::DOUBLE_MAT3x4; break;
				case UniformDataType::DOUBLE_MAT4x2: return BaseUniform::DataType::DOUBLE_MAT4x2; break;
				case UniformDataType::DOUBLE_MAT4x3: return BaseUniform::DataType::DOUBLE_MAT4x3; break;
				case UniformDataType::SAMPLER_1D: return BaseUniform::DataType::SAMPLER_1D; break;
				case UniformDataType::SAMPLER_2D: return BaseUniform::DataType::SAMPLER_2D; break;
				case UniformDataType::SAMPLER_3D: return BaseUniform::DataType::SAMPLER_3D; break;
				case UniformDataType::SAMPLER_CUBE: return BaseUniform::DataType::SAMPLER_CUBE; break;
				case UniformDataType::SAMPLER_1D_SHADOW: return BaseUniform::DataType::SAMPLER_1D_SHADOW; break;
				case UniformDataType::SAMPLER_2D_SHADOW: return BaseUniform::DataType::SAMPLER_2D_SHADOW; break;
				case UniformDataType::SAMPLER_1D_ARRAY: return BaseUniform::DataType::SAMPLER_1D_ARRAY; break;
				case UniformDataType::SAMPLER_2D_ARRAY: return BaseUniform::DataType::SAMPLER_2D_ARRAY; break;
				case UniformDataType::SAMPLER_1D_ARRAY_SHADOW: return BaseUniform::DataType::SAMPLER_1D_ARRAY_SHADOW; break;
				case UniformDataType::SAMPLER_2D_ARRAY_SHADOW: return BaseUniform::DataType::SAMPLER_2D_ARRAY_SHADOW; break;
				case UniformDataType::SAMPLER_2D_MULTISAMPLE: return BaseUniform::DataType::SAMPLER_2D_MULTISAMPLE; break;
				case UniformDataType::SAMPLER_2D_MULTISAMPLE_ARRAY: return BaseUniform::DataType::SAMPLER_2D_MULTISAMPLE_ARRAY; break;
				case UniformDataType::SAMPLER_CUBE_SHADOW: return BaseUniform::DataType::SAMPLER_CUBE_SHADOW; break;
				case UniformDataType::SAMPLER_BUFFER: return BaseUniform::DataType::SAMPLER_BUFFER; break;
				case UniformDataType::SAMPLER_2D_RECT: return BaseUniform::DataType::SAMPLER_2D_RECT; break;
				case UniformDataType::SAMPLER_2D_RECT_SHADOW: return BaseUniform::DataType::SAMPLER_2D_RECT_SHADOW; break;
				case UniformDataType::INT_SAMPLER_1D: return BaseUniform::DataType::INT_SAMPLER_1D; break;
				case UniformDataType::INT_SAMPLER_2D: return BaseUniform::DataType::INT_SAMPLER_2D; break;
				case UniformDataType::INT_SAMPLER_3D: return BaseUniform::DataType::INT_SAMPLER_3D; break;
				case UniformDataType::INT_SAMPLER_CUBE: return BaseUniform::DataType::INT_SAMPLER_CUBE; break;
				case UniformDataType::INT_SAMPLER_1D_ARRAY: return BaseUniform::DataType::INT_SAMPLER_1D_ARRAY; break;
				case UniformDataType::INT_SAMPLER_2D_ARRAY: return BaseUniform::DataType::INT_SAMPLER_2D_ARRAY; break;
				case UniformDataType::INT_SAMPLER_2D_MULTISAMPLE: return BaseUniform::DataType::INT_SAMPLER_2D_MULTISAMPLE; break;
				case UniformDataType::INT_SAMPLER_2D_MULTISAMPLE_ARRAY: return BaseUniform::DataType::INT_SAMPLER_2D_MULTISAMPLE_ARRAY; break;
				case UniformDataType::INT_SAMPLER_BUFFER: return BaseUniform::DataType::INT_SAMPLER_BUFFER; break;
				case UniformDataType::INT_SAMPLER_2D_RECT: return BaseUniform::DataType::INT_SAMPLER_2D_RECT; break;
				case UniformDataType::UNSIGNED_INT_SAMPLER_1D: return BaseUniform::DataType::UNSIGNED_INT_SAMPLER_1D; break;
				case UniformDataType::UNSIGNED_INT_SAMPLER_2D: return BaseUniform::DataType::UNSIGNED_INT_SAMPLER_2D; break;
				case UniformDataType::UNSIGNED_INT_SAMPLER_3D: return BaseUniform::DataType::UNSIGNED_INT_SAMPLER_3D; break;
				case UniformDataType::UNSIGNED_INT_SAMPLER_CUBE: return BaseUniform::DataType::UNSIGNED_INT_SAMPLER_CUBE; break;
				case UniformDataType::UNSIGNED_INT_SAMPLER_1D_ARRAY: return BaseUniform::DataType::UNSIGNED_INT_SAMPLER_1D_ARRAY; break;
				case UniformDataType::UNSIGNED_INT_SAMPLER_2D_ARRAY: return BaseUniform::DataType::UNSIGNED_INT_SAMPLER_2D_ARRAY; break;
				case UniformDataType::UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE: return BaseUniform::DataType::UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE; break;
				case UniformDataType::UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE_ARRAY: return BaseUniform::DataType::UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE_ARRAY; break;
				case UniformDataType::UNSIGNED_INT_SAMPLER_BUFFER: return BaseUniform::DataType::UNSIGNED_INT_SAMPLER_BUFFER; break;
				case UniformDataType::UNSIGNED_INT_SAMPLER_2D_RECT: return BaseUniform::DataType::UNSIGNED_INT_SAMPLER_2D_RECT; break;
				case UniformDataType::IMAGE_1D: return BaseUniform::DataType::IMAGE_1D; break;
				case UniformDataType::IMAGE_2D: return BaseUniform::DataType::IMAGE_2D; break;
				case UniformDataType::IMAGE_3D: return BaseUniform::DataType::IMAGE_3D; break;
				case UniformDataType::IMAGE_2D_RECT: return BaseUniform::DataType::IMAGE_2D_RECT; break;
				case UniformDataType::IMAGE_CUBE: return BaseUniform::DataType::IMAGE_CUBE; break;
				case UniformDataType::IMAGE_BUFFER: return BaseUniform::DataType::IMAGE_BUFFER; break;
				case UniformDataType::IMAGE_1D_ARRAY: return BaseUniform::DataType::IMAGE_1D_ARRAY; break;
				case UniformDataType::IMAGE_2D_ARRAY: return BaseUniform::DataType::IMAGE_2D_ARRAY; break;
				case UniformDataType::IMAGE_2D_MULTISAMPLE: return BaseUniform::DataType::IMAGE_2D_MULTISAMPLE; break;
				case UniformDataType::IMAGE_2D_MULTISAMPLE_ARRAY: return BaseUniform::DataType::IMAGE_2D_MULTISAMPLE_ARRAY; break;
				case UniformDataType::INT_IMAGE_1D: return BaseUniform::DataType::INT_IMAGE_1D; break;
				case UniformDataType::INT_IMAGE_2D: return BaseUniform::DataType::INT_IMAGE_2D; break;
				case UniformDataType::INT_IMAGE_3D: return BaseUniform::DataType::INT_IMAGE_3D; break;
				case UniformDataType::INT_IMAGE_2D_RECT: return BaseUniform::DataType::INT_IMAGE_2D_RECT; break;
				case UniformDataType::INT_IMAGE_CUBE: return BaseUniform::DataType::INT_IMAGE_CUBE; break;
				case UniformDataType::INT_IMAGE_BUFFER: return BaseUniform::DataType::INT_IMAGE_BUFFER; break;
				case UniformDataType::INT_IMAGE_1D_ARRAY: return BaseUniform::DataType::INT_IMAGE_1D_ARRAY; break;
				case UniformDataType::INT_IMAGE_2D_ARRAY: return BaseUniform::DataType::INT_IMAGE_2D_ARRAY; break;
				case UniformDataType::INT_IMAGE_2D_MULTISAMPLE: return BaseUniform::DataType::INT_IMAGE_2D_MULTISAMPLE; break;
				case UniformDataType::INT_IMAGE_2D_MULTISAMPLE_ARRAY: return BaseUniform::DataType::INT_IMAGE_2D_MULTISAMPLE_ARRAY; break;
				case UniformDataType::UNSIGNED_INT_IMAGE_1D: return BaseUniform::DataType::UNSIGNED_INT_IMAGE_1D; break;
				case UniformDataType::UNSIGNED_INT_IMAGE_2D: return BaseUniform::DataType::UNSIGNED_INT_IMAGE_2D; break;
				case UniformDataType::UNSIGNED_INT_IMAGE_3D: return BaseUniform::DataType::UNSIGNED_INT_IMAGE_3D; break;
				case UniformDataType::UNSIGNED_INT_IMAGE_2D_RECT: return BaseUniform::DataType::UNSIGNED_INT_IMAGE_2D_RECT; break;
				case UniformDataType::UNSIGNED_INT_IMAGE_CUBE: return BaseUniform::DataType::UNSIGNED_INT_IMAGE_CUBE; break;
				case UniformDataType::UNSIGNED_INT_IMAGE_BUFFER: return BaseUniform::DataType::UNSIGNED_INT_IMAGE_BUFFER; break;
				case UniformDataType::UNSIGNED_INT_IMAGE_1D_ARRAY: return BaseUniform::DataType::UNSIGNED_INT_IMAGE_1D_ARRAY; break;
				case UniformDataType::UNSIGNED_INT_IMAGE_2D_ARRAY: return BaseUniform::DataType::UNSIGNED_INT_IMAGE_2D_ARRAY; break;
				case UniformDataType::UNSIGNED_INT_IMAGE_2D_MULTISAMPLE: return BaseUniform::DataType::UNSIGNED_INT_IMAGE_2D_MULTISAMPLE; break;
				case UniformDataType::UNSIGNED_INT_IMAGE_2D_MULTISAMPLE_ARRAY: return BaseUniform::DataType::UNSIGNED_INT_IMAGE_2D_MULTISAMPLE_ARRAY; break;
				case UniformDataType::UNSIGNED_INT_ATOMIC_COUNTER: return BaseUniform::DataType::UNSIGNED_INT_ATOMIC_COUNTER; break;
				default: throw std::runtime_error("Unknown value for UniformDataType enumeration."); break;
				}
			}

			BaseUniform::Info getUniformInfo(UniformInfo type)
			{
				return { type.name, getUniformDataType(type.type), type.size };
			}

			std::string to_string(UniformDataType type)
			{
				switch (type) {
				case UniformDataType::FLOAT: return "GL_FLOAT"; break;
				case UniformDataType::FLOAT_VEC2: return "GL_FLOAT_VEC2"; break;
				case UniformDataType::FLOAT_VEC3: return "GL_FLOAT_VEC3"; break;
				case UniformDataType::FLOAT_VEC4: return "GL_FLOAT_VEC4"; break;
				case UniformDataType::DOUBLE: return "GL_DOUBLE"; break;
				case UniformDataType::DOUBLE_VEC2: return "GL_DOUBLE_VEC2"; break;
				case UniformDataType::DOUBLE_VEC3: return "GL_DOUBLE_VEC3"; break;
				case UniformDataType::DOUBLE_VEC4: return "GL_DOUBLE_VEC4"; break;
				case UniformDataType::INT: return "GL_INT"; break;
				case UniformDataType::INT_VEC2: return "GL_INT_VEC2"; break;
				case UniformDataType::INT_VEC3: return "GL_INT_VEC3"; break;
				case UniformDataType::INT_VEC4: return "GL_INT_VEC4"; break;
				case UniformDataType::UNSIGNED_INT: return "GL_UNSIGNED_INT"; break;
				case UniformDataType::UNSIGNED_INT_VEC2: return "GL_UNSIGNED_INT_VEC2"; break;
				case UniformDataType::UNSIGNED_INT_VEC3: return "GL_UNSIGNED_INT_VEC3"; break;
				case UniformDataType::UNSIGNED_INT_VEC4: return "GL_UNSIGNED_INT_VEC4"; break;
				case UniformDataType::BOOL: return "GL_BOOL"; break;
				case UniformDataType::BOOL_VEC2: return "GL_BOOL_VEC2"; break;
				case UniformDataType::BOOL_VEC3: return "GL_BOOL_VEC3"; break;
				case UniformDataType::BOOL_VEC4: return "GL_BOOL_VEC4"; break;
				case UniformDataType::FLOAT_MAT2: return "GL_FLOAT_MAT2"; break;
				case UniformDataType::FLOAT_MAT3: return "GL_FLOAT_MAT3"; break;
				case UniformDataType::FLOAT_MAT4: return "GL_FLOAT_MAT4"; break;
				case UniformDataType::FLOAT_MAT2x3: return "GL_FLOAT_MAT2x3"; break;
				case UniformDataType::FLOAT_MAT2x4: return "GL_FLOAT_MAT2x4"; break;
				case UniformDataType::FLOAT_MAT3x2: return "GL_FLOAT_MAT3x2"; break;
				case UniformDataType::FLOAT_MAT3x4: return "GL_FLOAT_MAT3x4"; break;
				case UniformDataType::FLOAT_MAT4x2: return "GL_FLOAT_MAT4x2"; break;
				case UniformDataType::FLOAT_MAT4x3: return "GL_FLOAT_MAT4x3"; break;
				case UniformDataType::DOUBLE_MAT2: return "GL_DOUBLE_MAT2"; break;
				case UniformDataType::DOUBLE_MAT3: return "GL_DOUBLE_MAT3"; break;
				case UniformDataType::DOUBLE_MAT4: return "GL_DOUBLE_MAT4"; break;
				case UniformDataType::DOUBLE_MAT2x3: return "GL_DOUBLE_MAT2x3"; break;
				case UniformDataType::DOUBLE_MAT2x4: return "GL_DOUBLE_MAT2x4"; break;
				case UniformDataType::DOUBLE_MAT3x2: return "GL_DOUBLE_MAT3x2"; break;
				case UniformDataType::DOUBLE_MAT3x4: return "GL_DOUBLE_MAT3x4"; break;
				case UniformDataType::DOUBLE_MAT4x2: return "GL_DOUBLE_MAT4x2"; break;
				case UniformDataType::DOUBLE_MAT4x3: return "GL_DOUBLE_MAT4x3"; break;
				case UniformDataType::SAMPLER_1D: return "GL_SAMPLER_1D"; break;
				case UniformDataType::SAMPLER_2D: return "GL_SAMPLER_2D"; break;
				case UniformDataType::SAMPLER_3D: return "GL_SAMPLER_3D"; break;
				case UniformDataType::SAMPLER_CUBE: return "GL_SAMPLER_CUBE"; break;
				case UniformDataType::SAMPLER_1D_SHADOW: return "GL_SAMPLER_1D_SHADOW"; break;
				case UniformDataType::SAMPLER_2D_SHADOW: return "GL_SAMPLER_2D_SHADOW"; break;
				case UniformDataType::SAMPLER_1D_ARRAY: return "GL_SAMPLER_1D_ARRAY"; break;
				case UniformDataType::SAMPLER_2D_ARRAY: return "GL_SAMPLER_2D_ARRAY"; break;
				case UniformDataType::SAMPLER_1D_ARRAY_SHADOW: return "GL_SAMPLER_1D_ARRAY_SHADOW"; break;
				case UniformDataType::SAMPLER_2D_ARRAY_SHADOW: return "GL_SAMPLER_2D_ARRAY_SHADOW"; break;
				case UniformDataType::SAMPLER_2D_MULTISAMPLE: return "GL_SAMPLER_2D_MULTISAMPLE"; break;
				case UniformDataType::SAMPLER_2D_MULTISAMPLE_ARRAY: return "GL_SAMPLER_2D_MULTISAMPLE_ARRAY"; break;
				case UniformDataType::SAMPLER_CUBE_SHADOW: return "GL_SAMPLER_CUBE_SHADOW"; break;
				case UniformDataType::SAMPLER_BUFFER: return "GL_SAMPLER_BUFFER"; break;
				case UniformDataType::SAMPLER_2D_RECT: return "GL_SAMPLER_2D_RECT"; break;
				case UniformDataType::SAMPLER_2D_RECT_SHADOW: return "GL_SAMPLER_2D_RECT_SHADOW"; break;
				case UniformDataType::INT_SAMPLER_1D: return "GL_INT_SAMPLER_1D"; break;
				case UniformDataType::INT_SAMPLER_2D: return "GL_INT_SAMPLER_2D"; break;
				case UniformDataType::INT_SAMPLER_3D: return "GL_INT_SAMPLER_3D"; break;
				case UniformDataType::INT_SAMPLER_CUBE: return "GL_INT_SAMPLER_CUBE"; break;
				case UniformDataType::INT_SAMPLER_1D_ARRAY: return "GL_INT_SAMPLER_1D_ARRAY"; break;
				case UniformDataType::INT_SAMPLER_2D_ARRAY: return "GL_INT_SAMPLER_2D_ARRAY"; break;
				case UniformDataType::INT_SAMPLER_2D_MULTISAMPLE: return "GL_INT_SAMPLER_2D_MULTISAMPLE"; break;
				case UniformDataType::INT_SAMPLER_2D_MULTISAMPLE_ARRAY: return "GL_INT_SAMPLER_2D_MULTISAMPLE_ARRAY"; break;
				case UniformDataType::INT_SAMPLER_BUFFER: return "GL_INT_SAMPLER_BUFFER"; break;
				case UniformDataType::INT_SAMPLER_2D_RECT: return "GL_INT_SAMPLER_2D_RECT"; break;
				case UniformDataType::UNSIGNED_INT_SAMPLER_1D: return "GL_UNSIGNED_INT_SAMPLER_1D"; break;
				case UniformDataType::UNSIGNED_INT_SAMPLER_2D: return "GL_UNSIGNED_INT_SAMPLER_2D"; break;
				case UniformDataType::UNSIGNED_INT_SAMPLER_3D: return "GL_UNSIGNED_INT_SAMPLER_3D"; break;
				case UniformDataType::UNSIGNED_INT_SAMPLER_CUBE: return "GL_UNSIGNED_INT_SAMPLER_CUBE"; break;
				case UniformDataType::UNSIGNED_INT_SAMPLER_1D_ARRAY: return "GL_UNSIGNED_INT_SAMPLER_1D_ARRAY"; break;
				case UniformDataType::UNSIGNED_INT_SAMPLER_2D_ARRAY: return "GL_UNSIGNED_INT_SAMPLER_2D_ARRAY"; break;
				case UniformDataType::UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE: return "GL_UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE"; break;
				case UniformDataType::UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE_ARRAY: return "GL_UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE_ARRAY"; break;
				case UniformDataType::UNSIGNED_INT_SAMPLER_BUFFER: return "GL_UNSIGNED_INT_SAMPLER_BUFFER"; break;
				case UniformDataType::UNSIGNED_INT_SAMPLER_2D_RECT: return "GL_UNSIGNED_INT_SAMPLER_2D_RECT"; break;
				case UniformDataType::IMAGE_1D: return "GL_IMAGE_1D"; break;
				case UniformDataType::IMAGE_2D: return "GL_IMAGE_2D"; break;
				case UniformDataType::IMAGE_3D: return "GL_IMAGE_3D"; break;
				case UniformDataType::IMAGE_2D_RECT: return "GL_IMAGE_2D_RECT"; break;
				case UniformDataType::IMAGE_CUBE: return "GL_IMAGE_CUBE"; break;
				case UniformDataType::IMAGE_BUFFER: return "GL_IMAGE_BUFFER"; break;
				case UniformDataType::IMAGE_1D_ARRAY: return "GL_IMAGE_1D_ARRAY"; break;
				case UniformDataType::IMAGE_2D_ARRAY: return "GL_IMAGE_2D_ARRAY"; break;
				case UniformDataType::IMAGE_2D_MULTISAMPLE: return "GL_IMAGE_2D_MULTISAMPLE"; break;
				case UniformDataType::IMAGE_2D_MULTISAMPLE_ARRAY: return "GL_IMAGE_2D_MULTISAMPLE_ARRAY"; break;
				case UniformDataType::INT_IMAGE_1D: return "GL_INT_IMAGE_1D"; break;
				case UniformDataType::INT_IMAGE_2D: return "GL_INT_IMAGE_2D"; break;
				case UniformDataType::INT_IMAGE_3D: return "GL_INT_IMAGE_3D"; break;
				case UniformDataType::INT_IMAGE_2D_RECT: return "GL_INT_IMAGE_2D_RECT"; break;
				case UniformDataType::INT_IMAGE_CUBE: return "GL_INT_IMAGE_CUBE"; break;
				case UniformDataType::INT_IMAGE_BUFFER: return "GL_INT_IMAGE_BUFFER"; break;
				case UniformDataType::INT_IMAGE_1D_ARRAY: return "GL_INT_IMAGE_1D_ARRAY"; break;
				case UniformDataType::INT_IMAGE_2D_ARRAY: return "GL_INT_IMAGE_2D_ARRAY"; break;
				case UniformDataType::INT_IMAGE_2D_MULTISAMPLE: return "GL_INT_IMAGE_2D_MULTISAMPLE"; break;
				case UniformDataType::INT_IMAGE_2D_MULTISAMPLE_ARRAY: return "GL_INT_IMAGE_2D_MULTISAMPLE_ARRAY"; break;
				case UniformDataType::UNSIGNED_INT_IMAGE_1D: return "GL_UNSIGNED_INT_IMAGE_1D"; break;
				case UniformDataType::UNSIGNED_INT_IMAGE_2D: return "GL_UNSIGNED_INT_IMAGE_2D"; break;
				case UniformDataType::UNSIGNED_INT_IMAGE_3D: return "GL_UNSIGNED_INT_IMAGE_3D"; break;
				case UniformDataType::UNSIGNED_INT_IMAGE_2D_RECT: return "GL_UNSIGNED_INT_IMAGE_2D_RECT"; break;
				case UniformDataType::UNSIGNED_INT_IMAGE_CUBE: return "GL_UNSIGNED_INT_IMAGE_CUBE"; break;
				case UniformDataType::UNSIGNED_INT_IMAGE_BUFFER: return "GL_UNSIGNED_INT_IMAGE_BUFFER"; break;
				case UniformDataType::UNSIGNED_INT_IMAGE_1D_ARRAY: return "GL_UNSIGNED_INT_IMAGE_1D_ARRAY"; break;
				case UniformDataType::UNSIGNED_INT_IMAGE_2D_ARRAY: return "GL_UNSIGNED_INT_IMAGE_2D_ARRAY"; break;
				case UniformDataType::UNSIGNED_INT_IMAGE_2D_MULTISAMPLE: return "GL_UNSIGNED_INT_IMAGE_2D_MULTISAMPLE"; break;
				case UniformDataType::UNSIGNED_INT_IMAGE_2D_MULTISAMPLE_ARRAY: return "GL_UNSIGNED_INT_IMAGE_2D_MULTISAMPLE_ARRAY"; break;
				case UniformDataType::UNSIGNED_INT_ATOMIC_COUNTER: return "GL_UNSIGNED_INT_ATOMIC_COUNTER"; break;
				default: throw std::runtime_error("Unknown value for UniformDataType enumeration."); break;
				}
			}
		} // namespace opengl
	} // namespace renderer
} // namespace ece