#ifndef WINDOW_ADAPTER_HPP
#define WINDOW_ADAPTER_HPP

#include <Windows.h>

#include "window_refactor/base_window_adapter.hpp"

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
		virtual std::string getTitle() const override;

		virtual void setPosition(const IntVertex2u & position) override;
		virtual IntVertex2u getPosition() const override;

		virtual void minimize() override;
		virtual void maximize() override;

		virtual void processEvent(const bool blocking) override;
	private:
		HWND windowId;

		void registerPattern();
		static const LPCWSTR className;
		static LRESULT CALLBACK processMessages(HWND windowId, UINT message, WPARAM wParam, LPARAM lParam);
		LRESULT  processMessage(UINT message, WPARAM wParam, LPARAM lParam);
	};
}

#endif // WINDOW_ADAPTER_HPP