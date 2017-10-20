#include "wgl/window_adapter.hpp"

#include <iostream>

namespace ece
{
	void WindowAdapter::createWindow()
	{
		WNDCLASSEX windowPattern;
		windowPattern.cbClsExtra = 0;
		windowPattern.cbSize = sizeof(WNDCLASSEX);
		windowPattern.cbWndExtra = 0;
		windowPattern.hbrBackground = static_cast<HBRUSH>(GetStockObject(BLACK_BRUSH));
		windowPattern.hCursor = LoadCursor(nullptr, IDC_ARROW);
		windowPattern.hIcon = LoadIcon(nullptr, IDI_APPLICATION);
		windowPattern.hIconSm = LoadIcon(nullptr, IDI_APPLICATION);
		windowPattern.hInstance = nullptr;
		windowPattern.lpfnWndProc = WindowAdapter::processMessages;
		windowPattern.lpszClassName = this->className;
		windowPattern.lpszMenuName = nullptr;
		windowPattern.style = CS_HREDRAW | CS_VREDRAW | CS_OWNDC;

		int codeError = RegisterClassEx(&windowPattern);
		if (codeError == 0) {
			std::cout << "Erreur enregistrement du WNDCLASSEX window pattern. (WGL)" << std::endl;
		}

		DWORD settingsEx = WS_EX_APPWINDOW | WS_EX_WINDOWEDGE;
		DWORD settings = WS_VISIBLE;

		this->windowId = CreateWindowEx(settings, this->className, L"", settings, 0, 0, 100, 100, nullptr, nullptr, nullptr, nullptr);
	}

	void WindowAdapter::deleteWindow()
	{
		int codeError = DestroyWindow(this->windowId);
		if (codeError == 0) {
			std::cout << "Erreur destruction HWND. (WGL)" << std::endl;
		}
	}

	bool WindowAdapter::isWindowCreated() const
	{
		return this->windowId != nullptr;
	}

	void WindowAdapter::setTitle(const std::string & title)
	{
		SetWindowTextA(this->windowId, title.data());
	}

	LRESULT CALLBACK WindowAdapter::processMessages(HWND windowId, UINT message, WPARAM wParam, LPARAM lParam)
	{
		switch (message) {
		case WM_DESTROY:
			PostQuitMessage(WM_QUIT);
			break;
		default:
			break;
		}
		return 0;
	}
}