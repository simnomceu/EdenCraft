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

#include "renderer/opengl/enum/depth_function_condition.hpp"

#include <stdexcept>

namespace ece
{
	namespace renderer
	{
		namespace opengl
		{
			DepthFunctionCondition getDepthFunctionCondition(RenderState::DepthFunctionCondition condition)
			{
				switch (condition) {
				case RenderState::DepthFunctionCondition::NEVER: return DepthFunctionCondition::NEVER; break;
				case RenderState::DepthFunctionCondition::LESS: return DepthFunctionCondition::LESS; break;
				case RenderState::DepthFunctionCondition::EQUAL: return DepthFunctionCondition::EQUAL; break;
				case RenderState::DepthFunctionCondition::LEQUAL: return DepthFunctionCondition::LEQUAL; break;
				case RenderState::DepthFunctionCondition::GREATER: return DepthFunctionCondition::GREATER; break;
				case RenderState::DepthFunctionCondition::NOTEQUAL: return DepthFunctionCondition::NOTEQUAL; break;
				case RenderState::DepthFunctionCondition::GEQUAL: return DepthFunctionCondition::GEQUAL; break;
				case RenderState::DepthFunctionCondition::ALWAYS: return DepthFunctionCondition::ALWAYS; break;
				default: throw std::runtime_error("Unknown value for DepthFunctionCondition enumeration."); break;
				}
			}

			std::string to_string(DepthFunctionCondition condition)
			{
				switch (condition) {
				case DepthFunctionCondition::NEVER: return "GL_NEVER"; break;
				case DepthFunctionCondition::LESS: return "GL_LESS"; break;
				case DepthFunctionCondition::EQUAL: return "GL_EQUAL"; break;
				case DepthFunctionCondition::LEQUAL: return "GL_LEQUAL"; break;
				case DepthFunctionCondition::GREATER: return "GL_GREATER"; break;
				case DepthFunctionCondition::NOTEQUAL: return "GL_NOTEQUAL"; break;
				case DepthFunctionCondition::GEQUAL: return "GL_GEQUAL"; break;
				case DepthFunctionCondition::ALWAYS: return "GL_ALWAYS"; break;
				default: throw std::runtime_error("Unknown value for DepthFunctionCondition enumeration."); break;
				}
			}
		} // namespace opengl
	} // namespace renderer
} // namespace ece