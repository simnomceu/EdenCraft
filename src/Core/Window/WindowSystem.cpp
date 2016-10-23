#include "Core\Window\WindowSystem.hpp"

#include "Core\Window\WindowServiceLocator.hpp"
#include "Core\Window\WindowManagerGLFW.hpp"
#include "Core\Window\WindowManagerBuilder.hpp"

#include <memory>
#include <iostream>

namespace ece
{
	void WindowSystem::initWindowService()
	{
		try {
			WindowServiceLocator::provide(WindowManagerBuilder::makeWindowManager<WindowManagerGLFW>());
		}
		catch (std::exception & e) {
			std::cerr << e.what() << std::endl;
		}
	}
}
