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

namespace ece
{
	inline Window::Window(const Window & copy) noexcept:Emitter(copy), _adapter(static_cast<WindowAdapter*>(copy._adapter.get())), _ups(copy._ups) {}

	inline Window::Window(Window && move) noexcept : Emitter(move), _adapter(std::move(_adapter)), _ups(std::move(move._ups)) {}

	inline Window::~Window() noexcept {}

	inline void Window::open(const WindowSetting & /*settings*/) {}

	inline bool Window::isOpened() const { return this->_adapter->isWindowCreated(); }

	inline std::string Window::getTitle() const { return std::move(this->_adapter.get()->getTitle()); }

	inline void Window::setMinimumSize(const IntVector2u & /*size*/) { this->emit(WINDOW_RESIZED); }

	inline void Window::setMaximumSize(const IntVector2u & /*size*/) { this->emit(WINDOW_RESIZED); }

	inline void Window::setFullscreen(const bool /*fullscreen*/) { this->emit(WINDOW_RESIZED); }

	inline void Window::enableDoubleClick(const bool /*enabled*/) {}

	inline bool Window::isDoubleClickEnabled() const { return false; }

	inline void Window::enableKeyRepeat(const bool enabled) { this->_adapter->enableKeyRepeat(enabled); }

	inline bool Window::isKeyRepeatedEnabled() const { return false; }

	inline void Window::limitUPS(const int limit) { this->_ups.setUPS(limit); }

	inline std::weak_ptr<BaseWindowAdapter> Window::getAdapter() const { return this->_adapter; }

	inline VideoMode & Window::getVideoMode() { return this->_videoMode; }

	inline const VideoMode & Window::getVideoMode() const { return this->_videoMode; }
}
