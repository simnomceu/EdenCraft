#ifndef WINDOWMANAGERGLFW_HPP
#define WINDOWMANAGERGLFW_HPP

#include "Window\WindowManager.hpp"

#include <memory>
#include <map>
#include <stack>

#include "Window\Constant.inl"

namespace ece
{
	class WindowManagerGLFW : public WindowManager
	{
	public:

		WindowManagerGLFW();
		~WindowManagerGLFW();

		virtual ece::WindowID openWindow(const ece::WindowTag & tag = ece::NO_OPTIONS_BIS) override;
		virtual void closeWindow(const ece::WindowID &  windowId) override;

		virtual bool windowShouldClose(const ece::WindowID & windowId) override;

		virtual void setTitle(const ece::WindowID & windowId, const std::string & title) override;
		virtual void setBounds(const ece::WindowID & windowId, const ece::Rectangle<unsigned int> & bounds) override;
		virtual void setState(const ece::WindowID & windowId, const ece::WindowState & state) override;
		virtual void provideSettings(const ece::WindowID & windowId, ece::WindowSetting & settings) override;

		virtual void provideVideoMode(const ece::VideoMode & videoMode) override;

		virtual void attachToMonitor(const ece::WindowID & windowId, const short int monitorId, const ece::WindowSetting & settings) override;

		virtual unsigned short int getNumberOfMonitors() override;

		virtual void pollEvents(const ece::WindowID & windowId, Event & event) override;
		virtual void waitEvents(const ece::WindowID & windowId, Event & event) override;

		virtual void registerEventHandler(const ece::WindowID & windowId) override;
		virtual void displayOnWindow(const ece::WindowID & windowId) override;

	protected:
		GLFWwindow * getWindow(const ece::WindowID & windowId);
		GLFWmonitor * getMonitor(const ece::MonitorID & monitorId);

		void setWindowHint(const ece::WindowTag & tag);

	private:
		bool isWindowOpen;
		short isContextDefined;

		std::stack<unsigned short int> idsAvailable;

		std::map<unsigned short int, GLFWwindow*> windows;
	};
}

#endif // WINDOWMANAGERGLFW_HPP