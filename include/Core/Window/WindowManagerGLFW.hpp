#ifndef WINDOWMANAGERGLFW_HPP
#define WINDOWMANAGERGLFW_HPP

#include "Core\Window\WindowManager.hpp"

#include <memory>
#include <map>
#include <stack>

#pragma warning(push)
#pragma warning(disable : 4505)
#define GLEW_STATIC
#include "GL\glew.h"
#include "GL\freeglut.h"
#include "GLFW\glfw3.h"
#pragma warning(pop)

namespace ece
{
	struct WindowDeleter {
		void operator()(GLFWwindow * ptr) {
			glfwDestroyWindow(ptr);
		}
	};

	class WindowManagerGLFW : public WindowManager
	{
	public:
		static void DestroyGLFWwindow(GLFWwindow* ptr) {
				glfwDestroyWindow(ptr);
			}

		WindowManagerGLFW();
		~WindowManagerGLFW();

		ece::WindowID openWindow(const ece::WindowTag & tag = ece::NO_OPTIONS_BIS);
		void closeWindow(const ece::WindowID &  windowId);

		void setTitle(const ece::WindowID & windowId, const std::string & title);
		void setBounds(const ece::WindowID & windowId, const ece::Rectangle<unsigned int> & bounds);
		void setState(const ece::WindowID & windowId, const ece::WindowState & state);
		void provideSettings(const ece::WindowID & windowId, ece::WindowSetting & settings);

		void provideVideoMode(const ece::VideoMode & videoMode);

		void attachToMonitor(const ece::WindowID & windowId, const short int monitorId, const ece::WindowSetting & settings);

		unsigned short int getNumberOfMonitors();

	protected:
		void initGLFW();
		void parametrizeContextGL();
		void initGLEW();
		void terminateGLFW();

		GLFWwindow * getWindow(const ece::WindowID & windowId);
		GLFWmonitor * getMonitor(const ece::MonitorID & monitorId);

		void setWindowHint(const ece::WindowTag & tag);

	private:
		bool isGLFWInitialized;
		bool isContextParametrized;
		bool isWindowOpen;
		short isContextDefined;
		bool isGLEWInit;

		std::stack<unsigned short int> idsAvailable;

		std::map<unsigned short int, std::unique_ptr<GLFWwindow, WindowDeleter>> windows;
	};
}

#endif // WINDOWMANAGERGLFW_HPP