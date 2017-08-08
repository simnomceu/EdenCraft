#include "graphic_library\glfw.hpp"

#include "log\service_logger.hpp"

namespace ece
{
	GLFW::GLFW(): initialized(false) {}

	GLFW::~GLFW()
	{
		if (this->initialized) {
			glfwTerminate();
		}
	}

	void GLFW::init()
	{
		if (!glfwInit()) {
			ServiceLoggerLocator::getService().logError("GLFW has encoutered a problem and couldn't be initialized.");
			this->initialized = false;
		}
		else {
			int major, minor, rev;
			glfwGetVersion(&major, &minor, &rev);
			ServiceLoggerLocator::getService().logInfo("GLFW initialized in version " + std::to_string(major) + "." + std::to_string(minor)
				+ "." + std::to_string(rev));
			this->initialized = true;
		}
	}

	bool GLFW::isInit()
	{
		return this->initialized;
	}

	void GLFW::parametrizeContext()
	{
		glfwWindowHint(GLFW_CLIENT_API, GL_CLIENT_API_ECE);
		glfwWindowHint(GLFW_CONTEXT_CREATION_API, GL_CONTEXT_CREATION_API_ECE);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, GL_MAJOR_VERSION_ECE);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, GL_MINOR_VERSION_ECE);
		glfwWindowHint(GLFW_CONTEXT_ROBUSTNESS, GL_CONTEXT_ROBUSTNESS_ECE);
		glfwWindowHint(GLFW_CONTEXT_RELEASE_BEHAVIOR, GL_CONTEXT_RELEASE_BEHAVIOR_ECE);
		glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_OPENGL_FORWARD_COMPAT_ECE);
		glfwWindowHint(GLFW_OPENGL_DEBUG_CONTEXT, GL_OPENGL_DEBUG_CONTEXT_ECE);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GL_OPENGL_PROFILE_ECE);
		glfwSwapInterval(DEFAULT_INTERVAL_SWAP_ECE);
	}
}