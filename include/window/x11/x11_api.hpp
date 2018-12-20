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

#ifndef X11_API_HPP
#define X11_API_HPP

#include <X11/Xlib.h>

#include "window/pch.hpp"
#include "utility/mathematics.hpp"
#include "window/event.hpp"

namespace ece
{
	namespace window
	{
		namespace common
		{
			struct WindowMessage;
		}

		namespace x11
		{
			using common::WindowMessage;

			/**
			 * @class X11API
			 * @brief
			 */
			class X11API
			{
			public:
				/**
				 * @fn constexpr X11API() noexcept
				 * @brief Default constructor.
				 * @throw noexcept
				 */
				constexpr X11API() noexcept = default;

				/**
				 * @fn X11API(const X11API & copy) noexcept
				 * @param[in] copy The X11API to copy from.
				 * @brief Default copy constructor.
				 * @throw noexcept
				 */
				X11API(const X11API & copy) noexcept = default;

				/**
				 * @fn X11API(X11API && move) noexcept
				 * @param[in] move The X11API to move.
				 * @brief Default copy constructor.
				 * @throw noexcept
				 */
				X11API(X11API && move) noexcept = default;

				/**
				 * @fn ~X11API() noexcept
				 * @brief Default destructor.
				 * @throw noexcept
				 */
				~X11API() noexcept = default;

				/**
				 * @fn X11API & operator=(const X11API & copy) noexcept
				 * @param[in] copy The X11API to copy from.
				 * @return The X11API copied.
				 * @brief Default copy assignment operator.
				 * @throw noexcept
				 */
				X11API & operator=(const X11API & copy) noexcept = default;

				/**
				 * @fn X11API & operator=(X11API && move) noexcept
				 * @param[in] move The X11API to move.
				 * @return The X11API moved.
				 * @brief Default copy assignment operator.
				 * @throw noexcept
				 */
				X11API & operator=(X11API && move) noexcept = default;

				/**
				 * Window getWindowHandle() const
				 * @return The window ID of the internal API.
				 * @brief Get the window ID of the internal API.
				 * @throw
				 */
				virtual auto getWindowHandle() const -> ::Window = 0;

				/**
				 * Display * getDevice() const
				 * @return The device associated to the window.
				 * @brief Get the device associated to the window.
				 * @throw
				 */
				virtual auto getDevice() const -> Display * = 0;

				/**
				 * @fn void createWindow()
				 * @brief Generate a window.
				 * @throw
				 */
				virtual void createWindow() = 0;

				/**
				 * @fn void deleteWindow()
				 * @brief Delete a window.
				 * If that window does not exist, the behaviour is unknown.
				 * @throw
				 */
				virtual void deleteWindow() = 0;

				/**
				 * @fn bool isWindowCreated() const
				 * @return True if window exist, false else.
				 * @brief Check if the window is existing or not.
				 * @throw
				 */
				virtual auto isWindowCreated() const -> bool = 0;

				/**
				 * @fn void setTitle(const std::string & title)
				 * @param[in] title The title to set.
				 * @brief Set the window title.
				 * @throw
				 */
				virtual void setTitle(const std::string & title) = 0;

				/**
				 * @fn std::string getTitle() const
				 * @return The title of the window.
				 * @brief Get the window title.
				 * @throw
				 */
				virtual auto getTitle() const -> std::string = 0;

				/**
				 * @fn void setPosition(const IntVector2u & position)
				 * @param[in] position The position to set the window to.
				 * @brief Set the window to the position.
				 * throw
				 */
				virtual void setPosition(const IntVector2u & position) = 0;

				/**
				 * @fn IntVector2u getPosition() const
				 * @return The window position.
				 * @brief Get the position of the window.
				 * @throw
				 */
				virtual auto getPosition() const -> IntVector2u = 0;

				/**
				 * @fn IntVector2u getSize() const
				 * @return The window size.
				 * @brief Get the size of the window.
				 * @throw
				 */
				virtual auto getSize() const -> IntVector2u = 0;

				/**
				 * @fn void minimize()
				 * @brief Set the window to its minimum size.
				 * @throw
				 */
				virtual void minimize() = 0;

				/**
				 * @fn void maximize()
				 * @brief Set the window to its maximum size.
				 * @throw
				 */
				virtual void maximize() = 0;

				/**
				 * @fn std::vector<InputEvent> processEvent(const bool blocking)
				 * @param[in] blocking Block the thread until an event has been processed.
				 * @return The events obtained from the window.
				 * @brief Process a window event.
				 * @throw
				 */
				virtual auto processEvent(const bool blocking, const bool keyRepeat) -> std::vector<InputEvent> = 0;
			};
		} // namespace x11
	} // namespace window
} // namespace ece

#endif // X11_API_HPP
