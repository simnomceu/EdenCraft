#include "Core\Window\Window\WindowManagerNone.hpp"

namespace ece
{
	WindowManagerNone::WindowManagerNone(): WindowManager()
	{
	}

	WindowManagerNone::~WindowManagerNone()
	{
	}

	ece::WindowID WindowManagerNone::openWindow(const ece::WindowTag & tag)
	{
		return -1;
	}

	void WindowManagerNone::closeWindow(const ece::WindowID & windowId)
	{
	}

	bool WindowManagerNone::windowShouldClose(const ece::WindowID & windowId)
	{
		return false;
	}

	void WindowManagerNone::setTitle(const ece::WindowID & windowId, const std::string & title)
	{
	}

	void WindowManagerNone::setBounds(const ece::WindowID & windowId, const ece::Rectangle<unsigned int>& bounds)
	{
	}

	void WindowManagerNone::setState(const ece::WindowID & windowId, const ece::WindowState & state)
	{
	}

	void WindowManagerNone::provideSettings(const ece::WindowID & windowId, ece::WindowSetting & settings)
	{
	}

	void WindowManagerNone::provideVideoMode(const ece::VideoMode & videoMode)
	{
	}

	void WindowManagerNone::attachToMonitor(const ece::WindowID & windowId, const short int monitorId, const ece::WindowSetting & settings)
	{
	}

	unsigned short int WindowManagerNone::getNumberOfMonitors()
	{
		return 0;
	}
}