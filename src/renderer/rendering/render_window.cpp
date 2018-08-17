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

#include "renderer/rendering/render_window.hpp"

#include "renderer/opengl/context_opengl.hpp"
#include "renderer/opengl/opengl.hpp"
#include "utility/log/service_logger.hpp"
#include "window/common/video_mode.hpp"
#include "renderer/rendering/renderable.hpp"

namespace ece
{
	namespace renderer
	{
		namespace rendering
		{
			using opengl::ContextOpenGL;
			using opengl::OpenGL;
			using utility::log::ServiceLoggerLocator;
			using window::common::VideoMode;

			RenderWindow::RenderWindow() : Window(), RenderTarget(), _context(std::make_shared<ContextOpenGL>()), _currentState()
			{
				this->setCurrent();
			}

			RenderWindow::~RenderWindow() noexcept
			{
				this->_renderers.clear();
			}

			void RenderWindow::open()
			{
				if (!this->isOpened()) {
					this->_adapter->createWindow();
					this->_isOpened = true;

					try {
						this->_context->create(*this);
					}
					catch (Exception & /*e*/) {
						throw;
					}
					catch (std::runtime_error & e) {
						ServiceLoggerLocator::getService().logError(e.what());
					}

					this->_currentViewport.resetViewport(Rectangle<float>(0.0f, 0.0f, static_cast<float>(this->getSize()[0]), static_cast<float>(this->getSize()[1])));
					this->_viewportHasChanged = true;
					this->onWindowOpened();
				}
			}

			IntVector2u RenderWindow::getSize() const
			{
				return Window::getSize();
			}

			void RenderWindow::clear(const Color & color, const Rectangle<float> & scissorArea)
			{
				Rectangle<float> viewport;
				if (this->_currentViewport.isRatioUsed()) {
					viewport = Rectangle<float>(0.0f, 0.0f, this->getSize()[0] * this->_currentViewport.getViewportRatio().getWidth(), this->getSize()[1] * this->_currentViewport.getViewportRatio().getHeight());
				}
				else {
					viewport = this->_currentViewport.getViewport();
				}

				if (this->_viewportHasChanged)
				{
					OpenGL::viewport(static_cast<int>(viewport.getX()), static_cast<int>(viewport.getY()), static_cast<int>(viewport.getWidth()), static_cast<int>(viewport.getHeight()));

					if (scissorArea != Rectangle<float>()) {
						OpenGL::scissor(static_cast<int>(scissorArea.getX()), static_cast<int>(scissorArea.getY()), static_cast<int>(scissorArea.getWidth()), static_cast<int>(scissorArea.getHeight()));
						OpenGL::enable(Capability::SCISSOR_TEST);
					}

					this->_viewportHasChanged = false;
				}
				if (scissorArea == Rectangle<float>()) {
					OpenGL::scissor(static_cast<int>(viewport.getX()), static_cast<int>(viewport.getY()), static_cast<int>(viewport.getWidth()), static_cast<int>(viewport.getHeight()));
					OpenGL::enable(Capability::SCISSOR_TEST);
				}

				if (this->isOpened()) {
					OpenGL::clearColor(static_cast<float>(color.red) / 255.0f,
											static_cast<float>(color.green) / 255.0f,
											static_cast<float>(color.blue) / 255.0f,
											static_cast<float>(color.alpha) / 100.0f);
					OpenGL::clear(Bitfield::COLOR_BUFFER_BIT | Bitfield::STENCIL_BUFFER_BIT | Bitfield::DEPTH_BUFFER_BIT);
				}
			}

			void RenderWindow::display()
			{
				this->_context->swapBuffers();
			}

			void RenderWindow::enableMSAA(const unsigned short int samples)
			{
				if (samples < 2) {
					OpenGL::disable(Capability::MULTISAMPLE);
				}
				this->_videoMode.setSamples(samples);
			}

			void RenderWindow::updateVideoMode()
			{
				if (this->_videoMode.hasChanged()) {
					this->_context.reset();
					this->close();
					this->_context = std::make_shared<ContextOpenGL>();
					this->open();
					this->_videoMode.applyChanges();
				}
			}
		} // namespace rendering
	} // namespace renderer
} // ece
