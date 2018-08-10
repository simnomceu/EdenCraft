/*
	
	oooooooooooo       .o8                          .oooooo.                       .o88o.     .   
	`888'     `8      "888                         d8P'  `Y8b                      888 `"   .o8   
	 888          .oooo888   .ooooo.  ooo. .oo.   888          oooo d8b  .oooo.   o888oo  .o888oo 
	 888oooo8    d88' `888  d88' `88b `888P"Y88b  888          `888""8P `P  )88b   888      888   
	 888    "    888   888  888ooo888  888   888  888           888      .oP"888   888      888   
	 888       o 888   888  888    .o  888   888  `88b    ooo   888     d8(  888   888      888 . 
	o888ooooood8 `Y8bod88P" `Y8bod8P' o888o o888o  `Y8bood8P'  d888b    `Y888""8o o888o     "888" 

															oooooo   oooooo     oooo  o8o                    .o8                             
															 `888.    `888.     .8'   `"'                   "888                             
															  `888.   .8888.   .8'   oooo  ooo. .oo.    .oooo888   .ooooo.  oooo oooo    ooo 
															   `888  .8'`888. .8'    `888  `888P"Y88b  d88' `888  d88' `88b  `88. `88.  .8'  
																`888.8'  `888.8'      888   888   888  888   888  888   888   `88..]88..8'   
																 `888'    `888'       888   888   888  888   888  888   888    `888'`888'    
																  `8'      `8'       o888o o888o o888o `Y8bod88P" `Y8bod8P'     `8'  `8'    


				This file is part of EdenCraft Engine - Window module.
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

#include "window/common/window.hpp"

#include "window/window_event/input_event.hpp"

#include <iostream>

namespace ece
{
	namespace window
	{
		namespace common
		{
			using window_event::InputEvent;

			Window::Window() noexcept: _adapter(std::make_shared<WindowAdapter>()), _videoMode(), _ups(0), _isOpened(false)
			{
			}

			void Window::open()
			{
				//		ece::WindowServiceLocator::getService().provideVideoMode(videoMode);
				if (!this->isOpened()) {
					this->_adapter->createWindow();
					this->_isOpened = true;
					//			WindowServiceLocator::getService().setBounds(this->windowId, this->settings.getBounds());
					//			WindowServiceLocator::getService().registerEventHandler(this->windowId);
					this->onWindowOpened();
				}
			}

			void Window::close()
			{
				if (this->isOpened()) {
					this->_adapter->deleteWindow();
					this->_isOpened = false;
					this->onWindowClosed();
				}
			}

			WindowSetting Window::getSettings() const
			{
				WindowSetting settings;
				settings._title = this->getTitle();

				return settings;
			}

			void Window::setSettings(const WindowSetting & settings)
			{
				//		this->setBounds(settings.getBounds());
				this->setTitle(settings._title);
				this->setPosition(settings._position);
				//		this->setState(settings.getState());
			}

			void Window::setTitle(const std::string & title)
			{
				this->_adapter.get()->setTitle(title);
				this->onWindowRenamed();
			}

			void Window::setPosition(const IntVector2u & position)
			{
				auto oldPosition = this->_adapter.get()->getPosition();
				if (oldPosition != position) { // TODO : overload operator!= for vertex classes
					this->_adapter.get()->setPosition(position);
					this->onWindowMoved();
				}
			}

			void Window::maximize()
			{
				if (this->isOpened()) {
					this->_adapter.get()->maximize();
					this->onWindowResized();
				}
			}

			void Window::minimize()
			{
				if (this->isOpened()) {
					this->_adapter.get()->minimize();
					this->onWindowResized();
				}
			}

			bool Window::waitEvent(InputEvent & event)
			{
				if (this->isOpened()) {
					while (!this->_adapter.get()->hasEvents()) {
						this->_adapter.get()->processEvent(true);
					}
					event = this->_adapter.get()->popEvent();
					return true;
				}
				return false;
			}

			bool Window::pollEvent(InputEvent & event)
			{
				if (this->isOpened()) {
					if (this->_ups.getLimit() == 0 || (this->_ups.getLimit() > 0 && this->_ups.isReadyToUpdate())) {
						this->_adapter.get()->processEvent(false);
						if (this->_adapter.get()->hasEvents()) {
							event = this->_adapter.get()->popEvent();
							return true;
						}
						return false;
					}
					return false;
				}
				return false;
			}

			void Window::updateVideoMode()
			{
				if (this->_videoMode.hasChanged()) {
					this->_videoMode.applyChanges();
				}
			}

			/*void BaseWindow::setState(const ece::WindowState state)
			{

				if (this->isFullscreenActivated()) {
					this->monitorToFill = glfwGetPrimaryMonitor();
				}

				if (this->isResizable()) {
					glfwWindowHint(GLFW_RESIZABLE, GL_TRUE);
				}
				else {
					glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
				}

				if (this->isToolbarActivated()) {
					glfwWindowHint(GLFW_DECORATED, GL_TRUE);
				}
				else {
					glfwWindowHint(GLFW_DECORATED, GL_FALSE);
				}
			}

			void BaseWindow::attachToMonitor(const int monitorIdIn)
			{
				if (monitorId < GLAdapter::getNumberOfMonitors()) {
					this->monitorId = monitorIdIn;
				}

				if (this->isFullscreenActivated()) {
					this->monitorToFill = GLAdapter::getMonitor(this->monitorId);
				}

				if (this->isOpened() && this->isFullscreenActivated()) {
					this->close();
					this->open();
				}
			}
			*/
		} // namespace common
	} // namespace window
} // namespace ece