#include "Util\OpenGL\OpenGL.hpp"

#include "Util\Log\ServiceLogger.hpp"
#include "GLFW\glfw3.h"

namespace ece
{
	bool OpenGL::initGLFW()
	{
		if (!glfwInit()) {
			ServiceLoggerLocator::getService().logError("GLFW has encoutered a problem and couldn't be initialized.");
			return false;
		}
		else {
			int major, minor, rev;
			glfwGetVersion(&major, &minor, &rev);
			ServiceLoggerLocator::getService().logInfo("GLFW initialized in version " + std::to_string(major) + "." + std::to_string(minor)
				+ "." + std::to_string(rev));
			return true;
		}
	}

	bool OpenGL::initGlew()
	{
		// Required to use VAO & VBO & ShaderProgram.
		glewExperimental = GL_TRUE;

		GLint GlewInitResult = glewInit();
		if (GLEW_OK != GlewInitResult)
		{
			ServiceLoggerLocator::getService().logInfo("Glew has encoutered a problem and couldn't be initialized: " + std::string(reinterpret_cast< const char * >(glewGetErrorString(GlewInitResult))));
			return false;
		}
		else {
			ServiceLoggerLocator::getService().logInfo("Glew has been initialized.");
			ServiceLoggerLocator::getService().logInfo("Renderer used: " + std::string(reinterpret_cast< const char * >(glGetString(GL_RENDERER))));
			ServiceLoggerLocator::getService().logInfo(std::string(reinterpret_cast< const char * >(glGetString(GL_VERSION))) + " used in an GLFW context.");

			glEnable(GL_DEPTH_TEST);
			glDepthFunc(GL_LESS);
			return true;
		}
	}
}