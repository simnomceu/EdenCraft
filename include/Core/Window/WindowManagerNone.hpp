#pragma once

#include "Core\Window\WindowManager.hpp"

namespace ece
{
	class WindowManagerNone : public WindowManager
	{
	public:
		WindowManagerNone();
		~WindowManagerNone();

		short int openWindow();
		void closeWindow(const short int windowId);

		void provideSettings(const ece::WindowID & windowId, const ece::WindowSetting & settings);

		void provideVideoMode(const ece::WindowID & windowId, const ece::VideoMode & settings);

		void attachToMonitor(const ece::WindowID & windowId, const short int monitorId);

		std::vector<ece::MonitorID> & getMonitors();
	};
}