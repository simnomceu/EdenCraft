#ifndef WINDOWSERVICELOCATOR_HPP
#define WINDOWSERVICELOCATOR_HPP

#include "Core\Window\Window\WindowManager.hpp"

#include <memory>

namespace ece
{
	class WindowServiceLocator
	{
	public:
		static void provide(WindowManager * service);

		static WindowManager & getService();
		
		static void stopService();

	private:
		static std::shared_ptr<WindowManager> service;
	};
}

#endif // WINDOWSERVICLOCATOR_HPP