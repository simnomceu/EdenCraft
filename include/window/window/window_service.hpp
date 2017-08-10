#ifndef WINDOW_SERVICE_HPP
#define WINDOW_SERVICE_HPP

#include "service/service_factory.hpp"
#include "service/service_locator.hpp"
#include "window/window_manager_none.hpp"
#include "window/window_manager.hpp"

namespace ece
{
	typedef ServiceFactory<WindowManager> WindowServiceFactory;

	typedef ServiceLocator<WindowManager, WindowManagerNone> WindowServiceLocator;
}

#endif // WINDOW_SERVICE_HPP
