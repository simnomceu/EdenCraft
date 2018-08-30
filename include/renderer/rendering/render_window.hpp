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

#ifndef RENDER_WINDOW_HPP
#define RENDER_WINDOW_HPP

#include "renderer/config.hpp"
#include "window/common/window.hpp"
#include "renderer/rendering/renderer.hpp"
#include "renderer/rendering/render_context.hpp"
#include "renderer/rendering/render_target.hpp"
#include "renderer/pipeline/render_state.hpp"

#include <vector>
#include <memory>

namespace ece
{
	namespace renderer
	{
		namespace rendering
		{
			using window::common::Window;
			using pipeline::RenderState;

			/**
			 * @class RenderWindow
			 * @extends Window RenderTarget
			 * @brief A window that include a renderer, to draw scenes.
			 * @see Window
			 */
			class ECE_RENDERER_API RenderWindow : public Window, public RenderTarget
			{
			public:
				/**
				 * @fn RenderWndow()
				 * @brief Default constructor.
				 * @throw noexcept
				 */
				RenderWindow();

				/**
				 * @fn RenderWindow(const RenderWindow & copy)
				 * @param[in] copy The RenderWindow to copy from.
				 * @brief Default copy constructor.
				 * @throw
				 */
				RenderWindow(const RenderWindow & copy) = default;

				/**
				 * @fn RenderWindow(RenderWindow && move) noexcept
				 * @param[in] move The RenderWindow to move.
				 * @brief Default move constructor.
				 * @throw noexcept
				 */
				RenderWindow(RenderWindow && move) = default;

				/**
				 * @fn ~RenderWindow()
				 * @brief Default destructor.
				 * @throw noexcept
				 */
				~RenderWindow() noexcept;

				/**
				 * @fn RenderWindow & operator=(const RenderWindow & copy)
				 * @param[in] copy The RenderWindow to copy from.
				 * @return The RenderWindow copied.
				 * @brief Default copy assignment operator.
				 * @throw
				 */
				RenderWindow & operator=(const RenderWindow & copy) = default;

				/**
				 * @fn RenderWindow & operator=(RenderWindow && move) noexcept
				 * @param[in] move The RenderWindow to move.
				 * @return The RenderWindow moved.
				 * @brief Default move assignment operator.
				 * @throw noexcept
				 */
				RenderWindow & operator=(RenderWindow && move) noexcept = default;

				/**
				 * @fn void setContextMinimumVersion(const Version<2> & minVersion)
				 * @param[in] minVersion The minimum version to set.
				 * @brief Define the required minimum version for the context to use.
				 * @throw
				 */
				inline void setContextMinimumVersion(const Version<2> & minVersion);

				/**
				 * @fn void setContextMaximumVersion(const Version<2> & maxVersion)
				 * @param[in] maxVersion The maximum version to set.
				 * @brief Define the required maximum version for the context to use.
				 * @throw
				 */
				inline void setContextMaximumVersion(const Version<2> & maxVersion);

				/**
				* @fn void open()
				* @brief Open the window.
				* If the window is already opened, nothing happen. Current window settings are used.
				* @throw
				* @see void Window::open()
				*/
				void open();

				/**
				 * @fn FloatVector2u getSize() const
				 * @return The size of the render target.
				 * @brief Get the size of the render target.
				 * @throw
				 */
				virtual IntVector2u getSize() const override;

				/**
				 * @fn void clear(const Color & color = BLACK, const Rectangle<float> & scissorArea = Rectangle<float>())
				 * @param[in] color The color to use to clean the render target.
				 * @param[in] scissorArea The area of the render target to limit the cleaning.
				 * @brief Clean the render target using a specific color.
				 * @throw
				 */
				virtual void clear(const Color & color = BLACK, const Rectangle<float> & scissorArea = Rectangle<float>()) override;

				/**
				 * void display()
				 * @brief Display the next frame in the window.
				 * If multi-buffering is enable, it only switches the buffers.
				 * @throw
				 */
				void display();

				/**
				 * @fn void enableMSAA(const unsigned short int samples)
				 * @param[in] samples The number of samples to compute.
				 * @brief Enable the MSAA rendering otpion. if samples is lower than or equalt to zero, MSAA is disable.
				 */
				void enableMSAA(const unsigned short int samples);

				/**
				 * @fn void updateVideoMode()
				 * @brief Update the window according to the current video mode.
				 * @throw
				 * @see void Window::updateVideoMode()
				 */
				virtual void updateVideoMode() override;

			private:
				/**
				 * @property _renderers
				 * @brief The list of renderers available for this render target.
				 */
				std::vector<std::shared_ptr<Renderer>> _renderers;

				/**
				 * @property _context
				 * @brief The render context to use for rendering.
				 */
				std::shared_ptr<RenderContext> _context;

				RenderState _currentState;
			};
		} // namespace rendering
	} // namespace renderer
} // namespace ece

#include "renderer/rendering/render_window.inl"

#endif // RENDER_WINDOW_HPP
