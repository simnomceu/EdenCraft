#pragma once

#include <vector>

#include "WindowSetting.hpp"
#include "VideoMode.hpp"
#include "Window.inl"

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

		virtual const std::vector<Utils::MonitorID> & getMonitors() = 0;
	};
}