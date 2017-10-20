#ifndef WINDOW_ADAPTER_HPP
#define WINDOW_ADAPTER_HPP

#include <Windows.h>

#include "window_refactor\base_window_adapter.hpp"

namespace ece
{
	class WindowAdapter: public BaseWindowAdapter
	{
	public:
		WindowAdapter() = default;
		WindowAdapter(const WindowAdapter & copy) = default;
		WindowAdapter(WindowAdapter && move) = default;

		~WindowAdapter() = default;

		WindowAdapter & operator=(const WindowAdapter & copy) = default;
		WindowAdapter & operator=(WindowAdapter && move) = default;

		virtual void createWindow() override;
		virtual void deleteWindow() override;
		virtual bool isWindowCreated() const override;

		virtual void setTitle(const std::string & title) override;

	private:
		HWND windowId;

		static LRESULT CALLBACK processMessages(HWND windowId, UINT message, WPARAM wParam, LPARAM lParam);

		const LPCWSTR className = L"ECE Window";
	};
}

#endif // WINDOW_ADAPTER_HPP