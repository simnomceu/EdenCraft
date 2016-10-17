#include "Core\WindowManagerBuilder.hpp"

namespace Utils
{
	WindowManager * WindowManagerBuilder::makeWindowManager(const ManagerType & type)
	{
		switch (type) {
		case NONE:
			return new WindowManagerNone();
			break;
		case GLFW:
			return new WindowManagerGLFW();
		}
	}
}