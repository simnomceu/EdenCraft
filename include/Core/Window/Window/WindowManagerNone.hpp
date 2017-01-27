#ifndef WINDOWMANAGERNONE_HPP
#define WINDOWMANAGERNONE_HPP

#include "Core\Window\Window\WindowManager.hpp"

namespace ece
{
	class WindowManagerNone : public WindowManager
	{
	public:
		WindowManagerNone();
		~WindowManagerNone();

		virtual ece::WindowID openWindow(const ece::WindowTag & tag = ece::NO_OPTIONS_BIS);
		virtual void closeWindow(const ece::WindowID & windowId);

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
	};
}

#endif // WINDOWMANAGERNONE_HPP