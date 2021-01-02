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
#include "renderer/pipeline/render_state.hpp"

#include "renderer/opengl.hpp"

namespace ece
{
	namespace renderer
	{
		namespace pipeline
		{
			RenderState RenderState::_currentState = RenderState();

			RenderState::RenderState() noexcept :
				faceCulling(true),
				cullFaceMode(CullFaceMode::BACK),
				frontFaceMode(FrontFaceMode::COUNTERCLOCKWISE),
				depthTest(true),
				depthFunction(DepthFunctionCondition::LESS),
				pointSize(0.0f),
				lineWidth(0.0f),
				smoothLine(false),
				blending(false),
				sourceBlend(BlendingFactor::SRC_ALPHA),
				destinationBlend(BlendingFactor::ONE_MINUS_SRC_ALPHA)
			{
			}

			bool RenderState::operator==(const RenderState & rhs) const noexcept
			{
				return this->faceCulling == rhs.faceCulling
					&& this->cullFaceMode == rhs.cullFaceMode
					&& this->frontFaceMode == rhs.frontFaceMode
					&& this->depthTest == rhs.depthTest
					&& this->depthFunction == rhs.depthFunction
					&& this->pointSize == rhs.pointSize
					&& this->lineWidth == rhs.lineWidth
					&& this->smoothLine == rhs.smoothLine
					&& this->blending == rhs.blending
					&& this->sourceBlend == rhs.sourceBlend
					&& this->destinationBlend == rhs.destinationBlend;
			}

			void RenderState::apply(const bool forced)
			{
				if (forced || RenderState::_currentState != *this) {
					RenderState::_currentState = *this;

					if (RenderState::_currentState.faceCulling) {
						OpenGL::enable(Capability::CULL_FACE);
						OpenGL::cullFace(getCullFaceMode(RenderState::_currentState.cullFaceMode));
						OpenGL::frontFace(getFrontFaceMode(RenderState::_currentState.frontFaceMode));
					}
					else {
						OpenGL::disable(Capability::CULL_FACE);
					}

					if (RenderState::_currentState.depthTest) {
						OpenGL::enable(Capability::DEPTH_TEST);
						OpenGL::depthFunc(getDepthFunctionCondition(RenderState::_currentState.depthFunction));
					}
					else {
						OpenGL::disable(Capability::DEPTH_TEST);
					}

					if (RenderState::_currentState.pointSize > 0.0f) {
						OpenGL::enable(Capability::PROGRAM_POINT_SIZE);
						OpenGL::pointSize(RenderState::_currentState.pointSize);
					}
					else {
						OpenGL::disable(Capability::PROGRAM_POINT_SIZE);
					}

					if (RenderState::_currentState.lineWidth > 0.0f) {
						OpenGL::lineWidth(RenderState::_currentState.lineWidth);
						if (RenderState::_currentState.smoothLine) {
							OpenGL::enable(Capability::LINE_SMOOTH);
						}
						else {
							OpenGL::disable(Capability::LINE_SMOOTH);
						}
					}
					else {
						OpenGL::disable(Capability::LINE_SMOOTH);
					}

					if (RenderState::_currentState.blending) {
						OpenGL::enable(Capability::BLEND);
						OpenGL::blendFunc(getBlendingFactor(RenderState::_currentState.sourceBlend), getBlendingFactor(RenderState::_currentState.destinationBlend));
					}
					else {
						OpenGL::disable(Capability::BLEND);
					}
				}
			}
		} // namespace pipeline
	} // namesapce renderer
} // namespace ece
