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
#include "renderer/opengl/enum/blending_factor.hpp"

namespace ece
{
	namespace renderer
	{
		namespace opengl
		{
			BlendingFactor getBlendingFactor(RenderState::BlendingFactor type)
			{
				switch (type) {
				case RenderState::BlendingFactor::ZERO: return BlendingFactor::ZERO; break;
				case RenderState::BlendingFactor::ONE: return BlendingFactor::ONE; break;
				case RenderState::BlendingFactor::SRC_COLOR: return BlendingFactor::SRC_COLOR; break;
				case RenderState::BlendingFactor::ONE_MINUS_SRC_COLOR: return BlendingFactor::ONE_MINUS_SRC_COLOR; break;
				case RenderState::BlendingFactor::DST_COLOR: return BlendingFactor::DST_COLOR; break;
				case RenderState::BlendingFactor::ONE_MINUS_DST_COLOR: return BlendingFactor::ONE_MINUS_DST_COLOR; break;
				case RenderState::BlendingFactor::SRC_ALPHA: return BlendingFactor::SRC_ALPHA; break;
				case RenderState::BlendingFactor::ONE_MINUS_SRC_ALPHA: return BlendingFactor::ONE_MINUS_SRC_ALPHA; break;
				case RenderState::BlendingFactor::DST_ALPHA: return BlendingFactor::DST_ALPHA; break;
				case RenderState::BlendingFactor::ONE_MINUS_DST_ALPHA: return BlendingFactor::ONE_MINUS_DST_ALPHA; break;
				case RenderState::BlendingFactor::CONSTANT_COLOR: return BlendingFactor::CONSTANT_COLOR; break;
				case RenderState::BlendingFactor::ONE_MINUS_CONSTANT_COLOR: return BlendingFactor::ONE_MINUS_CONSTANT_COLOR; break;
				case RenderState::BlendingFactor::CONSTANT_ALPHA: return BlendingFactor::CONSTANT_ALPHA; break;
				case RenderState::BlendingFactor::ONE_MINUS_CONSTANT_ALPHA: return BlendingFactor::ONE_MINUS_CONSTANT_ALPHA; break;
				case RenderState::BlendingFactor::SRC_ALPHA_SATURATE: return BlendingFactor::SRC_ALPHA_SATURATE; break;
				case RenderState::BlendingFactor::SRC1_COLOR: return BlendingFactor::SRC1_COLOR; break;
				case RenderState::BlendingFactor::ONE_MINUS_SRC1_COLOR: return BlendingFactor::ONE_MINUS_SRC1_COLOR; break;
				case RenderState::BlendingFactor::SRC1_ALPHA: return BlendingFactor::SRC1_ALPHA; break;
				case RenderState::BlendingFactor::ONE_MINUS_SRC1_ALPHA: return BlendingFactor::ONE_MINUS_SRC1_ALPHA; break;
				default: throw std::runtime_error("Unknown value for BlendingFactor enumeration."); break;
				}
			}

			std::string to_string(BlendingFactor type)
			{
				switch (type) {
				case BlendingFactor::ZERO: return "GL_ZERO"; break;
				case BlendingFactor::ONE: return "GL_ONE"; break;
				case BlendingFactor::SRC_COLOR: return "GL_SRC_COLOR"; break;
				case BlendingFactor::ONE_MINUS_SRC_COLOR: return "GL_ONE_MINUS_SRC_COLOR"; break;
				case BlendingFactor::DST_COLOR: return "GL_DST_COLOR"; break;
				case BlendingFactor::ONE_MINUS_DST_COLOR: return "GL_ONE_MINUS_DST_COLOR"; break;
				case BlendingFactor::SRC_ALPHA: return "GL_SRC_ALPHA"; break;
				case BlendingFactor::ONE_MINUS_SRC_ALPHA: return "GL_ONE_MINUS_SRC_ALPHA"; break;
				case BlendingFactor::DST_ALPHA: return "GL_DST_ALPHA"; break;
				case BlendingFactor::ONE_MINUS_DST_ALPHA: return "GL_ONE_MINUS_DST_ALPHA"; break;
				case BlendingFactor::CONSTANT_COLOR: return "GL_CONSTANT_COLOR"; break;
				case BlendingFactor::ONE_MINUS_CONSTANT_COLOR: return "GL_ONE_MINUS_CONSTANT_COLOR"; break;
				case BlendingFactor::CONSTANT_ALPHA: return "GL_CONSTANT_ALPHA"; break;
				case BlendingFactor::ONE_MINUS_CONSTANT_ALPHA: return "GL_ONE_MINUS_CONSTANT_ALPHA"; break;
				case BlendingFactor::SRC_ALPHA_SATURATE: return "GL_SRC_ALPHA_SATURATE"; break;
				case BlendingFactor::SRC1_COLOR: return "GL_SRC1_COLOR"; break;
				case BlendingFactor::ONE_MINUS_SRC1_COLOR: return "GL_ONE_MINUS_SRC1_COLOR"; break;
				case BlendingFactor::SRC1_ALPHA: return "GL_SRC1_ALPHA"; break;
				case BlendingFactor::ONE_MINUS_SRC1_ALPHA: return "GL_ONE_MINUS_SRC1_ALPHA"; break;
				default: throw std::runtime_error("Unknown value for BlendingFactor enumeration."); break;
				}
			}
		} // namespace opengl
	} // namespace renderer
} // namespace ece