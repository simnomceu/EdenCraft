#include "Core\Window\WindowManagerNone.hpp"

namespace ece
{
	WindowManagerNone::WindowManagerNone(): WindowManager()
	{
	}

	WindowManagerNone::~WindowManagerNone()
	{
	}

	short int WindowManagerNone::openWindow()
	{
		return -1;
	}

	void WindowManagerNone::closeWindow(const short int windowId)
	{
	}

	void WindowManagerNone::provideSettings(const ece::WindowID & windowId, const ece::WindowSetting & settings)
	{
	}

	void WindowManagerNone::provideVideoMode(const ece::WindowID & windowId, const ece::VideoMode & settings)
	{
	}

	void WindowManagerNone::attachToMonitor(const ece::WindowID & windowId, const short int monitorId)
	{
	}

	std::vector<ece::MonitorID> WindowManagerNone::getMonitors()
	{
		return std::vector<ece::MonitorID>();
	}
}