#pragma once

#include "WindowManager.hpp"

#include <memory>
#include <map>
#include <stack>

#pragma warning(push)
#pragma warning(disable : 4505)
#include "GL\glew.h"
#include "GL\freeglut.h"
#include "GLFW\glfw3.h"
#pragma warning(pop)

namespace Utils
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

		void provideSettings(const Utils::WindowID & windowId, const Utils::WindowSetting & settings);

		void provideVideoMode(const Utils::WindowID & windowId, const Utils::VideoMode & settings);

		void attachToMonitor(const Utils::WindowID & windowId, const short int monitorId);

		std::vector<Utils::MonitorID> & getMonitors();

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