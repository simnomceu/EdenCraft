#ifndef WINDOWMANAGERGLFW_HPP
#define WINDOWMANAGERGLFW_HPP

#include "Core\Window\Window\WindowManager.hpp"

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
	class WindowManagerGLFW : public WindowManager
	{
	public:

		WindowManagerGLFW();
		~WindowManagerGLFW();

		virtual ece::WindowID openWindow(const ece::WindowTag & tag = ece::NO_OPTIONS_BIS);
		virtual void closeWindow(const ece::WindowID &  windowId);

		virtual bool windowShouldClose(const ece::WindowID & windowId);

		virtual void setTitle(const ece::WindowID & windowId, const std::string & title);
		virtual void setBounds(const ece::WindowID & windowId, const ece::Rectangle<unsigned int> & bounds);
		virtual void setState(const ece::WindowID & windowId, const ece::WindowState & state);
		virtual void provideSettings(const ece::WindowID & windowId, ece::WindowSetting & settings);

		virtual void provideVideoMode(const ece::VideoMode & videoMode);

		virtual void attachToMonitor(const ece::WindowID & windowId, const short int monitorId, const ece::WindowSetting & settings);

		virtual unsigned short int getNumberOfMonitors();

		virtual void pollEvents(const ece::WindowID & windowId, Event & event);
		virtual void waitEvents(const ece::WindowID & windowId, Event & event);

		virtual void registerEventHandler(const ece::WindowID & windowId);

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

		std::map<unsigned short int, GLFWwindow*> windows;
	};
}

#endif // WINDOWMANAGERGLFW_HPP