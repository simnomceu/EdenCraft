#ifndef WINDOWSERVICE_HPP
#define WINDOWSERVICE_HPP

#include "Util\Module\ServiceFactory.hpp"
#include "Util\Module\ServiceLocator.hpp"
#include "Window\WindowManagerNone.hpp"
#include "Window\WindowManager.hpp"

namespace ece
{
	typedef ServiceFactory<WindowManager> WindowServiceFactory;

	typedef ServiceLocator<WindowManager, WindowManagerNone> WindowServiceLocator;
}

#endif // WINDOWSERVICE_HPP