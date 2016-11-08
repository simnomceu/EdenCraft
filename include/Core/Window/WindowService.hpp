#ifndef WINDOWSERVICE_HPP
#define WINDOWSERVICE_HPP

#include "Core\Util\Module\ServiceFactory.hpp"
#include "Core\Util\Module\ServiceLocator.hpp"
#include "Core\Util\Module\Service.hpp"
#include "Core\Window\Window\WindowManager.hpp"
#include "Core\Window\Window\WindowManagerNone.hpp"

namespace ece
{
	typedef ServiceFactory<WindowManager> WindowServiceFactory;

	typedef ServiceLocator<WindowManager, WindowManagerNone> WindowServiceLocator;

	class WindowService : public Service
	{
	public:
		WindowService();

		virtual void init(Mode mode = Mode::NONE);

		virtual void setMode(Mode mode);
	};
}

#endif // WINDOWSERVICE_HPP
