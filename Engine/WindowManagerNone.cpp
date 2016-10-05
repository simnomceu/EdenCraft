#include "WindowManagerNone.hpp"

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
	void WindowManagerNone::setTitle(const short int windowId, const std::string & title)
	{

	}
	void WindowManagerNone::setBounds(const short int windowId, const Utils::Rectangle<unsigned int>& bounds)
	{
	}
	void WindowManagerNone::setPosition(const short int windowId, const Utils::Vector2ui & position)
	{
	}
	void WindowManagerNone::setSize(const short int windowId, const Utils::Vector2ui & size)
	{
	}
	Rectangle<unsigned int> WindowManagerNone::getBounds(const short int windowId)
	{
		return Rectangle<unsigned int>();
	}
	Vector2ui WindowManagerNone::getPosition(const short int windowId)
	{
		return Vector2ui();
	}
	Vector2ui WindowManagerNone::getSize(const short int windowId)
	{
		return Vector2ui();
	}
}