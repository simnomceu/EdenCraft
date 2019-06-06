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

#include "window/pch.hpp"
#include "window/common/window_adapter.hpp"
#include "window/win32.hpp"
#include "utility/log.hpp"

#include <windowsx.h>

namespace ece
{
	namespace window
	{
		namespace common
		{
			// TODO: Refactor applying correctly use of Desktop Window Manager (DWM windowing system).
			WindowAdapter::WindowAdapter() noexcept: BaseWindowAdapter(), _data(makePimpl<DataWindowAdapter>(nullptr)) {}

			void WindowAdapter::createWindow()
			{
				registerPattern();

				auto settingsEx = WS_EX_TOPMOST;
				auto settings = WS_OVERLAPPEDWINDOW;

				this->_data->windowId = CreateWindowEx(settingsEx, className, L"", settings, 0, 0, 320, 320, nullptr, nullptr, GetModuleHandle(nullptr), this);
				ShowWindow(this->_data->windowId, SW_SHOW);
				UpdateWindow(this->_data->windowId);
			}

			void WindowAdapter::deleteWindow()
			{
				auto codeError = DestroyWindow(this->_data->windowId);
				if (codeError == 0) {
					ERROR << "Erreur destruction HWND. (WGL) Code " << GetLastError() << flush;
				}
				this->_data->windowId = nullptr;
			}

			auto WindowAdapter::isWindowCreated() const -> bool
			{
				return this->_data->windowId != nullptr;
			}

			void WindowAdapter::setTitle(const std::string & title)
			{
				auto success = SetWindowTextA(this->_data->windowId, title.data());
				if (!success) {
					ERROR << "Erreur while renaming window. (WGL) Code " << GetLastError() << flush;
				}
			}

			auto WindowAdapter::getTitle() const -> std::string
			{
				auto title = LPSTR{ nullptr };
				auto success = GetWindowTextA(this->_data->windowId, title, GetWindowTextLengthA(this->_data->windowId));
				if (!success) {
					ERROR << "Erreur while getting window name. (WGL) Code " << GetLastError() << flush;
				}
				return { title };
			}

			void WindowAdapter::setPosition(const IntVector2u & position)
			{
				auto success = SetWindowPos(this->_data->windowId, HWND_NOTOPMOST, position[0], position[1], 0, 0, SWP_NOMOVE | SWP_NOSIZE);
				if (!success) {
					ERROR << "Erreur while moving window. (WGL) Code " << GetLastError() << flush;
				}
			}

			auto WindowAdapter::getSize() const -> IntVector2u
			{
				auto bounds = RECT{};
				auto success = GetWindowRect(this->_data->windowId, &bounds);
				if (!success) {
					ERROR << "Erreur while retrieving window bounds. (WGL) Code " << GetLastError() << flush;
				}

				return { bounds.right - bounds.left, bounds.bottom - bounds.top };
			}

			auto WindowAdapter::getPosition() const -> IntVector2u
			{
				auto bounds = RECT{};
				auto success = GetWindowRect(this->_data->windowId, &bounds);
				if (!success) {
					ERROR << "Erreur while retrieving window bounds. (WGL) Code " << GetLastError() << flush;
				}
				return { bounds.left, bounds.top };
			}

			void WindowAdapter::minimize()
			{
				auto success = ShowWindow(this->_data->windowId, SW_SHOWMINIMIZED);
				if (!success) {
					ERROR << "Erreur while minimizing window. (WGL) Code " << GetLastError() << flush;
				}
			}

			void WindowAdapter::maximize()
			{
				auto success = ShowWindow(this->_data->windowId, SW_SHOWMAXIMIZED);
				if (!success) {
					ERROR << "Erreur while maximizing window. (WGL) Code " << GetLastError() << flush;
				}
			}

			void WindowAdapter::processEvent(const bool blocking)
			{
				auto message = MSG{};
				if (blocking) {
					auto success = WaitMessage();
					if (!success) {
						ERROR << "Erreur while blocking messages queue window. (WGL) Code " << GetLastError() << flush;
					}
				}
				while (PeekMessageW(&message, nullptr, 0, 0, PM_REMOVE)) {
					TranslateMessage(&message);
					DispatchMessageW(&message);
				}
			}

