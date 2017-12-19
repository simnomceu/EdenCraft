#include "window/common/window_adapter.hpp"
#include "window/win32/data_window_adapter.hpp"

#include <iostream>
#include <windowsx.h>

namespace ece
{
	WindowAdapter::WindowAdapter(): BaseWindowAdapter(), data(makePimpl<DataWindowAdapter>(nullptr)) {}

	void WindowAdapter::createWindow()
	{
		registerPattern();

		DWORD settingsEx = WS_EX_TOPMOST;
		DWORD settings = WS_OVERLAPPEDWINDOW;

		this->data->windowId = CreateWindowEx(settingsEx, className, L"", settings, 0, 0, 320, 320, nullptr, nullptr, GetModuleHandle(nullptr), this);
		ShowWindow(this->data->windowId, SW_SHOW);
		UpdateWindow(this->data->windowId);
	}

	void WindowAdapter::deleteWindow()
	{
		int codeError = DestroyWindow(this->data->windowId);
		if (codeError == 0) {
			std::cout << "Erreur destruction HWND. (WGL)";
			std::cout << " Code " << GetLastError() << std::endl;
		}
		this->data->windowId = nullptr;
	}

	bool WindowAdapter::isWindowCreated() const
	{
		return this->data->windowId != nullptr;
	}

	void WindowAdapter::setTitle(const std::string & title)
	{
		bool success = SetWindowTextA(this->data->windowId, title.data());
		if (!success) {
			std::cout << "Error while renaming window. (WGL)";
			std::cout << " Code " << GetLastError() << std::endl;
		}
	}

	std::string WindowAdapter::getTitle() const
	{
		LPSTR title = nullptr;
		bool success = GetWindowTextA(this->data->windowId, title, GetWindowTextLengthA(this->data->windowId));
		if (!success) {
			std::cout << "Error while getting window name. (WGL)";
			std::cout << " Code " << GetLastError() << std::endl;
		}
		return std::string(title);
	}

	void WindowAdapter::setPosition(const IntVertex2u & position)
	{
		bool success = SetWindowPos(this->data->windowId, 0, position[0], position[1], 0, 0, SWP_NOSIZE | SWP_NOZORDER);
		if (!success) {
			std::cout << "Error while moving window. (WGL)";
			std::cout << " Code " << GetLastError() << std::endl;
		}
	}

	IntVertex2u WindowAdapter::getPosition() const
	{
		RECT bounds;
		bool success = GetWindowRect(this->data->windowId, &bounds);
		if (!success) {
			std::cout << "Error while retrieving window bounds. (WGL)";
			std::cout << " Code " << GetLastError() << std::endl;
		}
		return IntVertex2u(bounds.left, bounds.top);
	}

	void WindowAdapter::minimize()
	{
		bool success = ShowWindow(this->data->windowId, SW_RESTORE | SW_SHOWMINIMIZED);
		if (!success) {
			std::cout << "Error while minimizing window. (WGL)";
			std::cout << " Code " << GetLastError() << std::endl;
		}
	}

