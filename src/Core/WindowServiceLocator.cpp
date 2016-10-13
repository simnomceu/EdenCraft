#include "Core/WindowServiceLocator.hpp"

#include "Core/WindowManagerNone.hpp"

namespace Utils
{
	WindowManager * WindowServiceLocator::service = new WindowManagerNone();

	void WindowServiceLocator::provide(WindowManager * service)
	{
		WindowServiceLocator::service = service;
	}

	WindowManager & WindowServiceLocator::getService()
	{
		return *WindowServiceLocator::service;
	}
	void WindowServiceLocator::stopService()
	{
		WindowServiceLocator::service = new WindowManagerNone();
	}
}