#pragma once

#include "WindowManager.hpp"
namespace Utils
{
	class WindowManagerNone : public WindowManager
	{
	public:
		WindowManagerNone();
		~WindowManagerNone();

		short int openWindow();
		void closeWindow(const short int windowId);

		void provideSettings(const Utils::WindowID & windowId, const Utils::WindowSetting & settings);

		void provideVideoMode(const Utils::WindowID & windowId, const Utils::VideoMode & settings);

		void attachToMonitor(const Utils::WindowID & windowId, const short int monitorId);

		std::vector<Utils::MonitorID> & getMonitors();
	};
}