	void WindowAdapter::maximize()
	{
		bool success = ShowWindow(this->data->windowId, SW_RESTORE | SW_SHOWMAXIMIZED);
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

	/*bool WindowAdapter::hasEvents() const
	{
		return PeekMessage(nullptr, this->windowId, 0, 0, PM_NOREMOVE);
	}*/

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

	void WindowAdapter::processMessage(const WindowMessage & message)
	{
		if (this->data->windowId == message.windowId) {
			switch (message.message) {
			case WM_KEYDOWN: {
				auto keyCode = interpretKey(message.wParam);
				if (this->keyRepeat || (!this->keyRepeat && !Keyboard::isKeyPressed(keyCode))) {
					InputEvent newEvent;
					newEvent.type = InputEvent::ECE_KEY_PRESSED;
					newEvent.key = keyCode;
					this->pushEvent(newEvent);
					Keyboard::pressKey(keyCode, true);
				}
				break;
			}
			case WM_KEYUP: {
				auto keyCode = interpretKey(message.wParam);
				InputEvent newEvent;
				newEvent.type = InputEvent::ECE_KEY_RELEASED;
				newEvent.key = keyCode;
				this->pushEvent(newEvent);
				Keyboard::pressKey(keyCode, false);
				break;
			}
			case WM_LBUTTONDOWN: {
				if (this->keyRepeat || (!this->keyRepeat && !Mouse::isKeyPressed(Mouse::ECE_MOUSE_LEFT))) {
					InputEvent newEvent;
					newEvent.type = InputEvent::ECE_MOUSE_PRESSED;
					newEvent.mouseButton = Mouse::ECE_MOUSE_LEFT;
					this->pushEvent(newEvent);
					Mouse::pressKey(Mouse::ECE_MOUSE_LEFT, true);
				}
				break;
			}
			case WM_LBUTTONUP: {
				InputEvent newEvent;
				newEvent.type = InputEvent::ECE_MOUSE_RELEASED;
				newEvent.mouseButton = Mouse::ECE_MOUSE_LEFT;
				this->pushEvent(newEvent);
				Mouse::pressKey(Mouse::ECE_MOUSE_LEFT, false);
				break;
			}
			case WM_LBUTTONDBLCLK: {
				InputEvent newEvent;
				newEvent.type = InputEvent::ECE_MOUSE_PRESSED;
				newEvent.mouseButton = Mouse::ECE_MOUSE_LEFT;
				newEvent.doubleTap = InputEvent::ECE_FIRST_OF;
				this->pushEvent(newEvent);
				newEvent.doubleTap = InputEvent::ECE_LAST_OF;
				this->pushEvent(newEvent);
				break;
			}
			case WM_RBUTTONDOWN: {
				if (this->keyRepeat || (!this->keyRepeat && !Mouse::isKeyPressed(Mouse::ECE_MOUSE_RIGHT))) {
					InputEvent newEvent;
					newEvent.type = InputEvent::ECE_MOUSE_PRESSED;
					newEvent.mouseButton = Mouse::ECE_MOUSE_RIGHT;
					this->pushEvent(newEvent);
					Mouse::pressKey(Mouse::ECE_MOUSE_RIGHT, true);
				}
				break;
			}
			case WM_RBUTTONUP: {
				InputEvent newEvent;
				newEvent.type = InputEvent::ECE_MOUSE_RELEASED;
				newEvent.mouseButton = Mouse::ECE_MOUSE_RIGHT;
				this->pushEvent(newEvent);
				Mouse::pressKey(Mouse::ECE_MOUSE_RIGHT, false);
				break;
			}
			case WM_RBUTTONDBLCLK: {
				InputEvent newEvent;
				newEvent.type = InputEvent::ECE_MOUSE_PRESSED;
				newEvent.mouseButton = Mouse::ECE_MOUSE_RIGHT;
				this->pushEvent(newEvent);
				this->pushEvent(newEvent);
				break;
			}
			case WM_MBUTTONDOWN: {
				if (this->keyRepeat || (!this->keyRepeat && !Mouse::isKeyPressed(Mouse::ECE_MOUSE_WHEEL))) {
					InputEvent newEvent;
					newEvent.type = InputEvent::ECE_MOUSE_PRESSED;
					newEvent.mouseButton = Mouse::ECE_MOUSE_WHEEL;
					this->pushEvent(newEvent);
					Mouse::pressKey(Mouse::ECE_MOUSE_WHEEL, true);
				}
				break;
			}
			case WM_MBUTTONUP: {
				InputEvent newEvent;
				newEvent.type = InputEvent::ECE_MOUSE_RELEASED;
				newEvent.mouseButton = Mouse::ECE_MOUSE_WHEEL;
				this->pushEvent(newEvent);
				Mouse::pressKey(Mouse::ECE_MOUSE_WHEEL, false);
				break;
			}
			case WM_MBUTTONDBLCLK: {
				InputEvent newEvent;
				newEvent.type = InputEvent::ECE_MOUSE_PRESSED;
				newEvent.mouseButton = Mouse::ECE_MOUSE_WHEEL;
				this->pushEvent(newEvent);
				this->pushEvent(newEvent);
				break;
			}
			case WM_MOUSEMOVE: {
				InputEvent newEvent;
				newEvent.type = InputEvent::ECE_MOUSE_MOVED;
				newEvent.mousePosition[0] = GET_X_LPARAM(message.lParam);
				newEvent.mousePosition[1] = GET_Y_LPARAM(message.lParam);
				Mouse::setPosition(this->getPosition() + newEvent.mousePosition);
				this->pushEvent(newEvent);
				break;
			}
			default: {
				break;
			}
			}
		}
	}

	Keyboard::Key interpretKey(WPARAM wParam)
	{
		Keyboard::Key key;
		switch (wParam) {
		case VK_CANCEL: //Control-break processing
		case VK_BACK:
			key = Keyboard::BACKSPACE;
			break;
		case VK_TAB:
			key = Keyboard::TAB;
			break;
		case VK_CLEAR: // CLEAR key
		case VK_RETURN:
			key = Keyboard::RETURN;
			break;
		case VK_SHIFT:
			key = Keyboard::SHIFT;
			break;
		case VK_CONTROL:
			key = Keyboard::CTRL;
			break;
		case VK_MENU:
			key = Keyboard::ALTGR;
			break;
		case VK_PAUSE:
			key = Keyboard::PAUSE;
			break;
		case VK_CAPITAL:
			key = Keyboard::CAPS_LOCK;
			break; // CAPS LOCK key
		case VK_KANA: // IME Kana mode // IME Hangul mode
		case VK_JUNJA: // IME Junja mode
		case VK_FINAL: // IME final mode
		case VK_HANJA: // IME Hanja mode // IME Kanji mode
		case VK_ESCAPE:
			key = Keyboard::ESCAPE;
			break;
		case VK_CONVERT: // IME convert
		case VK_NONCONVERT: // IME nonconvert
		case VK_ACCEPT: // IME accept
		case VK_MODECHANGE: // IME mode change request
		case VK_SPACE:
			key = Keyboard::SPACEBAR;
			break;
		case VK_PRIOR:
			key = Keyboard::PAGE_UP;
			break;
		case VK_NEXT:
			key = Keyboard::PAGE_DOWN;
			break;
		case VK_END:
			key = Keyboard::END;
			break;
		case VK_HOME:
			key = Keyboard::HOME;
			break;
		case VK_LEFT:
			key = Keyboard::LEFT;
			break;
		case VK_UP:
			key = Keyboard::UP;
			break;
		case VK_RIGHT:
			key = Keyboard::RIGHT;
			break;
		case VK_DOWN:
			key = Keyboard::DOWN;
			break;
		case VK_SELECT: // SELECT key
		case VK_PRINT: // PRINT key
		case VK_EXECUTE: // EXECUTE key
		case VK_SNAPSHOT:
			key = Keyboard::PRINT_SCREEN;
			break; 
		case VK_INSERT:
			key = Keyboard::INS;
			break;
		case VK_DELETE:
			key = Keyboard::DEL;
			break;
		case VK_HELP:
			key = Keyboard::HELP;
			break;
		case '0':
			key = Keyboard::NUM_0;
			break;
		case '1':
			key = Keyboard::NUM_1;
			break;
		case '2':
			key = Keyboard::NUM_2;
			break;
		case '3':
			key = Keyboard::NUM_3;
			break;
		case '4':
			key = Keyboard::NUM_4;
			break;
		case '5':
			key = Keyboard::NUM_5;
			break;
		case '6':
			key = Keyboard::NUM_6;
			break;
		case '7':
			key = Keyboard::NUM_7;
			break;
		case '8':
			key = Keyboard::NUM_8;
			break;
		case '9':
			key = Keyboard::NUM_9;
			break;
		case 'A':
			key = Keyboard::A;
			break;
		case 'B':
			key = Keyboard::B;
			break;
		case 'C':
			key = Keyboard::C;
			break;
		case 'D':
			key = Keyboard::D;
			break;
		case 'E':
			key = Keyboard::E;
			break;
		case 'F':
			key = Keyboard::F;
			break;
		case 'G':
			key = Keyboard::G;
			break;
		case 'H':
			key = Keyboard::H;
			break;
		case 'I':
			key = Keyboard::I;
			break;
		case 'J':
			key = Keyboard::J;
			break;
		case 'K':
			key = Keyboard::K;
			break;
		case 'L':
			key = Keyboard::L;
			break;
		case 'M':
			key = Keyboard::M;
			break;
		case 'N':
			key = Keyboard::N;
			break;
		case 'O':
			key = Keyboard::O;
			break;
		case 'P':
			key = Keyboard::P;
			break;
		case 'Q':
			key = Keyboard::Q;
			break;
		case 'R':
			key = Keyboard::R;
			break;
		case 'S':
			key = Keyboard::S;
			break;
		case 'T':
			key = Keyboard::T;
			break;
		case 'U':
			key = Keyboard::U;
			break;
		case 'V':
			key = Keyboard::V;
			break;
		case 'W':
			key = Keyboard::W;
			break;
		case 'X':
			key = Keyboard::X;
			break;
		case 'Y':
			key = Keyboard::Y;
			break;
		case 'Z':
			key = Keyboard::Z;
			break;
		case VK_LWIN:
			key = Keyboard::LEFT_COMMAND;
			break; // Left Windows key(Natural keyboard)
		case VK_RWIN:
			key = Keyboard::RIGHT_COMMAND;
			break; // Right Windows key(Natural keyboard)
		case VK_APPS:
			key = Keyboard::APPLICATIONS;
			break;
		case VK_SLEEP:
			key = Keyboard::SLEEP;
			break;
		case VK_NUMPAD0:
			key = Keyboard::NUMPAD_0;
			break;
		case VK_NUMPAD1:
			key = Keyboard::NUMPAD_1;
			break;
		case VK_NUMPAD2:
			key = Keyboard::NUMPAD_2;
			break;
		case VK_NUMPAD3:
			key = Keyboard::NUMPAD_3;
			break;
		case VK_NUMPAD4:
			key = Keyboard::NUMPAD_4;
			break;
		case VK_NUMPAD5:
			key = Keyboard::NUMPAD_5;
			break;
		case VK_NUMPAD6:
			key = Keyboard::NUMPAD_6;
			break;
		case VK_NUMPAD7:
			key = Keyboard::NUMPAD_7;
			break;
		case VK_NUMPAD8:
			key = Keyboard::NUMPAD_8;
			break;
		case VK_NUMPAD9:
			key = Keyboard::NUMPAD_9;
			break;
		case VK_MULTIPLY:
			key = Keyboard::MULTIPLY;
 			break;
		case VK_ADD:
			key = Keyboard::ADD;
			break;
		case VK_SEPARATOR: // Separator key
		case VK_SUBTRACT:
			key = Keyboard::SUBSTRACT;
			break;
		case VK_DECIMAL:
			key = Keyboard::NUMPAD_DEL;
			break;
		case VK_DIVIDE:
			key = Keyboard::DIVIDE;
			break;
		case VK_F1:
			key = Keyboard::F1;
			break;
		case VK_F2:
			key = Keyboard::F2;
			break;
		case VK_F3:
			key = Keyboard::F3;
			break;
		case VK_F4:
			key = Keyboard::F4;
			break;
		case VK_F5:
			key = Keyboard::F5;
			break;
		case VK_F6:
			key = Keyboard::F6;
			break;
		case VK_F7:
			key = Keyboard::F7;
			break;
		case VK_F8:
			key = Keyboard::F8;
			break;
		case VK_F9:
			key = Keyboard::F9;
			break;
		case VK_F10:
			key = Keyboard::F10;
			break;
		case VK_F11:
			key = Keyboard::F11;
			break;
		case VK_F12:
			key = Keyboard::F12;
			break;
		case VK_F13:
			key = Keyboard::F13;
			break;
		case VK_F14:
			key = Keyboard::F14;
			break;
		case VK_F15:
			key = Keyboard::F15;
			break;
		case VK_F16:
			key = Keyboard::F16;
			break;
		case VK_F17:
			key = Keyboard::F17;
			break;
		case VK_F18:
			key = Keyboard::F18;
			break;
		case VK_F19:
			key = Keyboard::F19;
			break;
		case VK_F20:
			key = Keyboard::F20;
			break;
		case VK_F21:
			key = Keyboard::F21;
			break;
		case VK_F22:
			key = Keyboard::F22;
			break;
		case VK_F23:
			key = Keyboard::F23;
			break;
		case VK_F24:
			key = Keyboard::F24;
			break;
		case VK_NUMLOCK:
			key = Keyboard::NUMLOCK;
			break;
		case VK_SCROLL: // SCROLL LOCK key
		case VK_LSHIFT: // Left SHIFT key
		case VK_RSHIFT: // Right SHIFT key
		case VK_LCONTROL: // Left CONTROL key
		case VK_RCONTROL: // Right CONTROL key
		case VK_LMENU: // Left MENU key
		case VK_RMENU: // Right MENU key
		case VK_BROWSER_BACK:
			key = Keyboard::BROWSER_BACK;
			break;
		case VK_BROWSER_FORWARD:
			key = Keyboard::BROWSER_FORWARD;
			break;
		case VK_BROWSER_REFRESH:
			key = Keyboard::BROWSER_REFRESH;
			break;
		case VK_BROWSER_STOP:
			key = Keyboard::BROWSER_STOP;
			break;
		case VK_BROWSER_SEARCH:
			Keyboard::BROWSER_SEARCH;
			break;
		case VK_BROWSER_FAVORITES:
			key = Keyboard::BROWSER_FAVORITES;
			break;
		case VK_BROWSER_HOME:
			key = Keyboard::BROWSER_HOME;
			break;
		case VK_VOLUME_MUTE:
			key = Keyboard::VOLUME_MUTE;
			break;
		case VK_VOLUME_DOWN:
			key = Keyboard::VOLUME_DOWN;
			break;
		case VK_VOLUME_UP:
			key = Keyboard::VOLUME_UP;
			break;
		case VK_MEDIA_NEXT_TRACK:
			key = Keyboard::MEDIA_NEXT;
			break;
		case VK_MEDIA_PREV_TRACK:
			key = Keyboard::MEDIA_PREVIOUS;
			break;
		case VK_MEDIA_STOP:
			key = Keyboard::MEDIA_STOP;
			break;
		case VK_MEDIA_PLAY_PAUSE:
			key = Keyboard::MEDIA_PLAY;
			break;
		case VK_LAUNCH_MAIL:
			key = Keyboard::LAUNCH_MAIL;
			break;
		case VK_LAUNCH_MEDIA_SELECT:
			key = Keyboard::SELECT_MEDIA;
			break;
		case VK_LAUNCH_APP1:
			key = Keyboard::APP_1;
			break;
		case VK_LAUNCH_APP2:
			key = Keyboard::APP_2;
			break;
		case VK_OEM_1:
			key = Keyboard::OEM_1;
			break; // £ $ ¤
		case VK_OEM_PLUS:
			key = Keyboard::OEM_PLUS;
			break; // + = }
		case VK_OEM_COMMA:
			key = Keyboard::OEM_COMMA;
			break; // ? ,
		case VK_OEM_MINUS:
			key = Keyboard::OEM_MINUS;
			break; //  - _
		case VK_OEM_PERIOD:
			key = Keyboard::OEM_PERIOD;
			break; // . ;
		case VK_OEM_2:
			key = Keyboard::OEM_2;
			break; // : /
		case VK_OEM_3:
			key = Keyboard::OEM_3;
			break; // % ù
		case VK_OEM_4:
			key = Keyboard::OEM_4;
			break; // ° ) ]
		case VK_OEM_5:
			key = Keyboard::OEM_5;
			break; // µ *
		case VK_OEM_6:
			key = Keyboard::OEM_6;
			break; // ^ ¨
		case VK_OEM_7:
			key = Keyboard::OEM_7;
			break; // ²
		case VK_OEM_8:
			key = Keyboard::OEM_8;
			break; // § !
		case VK_OEM_102:
			key = Keyboard::OEM_102;
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
			key = Keyboard::KEY_NONE;
			break;
		}
		return key;
	}
}