			void WindowAdapter::processMessage(const WindowMessage & message)
			{
				if (this->_data->windowId == message.windowId) {
					switch (message.message) {
					case WM_KEYDOWN: {
						auto keyCode = Keyboard::getKey(static_cast<unsigned int>(message.wParam));
						if (this->_keyRepeat || (!this->_keyRepeat && !Keyboard::isKeyPressed(keyCode))) {
							auto newEvent = InputEvent{};
							newEvent.type = InputEvent::Type::KEY_PRESSED;
							newEvent.key = keyCode;
							this->pushEvent(newEvent);
							Keyboard::pressKey(keyCode, true);
						}
						break;
					}
					case WM_KEYUP: {
						auto keyCode = Keyboard::getKey(static_cast<unsigned int>(message.wParam));
						auto newEvent = InputEvent{};
						newEvent.type = InputEvent::Type::KEY_RELEASED;
						newEvent.key = keyCode;
						this->pushEvent(newEvent);
						Keyboard::pressKey(keyCode, false);
						break;
					}
					case WM_LBUTTONDOWN: {
						if (this->_keyRepeat || (!this->_keyRepeat && !Mouse::isKeyPressed(Mouse::Button::LEFT))) {
							auto newEvent = InputEvent{};
							newEvent.type = InputEvent::Type::MOUSE_PRESSED;
							newEvent.mouseButton = Mouse::Button::LEFT;
							this->pushEvent(newEvent);
							Mouse::pressKey(Mouse::Button::LEFT, true);
						}
						break;
					}
					case WM_LBUTTONUP: {
						auto newEvent = InputEvent{};
						newEvent.type = InputEvent::Type::MOUSE_RELEASED;
						newEvent.mouseButton = Mouse::Button::LEFT;
						this->pushEvent(newEvent);
						Mouse::pressKey(Mouse::Button::LEFT, false);
						break;
					}
					case WM_LBUTTONDBLCLK: {
						auto newEvent = InputEvent{};
						newEvent.type = InputEvent::Type::MOUSE_PRESSED;
						newEvent.mouseButton = Mouse::Button::LEFT;
						newEvent.doubleTap = InputEvent::DoubleTap::FIRST_OF;
						this->pushEvent(newEvent);
						newEvent.doubleTap = InputEvent::DoubleTap::LAST_OF;
						this->pushEvent(newEvent);
						break;
					}
					case WM_RBUTTONDOWN: {
						if (this->_keyRepeat || (!this->_keyRepeat && !Mouse::isKeyPressed(Mouse::Button::RIGHT))) {
							auto newEvent = InputEvent{};
							newEvent.type = InputEvent::Type::MOUSE_PRESSED;
							newEvent.mouseButton = Mouse::Button::RIGHT;
							this->pushEvent(newEvent);
							Mouse::pressKey(Mouse::Button::RIGHT, true);
						}
						break;
					}
					case WM_RBUTTONUP: {
						auto newEvent = InputEvent{};
						newEvent.type = InputEvent::Type::MOUSE_RELEASED;
						newEvent.mouseButton = Mouse::Button::RIGHT;
						this->pushEvent(newEvent);
						Mouse::pressKey(Mouse::Button::RIGHT, false);
						break;
					}
					case WM_RBUTTONDBLCLK: {
						auto newEvent = InputEvent{};
						newEvent.type = InputEvent::Type::MOUSE_PRESSED;
						newEvent.mouseButton = Mouse::Button::RIGHT;
						this->pushEvent(newEvent);
						this->pushEvent(newEvent);
						break;
					}
					case WM_MBUTTONDOWN: {
						if (this->_keyRepeat || (!this->_keyRepeat && !Mouse::isKeyPressed(Mouse::Button::WHEEL))) {
							auto newEvent = InputEvent{};
							newEvent.type = InputEvent::Type::MOUSE_PRESSED;
							newEvent.mouseButton = Mouse::Button::WHEEL;
							this->pushEvent(newEvent);
							Mouse::pressKey(Mouse::Button::WHEEL, true);
						}
						break;
					}
					case WM_MBUTTONUP: {
						auto newEvent = InputEvent{};
						newEvent.type = InputEvent::Type::MOUSE_RELEASED;
						newEvent.mouseButton = Mouse::Button::WHEEL;
						this->pushEvent(newEvent);
						Mouse::pressKey(Mouse::Button::WHEEL, false);
						break;
					}
					case WM_MBUTTONDBLCLK: {
						auto newEvent = InputEvent{};
						newEvent.type = InputEvent::Type::MOUSE_PRESSED;
						newEvent.mouseButton = Mouse::Button::WHEEL;
						this->pushEvent(newEvent);
						this->pushEvent(newEvent);
						break;
					}
					case WM_MOUSEMOVE: {
						auto newEvent = InputEvent{};
						newEvent.type = InputEvent::Type::MOUSE_MOVED;
						newEvent.mousePosition[0] = GET_X_LPARAM(message.lParam);
						newEvent.mousePosition[1] = GET_Y_LPARAM(message.lParam) + 38;
						Mouse::setPosition(newEvent.mousePosition);
						this->pushEvent(newEvent);
						break;
					}
					case WM_MOUSEWHEEL: {
						auto newEvent = InputEvent{};
						newEvent.type = InputEvent::Type::MOUSE_SCROLLED;
						newEvent.mouseWheel = static_cast<float>(GET_WHEEL_DELTA_WPARAM(message.wParam) / WHEEL_DELTA);
						this->pushEvent(newEvent);
						break;
					}
					case WM_CHAR: {
						auto newEvent = InputEvent{};
						newEvent.type = InputEvent::Type::CHAR;
						newEvent.character = static_cast<unsigned char>(message.wParam);
						this->pushEvent(newEvent);
						break;
					}
					case WM_MOVE: {
						break;
					}
					case WM_MOVING: {
						break;
					}
					case WM_SIZE: {
						break;
					}
					case WM_SIZING: {
						break;
					}
					case WM_CLOSE: {
						this->deleteWindow();
						break;
					}
					default: {
						break;
					}
					}
				}
			}
		} // namespace common

