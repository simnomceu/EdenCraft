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

#ifndef WINDOW_HPP
#define WINDOW_HPP

#include <string>
#include <memory>

#include "window/common/window_adapter.hpp"
#include "utility/mathematics/vector2u.hpp"
#include "core/event/emitter.hpp"
#include "window/common/video_mode.hpp"
#include "window/common/window_setting.hpp"
#include "utility/time/update_per_second.hpp"

namespace ece
{
    using utility::mathematics::IntVector2u;
    using utility::time::UpdatePerSecond;
	using core::event::Emitter;
	using core::event::Signal;
    
	class InputEvent;

	/**
	 * @typedef WindowID
	 * @brief The unique ID of a window, whatever the platform is.
	 */
	using WindowID = short int;

	/**
	 * @typedef MonitorID
	 * @brief The unique ID of a monitor, whatever the platform is.
	 */
	using MonitorID = short int;

	/**
	 * @class Window
	 * @extends Emitter
	 * @brief A basic window as defined by the platform.
	 * Only the mechanism related to a window are implemented with. By default other features like rendering are not available in this window.
	 */
	class Window: public Emitter
	{
	public:
		static constexpr Signal::SignalID WINDOW_OPENED = 0;
		static constexpr Signal::SignalID WINDOW_CLOSED = 1;
		static constexpr Signal::SignalID WINDOW_RESIZED = 2;
		static constexpr Signal::SignalID WINDOW_MOVED = 3;
		static constexpr Signal::SignalID WINDOW_RENAMED = 4;

		/**
		 * @fn Window() noexcept
		 * @brief Default constructor.
		 * It does not open the window.
		 * @throw noexcept
		 */
		Window() noexcept;

		/**
		 * @fn Window(const Window & copy) noexcept
		 * @param[in] copy The window to copy from.
		 * @brief Default copy constructor.
		 * @throw noexcept
		 */
		inline Window(const Window & copy) noexcept;

		/**
		 * @fn Window(Window && move) noexcept
		 * @param[in] move The window to move.
		 * @brief Default move constructor.
		 * @throw noexcept
		 */
		inline Window(Window && move) noexcept;

		/**
		 * @fn ~Window() noexcept
		 * @brief Default destructor.
		 * @throw noexcept
		 */
		inline ~Window() noexcept;

		/**
		 * @fn Window & operator=(const Window & copy) noexcept
		 * @param[in] copy The window to copy from.
		 * @return The window copied.
		 * @brief Default copy assignment operator.
		 * @throw noexcept
		 */
		Window & operator=(const Window & copy) noexcept;

		/**
		 * @fn Window & operator=(Window && move) noexcept
		 * @param[in] move The window to move.
		 * @return The window moved.
		 * @brief Default move assignment operator.
		 * @throw noexcept
		 */
		Window & operator=(Window && move) noexcept;

		/**
		 * @fn void open()
		 * @brief Open the window.
		 * If the window is already opened, nothing happen. Current window settings are used.
		 * @throw
		 * @see void open(const WindowSetting & settings)
		 */
		void open();

		/**
		 * @fn void open(const WindowSetting & settings)
		 * @param[in] settings Window settings to apply to the window before opening it.
		 * @brief Open the window.
		 * If the window is already opened, nothing happen.
		 * @throw
		 * @see void open()
		 */
		inline void open(const WindowSetting & settings);

		/**
		 * @fn void close()
		 * @brief Close the window.
		 * If the window is not opened, nothing happen.
		 * @throw
		 */
		void close();

		/**
		 * @fn bool isOpened() const
		 * @return True if the window is opened, false else.
		 */
		inline bool isOpened() const;

		/**
		 * @fn WindowSetting getSettings() const
		 * @return The current window settings.
		 * @brief Get the current window settings.
		 * @throw
		 */
		WindowSetting getSettings() const;

		/**
		 * @fn void setSettings(const WindowSetting & settings)
		 * @param[in] settings The settings to apply to the window.
		 * @brief Apply new settings to the window.
		 * @throw
		 */
		void setSettings(const WindowSetting & settings);

		/**
		 * @fn std::string getTitle() const
		 * @return The title of the window.
		 * @brief get The window title.
		 * @throw
		 */
		inline std::string getTitle() const;

		/**
		 * @fn void setTitle(const std::string & title)
		 * @param[in] title The title to set.
		 * @brief Set the window title.
		 * @throw
		 */
		void setTitle(const std::string & title);

		/**
		 * @fn void setPosition(const IntVector2u & position)
		 * @param[in] position The position to set.
		 * @brief Set the window position.
		 * (0, 0) is usually defined in the top-left corner of the screen.
		 */
		void setPosition(const IntVector2u & position);

