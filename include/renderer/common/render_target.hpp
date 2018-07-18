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

#ifndef RENDER_TARGET_HPP
#define RENDER_TARGET_HPP

#include "renderer/config.hpp"
#include "utility/mathematics/vector2u.hpp"
#include "renderer/common/color.hpp"
#include "renderer/common/render_state.hpp"
#include "renderer/common/viewport.hpp"

namespace ece
{
	namespace renderer
	{
		namespace common
		{
			using utility::mathematics::IntVector2u;
			using utility::mathematics::Rectangle;

			// TODO: Renderable vs Drawable ?
			class Renderable;

			/**
			 * @class RenderTarget
			 * @brief
			 */
			class ECE_RENDERER_API RenderTarget
			{
			public:
				/**
				 * @fn constexpr RenderTarget() noexcept
				 * @brief Default constructor.
				 * @throw noexcept
				 */
				RenderTarget() noexcept;

				/**
				 * @fn RenderTarget(const RenderTarget & copy) noexcept
				 * @param[in] copy The RenderTarget to copy from.
				 * @brief Default copy constructor.
				 * @throw noexcept
				 */
				RenderTarget(const RenderTarget & copy) noexcept = default;

				/**
				 * @fn RenderTarget(RenderTarget && move) noexcept
				 * @param[in] move The RenderTarget to move.
				 * @brief Default move constructor.
				 * @throw noexcept
				 */
				RenderTarget(RenderTarget && move) noexcept = default;

				/**
				 * @fn ~RenderTarget() noexcept
				 * @brief Default destructor.
				 * @throw noexcept
				 */
				~RenderTarget() noexcept = default;

				/**
				 * @fn RenderTarget & operator=(const RenderTarget & copy) noexcept
				 * @param[in] The RenderTarget to copy from.
				 * @return The RenderTarget copied.
				 * @brief Default copy assignment operator.
				 * @throw noexcept
				 */
				RenderTarget & operator=(const RenderTarget & copy) noexcept = default;

				/**
				 * @fn RenderTarget & operator=(RenderTarget && move) noexcept
				 * @param[in] The RenderTarget to move.
				 * @return The RenderTarget moved.
				 * @brief Default move assignment operator.
				 * @throw noexcept
				 */
				RenderTarget & operator=(RenderTarget && move) noexcept = default;

				/**
				 * @fn IntVector2u getSize() const
				 * @return The size of the render target.
				 * @brief Get the size of the render target.
				 * @throw
				 */
				virtual IntVector2u getSize() const = 0;

				/**
				 * @fn void clear(const Color & color = BLACK, const Rectangle<float> & scissorArea = Rectangle<float>())
				 * @param[in] color The color to use to clean the render target.
				 * @param[in] scissorArea The area of the render target to limit the cleaning.
				 * @brief Clean the render target using a specific color.
				 * @throw
				 */
				virtual void clear(const Color & color = BLACK, const Rectangle<float> & scissorArea = Rectangle<float>()) = 0;

				/**
				 * @fn void draw(Renderable & renderable, const RenderState & states = RenderState())
				 * @param[in/out] renderable The drawable to draw to the render target.
				 * @param[in] states The states to apply to the render for drawing.
				 * @brief Draw an object to the render target.
				 * @throw
				 */
				virtual void draw(Renderable & renderable, const RenderState & states = RenderState()) = 0;

				Viewport getDefaultViewport() const;

				void setViewport(const Viewport & viewport);

				inline const Viewport & getCurrentViewport() const;

			protected:
				void loadRenderState(const RenderState & states);

				Viewport _currentViewport;
				bool _viewportHasChanged;

			private:
				RenderState _currentState;
			};
		} // namespace common
	} // namespace renderer
} // namespace ece

#include "renderer/common/render_target.inl"

#endif // RENDER_TARGET_HPP
