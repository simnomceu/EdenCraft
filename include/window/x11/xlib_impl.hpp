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

#ifndef XLIB_IMPL_HPP
#define XLIB_IMPL_HPP

#include <X11/Xlib.h>

#include "window/x11/x11_api.hpp"

namespace ece
{
	namespace window
	{
		namespace common
		{
			/**
			 * @struct WindowMessage
			 * @brief X11 implementation for a window message/notification, including input messages.
			 */
			struct WindowMessage
			{
				/**
				 * @property _impl
				 * @brief Xlib implementation of the event.
				 */
				XEvent _impl;

				inline WindowMessage(const XEvent & impl) : _impl(impl) {}
			};
		} // namespace common

		namespace x11
		{
			using common::WindowMessage;

			/**
			 * @class XlibImpl
			 * @extends X11API
			 * @brief
			 */
			class XlibImpl : public X11API
			{
			public:
				/**
				 * @fn XlibImpl() noexcept
				 * @brief Default constructor.
				 * @throw noexcept
				 */
				XlibImpl() noexcept;

				/**
				 * @fn XlibImpl(const XlibImpl & copy) noexcept
				 * @param[in] copy The XlibImpl to copy from.
				 * @brief Default copy constructor.
				 * @throw noexcept
				 */
				XlibImpl(const XlibImpl & copy) noexcept = default;

				/**
				 * @fn XlibImpl(XlibImpl && move) noexcept
				 * @param[in] move The XlibImpl to move.
				 * @brief Default copy constructor.
				 * @throw noexcept
				 */
				XlibImpl(XlibImpl && move) noexcept = default;

				/**
				 * @fn ~XlibImpl() noexcept
				 * @brief Default destructor.
				 * @throw noexcept
				 */
				~XlibImpl() noexcept = default;

				/**
				 * @fn XlibImpl & operator=(const XlibImpl & copy) noexcept
				 * @param[in] copy The XlibImpl to copy from.
				 * @return The XlibImpl copied.
				 * @brief Default copy assignment operator.
				 * @throw noexcept
				 */
				XlibImpl & operator=(const XlibImpl & copy) noexcept = default;

				/**
				 * @fn XlibImpl & operator=(XlibImpl && move) noexcept
				 * @param[in] move The XlibImpl to move.
				 * @return The XlibImpl moved.
				 * @brief Default copy assignment operator.
				 * @throw noexcept
				 */
				XlibImpl & operator=(XlibImpl && move) noexcept = default;

				/**
				 * Window getWindowHandle() const
				 * @return The window ID of the internal API.
				 * @brief Get the window ID of the internal API.
				 * @throw
				 */
				virtual Window getWindowHandle() const override;

				/**
				 * Display * getDevice() const
				 * @return The device associated to the window.
				 * @brief Get the device associated to the window.
				 * @throw
				 */
				virtual Display * getDevice() const override;

				/**
				 * @fn void createWindow()
				 * @brief Generate a window.
				 * @throw
				 * @see void X11API::createWindow()
				 */
				virtual void createWindow() override;

				/**
				 * @fn void deleteWindow()
				 * @brief Delete a window.
				 * If that window does not exist, the behaviour is unknown.
				 * @throw
				 * @see void X11API::deleteWindow()
				 */
				virtual void deleteWindow() override;

				/**
				 * @fn bool isWindowCreated() const
				 * @return True if window exist, false else.
				 * @brief Check if the window is existing or not.
				 * @throw
				 * @see bool X11API::isWindowCreated() const
				 */
				virtual bool isWindowCreated() const override;

				/**
				 * @fn void setTitle(const std::string & title)
				 * @param[in] title The title to set.
				 * @brief Set the window title.
				 * @throw
				 * @see void X11API::setTitle(const std::string & title)
				 */
				virtual void setTitle(const std::string & title) override;

				/**
				 * @fn std::string getTitle() const
				 * @return The title of the window.
				 * @brief Get the window title.
				 * @throw
				 * @see std::string X11API::getTitle() const
				 */
				virtual std::string getTitle() const override;

				/**
				 * @fn void setPosition(const IntVector2u & position)
				 * @param[in] position The position to set the window to.
				 * @brief Set the window to the position.
				 * throw
				 * @see void X11API::setPosition(const IntVector2u & position)
				 */
				virtual void setPosition(const IntVector2u & position) override;

				/**
				 * @fn IntVector2u getPosition() const
				 * @return The window position.
				 * @brief Get the position of the window.
				 * @throw
				 * @see IntVector2u X11API::getPosition() const
				 */
				virtual IntVector2u getPosition() const override;
		/**
		 * @fn IntVector2u getSize() const
		 * @return The window size.
		 * @brief Get the size of the window.
		 * @throw
		 * @see IntVector2u X11API::getSize() const
		 */
		virtual IntVector2u getSize() const override;

				/**
				 * @fn void minimize()
				 * @brief Set the window to its minimum size.
				 * @throw
				 * @see void X11API minimize()
				 */
				virtual void minimize() override;

				/**
				 * @fn void maximize()
				 * @brief Set the window to its maximum size.
				 * @throw
				 * @see void X11API::maximize()
				 */
				virtual void maximize() override;

				/**
				 * @fn std::vector<InputEvent> processEvent(const bool blocking)
				 * @param[in] blocking Block the thread until an event has been processed.
				 * @return The events obtained from the window.
				 * @brief Process a window event.
				 * @throw
				 * @see std::vector<InputEvent> X11API::processEvent(const bool blocking)
				 */
				virtual std::vector<InputEvent> processEvent(const bool blocking) override;

				/**
				 * @fn void logInfos()
				 * @brief Log infos about the connection to the X server.
				 * @throw
				 */
				void logInfos();

			protected:
				/**
				 * @fn WindowMessage getNextMessage()
				 * @return The next window message.
				 * @brief Get the next window message available.
				 * @throw
				 */
				WindowMessage getNextMessage();

				/**
				 * @fn InputEvent processMessage(const WindowMessage & message)
				 * @param[in] message The window message to process.
				 * @return The window message standardized.
				 * @brief Process a window message.
				 * @throw
				 */
				InputEvent processMessage(const WindowMessage & message);

			private:
				/**
				 * @property _windowId
				 * @brief The handle of the window.
				 */
				Window _windowId;

				/**
				 * @property _connection
				 * @brief The connection to the X server.
				 */
				Display * _connection;

				/**
				 * @property _screen
				 * @brief The screen associated.
				 */
				int _screen;
			};
		} // namespace x11
	} // namespace window
} // namespace ece

#endif // XLIB_IMPL_HPP
