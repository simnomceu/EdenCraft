#include "graphic_library\glew.hpp"

#include "gl\glew.h"
#include "log\service_logger.hpp"

namespace ece
{
	GLEW::GLEW(): initialized(false) {}

	void GLEW::init()
	{
		// Required to use VAO & VBO & ShaderProgram.
		glewExperimental = GL_TRUE;

		GLint GlewInitResult = glewInit();
		if (GLEW_OK != GlewInitResult)
		{
			ServiceLoggerLocator::getService().logInfo("Glew has encoutered a problem and couldn't be initialized: " + std::string(reinterpret_cast<const char *>(glewGetErrorString(GlewInitResult))));
			this->initialized = false;
		}
		else {
			ServiceLoggerLocator::getService().logInfo("Glew has been initialized.");
			ServiceLoggerLocator::getService().logInfo("Renderer used: " + std::string(reinterpret_cast<const char *>(glGetString(GL_RENDERER))));
			ServiceLoggerLocator::getService().logInfo(std::string(reinterpret_cast<const char *>(glGetString(GL_VERSION))) + " used in an GLFW context.");

			glEnable(GL_DEPTH_TEST);
			glDepthFunc(GL_LESS);
			this->initialized = true;
		}
	}

	bool GLEW::isInit() const
	{
		return this->initialized;
	}
}