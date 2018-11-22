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

#include "window/common/window_adapter.hpp"
#include "window/win32.hpp"

#include <iostream>
#include <Windowsx.h>

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

				DWORD settingsEx = WS_EX_TOPMOST;
				DWORD settings = WS_OVERLAPPEDWINDOW;

				this->_data->_windowId = CreateWindowEx(settingsEx, className, L"", settings, 0, 0, 320, 320, nullptr, nullptr, GetModuleHandle(nullptr), this);
				ShowWindow(this->_data->_windowId, SW_SHOW);
				UpdateWindow(this->_data->_windowId);
			}

			void WindowAdapter::deleteWindow()
			{
				int codeError = DestroyWindow(this->_data->_windowId);
				if (codeError == 0) {
					std::cout << "Erreur destruction HWND. (WGL)";
					std::cout << " Code " << GetLastError() << std::endl;
				}
				this->_data->_windowId = nullptr;
			}

			bool WindowAdapter::isWindowCreated() const
			{
				return this->_data->_windowId != nullptr;
			}

			void WindowAdapter::setTitle(const std::string & title)
			{
				bool success = SetWindowTextA(this->_data->_windowId, title.data());
				if (!success) {
					std::cout << "Error while renaming window. (WGL)";
					std::cout << " Code " << GetLastError() << std::endl;
				}
			}

			std::string WindowAdapter::getTitle() const
			{
				LPSTR title = nullptr;
				bool success = GetWindowTextA(this->_data->_windowId, title, GetWindowTextLengthA(this->_data->_windowId));
				if (!success) {
					std::cout << "Error while getting window name. (WGL)";
					std::cout << " Code " << GetLastError() << std::endl;
				}
				return std::string(title);
			}

			void WindowAdapter::setPosition(const IntVector2u & position)
			{
				bool success = SetWindowPos(this->_data->_windowId, HWND_NOTOPMOST, position[0], position[1], 0, 0, SWP_NOMOVE | SWP_NOSIZE);
				if (!success) {
					std::cout << "Error while moving window. (WGL)";
					std::cout << " Code " << GetLastError() << std::endl;
				}
			}

			IntVector2u WindowAdapter::getSize() const
			{
				RECT bounds;
				bool success = GetWindowRect(this->_data->_windowId, &bounds);
				if (!success) {
					std::cout << "Error while retrieving window bounds. (WGL)";
					std::cout << " Code " << GetLastError() << std::endl;
				}

				return IntVector2u{ bounds.right - bounds.left, bounds.bottom - bounds.top };
			}

			IntVector2u WindowAdapter::getPosition() const
			{
				RECT bounds;
				bool success = GetWindowRect(this->_data->_windowId, &bounds);
				if (!success) {
					std::cout << "Error while retrieving window bounds. (WGL)";
					std::cout << " Code " << GetLastError() << std::endl;
				}
				return IntVector2u{ bounds.left, bounds.top };
			}

			void WindowAdapter::minimize()
			{
				bool success = ShowWindow(this->_data->_windowId, SW_SHOWMINIMIZED);
				if (!success) {
					std::cout << "Error while minimizing window. (WGL)";
					std::cout << " Code " << GetLastError() << std::endl;
				}
			}

			void WindowAdapter::maximize()
			{
				bool success = ShowWindow(this->_data->_windowId, SW_SHOWMAXIMIZED);
				if (!success) {
					std::cout << "Error while maximizing window. (WGL)";
					std::cout << " Code " << GetLastError() << std::endl;
				}
			}

			void WindowAdapter::processEvent(const bool blocking)
			{
				MSG message;
				if (blocking) {
					bool success = WaitMessage();
					if (!success) {
						std::cout << "Error while blocking messages queue window. (WGL)";
						std::cout << " Code " << GetLastError() << std::endl;
					}
				}
				while (PeekMessage(&message, nullptr, 0, 0, PM_REMOVE)) {
					TranslateMessage(&message);
					DispatchMessage(&message);
				}
			}

			void WindowAdapter::processMessage(const WindowMessage & message)
			{
				if (this->_data->_windowId == message._windowId) {
					switch (message._message) {
					case WM_KEYDOWN: {
						auto keyCode = Keyboard::getKey(message._wParam);
						if (this->_keyRepeat || (!this->_keyRepeat && !Keyboard::isKeyPressed(keyCode))) {
							InputEvent newEvent;
							newEvent._type = InputEvent::Type::ECE_KEY_PRESSED;
							newEvent._key = keyCode;
							this->pushEvent(newEvent);
							Keyboard::pressKey(keyCode, true);
						}
						break;
					}
					case WM_KEYUP: {
						auto keyCode = Keyboard::getKey(message._wParam);
						InputEvent newEvent;
						newEvent._type = InputEvent::Type::ECE_KEY_RELEASED;
						newEvent._key = keyCode;
						this->pushEvent(newEvent);
						Keyboard::pressKey(keyCode, false);
						break;
					}
					case WM_LBUTTONDOWN: {
						if (this->_keyRepeat || (!this->_keyRepeat && !Mouse::isKeyPressed(Mouse::Button::ECE_MOUSE_LEFT))) {
							InputEvent newEvent;
							newEvent._type = InputEvent::Type::ECE_MOUSE_PRESSED;
							newEvent._mouseButton = Mouse::Button::ECE_MOUSE_LEFT;
							this->pushEvent(newEvent);
							Mouse::pressKey(Mouse::Button::ECE_MOUSE_LEFT, true);
						}
						break;
					}
					case WM_LBUTTONUP: {
						InputEvent newEvent;
						newEvent._type = InputEvent::Type::ECE_MOUSE_RELEASED;
						newEvent._mouseButton = Mouse::Button::ECE_MOUSE_LEFT;
						this->pushEvent(newEvent);
						Mouse::pressKey(Mouse::Button::ECE_MOUSE_LEFT, false);
						break;
					}
					case WM_LBUTTONDBLCLK: {
						InputEvent newEvent;
						newEvent._type = InputEvent::Type::ECE_MOUSE_PRESSED;
						newEvent._mouseButton = Mouse::Button::ECE_MOUSE_LEFT;
						newEvent._doubleTap = InputEvent::DoubleTap::ECE_FIRST_OF;
						this->pushEvent(newEvent);
						newEvent._doubleTap = InputEvent::DoubleTap::ECE_LAST_OF;
						this->pushEvent(newEvent);
						break;
					}
					case WM_RBUTTONDOWN: {
						if (this->_keyRepeat || (!this->_keyRepeat && !Mouse::isKeyPressed(Mouse::Button::ECE_MOUSE_RIGHT))) {
							InputEvent newEvent;
							newEvent._type = InputEvent::Type::ECE_MOUSE_PRESSED;
							newEvent._mouseButton = Mouse::Button::ECE_MOUSE_RIGHT;
							this->pushEvent(newEvent);
							Mouse::pressKey(Mouse::Button::ECE_MOUSE_RIGHT, true);
						}
						break;
					}
					case WM_RBUTTONUP: {
						InputEvent newEvent;
						newEvent._type = InputEvent::Type::ECE_MOUSE_RELEASED;
						newEvent._mouseButton = Mouse::Button::ECE_MOUSE_RIGHT;
						this->pushEvent(newEvent);
						Mouse::pressKey(Mouse::Button::ECE_MOUSE_RIGHT, false);
						break;
					}
					case WM_RBUTTONDBLCLK: {
						InputEvent newEvent;
						newEvent._type = InputEvent::Type::ECE_MOUSE_PRESSED;
						newEvent._mouseButton = Mouse::Button::ECE_MOUSE_RIGHT;
						this->pushEvent(newEvent);
						this->pushEvent(newEvent);
						break;
					}
					case WM_MBUTTONDOWN: {
						if (this->_keyRepeat || (!this->_keyRepeat && !Mouse::isKeyPressed(Mouse::Button::ECE_MOUSE_WHEEL))) {
							InputEvent newEvent;
							newEvent._type = InputEvent::Type::ECE_MOUSE_PRESSED;
							newEvent._mouseButton = Mouse::Button::ECE_MOUSE_WHEEL;
							this->pushEvent(newEvent);
							Mouse::pressKey(Mouse::Button::ECE_MOUSE_WHEEL, true);
						}
						break;
					}
					case WM_MBUTTONUP: {
						InputEvent newEvent;
						newEvent._type = InputEvent::Type::ECE_MOUSE_RELEASED;
						newEvent._mouseButton = Mouse::Button::ECE_MOUSE_WHEEL;
						this->pushEvent(newEvent);
						Mouse::pressKey(Mouse::Button::ECE_MOUSE_WHEEL, false);
						break;
					}
					case WM_MBUTTONDBLCLK: {
						InputEvent newEvent;
						newEvent._type = InputEvent::Type::ECE_MOUSE_PRESSED;
						newEvent._mouseButton = Mouse::Button::ECE_MOUSE_WHEEL;
						this->pushEvent(newEvent);
						this->pushEvent(newEvent);
						break;
					}
					case WM_MOUSEMOVE: {
						InputEvent newEvent;
						newEvent._type = InputEvent::Type::ECE_MOUSE_MOVED;
						newEvent._mousePosition[0] = GET_X_LPARAM(message._lParam);
						newEvent._mousePosition[1] = GET_Y_LPARAM(message._lParam);
						Mouse::setPosition(this->getPosition() + newEvent._mousePosition);
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
				WNDCLASSEX windowPattern;
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

					int codeError = RegisterClassEx(&windowPattern);
					if (codeError == 0) {
						std::cout << "Erreur enregistrement du WNDCLASSEX window pattern. (WGL)";
						std::cout << " Code " << GetLastError() << std::endl;
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
				return DefWindowProc(windowId, message, wParam, lParam);
			}
		} // namespace common
	} // namespace window
} // namespace ece
