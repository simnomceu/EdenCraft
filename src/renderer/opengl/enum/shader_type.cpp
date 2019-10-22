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
#include "renderer/opengl/enum/shader_type.hpp"

namespace ece
{
	namespace renderer
	{
		namespace opengl
		{
			ShaderType getShaderType(ShaderStage::Type type)
			{
				switch (type) {
				case ShaderStage::Type::COMPUTE: return ShaderType::COMPUTE_SHADER; break;
				case ShaderStage::Type::FRAGMENT: return ShaderType::FRAGMENT_SHADER; break;
				case ShaderStage::Type::GEOMETRY: return ShaderType::GEOMETRY_SHADER; break;
				case ShaderStage::Type::VERTEX: return ShaderType::VERTEX_SHADER; break;
				case ShaderStage::Type::TESS_EVALUATION: return ShaderType::TESS_EVALUATION_SHADER; break;
				case ShaderStage::Type::TESS_CONTROL: return ShaderType::TESS_CONTROL_SHADER; break;
				default: throw std::runtime_error("Unknown value for ShaderType enumeration."); break;
				}
			}

			ShaderStage::Type getShaderType(ShaderType type)
			{
				switch (type) {
				case ShaderType::COMPUTE_SHADER: return ShaderStage::Type::COMPUTE; break;
				case ShaderType::FRAGMENT_SHADER: return ShaderStage::Type::FRAGMENT; break;
				case ShaderType::GEOMETRY_SHADER: return ShaderStage::Type::GEOMETRY; break;
				case ShaderType::VERTEX_SHADER: return ShaderStage::Type::VERTEX; break;
				case ShaderType::TESS_EVALUATION_SHADER: return ShaderStage::Type::TESS_EVALUATION; break;
				case ShaderType::TESS_CONTROL_SHADER: return ShaderStage::Type::TESS_CONTROL; break;
				default: throw std::runtime_error("Unknown value for ShaderStage::Type enumeration."); break;
				}
			}

			std::string to_string(ShaderType type)
			{
				switch (type) {
				case ShaderType::COMPUTE_SHADER: return "GL_COMPUTE_SHADER"; break;
				case ShaderType::FRAGMENT_SHADER: return "GL_FRAGMENT_SHADER"; break;
				case ShaderType::GEOMETRY_SHADER: return "GL_GEOMETRY_SHADER"; break;
				case ShaderType::VERTEX_SHADER: return "GL_VERTEX_SHADER"; break;
				case ShaderType::TESS_EVALUATION_SHADER: return "GL_TESS_EVALUATION_SHADER"; break;
				case ShaderType::TESS_CONTROL_SHADER: return "GL_TESS_CONTROL_SHADER"; break;
				default: throw std::runtime_error("Unknown value for ShaderType enumeration."); break;
				}
			}
		} // namespace opengl
	} // namespace renderer
} // namespace ece