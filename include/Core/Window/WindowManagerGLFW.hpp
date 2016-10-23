#pragma once

#include "Core\Window\WindowManager.hpp"

#include <memory>
#include <map>
#include <stack>

#pragma warning(push)
#pragma warning(disable : 4505)
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

		short int openWindow();
		void closeWindow(const short int windowId);

		void provideSettings(const ece::WindowID & windowId, const ece::WindowSetting & settings);

		void provideVideoMode(const ece::WindowID & windowId, const ece::VideoMode & settings);

		void attachToMonitor(const ece::WindowID & windowId, const short int monitorId);

		std::vector<ece::MonitorID> & getMonitors();

	protected:
		void initGLFW();
		void parametrizeContextGL();
		void initGLEW();
		void terminateGLFW();

		GLFWwindow * getWindow(const short int windowId);

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