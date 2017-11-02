#include "win32/window_adapter.hpp"

#include <iostream>

namespace ece
{
	const LPCWSTR WindowAdapter::className = L"ECE Window";

	void WindowAdapter::createWindow()
	{
		this->registerPattern();

		DWORD settingsEx = WS_EX_TOPMOST;
		DWORD settings = WS_OVERLAPPEDWINDOW;

		this->windowId = CreateWindowEx(settingsEx, WindowAdapter::className, L"", settings, 0, 0, 320, 320, nullptr, nullptr, GetModuleHandle(nullptr), this);
		ShowWindow(this->windowId, SW_SHOW);
		UpdateWindow(this->windowId);
	}

	void WindowAdapter::deleteWindow()
	{
		int codeError = DestroyWindow(this->windowId);
		if (codeError == 0) {
			std::cout << "Erreur destruction HWND. (WGL)";
			std::cout << " Code " << GetLastError() << std::endl;
		}
		this->windowId = nullptr;
	}

	bool WindowAdapter::isWindowCreated() const
	{
		return this->windowId != nullptr;
	}

	void WindowAdapter::setTitle(const std::string & title)
	{
		bool success = SetWindowTextA(this->windowId, title.data());
		if (!success) {
			std::cout << "Error while renaming window. (WGL)";
			std::cout << " Code " << GetLastError() << std::endl;
		}
	}

	std::string WindowAdapter::getTitle() const
	{
		LPSTR title = nullptr;
		bool success = GetWindowTextA(this->windowId, title, GetWindowTextLengthA(this->windowId));
		if (!success) {
			std::cout << "Error while getting window name. (WGL)";
			std::cout << " Code " << GetLastError() << std::endl;
		}
		return std::string(title);
	}

	void WindowAdapter::setPosition(const IntVertex2u & position)
	{
		bool success = SetWindowPos(this->windowId, 0, position[0], position[1], 0, 0, SWP_NOSIZE | SWP_NOZORDER);
		if (!success) {
			std::cout << "Error while moving window. (WGL)";
			std::cout << " Code " << GetLastError() << std::endl;
		}
	}

	IntVertex2u WindowAdapter::getPosition() const
	{
		RECT bounds;
		bool success = GetWindowRect(this->windowId, &bounds);
		if (!success) {
			std::cout << "Error while retrieving window bounds. (WGL)";
			std::cout << " Code " << GetLastError() << std::endl;
		}
		return IntVertex2u(bounds.left, bounds.top);
	}

	void WindowAdapter::minimize()
	{
		bool success = ShowWindow(this->windowId, SW_RESTORE | SW_SHOWMINIMIZED);
		if (!success) {
			std::cout << "Error while minimizing window. (WGL)";
			std::cout << " Code " << GetLastError() << std::endl;
		}
	}

	void WindowAdapter::maximize()
	{
		bool success = ShowWindow(this->windowId, SW_RESTORE | SW_SHOWMAXIMIZED);
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

	HWND WindowAdapter::getWindowHandle() const
	{
		return this->windowId;
	}

	/*bool WindowAdapter::hasEvents() const
	{
		return PeekMessage(nullptr, this->windowId, 0, 0, PM_NOREMOVE);
	}*/

	void WindowAdapter::registerPattern()
	{
		WNDCLASSEX windowPattern;
		if (!GetClassInfoEx(GetModuleHandle(nullptr), WindowAdapter::className, &windowPattern)) {
			windowPattern.cbClsExtra = 0;
			windowPattern.cbSize = sizeof(WNDCLASSEX);
			windowPattern.cbWndExtra = 0;
			windowPattern.hbrBackground = nullptr;
			windowPattern.hCursor = LoadCursor(nullptr, IDC_ARROW);
			windowPattern.hIcon = LoadIcon(nullptr, IDI_APPLICATION);
			windowPattern.hIconSm = LoadIcon(nullptr, IDI_APPLICATION);
			windowPattern.hInstance = GetModuleHandle(nullptr);
			windowPattern.lpfnWndProc = WindowAdapter::processMessages;
			windowPattern.lpszClassName = WindowAdapter::className;
			windowPattern.lpszMenuName = nullptr;
			windowPattern.style = CS_DBLCLKS;

			int codeError = RegisterClassEx(&windowPattern);
			if (codeError == 0) {
				std::cout << "Erreur enregistrement du WNDCLASSEX window pattern. (WGL)";
				std::cout << " Code " << GetLastError() << std::endl;
			}
		}
	}

	LRESULT CALLBACK WindowAdapter::processMessages(HWND windowId, UINT message, WPARAM wParam, LPARAM lParam)
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
			return object->processMessage(message, wParam, lParam);
		}
		else {
			return DefWindowProc(windowId, message, wParam, lParam);
		}
	}

	LRESULT WindowAdapter::processMessage(UINT message, WPARAM wParam, LPARAM lParam)
	{
		if (this->windowId == windowId) {
			switch (message) {
			case WM_SYSKEYDOWN: {
				InputEvent newEvent;
				newEvent.type = InputEvent::ECE_KEY_PRESSED;
				newEvent.key = static_cast<Keyboard::Key>(wParam);
				this->pushEvent(newEvent);
				break;
			}
			case WM_SYSKEYUP: {
				InputEvent newEvent;
				newEvent.type = InputEvent::ECE_KEY_RELEASED;
				this->pushEvent(newEvent);
				break;
			}
			case WM_LBUTTONDOWN: {
				InputEvent newEvent;
				newEvent.type = InputEvent::ECE_MOUSE_PRESSED;
				newEvent.mouseButton = Mouse::ECE_MOUSE_LEFT;
				this->pushEvent(newEvent);
				break;
			}
			case WM_LBUTTONUP: {
				InputEvent newEvent;
				newEvent.type = InputEvent::ECE_MOUSE_RELEASED;
				newEvent.mouseButton = Mouse::ECE_MOUSE_LEFT;
				this->pushEvent(newEvent);
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
				InputEvent newEvent;
				newEvent.type = InputEvent::ECE_MOUSE_PRESSED;
				newEvent.mouseButton = Mouse::ECE_MOUSE_RIGHT;
				this->pushEvent(newEvent);
				break;
			}
			case WM_RBUTTONUP: {
				InputEvent newEvent;
				newEvent.type = InputEvent::ECE_MOUSE_RELEASED;
				newEvent.mouseButton = Mouse::ECE_MOUSE_RIGHT;
				this->pushEvent(newEvent);
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
				InputEvent newEvent;
				newEvent.type = InputEvent::ECE_MOUSE_PRESSED;
				newEvent.mouseButton = Mouse::ECE_MOUSE_WHEEL;
				this->pushEvent(newEvent);
				break;
			}
			case WM_MBUTTONUP: {
				InputEvent newEvent;
				newEvent.type = InputEvent::ECE_MOUSE_RELEASED;
				newEvent.mouseButton = Mouse::ECE_MOUSE_WHEEL;
				this->pushEvent(newEvent);
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
			default: {
				break;
			}
			}
		}
		return DefWindowProc(windowId, message, wParam, lParam);
	}
}