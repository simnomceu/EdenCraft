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

			RenderState RenderState::getCurrentstate()
			{
				auto state = RenderState();
				state.faceCulling = OpenGL::isEnabled(Capability::CULL_FACE);
				state.cullFaceMode = getCullFaceMode(static_cast<opengl::CullFaceMode>(OpenGL::getInteger(Parameter::CULL_FACE_MODE)[0]));
				state.frontFaceMode = getFrontFaceMode(static_cast<opengl::FrontFaceMode>(OpenGL::getInteger(Parameter::FRONT_FACE)[0]));
				state.depthTest = OpenGL::isEnabled(Capability::DEPTH_TEST);
				state.depthFunction = getDepthFunctionCondition(static_cast<opengl::DepthFunctionCondition>(OpenGL::getInteger(Parameter::DEPTH_FUNC)[0]));
				state.pointSize = OpenGL::getFloat(Parameter::PROGRAM_POINT_SIZE)[0];
				state.lineWidth = OpenGL::getFloat(Parameter::LINE_WIDTH)[0];
				state.smoothLine = OpenGL::isEnabled(Capability::LINE_SMOOTH);
				state.blending = OpenGL::isEnabled(Capability::BLEND);
				state.blendEquation = getBlendEquationMode(static_cast<opengl::BlendEquationMode>(OpenGL::getInteger(Parameter::BLEND_EQUATION_RGB)[0]));
				state.sourceBlend = getBlendingFactor(static_cast<opengl::BlendingFactor>(OpenGL::getInteger(Parameter::BLEND_SRC_RGB)[0]));
				state.destinationBlend = getBlendingFactor(static_cast<opengl::BlendingFactor>(OpenGL::getInteger(Parameter::BLEND_DST_RGB)[0]));
				state.scissorTest = OpenGL::isEnabled(Capability::SCISSOR_TEST);
				state.polygonMode = getPolygonMode(static_cast<opengl::PolygonMode>(OpenGL::getInteger(Parameter::POLYGON_MODE)[0]));
				state.primitiveRestart = OpenGL::isEnabled(Capability::PRIMITIVE_RESTART);
			
				return std::move(state);
			}

			RenderState::RenderState() noexcept :
				faceCulling(true),
				cullFaceMode(CullFaceMode::BACK),
				frontFaceMode(FrontFaceMode::CCW),
				depthTest(true),
				depthFunction(DepthFunctionCondition::LESS),
				pointSize(0.0f),
				lineWidth(0.0f),
				smoothLine(false),
				blending(false),
				blendEquation(BlendEquationMode::FUNC_ADD),
				sourceBlend(BlendingFactor::SRC_ALPHA),
				destinationBlend(BlendingFactor::ONE_MINUS_SRC_ALPHA),
				scissorTest(true),
				polygonMode(PolygonMode::FILL),
				primitiveRestart(false)
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
					&& this->blendEquation == rhs.blendEquation
					&& this->sourceBlend == rhs.sourceBlend
					&& this->destinationBlend == rhs.destinationBlend
					&& this->scissorTest == rhs.scissorTest
					&& this->polygonMode == rhs.polygonMode
					&& this->primitiveRestart == rhs.primitiveRestart;
			}

			void RenderState::apply(const bool forced)
			{
				if (forced || RenderState::_currentState != *this) {
					RenderState::_currentState = *this;

					if (RenderState::_currentState.faceCulling) {
						OpenGL::enable(Capability::CULL_FACE);
						OpenGL::cullFace(RenderState::_currentState.cullFaceMode);
						OpenGL::frontFace(RenderState::_currentState.frontFaceMode);
					}
					else {
						OpenGL::disable(Capability::CULL_FACE);
					}

					if (RenderState::_currentState.depthTest) {
						OpenGL::enable(Capability::DEPTH_TEST);
						OpenGL::depthFunc(RenderState::_currentState.depthFunction);
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
						OpenGL::blendEquation(getBlendEquationMode(RenderState::_currentState.blendEquation));
						OpenGL::blendFunc(RenderState::_currentState.sourceBlend, RenderState::_currentState.destinationBlend);
					}
					else {
						OpenGL::disable(Capability::BLEND);
					}

					if (RenderState::_currentState.scissorTest) {
						OpenGL::enable(Capability::SCISSOR_TEST);
					}
					else {
						OpenGL::disable(Capability::SCISSOR_TEST);
					}

					if (RenderState::_currentState.primitiveRestart) {
						OpenGL::enable(Capability::PRIMITIVE_RESTART);
					}
					else {
						OpenGL::disable(Capability::PRIMITIVE_RESTART);
					}

					OpenGL::polygonMode(getPolygonMode(RenderState::_currentState.polygonMode));
				}
			}
		} // namespace pipeline
	} // namesapce renderer
} // namespace ece
