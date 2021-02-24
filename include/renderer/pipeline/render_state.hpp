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

#ifndef RENDER_STATE_HPP
#define RENDER_STATE_HPP

#include "renderer/pch.hpp"
#include "renderer/config.hpp"
#include "renderer/opengl/enum.hpp"

namespace ece
{
	namespace renderer
	{
		namespace pipeline
		{
			using namespace opengl;

			/**
			 * @class RenderState
			 * @brief
			 */
			class ECE_RENDERER_API RenderState
			{
			public:


				static RenderState getCurrentstate();

				/**
				 * @fn RenderState() noexcept
				 * @brief Default constructor.
				 * @throw noexcept
				 */
				RenderState() noexcept;

				/**
				 * @fn RenderState(const RenderState & copy) noexcept
				 * @param[in] copy The RenderState to copy from.
				 * @brief Default copy constructor.
				 * @throw noexcept
				 */
				RenderState(const RenderState & copy) noexcept = default;

				/**
				 * @fn RenderState(RenderState && move) noexcept
				 * @param[in] move The RenderState to move.
				 * @brief Default move constructor.
				 * @throw noexcept
				 */
				RenderState(RenderState && move) noexcept = default;

				/**
				 * @fn ~RenderState() noexcept
				 * @brief Default destructor.
				 * @throw noexcept
				 */
				~RenderState() noexcept = default;

				/**
				 * @fn RenderState & operator=(const RenderState & copy) noexcept
				 * @param[in] The RenderState to copy from.
				 * @return The RenderState copied.
				 * @brief Default copy assignment operator.
				 * @throw noexcept
				 */
				RenderState & operator=(const RenderState & copy) noexcept = default;

				/**
				 * @fn RenderState & operator=(RenderState && move) noexcept
				 * @param[in] The RenderState to move.
				 * @return The RenderState moved.
				 * @brief Default move assignment operator.
				 * @throw noexcept
				 */
				RenderState & operator=(RenderState && move) noexcept = default;

				bool operator==(const RenderState & rhs) const noexcept;

				inline bool operator!=(const RenderState & rhs) const noexcept;

				void apply(const bool forced = false);

				bool faceCulling;
				CullFaceMode cullFaceMode;
				FrontFaceMode frontFaceMode;

				bool depthTest;
				DepthFunctionCondition depthFunction;

				float pointSize;
				float lineWidth;
				bool smoothLine;

				bool blending;
				BlendEquationMode blendEquation;
				BlendingFactor sourceBlend;
				BlendingFactor destinationBlend;

				bool scissorTest;

				PolygonMode polygonMode;

				bool primitiveRestart;

			private:
				static RenderState _currentState;
			};
		} // namespace pipeline
	} // namespace renderer
} // namespace ece

#include "renderer/pipeline/render_state.inl"

#endif // RENDER_STATE_HPP
