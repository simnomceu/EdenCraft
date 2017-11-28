#ifndef DATA_WINDOW_ADAPTER_HPP
#define DATA_WINDOW_ADAPTER_HPP

#include <Windows.h>

#include "window/window_event/keyboard.hpp"

namespace ece
{
	struct DataWindowAdapter
	{
		inline DataWindowAdapter(HWND windowId) : windowId(windowId) {}

		HWND windowId;
	};

	struct WindowMessage
	{
		HWND windowId;
		UINT message;
		WPARAM wParam;
		LPARAM lParam;
	};

	static constexpr LPCWSTR className = L"ECE Window";

	void registerPattern();
	LRESULT CALLBACK processMessages(HWND windowId, UINT message, WPARAM wParam, LPARAM lParam);
	Keyboard::Key interpretKey(WPARAM wParam);
}

#endif // DATA_WINDOW_ADAPTER_HPP

