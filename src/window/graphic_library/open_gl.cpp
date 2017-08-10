#include "graphic_library/open_gl.hpp"

namespace ece
{
	void OpenGL::preInit()
	{
		this->glfwHandle.init();
		this->glfwHandle.parametrizeContext();
	}

	void OpenGL::postInit()
	{
		this->glewHandle.init();
	}

	bool OpenGL::isPreInitialized()
	{
		return this->glfwHandle.isInit();
	}

	bool OpenGL::isPostInitialized()
	{
		return this->glewHandle.isInit();
	}
}