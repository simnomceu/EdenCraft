#include "DriverGL.hpp"
#include "Constants.inl"

#include <iostream>

namespace Utils
{
	std::shared_ptr<DriverGL> DriverGL::getInstance()
	{
		static std::shared_ptr<DriverGL> instance(new DriverGL());

		return instance;
	}

	DriverGL::~DriverGL()
	{
	}

	void DriverGL::initGLFW()
	{
		int initialized = glfwInit();
		this->glfwInitialized = (initialized == GL_TRUE);

		if (!this->glfwInitialized) {
			std::cerr << "GLFW has encoutered a problem and couldn't be initialized." << std::endl;
		}
		else {
			std::cerr << "GLFW has been initialized." << std::endl;
		}
	}

	void DriverGL::initGlew()
	{
		// Required to use VAO & VBO.
		glewExperimental = GL_TRUE;

		GLint GlewInitResult = glewInit();
		this->glewInitialized = (GLEW_OK != GlewInitResult);
		if (this->glewInitialized)
		{
			std::cerr << "Glew has encoutered a problem and couldn't be initialized: " << glewGetErrorString(GlewInitResult) << std::endl;
		}
		else {
			std::cerr << "Glew has been initialized." << std::endl;
		}
	}

	void DriverGL::parametrizeContextGL()
	{
		/*
		GLFW_RESIZABLE	GLFW_TRUE	GLFW_TRUE or GLFW_FALSE
			GLFW_VISIBLE	GLFW_TRUE	GLFW_TRUE or GLFW_FALSE
			GLFW_DECORATED	GLFW_TRUE	GLFW_TRUE or GLFW_FALSE
			GLFW_FOCUSED	GLFW_TRUE	GLFW_TRUE or GLFW_FALSE
			GLFW_AUTO_ICONIFY	GLFW_TRUE	GLFW_TRUE or GLFW_FALSE
			GLFW_FLOATING	GLFW_FALSE	GLFW_TRUE or GLFW_FALSE
			GLFW_MAXIMIZED	GLFW_FALSE	GLFW_TRUE or GLFW_FALSE
			GLFW_RED_BITS	8	0 to INT_MAX or GLFW_DONT_CARE
			GLFW_GREEN_BITS	8	0 to INT_MAX or GLFW_DONT_CARE
			GLFW_BLUE_BITS	8	0 to INT_MAX or GLFW_DONT_CARE
			GLFW_ALPHA_BITS	8	0 to INT_MAX or GLFW_DONT_CARE
			GLFW_DEPTH_BITS	24	0 to INT_MAX or GLFW_DONT_CARE
			GLFW_STENCIL_BITS	8	0 to INT_MAX or GLFW_DONT_CARE
			GLFW_ACCUM_RED_BITS	0	0 to INT_MAX or GLFW_DONT_CARE
			GLFW_ACCUM_GREEN_BITS	0	0 to INT_MAX or GLFW_DONT_CARE
			GLFW_ACCUM_BLUE_BITS	0	0 to INT_MAX or GLFW_DONT_CARE
			GLFW_ACCUM_ALPHA_BITS	0	0 to INT_MAX or GLFW_DONT_CARE
			GLFW_AUX_BUFFERS	0	0 to INT_MAX or GLFW_DONT_CARE
			GLFW_SAMPLES	0	0 to INT_MAX or GLFW_DONT_CARE
			GLFW_REFRESH_RATE	GLFW_DONT_CARE	0 to INT_MAX or GLFW_DONT_CARE
			GLFW_STEREO	GLFW_FALSE	GLFW_TRUE or GLFW_FALSE
			GLFW_SRGB_CAPABLE	GLFW_FALSE	GLFW_TRUE or GLFW_FALSE
			GLFW_DOUBLEBUFFER	GLFW_TRUE	GLFW_TRUE or GLFW_FALSE
			GLFW_CLIENT_API	GLFW_OPENGL_API	GLFW_OPENGL_API, GLFW_OPENGL_ES_API or GLFW_NO_API
			GLFW_CONTEXT_CREATION_API	GLFW_NATIVE_CONTEXT_API	GLFW_NATIVE_CONTEXT_API or GLFW_EGL_CONTEXT_API
			GLFW_CONTEXT_VERSION_MAJOR	1	Any valid major version number of the chosen client API
			GLFW_CONTEXT_VERSION_MINOR	0	Any valid minor version number of the chosen client API
			GLFW_CONTEXT_ROBUSTNESS	GLFW_NO_ROBUSTNESS	GLFW_NO_ROBUSTNESS, GLFW_NO_RESET_NOTIFICATION or GLFW_LOSE_CONTEXT_ON_RESET
			GLFW_CONTEXT_RELEASE_BEHAVIOR	GLFW_ANY_RELEASE_BEHAVIOR	GLFW_ANY_RELEASE_BEHAVIOR, GLFW_RELEASE_BEHAVIOR_FLUSH or GLFW_RELEASE_BEHAVIOR_NONE
			GLFW_OPENGL_FORWARD_COMPAT	GLFW_FALSE	GLFW_TRUE or GLFW_FALSE
			GLFW_OPENGL_DEBUG_CONTEXT	GLFW_FALSE	GLFW_TRUE or GLFW_FALSE
			GLFW_OPENGL_PROFILE	GLFW_OPENGL_ANY_PROFILE	GLFW_OPENGL_ANY_PROFILE, GLFW_OPENGL_COMPAT_PROFILE or GLFW_OPENGL_CORE_PROFILE
			*/
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, Constants::GL_MAJOR_VERSION_EC);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, Constants::GL_MINOR_VERSION_EC);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_ANY_PROFILE);

		this->glParametrized = true;
	}

	void DriverGL::terminateGLFW()
	{
		if (this->glfwInitialized) {
			glfwTerminate();
			this->glfwInitialized = false;
		}
	}

	DriverGL::DriverGL() : glfwInitialized(false), glewInitialized(false), glParametrized(false)
	{

	}
}