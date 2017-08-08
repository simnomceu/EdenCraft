#include "window\window_manager_glfw.hpp"

#include "log\service_logger.hpp"

#include "graphic_library\service_gl.hpp"
#include "event\event_handler.hpp"
#include "debug\exception.hpp"


#include <utility> // std::pair
#include <functional>

namespace ece
{
	WindowManagerGLFW::WindowManagerGLFW() : WindowManager(), isWindowOpen(false), 
											isContextDefined(-1), idsAvailable(), windows()
	{
		this->idsAvailable.push(0);
	}

	WindowManagerGLFW::~WindowManagerGLFW()
	{
		for (auto it = this->windows.begin(); it != this->windows.end(); ++it) {
			this->closeWindow(it->first);
		}
	}



	ece::WindowID WindowManagerGLFW::openWindow(const ece::WindowTag & tag)
	{
		if (!ServiceGLLocator::getService().isPreInitialized()) {
			ServiceGLLocator::getService().preInit();
		}

		if (tag != ece::NO_OPTIONS_BIS) {
			this->setWindowHint(tag);
		}

		if ((tag & ece::FULLSCREEN) == ece::FULLSCREEN) {
			this->windows[this->idsAvailable.top()] = glfwCreateWindow(640, 480, "My Title", glfwGetPrimaryMonitor(), NULL);
		}
		else {
			this->windows[this->idsAvailable.top()] = glfwCreateWindow(640, 480, "My Title", NULL, NULL);
		}
		ece::WindowID windowId = -1;

		if (this->windows[this->idsAvailable.top()] != nullptr) {
			this->isWindowOpen = true;
			windowId = this->idsAvailable.top();
			this->idsAvailable.pop();
			this->idsAvailable.push(windowId + 1);
			
			// TODO: define the right current context
			//if (this->isContextDefined == -1) {
				glfwMakeContextCurrent(this->getWindow(windowId));
			//}

			if (!ServiceGLLocator::getService().isPostInitialized()) {
				ServiceGLLocator::getService().postInit();
			}
		}
		else {
			this->windows.erase(this->idsAvailable.top());
			ServiceLoggerLocator::getService().logError("Invalid context used to open a window.");
		}
		return windowId;
	}

	void WindowManagerGLFW::closeWindow(const ece::WindowID & windowId)
	{
		try {
			glfwDestroyWindow(this->getWindow(windowId));
			if (this->isContextDefined == windowId) {
				if (this->windows.size() == 0) {
					this->isContextDefined = -1;// GL::NULL_ID;
				}
				else {
					this->isContextDefined = this->windows.end()->first;
					glfwMakeContextCurrent(this->getWindow(windowId));
					// TODO : re-init GLEW ?
				}
			}

			this->windows.erase(windowId);
			this->idsAvailable.push(windowId);
		}
		catch (OutOfRangeException & e) {
			// TODO: what to do here ? Is there a right place to catch this exception ? 
		}
	}

	bool WindowManagerGLFW::windowShouldClose(const ece::WindowID & windowId)
	{
		if (windowId > -1 && this->getWindow(windowId) != nullptr) {
			try {
				return glfwWindowShouldClose(this->getWindow(windowId)) == GLFW_TRUE;
			}
			catch (OutOfRangeException & e) {
				ServiceLoggerLocator::getService().logWarning(e.what());
				return true;
			}
		}
		else {
			return false;
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
		if (windowId != -1) {
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

	void WindowManagerGLFW::pollEvents(const ece::WindowID & windowId, InputEvent & event)
	{
		glfwPollEvents();
		try {
			GLFWwindow * window = this->getWindow(windowId);
			int focused = glfwGetWindowAttrib(window, GLFW_FOCUSED);
			double xpos = 0, ypos = 0;
			if (focused) {
				glfwGetCursorPos(window, &xpos, &ypos);
			}
		}
		catch (OutOfRangeException & e) {
			ServiceLoggerLocator::getService().logWarning(e.what());
		}
	}

	void WindowManagerGLFW::waitEvents(const ece::WindowID & windowId, InputEvent & event)
	{
		glfwWaitEvents();
		try {
			int focused = glfwGetWindowAttrib(this->getWindow(windowId), GLFW_FOCUSED);
			double xpos = 0, ypos = 0;
			if (focused) {
				glfwGetCursorPos(this->getWindow(windowId), &xpos, &ypos);
			}
		}
		catch (OutOfRangeException & e) {
			ServiceLoggerLocator::getService().logWarning(e.what());
		}
	}

	void WindowManagerGLFW::registerEventHandler(const ece::WindowID & windowId)
	{
		GLFWwindow * window = this->getWindow(windowId);

		glfwSetKeyCallback(window, 
							[](GLFWwindow* window, int key, int scancode, int action, int mods) {
								EventHandler::getInstance().produceKeyEvent(key, scancode, action, mods);
							}
		);
		glfwSetMouseButtonCallback(window,
			[](GLFWwindow* window, int button, int action, int mods) {
			EventHandler::getInstance().produceMouseButtonEvent(button, action, mods);
		}
		);
	}

	void WindowManagerGLFW::displayOnWindow(const ece::WindowID & windowId)
	{
		glfwSwapBuffers(this->getWindow(windowId));
	}

	GLFWwindow * WindowManagerGLFW::getWindow(const ece::WindowID & windowId)
	{
		if (windowId == -1/*GL::NULL_ID*/ || windowId > (int)this->windows.size() || this->windows[windowId] == nullptr) {
			throw OutOfRangeException::makeException("GLFWwindow", windowId);
			// TODO exception non attrapée quand fenêtre fermée
		}
		return this->windows[windowId];
	}

	GLFWmonitor * WindowManagerGLFW::getMonitor(const ece::MonitorID & monitorId)
	{
		int nbMonitors = 0;
		auto monitors = glfwGetMonitors(&nbMonitors);

		if (monitorId < 0 || monitorId > nbMonitors) {
			throw OutOfRangeException::makeException("GLFWmonitor", monitorId);
		}

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