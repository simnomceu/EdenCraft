#ifndef WINDOW_MANAGER_HPP
#define WINDOW_MANAGER_HPP

#include <vector>
#include <functional>

#include "window\window_setting.hpp"
#include "window\video_mode.hpp"
#include "window.inl"

namespace ece
{
	class EventHandler;
	class InputEvent;

	class WindowManager
	{
	public:
		virtual ~WindowManager() {}

		virtual ece::WindowID openWindow(const ece::WindowTag & tag = ece::NO_OPTIONS_BIS) = 0;
		virtual void closeWindow(const ece::WindowID & windowId) = 0;

		virtual bool windowShouldClose(const ece::WindowID & windowId) = 0;

		virtual void setTitle(const ece::WindowID & windowId, const std::string & title) = 0;
		virtual void setBounds(const ece::WindowID & windowId, const ece::Rectangle<unsigned int> & bounds) = 0;
		virtual void setState(const ece::WindowID & windowId, const ece::WindowState & state) = 0;
		virtual void provideSettings(const ece::WindowID & windowId, ece::WindowSetting & settings) = 0;

		virtual void provideVideoMode(const ece::VideoMode & videoMode) = 0;

		virtual void attachToMonitor(const ece::WindowID & windowId, const short int monitorId, const ece::WindowSetting & settings) = 0;

		virtual unsigned short int getNumberOfMonitors() = 0;

		virtual void pollEvents(const ece::WindowID & windowId, InputEvent & event) = 0;
		virtual void waitEvents(const ece::WindowID & windowId, InputEvent & event) = 0;

		virtual void registerEventHandler(const ece::WindowID & windowId) = 0;

		virtual void displayOnWindow(const ece::WindowID & windowId) = 0;
	};
}

#endif // WINDOW_MANAGER_HPP