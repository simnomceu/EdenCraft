#ifndef WINDOW_MANAGER_NONE_HPP
#define WINDOW_MANAGER_NONE_HPP

#include "window\window_manager.hpp"

namespace ece
{
	class WindowManagerNone : public WindowManager
	{
	public:
		WindowManagerNone() = default;
		~WindowManagerNone() = default;

		inline virtual ece::WindowID openWindow(const ece::WindowTag & tag = ece::NO_OPTIONS_BIS) override;
		inline virtual void closeWindow(const ece::WindowID & windowId) override;

		inline virtual bool windowShouldClose(const ece::WindowID & windowId) override;

		inline virtual void setTitle(const ece::WindowID & windowId, const std::string & title) override;
		inline virtual void setBounds(const ece::WindowID & windowId, const ece::Rectangle<unsigned int> & bounds) override;
		inline virtual void setState(const ece::WindowID & windowId, const ece::WindowState & state) override;
		inline virtual void provideSettings(const ece::WindowID & windowId, ece::WindowSetting & settings) override;

		inline virtual void provideVideoMode(const ece::VideoMode & videoMode) override;

		inline virtual void attachToMonitor(const ece::WindowID & windowId, const short int monitorId, const ece::WindowSetting & settings) override;

		inline virtual unsigned short int getNumberOfMonitors() override;

		inline virtual void pollEvents(const ece::WindowID & windowId, InputEvent & event) override;
		inline virtual void waitEvents(const ece::WindowID & windowId, InputEvent & event) override;
		
		inline virtual void registerEventHandler(const ece::WindowID & windowId) override;

		inline virtual void displayOnWindow(const ece::WindowID & windowId) override;
	};
}

#include "window\window_manager_none.inl"

#endif // WINDOW_MANAGER_NONE_HPP