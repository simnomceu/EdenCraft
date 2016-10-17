#include "Core/WindowManagerNone.hpp"

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
	void WindowManagerNone::attachToMonitor(const short int windowId, const short int monitorId)
	{
		// TODO attach to the monitor
	}
	void WindowManagerNone::setTitle(const short int windowId, const std::string & title)
	{

	}
	void WindowManagerNone::setBounds(const short int windowId, const Geom::Rectangle<unsigned int>& bounds)
	{
	}
	void WindowManagerNone::setPosition(const short int windowId, const Geom::Vector2ui & position)
	{
	}
	void WindowManagerNone::setSize(const short int windowId, const Geom::Vector2ui & size)
	{
	}
	Geom::Rectangle<unsigned int> WindowManagerNone::getBounds(const short int windowId)
	{
		return Geom::Rectangle<unsigned int>();
	}
	Geom::Vector2ui WindowManagerNone::getPosition(const short int windowId)
	{
		return Geom::Vector2ui();
	}
	Geom::Vector2ui WindowManagerNone::getSize(const short int windowId)
	{
		return Geom::Vector2ui();
	}
}