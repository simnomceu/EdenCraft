#include "WindowManagerGLFW.hpp"
#include "Constants.inl"

#include <iostream>
#include <utility> // std::pair
#include <functional>

namespace Utils
{
	WindowManagerGLFW::WindowManagerGLFW() : WindowManager(), isGLFWInitialized(false), isContextParametrized(false), isWindowOpen(false), 
											isContextDefined(-1), isGLEWInit(false), idsAvailable(), windows()
	{
		this->idsAvailable.push(0);
		this->windows.insert(std::make_pair(-1, nullptr));
	}
	WindowManagerGLFW::~WindowManagerGLFW()
	{
		for (auto it = this->windows.begin(); it != this->windows.end(); ++it) {
			this->closeWindow(it->first);
		}
	}
	void WindowManagerGLFW::initGLFW()
	{
		if (!glfwInit()) {
			std::cerr << "GLFW has encoutered a problem and couldn't be initialized." << std::endl;
		}
		else {
			int major, minor, rev;
			glfwGetVersion(&major, &minor, &rev);
			std::cerr << "GLFW initialized in version " << major << "." << minor << "." << rev << std::endl;
			this->isGLFWInitialized = true;
		}
	}

	short int WindowManagerGLFW::openWindow()
	{
		if (!this->isGLFWInitialized) {
			this->initGLFW();
		}
		if (!this->isContextParametrized) {
			this->parametrizeContextGL();
		}

		this->windows.insert(std::make_pair(this->idsAvailable.top(), 
										glfwCreateWindow(640, 480, "My Title", NULL, NULL)));
		unsigned short int windowId = -1;

		if (this->windows[this->idsAvailable.top()] != nullptr) {
			this->isWindowOpen = true;
			windowId = this->idsAvailable.top();
			this->idsAvailable.pop();
			this->idsAvailable.push(windowId + 1);

			if (this->isContextDefined == -1) {
				glfwMakeContextCurrent(this->getWindow(windowId));
			}

			if (!this->isGLEWInit) {
				this->initGLEW();
			}
		}
		else {
			this->windows.erase(this->idsAvailable.top());
		}
		return windowId;
	}

	void WindowManagerGLFW::closeWindow(const short int windowId)
	{
		glfwDestroyWindow(this->getWindow(windowId));
		if (this->isContextDefined == windowId) {
			if (this->windows.size() == 0) {
				this->isContextDefined = -1;
			}
			else {
				this->isContextDefined = this->windows.end()->first;
				glfwMakeContextCurrent(this->getWindow(windowId));
				// TODO : re-init GLEW ?
			}
		}

		this->windows.erase(windowId);
		this->idsAvailable.push(windowId);
		if (this->windows.size() == 0) {
			this->terminateGLFW();
		}
		std::cout << "Window with id " << windowId << " has been closed without encoutering errors ..." << std::endl;
	}

	void WindowManagerGLFW::setTitle(const short int windowId, const std::string & title)
	{
		glfwSetWindowTitle(this->getWindow(windowId), title.c_str());
	}

	void WindowManagerGLFW::setBounds(const short int windowId, const Utils::Rectangle<unsigned int>& bounds)
	{
		this->setPosition(windowId, Utils::Vector2ui({ bounds.getX(), bounds.getY() }));
		this->setSize(windowId, Utils::Vector2ui({ bounds.getWidth(), bounds.getHeight() }));
	}

	void WindowManagerGLFW::setPosition(const short int windowId, const Utils::Vector2ui & position)
	{
		glfwSetWindowPos(this->getWindow(windowId), position[0], position[1]);
	}

	void WindowManagerGLFW::setSize(const short int windowId, const Utils::Vector2ui & size)
	{
		glfwSetWindowSize(this->getWindow(windowId), size[0], size[1]);
	}

	Rectangle<unsigned int> WindowManagerGLFW::getBounds(const short int windowId)
	{
		auto position = this->getPosition(windowId);
		auto size = this->getSize(windowId);

		return Rectangle<unsigned int>(position[0], position[1], size[0], size[1]);
	}

	Vector2ui WindowManagerGLFW::getPosition(const short int windowId)
	{
		int x = 0, y = 0;
		glfwGetWindowPos(this->getWindow(windowId), &x, &y);
		unsigned int ux = 0, uy = 0;
		if (x >= 0) {
			x = ux;
		}
		if (y >= 0) {
			y = uy;
		}
		return Vector2ui({ ux, uy });
	}

	Vector2ui WindowManagerGLFW::getSize(const short int windowId)
	{
		int w = 0, h = 0;
		glfwGetWindowSize(this->getWindow(windowId), &w, &h);
		unsigned int uw = 0, uh = 0;
		if (w >= 0) {
			w = uw;
		}
		if (h >= 0) {
			h = uh;
		}
		return Vector2ui({ uw, uh });
	}

	void WindowManagerGLFW::parametrizeContextGL()
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
		glfwSwapInterval(0);
	}

	void WindowManagerGLFW::initGLEW()
	{
		if (this->isWindowOpen) {
			// Required to use VAO & VBO.
			glewExperimental = GL_TRUE;

			GLint GlewInitResult = glewInit();
			if (GLEW_OK != GlewInitResult)
			{
				std::cerr << "Glew has encoutered a problem and couldn't be initialized: " << glewGetErrorString(GlewInitResult) << std::endl;
			}
			else {
				std::cerr << "Glew has been initialized." << std::endl;
				std::cerr << "Renderer used: " << glGetString(GL_RENDERER) << std::endl;
				std::cerr << glGetString(GL_VERSION) << " used in an GLFW context." << std::endl;
				this->isGLEWInit = true;
			}
		}
		else {
			std::cerr << "GLEW need a context to work correctly." << std::endl;
		}
	}

	void WindowManagerGLFW::terminateGLFW()
	{
		glfwTerminate();
		this->isGLFWInitialized = false;
	}

	GLFWwindow * WindowManagerGLFW::getWindow(const short int windowId)
	{
		return this->windows[windowId].get();
	}
}