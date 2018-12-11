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
#include "renderer/rendering/render_window.hpp"

#include "renderer/opengl.hpp"
#include "utility/log.hpp"

namespace ece
{
	namespace renderer
	{
		namespace rendering
		{
			RenderWindow::RenderWindow() : Window(), RenderTarget(), _context(std::make_shared<ContextOpenGL>()), _contextSettings(), _currentState()
			{
				this->_contextSettings.minVersion = { 3, 2 };
				this->_contextSettings.maxVersion = { 4, 6 };
				this->_contextSettings.doubleBuffering = true;
				this->_contextSettings.antialiasingSamples = 8;
				this->_contextSettings.bitsPerPixel = 32;
				this->_contextSettings.depthBits = 24;
				this->_contextSettings.stencilBits = 8;
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
						this->_contextSettings.window = this->Window::weak_from_this();
						this->_contextSettings.oldContext = false;
						this->_context->create(this->_contextSettings);
					}
					catch (Exception & /*e*/) {
						throw;
					}
					catch (std::runtime_error & e) {
						ServiceLoggerLocator::getService().logError(e.what());
					}

					this->onWindowOpened();
				}
			}

			IntVector2u RenderWindow::getSize() const
			{
				return Window::getSize();
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
				this->_contextSettings.antialiasingSamples = samples;
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

			void RenderWindow::updateContext()
			{
				this->_context.reset();
				this->close();
				this->_context = std::make_shared<ContextOpenGL>();
				this->open();
			}
		} // namespace rendering
	} // namespace renderer
} // ece