		/**
		 * @fn void setMinimumSize(const IntVector2u & size)
		 * @param[in] size The minimum size to set.
		 * @brief Set the minimum size that the window could reach.
		 * @throw
		 */
		inline void setMinimumSize(const IntVector2u & size);

		/**
		 * @fn void setMaximumSize(const IntVector2u & size)
		 * @param[in] size The maximum size to set.
		 * @brief Set the maximum size that the window could reach.
		 * @throw
		 */
		inline void setMaximumSize(const IntVector2u & size);

		/**
		 * @fn void maximize()
		 * @brief Resize the window to its maximum size.
		 * @throw
		 */
		void maximize();

		/**
		 * @fn void minimize()
		 * @brief Resize the window to its minimum size.
		 * @throw
		 */
		void minimize();

		/**
		 * @fn void setFullscreen(const bool fullscreen)
		 * @param[in] fullscreen Switch parameter to toggle the fullscreen mode.
		 * @brief Enable or disable the fullscreen mode.
		 * @throw
		 */
		inline void setFullscreen(const bool fullscreen);

		/**
		 * @fn void enableDoubleClick(const bool enabled)
		 * @param[in] enabled Switch parameter to toggle the double click mode.
		 * @brief Enable or disable the double click mode.
		 * @throw
		 */
		inline void enableDoubleClick(const bool enabled);

		/**
		 * @fn bool isDoubleClickEnabled() const
		 * @return True if double click mode is enabled, false else.
		 * @brief Check if double click mode is enabled or not.
		 * @throw
		 */
		inline bool isDoubleClickEnabled() const;

		/**
		 * @fn void enableKeyRepeat(const bool enabled)
		 * @param[in] enabled Switch parameter to toggle the key repeating mode.
		 * @brief Enable or disable key repeating mode.
		 * @throw
		 */
		inline void enableKeyRepeat(const bool enabled);

		/**
		 * @fn bool isKeyRepeatedEnabled() const
		 * @return True if key repeating mode is enabled, false else.
		 * @brief Check if key repeating mode is enabled or not.
		 * @throw
		 */
		inline bool isKeyRepeatedEnabled() const;

		/**
		 * @fn void limitUPS(const int limit)
		 * @param[in] limit The limit to set for UPS.
		 * @brief Set the limit of window updates per second.
		 * @throw
		 */
		inline void limitUPS(const int limit);

		/**
		 * @fn bool waitEvent(InputEvent & event)
		 * @param[in] event The next event to get.
		 * @return True if there is a new event to process, false else.
		 * @brief Wait for a new event from the window.
		 * This method is blocking the thread until an event is get.
		 * @throw
		 */
		bool waitEvent(InputEvent & event);

		/**
		 * @fn bool pollEvent(InputEvent & event)
		 * @param[in] event The next event to get.
		 * @return True if there is a new event to process, false else.
		 * @brief Poll for a new event from the window.
		 * This is not blocking the thread.
		 * @throw
		 */
		bool pollEvent(InputEvent & event);

		/**
		 * @fn std::weak_ptr<BaseWindowAdapter> getAdapter() const
		 * @return The adapter to handle the platform implementation.
		 * @brief Get the window adapter of this window.
		 * @throw
		 */
		inline std::weak_ptr<BaseWindowAdapter> getAdapter() const;

		/**
		 * @fn VideoMode & getVideoMode()
		 * @return The current video mode.
		 * @brief Get the current video mode of the window.
		 * @throw
		 * @see const VideoMode & getVideoMode() const
		 */
		inline VideoMode & getVideoMode();

		/**
		 * @fn const VideoMode & getVideoMode() const
		 * @return The current video mode.
		 * @brief Get the current video mode of the window.
		 * @throw
		 * @see VideoMode & getVideoMode()
		 */
		inline const VideoMode & getVideoMode() const;

		/**
		 * @fn void updateVideoMode()
		 * @brief Update the window according to the current video mode.
		 * @throw
		 */
		virtual void updateVideoMode();

	protected:
		/**
		 * @property _adapter
		 * @brief The window adapter to handle the platform implementation.
		 */
		std::shared_ptr<BaseWindowAdapter> _adapter;

		/**
		 * @property _videoMode
		 * @brief The video mode used by the window.
		 */
		VideoMode _videoMode;

		/**
		 * @property _ups
		 * @brief The statistics about updates per second of the window.
		 */
		UpdatePerSecond _ups;
	};
}

#include "window/common/window.inl"

#endif // WINDOW_HPP
