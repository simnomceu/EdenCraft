#include "Core\Window\Window\WindowManagerGLFW.hpp"

#include "Core\Window\Constant.inl"
#include "Core\Util\LogService.hpp"

#include <iostream>
#include <utility> // std::pair
#include <functional>

namespace ece
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
			LogServiceLocator::getService().logError("GLFW has encoutered a problem and couldn't be initialized.");
		}
		else {
			int major, minor, rev;
			glfwGetVersion(&major, &minor, &rev);
			LogServiceLocator::getService().logInfo("GLFW initialized in version " + std::to_string(major) + "." + std::to_string(minor)
										+ "." + std::to_string(rev));
			this->isGLFWInitialized = true;
		}
	}

	ece::WindowID WindowManagerGLFW::openWindow(const ece::WindowTag & tag)
	{
		if (!this->isGLFWInitialized) {
			this->initGLFW();
		}
		if (!this->isContextParametrized) {
			this->parametrizeContextGL();
		}

		if (tag != ece::NO_OPTIONS_BIS) {
			this->setWindowHint(tag);
		}

		if ((tag & ece::FULLSCREEN) == ece::FULLSCREEN) {
			this->windows.insert(std::make_pair(this->idsAvailable.top(),
												glfwCreateWindow(640, 480, "My Title", glfwGetPrimaryMonitor(), NULL)));
		}
		else {

			this->windows.insert(std::make_pair(this->idsAvailable.top(),
												glfwCreateWindow(640, 480, "My Title", NULL, NULL)));
		}
		ece::WindowID windowId = -1;

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

	void WindowManagerGLFW::closeWindow(const ece::WindowID & windowId)
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
	}

	void WindowManagerGLFW::setTitle(const ece::WindowID & windowId, const std::string & title)
	{
		if (windowId != -1) {
			glfwSetWindowTitle(this->getWindow(windowId), title.c_str());
		}
	}

	void WindowManagerGLFW::setBounds(const ece::WindowID & windowId, const ece::Rectangle<unsigned int>& bounds)
	{
		if (windowId != -1) {
			auto window = this->getWindow(windowId);

			glfwSetWindowPos(window, bounds.getX(), bounds.getY());
			glfwSetWindowSize(window, bounds.getWidth(), bounds.getHeight());
		}
	}

	void WindowManagerGLFW::setState(const ece::WindowID & windowId, const ece::WindowState & state)
	{
		if (windowId != 1) {
			auto window = this->getWindow(windowId);

			if ((state & ece::VISIBLE) == ece::VISIBLE) {
				glfwShowWindow(window);
			}
			else {
				glfwHideWindow(window);
			}

			if ((state & ece::FOCUSED) == ece::FOCUSED) {
				glfwFocusWindow(window);
			}

			if ((state & ece::ICONIFIED) == ece::ICONIFIED) {
				glfwIconifyWindow(window);
			}
			else {
				glfwRestoreWindow(window);
			}

			if ((state & ece::MAXIMIZED) == ece::MAXIMIZED) {
				glfwMaximizeWindow(window);
			}
			else {
				glfwRestoreWindow(window);
			}
		}
	}

	void WindowManagerGLFW::provideSettings(const ece::WindowID & windowId, ece::WindowSetting & settings)
	{
		this->setTitle(windowId, settings.getTitle());
		this->setBounds(windowId, settings.getBounds());
		this->setState(windowId, settings.getState());
	}

	void WindowManagerGLFW::provideVideoMode(const ece::VideoMode & videoMode)
	{
		glfwWindowHint(GLFW_REFRESH_RATE, videoMode.getRefreshRate());
		glfwWindowHint(GLFW_RED_BITS, videoMode.getColorBits()[ece::RED_CHANNEL]);
		glfwWindowHint(GLFW_GREEN_BITS, videoMode.getColorBits()[ece::GREEN_CHANNEL]);
		glfwWindowHint(GLFW_BLUE_BITS, videoMode.getColorBits()[ece::BLUE_CHANNEL]);
		glfwWindowHint(GLFW_ALPHA_BITS, videoMode.getColorBits()[ece::ALPHA_CHANNEL]);
		glfwWindowHint(GLFW_DEPTH_BITS, videoMode.getDepthBits());
		glfwWindowHint(GLFW_STENCIL_BITS, videoMode.getStencilBits());
		glfwWindowHint(GLFW_SAMPLES, videoMode.getSamples());
		glfwWindowHint(GLFW_STEREO, videoMode.isStereoActivate());
		glfwWindowHint(GLFW_DOUBLEBUFFER, videoMode.isDoubleBufferingActivate());
		glfwWindowHint(GLFW_SRGB_CAPABLE, videoMode.isSrgbCapable());
	}

	void WindowManagerGLFW::attachToMonitor(const ece::WindowID & windowId, const short int monitorId, const ece::WindowSetting & settings)
	{
		if (monitorId != -1 && windowId != -1) {
			auto monitor = this->getMonitor(monitorId);
			auto window = this->getWindow(windowId);
			auto bounds = settings.getBounds();

			glfwSetWindowMonitor(window, monitor, bounds.getX(), bounds.getY(), bounds.getWidth(), bounds.getHeight(), 60);
		}
	}

	unsigned short int WindowManagerGLFW::getNumberOfMonitors()
	{
		std::vector<ece::MonitorID> monitors;

int nbMonitors = 0;
glfwGetMonitors(&nbMonitors);

return nbMonitors;
	}

	void WindowManagerGLFW::parametrizeContextGL()
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

	void WindowManagerGLFW::initGLEW()
	{
		if (this->isWindowOpen) {
			// Required to use VAO & VBO.
			glewExperimental = GL_TRUE;

			GLint GlewInitResult = glewInit();
			if (GLEW_OK != GlewInitResult)
			{
				LogServiceLocator::getService().logInfo("Glew has encoutered a problem and couldn't be initialized: " + std::string(reinterpret_cast< const char * >(glewGetErrorString(GlewInitResult))));
			}
			else {
				LogServiceLocator::getService().logInfo("Glew has been initialized.");
				LogServiceLocator::getService().logInfo("Renderer used: " + std::string(reinterpret_cast< const char * >(glGetString(GL_RENDERER))));
				LogServiceLocator::getService().logInfo(std::string(reinterpret_cast< const char * >(glGetString(GL_VERSION))) + " used in an GLFW context.");
				this->isGLEWInit = true;
			}
		}
		else {
			LogServiceLocator::getService().logError("GLEW need a context to work correctly.");
		}
	}

	void WindowManagerGLFW::terminateGLFW()
	{
		glfwTerminate();
		this->isGLFWInitialized = false;
	}

	GLFWwindow * WindowManagerGLFW::getWindow(const ece::WindowID & windowId)
	{
		// TODO add guard for the id (out of range)
		return this->windows[windowId].get();
	}

	GLFWmonitor * WindowManagerGLFW::getMonitor(const ece::MonitorID & monitorId)
	{
		// TODO add guard for the id and the number of monitors
		int nbMonitors = 0;
		auto monitors = glfwGetMonitors(&nbMonitors);

		return monitors[monitorId];
	}

	void WindowManagerGLFW::setWindowHint(const ece::WindowTag & tag)
	{
		if ((tag & ece::INIT_VISIBLE) == ece::INIT_VISIBLE) {
			glfwWindowHint(GLFW_VISIBLE, GLFW_TRUE);
		}
		else {

			glfwWindowHint(GLFW_VISIBLE, GLFW_FALSE);
		}

		if ((tag & ece::INIT_FOCUSED) == ece::INIT_FOCUSED) {
			glfwWindowHint(GLFW_FOCUSED, GLFW_TRUE);
		}
		else {
			glfwWindowHint(GLFW_FOCUSED, GLFW_FALSE);
		}

		if ((tag & ece::INIT_MAXIMIZED) == ece::INIT_MAXIMIZED) {
			glfwWindowHint(GLFW_MAXIMIZED, GLFW_TRUE);
		}
		else {
			glfwWindowHint(GLFW_MAXIMIZED, GLFW_FALSE);
		}
	}
}