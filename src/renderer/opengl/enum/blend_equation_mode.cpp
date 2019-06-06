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
#include "renderer/opengl/enum/blend_equation_mode.hpp"

namespace ece
{
	namespace renderer
	{
		namespace opengl
		{
			BlendEquationMode getBlendEquationMode(RenderState::BlendEquationMode mode)
			{
				switch (mode) {
				case RenderState::BlendEquationMode::FUNC_ADD: return BlendEquationMode::FUNC_ADD; break;
				case RenderState::BlendEquationMode::FUNC_SUBTRACT: return BlendEquationMode::FUNC_SUBTRACT; break;
				case RenderState::BlendEquationMode::FUNC_REVERSE_SUBTRACT: return BlendEquationMode::FUNC_REVERSE_SUBTRACT; break;
				case RenderState::BlendEquationMode::MIN: return BlendEquationMode::MIN; break;
				case RenderState::BlendEquationMode::MAX: return BlendEquationMode::MAX; break;
				default: throw std::runtime_error("Unknown value for BlendEquationMode enumeration."); break;
				}
			}

			RenderState::BlendEquationMode getBlendEquationMode(BlendEquationMode mode)
			{
				switch (mode) {
				case BlendEquationMode::FUNC_ADD: return RenderState::BlendEquationMode::FUNC_ADD; break;
				case BlendEquationMode::FUNC_SUBTRACT: return RenderState::BlendEquationMode::FUNC_SUBTRACT; break;
				case BlendEquationMode::FUNC_REVERSE_SUBTRACT: return RenderState::BlendEquationMode::FUNC_REVERSE_SUBTRACT; break;
				case BlendEquationMode::MIN: return RenderState::BlendEquationMode::MIN; break;
				case BlendEquationMode::MAX: return RenderState::BlendEquationMode::MAX; break;
				default: throw std::runtime_error("Unknown value for RenderState::BlendEquationMode enumeration."); break;
				}
			}

			std::string to_string(BlendEquationMode mode)
			{
				switch (mode) {
				case BlendEquationMode::FUNC_ADD: return "GL_FUNC_ADD"; break;
				case BlendEquationMode::FUNC_SUBTRACT: return "GL_FUNC_SUBTRACT"; break;
				case BlendEquationMode::FUNC_REVERSE_SUBTRACT: return "GL_FUNC_REVERSE_SUBTRACT"; break;
				case BlendEquationMode::MIN: return "GL_MIN"; break;
				case BlendEquationMode::MAX: return "GL_MAX"; break;
				default: throw std::runtime_error("Unknown value for BlendEquationMode enumeration."); break;
				}
			}
		} // namespace opengl
	} // namespace renderer
} // namespace ece