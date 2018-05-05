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
#include "window/win32/data_window_adapter.hpp"

#include <iostream>
#include <Windowsx.h>

namespace ece
{
	namespace window
	{
		namespace common
		{
			using utility::pattern::makePimpl;
			using win32::className;
			using win32::interpretKey;
			using win32::processMessages;
			using win32::registerPattern;

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
				bool success = ShowWindow(this->_data->_windowId, SW_RESTORE | SW_SHOWMINIMIZED);
				if (!success) {
					std::cout << "Error while minimizing window. (WGL)";
					std::cout << " Code " << GetLastError() << std::endl;
				}
			}

			void WindowAdapter::maximize()
			{
				bool success = ShowWindow(this->_data->_windowId, SW_RESTORE | SW_SHOWMAXIMIZED);
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
						auto keyCode = interpretKey(message._wParam);
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
						auto keyCode = interpretKey(message._wParam);
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
					windowPattern.lpfnWndProc = processMessages;
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

			LRESULT CALLBACK processMessages(HWND windowId, UINT message, WPARAM wParam, LPARAM lParam)
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

			Keyboard::Key interpretKey(WPARAM wParam)
			{
				Keyboard::Key key = Keyboard::Key::KEY_NONE;
				switch (wParam) {
				case VK_CANCEL: //Control-break processing
				case VK_BACK:
					key = Keyboard::Key::BACKSPACE;
					break;
				case VK_TAB:
					key = Keyboard::Key::TAB;
					break;
				case VK_CLEAR: // CLEAR key
				case VK_RETURN:
					key = Keyboard::Key::RETURN;
					break;
				case VK_SHIFT:
					key = Keyboard::Key::SHIFT;
					break;
				case VK_CONTROL:
					key = Keyboard::Key::CTRL;
					break;
				case VK_MENU:
					key = Keyboard::Key::ALTGR;
					break;
				case VK_PAUSE:
					key = Keyboard::Key::PAUSE;
					break;
				case VK_CAPITAL:
					key = Keyboard::Key::CAPS_LOCK;
					break; // CAPS LOCK key
				case VK_KANA: // IME Kana mode // IME Hangul mode
				case VK_JUNJA: // IME Junja mode
				case VK_FINAL: // IME final mode
				case VK_HANJA: // IME Hanja mode // IME Kanji mode
				case VK_ESCAPE:
					key = Keyboard::Key::ESCAPE;
					break;
				case VK_CONVERT: // IME convert
				case VK_NONCONVERT: // IME nonconvert
				case VK_ACCEPT: // IME accept
				case VK_MODECHANGE: // IME mode change request
				case VK_SPACE:
					key = Keyboard::Key::SPACEBAR;
					break;
				case VK_PRIOR:
					key = Keyboard::Key::PAGE_UP;
					break;
				case VK_NEXT:
					key = Keyboard::Key::PAGE_DOWN;
					break;
				case VK_END:
					key = Keyboard::Key::END;
					break;
				case VK_HOME:
					key = Keyboard::Key::HOME;
					break;
				case VK_LEFT:
					key = Keyboard::Key::LEFT;
					break;
				case VK_UP:
					key = Keyboard::Key::UP;
					break;
				case VK_RIGHT:
					key = Keyboard::Key::RIGHT;
					break;
				case VK_DOWN:
					key = Keyboard::Key::DOWN;
					break;
				case VK_SELECT: // SELECT key
				case VK_PRINT: // PRINT key
				case VK_EXECUTE: // EXECUTE key
				case VK_SNAPSHOT:
					key = Keyboard::Key::PRINT_SCREEN;
					break;
				case VK_INSERT:
					key = Keyboard::Key::INS;
					break;
				case VK_DELETE:
					key = Keyboard::Key::DEL;
					break;
				case VK_HELP:
					key = Keyboard::Key::HELP;
					break;
				case '0':
					key = Keyboard::Key::NUM_0;
					break;
				case '1':
					key = Keyboard::Key::NUM_1;
					break;
				case '2':
					key = Keyboard::Key::NUM_2;
					break;
				case '3':
					key = Keyboard::Key::NUM_3;
					break;
				case '4':
					key = Keyboard::Key::NUM_4;
					break;
				case '5':
					key = Keyboard::Key::NUM_5;
					break;
				case '6':
					key = Keyboard::Key::NUM_6;
					break;
				case '7':
					key = Keyboard::Key::NUM_7;
					break;
				case '8':
					key = Keyboard::Key::NUM_8;
					break;
				case '9':
					key = Keyboard::Key::NUM_9;
					break;
				case 'A':
					key = Keyboard::Key::A;
					break;
				case 'B':
					key = Keyboard::Key::B;
					break;
				case 'C':
					key = Keyboard::Key::C;
					break;
				case 'D':
					key = Keyboard::Key::D;
					break;
				case 'E':
					key = Keyboard::Key::E;
					break;
				case 'F':
					key = Keyboard::Key::F;
					break;
				case 'G':
					key = Keyboard::Key::G;
					break;
				case 'H':
					key = Keyboard::Key::H;
					break;
				case 'I':
					key = Keyboard::Key::I;
					break;
				case 'J':
					key = Keyboard::Key::J;
					break;
				case 'K':
					key = Keyboard::Key::K;
					break;
				case 'L':
					key = Keyboard::Key::L;
					break;
				case 'M':
					key = Keyboard::Key::M;
					break;
				case 'N':
					key = Keyboard::Key::N;
					break;
				case 'O':
					key = Keyboard::Key::O;
					break;
				case 'P':
					key = Keyboard::Key::P;
					break;
				case 'Q':
					key = Keyboard::Key::Q;
					break;
				case 'R':
					key = Keyboard::Key::R;
					break;
				case 'S':
					key = Keyboard::Key::S;
					break;
				case 'T':
					key = Keyboard::Key::T;
					break;
				case 'U':
					key = Keyboard::Key::U;
					break;
				case 'V':
					key = Keyboard::Key::V;
					break;
				case 'W':
					key = Keyboard::Key::W;
					break;
				case 'X':
					key = Keyboard::Key::X;
					break;
				case 'Y':
					key = Keyboard::Key::Y;
					break;
				case 'Z':
					key = Keyboard::Key::Z;
					break;
				case VK_LWIN:
					key = Keyboard::Key::LEFT_COMMAND;
					break; // Left Windows key(Natural keyboard)
				case VK_RWIN:
					key = Keyboard::Key::RIGHT_COMMAND;
					break; // Right Windows key(Natural keyboard)
				case VK_APPS:
					key = Keyboard::Key::APPLICATIONS;
					break;
				case VK_SLEEP:
					key = Keyboard::Key::SLEEP;
					break;
				case VK_NUMPAD0:
					key = Keyboard::Key::NUMPAD_0;
					break;
				case VK_NUMPAD1:
					key = Keyboard::Key::NUMPAD_1;
					break;
				case VK_NUMPAD2:
					key = Keyboard::Key::NUMPAD_2;
					break;
				case VK_NUMPAD3:
					key = Keyboard::Key::NUMPAD_3;
					break;
				case VK_NUMPAD4:
					key = Keyboard::Key::NUMPAD_4;
					break;
				case VK_NUMPAD5:
					key = Keyboard::Key::NUMPAD_5;
					break;
				case VK_NUMPAD6:
					key = Keyboard::Key::NUMPAD_6;
					break;
				case VK_NUMPAD7:
					key = Keyboard::Key::NUMPAD_7;
					break;
				case VK_NUMPAD8:
					key = Keyboard::Key::NUMPAD_8;
					break;
				case VK_NUMPAD9:
					key = Keyboard::Key::NUMPAD_9;
					break;
				case VK_MULTIPLY:
					key = Keyboard::Key::MULTIPLY;
					break;
				case VK_ADD:
					key = Keyboard::Key::ADD;
					break;
				case VK_SEPARATOR: // Separator key
				case VK_SUBTRACT:
					key = Keyboard::Key::SUBSTRACT;
					break;
				case VK_DECIMAL:
					key = Keyboard::Key::NUMPAD_DEL;
					break;
				case VK_DIVIDE:
					key = Keyboard::Key::DIVIDE;
					break;
				case VK_F1:
					key = Keyboard::Key::F1;
					break;
				case VK_F2:
					key = Keyboard::Key::F2;
					break;
				case VK_F3:
					key = Keyboard::Key::F3;
					break;
				case VK_F4:
					key = Keyboard::Key::F4;
					break;
				case VK_F5:
					key = Keyboard::Key::F5;
					break;
				case VK_F6:
					key = Keyboard::Key::F6;
					break;
				case VK_F7:
					key = Keyboard::Key::F7;
					break;
				case VK_F8:
					key = Keyboard::Key::F8;
					break;
				case VK_F9:
					key = Keyboard::Key::F9;
					break;
				case VK_F10:
					key = Keyboard::Key::F10;
					break;
				case VK_F11:
					key = Keyboard::Key::F11;
					break;
				case VK_F12:
					key = Keyboard::Key::F12;
					break;
				case VK_F13:
					key = Keyboard::Key::F13;
					break;
				case VK_F14:
					key = Keyboard::Key::F14;
					break;
				case VK_F15:
					key = Keyboard::Key::F15;
					break;
				case VK_F16:
					key = Keyboard::Key::F16;
					break;
				case VK_F17:
					key = Keyboard::Key::F17;
					break;
				case VK_F18:
					key = Keyboard::Key::F18;
					break;
				case VK_F19:
					key = Keyboard::Key::F19;
					break;
				case VK_F20:
					key = Keyboard::Key::F20;
					break;
				case VK_F21:
					key = Keyboard::Key::F21;
					break;
				case VK_F22:
					key = Keyboard::Key::F22;
					break;
				case VK_F23:
					key = Keyboard::Key::F23;
					break;
				case VK_F24:
					key = Keyboard::Key::F24;
					break;
				case VK_NUMLOCK:
					key = Keyboard::Key::NUMLOCK;
					break;
				case VK_SCROLL: // SCROLL LOCK key
				case VK_LSHIFT: // Left SHIFT key
				case VK_RSHIFT: // Right SHIFT key
				case VK_LCONTROL: // Left CONTROL key
				case VK_RCONTROL: // Right CONTROL key
				case VK_LMENU: // Left MENU key
				case VK_RMENU: // Right MENU key
				case VK_BROWSER_BACK:
					key = Keyboard::Key::BROWSER_BACK;
					break;
				case VK_BROWSER_FORWARD:
					key = Keyboard::Key::BROWSER_FORWARD;
					break;
				case VK_BROWSER_REFRESH:
					key = Keyboard::Key::BROWSER_REFRESH;
					break;
				case VK_BROWSER_STOP:
					key = Keyboard::Key::BROWSER_STOP;
					break;
				case VK_BROWSER_SEARCH:
					Keyboard::Key::BROWSER_SEARCH;
					break;
				case VK_BROWSER_FAVORITES:
					key = Keyboard::Key::BROWSER_FAVORITES;
					break;
				case VK_BROWSER_HOME:
					key = Keyboard::Key::BROWSER_HOME;
					break;
				case VK_VOLUME_MUTE:
					key = Keyboard::Key::VOLUME_MUTE;
					break;
				case VK_VOLUME_DOWN:
					key = Keyboard::Key::VOLUME_DOWN;
					break;
				case VK_VOLUME_UP:
					key = Keyboard::Key::VOLUME_UP;
					break;
				case VK_MEDIA_NEXT_TRACK:
					key = Keyboard::Key::MEDIA_NEXT;
					break;
				case VK_MEDIA_PREV_TRACK:
					key = Keyboard::Key::MEDIA_PREVIOUS;
					break;
				case VK_MEDIA_STOP:
					key = Keyboard::Key::MEDIA_STOP;
					break;
				case VK_MEDIA_PLAY_PAUSE:
					key = Keyboard::Key::MEDIA_PLAY;
					break;
				case VK_LAUNCH_MAIL:
					key = Keyboard::Key::LAUNCH_MAIL;
					break;
				case VK_LAUNCH_MEDIA_SELECT:
					key = Keyboard::Key::SELECT_MEDIA;
					break;
				case VK_LAUNCH_APP1:
					key = Keyboard::Key::APP_1;
					break;
				case VK_LAUNCH_APP2:
					key = Keyboard::Key::APP_2;
					break;
				case VK_OEM_1:
					key = Keyboard::Key::OEM_1;
					break; // � $ �
				case VK_OEM_PLUS:
					key = Keyboard::Key::OEM_PLUS;
					break; // + = }
				case VK_OEM_COMMA:
					key = Keyboard::Key::OEM_COMMA;
					break; // ? ,
				case VK_OEM_MINUS:
					key = Keyboard::Key::OEM_MINUS;
					break; //  - _
				case VK_OEM_PERIOD:
					key = Keyboard::Key::OEM_PERIOD;
					break; // . ;
				case VK_OEM_2:
					key = Keyboard::Key::OEM_2;
					break; // : /
				case VK_OEM_3:
					key = Keyboard::Key::OEM_3;
					break; // % �
				case VK_OEM_4:
					key = Keyboard::Key::OEM_4;
					break; // � ) ]
				case VK_OEM_5:
					key = Keyboard::Key::OEM_5;
					break; // � *
				case VK_OEM_6:
					key = Keyboard::Key::OEM_6;
					break; // ^ �
				case VK_OEM_7:
					key = Keyboard::Key::OEM_7;
					break; // �
				case VK_OEM_8:
					key = Keyboard::Key::OEM_8;
					break; // � !
				case VK_OEM_102:
					key = Keyboard::Key::OEM_102;
					break; // > <
				case VK_PROCESSKEY: // IME PROCESS key
				case VK_PACKET: // Used to pass Unicode characters as if they were keystrokes.The VK_PACKET key is the low word of a 32 - bit Virtual Key value used for non - keyboard input methods.For more information, see Remark in KEYBDINPUT, SendInput, WM_KEYDOWN, and WM_KEYUP
				case VK_ATTN: // Attn key
				case VK_CRSEL: // CrSel key
				case VK_EXSEL: // ExSel key
				case VK_EREOF: // Erase EOF key
				case VK_PLAY: // Play key
				case VK_ZOOM: // Zoom key
				case VK_PA1: // PA1 key
				case VK_OEM_CLEAR: // Clear key
				default:
					key = Keyboard::Key::KEY_NONE;
					break;
				}
				return key;
			}
		} // namespace common
	} // namespace window
} // namespace ece
