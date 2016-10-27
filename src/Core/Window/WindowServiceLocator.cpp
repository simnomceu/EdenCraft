#include "Core\Window\WindowServiceLocator.hpp"

#include "Core\Window\WindowManagerNone.hpp"

namespace ece
{
	std::shared_ptr<WindowManager> WindowServiceLocator::service(new WindowManagerNone());

	void WindowServiceLocator::provide(WindowManager * service)
	{
		WindowServiceLocator::service = std::shared_ptr<WindowManager>(service);
	}

	WindowManager & WindowServiceLocator::getService()
	{
		return *WindowServiceLocator::service;
	}

	void WindowServiceLocator::stopService()
	{
		WindowServiceLocator::service = std::shared_ptr<WindowManager>(new WindowManagerNone());
	}
}