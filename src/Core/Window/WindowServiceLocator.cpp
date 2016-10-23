#include "Core\Window\WindowServiceLocator.hpp"

#include "Core\Window\WindowManagerNone.hpp"

namespace ece
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