#pragma once

#include <vector>

#include "Core\Window\WindowSetting.hpp"
#include "Core\Window\VideoMode.hpp"
#include "Core\Window\Window.inl"

namespace Utils
{
	class WindowManager
	{
	public:
		virtual ~WindowManager() {}

		virtual short int openWindow() = 0;
		virtual void closeWindow(const short int windowId) = 0;

		virtual void provideSettings(const Utils::WindowID & windowId, const Utils::WindowSetting & settings) = 0;

		virtual void provideVideoMode(const Utils::WindowID & windowId, const Utils::VideoMode & settings) = 0;

		virtual void attachToMonitor(const Utils::WindowID & windowId, const short int monitorId) = 0;

		virtual std::vector<Utils::MonitorID> & getMonitors() = 0;
	};
}