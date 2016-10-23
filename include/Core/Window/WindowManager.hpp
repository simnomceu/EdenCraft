#pragma once

#include <vector>

#include "Core\Window\WindowSetting.hpp"
#include "Core\Window\VideoMode.hpp"
#include "Core\Window\Window.inl"

namespace ece
{
	class WindowManager
	{
	public:
		virtual ~WindowManager() {}

		virtual short int openWindow() = 0;
		virtual void closeWindow(const short int windowId) = 0;

		virtual void provideSettings(const ece::WindowID & windowId, const ece::WindowSetting & settings) = 0;

		virtual void provideVideoMode(const ece::WindowID & windowId, const ece::VideoMode & settings) = 0;

		virtual void attachToMonitor(const ece::WindowID & windowId, const short int monitorId) = 0;

		virtual std::vector<ece::MonitorID> & getMonitors() = 0;
	};
}