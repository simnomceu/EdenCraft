#include "Core\Window\WindowManagerNone.hpp"

namespace Utils
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

	void WindowManagerNone::provideSettings(const Utils::WindowID & windowId, const Utils::WindowSetting & settings)
	{
	}

	void WindowManagerNone::provideVideoMode(const Utils::WindowID & windowId, const Utils::VideoMode & settings)
	{
	}

	void WindowManagerNone::attachToMonitor(const Utils::WindowID & windowId, const short int monitorId)
	{
	}

	std::vector<Utils::MonitorID>& WindowManagerNone::getMonitors()
	{
		return std::vector<Utils::MonitorID>();
	}
}