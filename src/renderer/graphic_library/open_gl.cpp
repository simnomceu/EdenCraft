#include "graphic_library/open_gl.hpp"

namespace ece
{
	void OpenGL::preInit()
	{
	}

	void OpenGL::postInit()
	{
		this->glewHandle.init();
	}

	bool OpenGL::isPreInitialized()
	{
		return false;
	}

	bool OpenGL::isPostInitialized()
	{
		return this->glewHandle.isInit();
	}
}