		namespace win32
		{
			using common::WindowAdapter;
			using common::WindowMessage;

			void registerPattern()
			{
				auto windowPattern = WNDCLASSEX{};
				if (!GetClassInfoEx(GetModuleHandle(nullptr), className, &windowPattern)) {
					windowPattern.cbClsExtra = 0;
					windowPattern.cbSize = sizeof(WNDCLASSEX);
					windowPattern.cbWndExtra = 0;
					windowPattern.hbrBackground = nullptr;
					windowPattern.hCursor = LoadCursor(nullptr, IDC_ARROW);
					windowPattern.hIcon = LoadIcon(nullptr, IDI_APPLICATION);
					windowPattern.hIconSm = LoadIcon(nullptr, IDI_APPLICATION);
					windowPattern.hInstance = GetModuleHandle(nullptr);
					windowPattern.lpfnWndProc = processMessagesCallback;
					windowPattern.lpszClassName = className;
					windowPattern.lpszMenuName = nullptr;
					windowPattern.style = CS_DBLCLKS;

					auto codeError = RegisterClassEx(&windowPattern);
					if (codeError == 0) {
						ERROR << "Erreur while registering WNDCLASSEX window pattern. (WGL) Code " << GetLastError() << flush;
					}
				}
			}

			LRESULT CALLBACK processMessagesCallback(HWND windowId, UINT message, WPARAM wParam, LPARAM lParam)
			{
				WindowAdapter * object = nullptr;
				if (message == WM_CREATE) {
					object = static_cast<WindowAdapter*>(reinterpret_cast<CREATESTRUCT*>(lParam)->lpCreateParams);
					SetWindowLongPtr(windowId, GWLP_USERDATA, reinterpret_cast<LONG_PTR>(object));
				}
				else {
					object = reinterpret_cast<WindowAdapter*>(GetWindowLongPtr(windowId, GWLP_USERDATA));
				}

				if (object) {
					object->processMessage(WindowMessage{ windowId, message, wParam, lParam });
				}
				return DefWindowProcW(windowId, message, wParam, lParam);
			}
		} // namespace common
	} // namespace window
} // namespace ece
