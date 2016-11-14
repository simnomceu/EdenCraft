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

		ece::WindowID openWindow(const ece::WindowTag & tag = ece::NO_OPTIONS_BIS);
		void closeWindow(const ece::WindowID & windowId);

		bool windowShouldClose(const ece::WindowID & windowId);

		void setTitle(const ece::WindowID & windowId, const std::string & title);
		void setBounds(const ece::WindowID & windowId, const ece::Rectangle<unsigned int> & bounds);
		void setState(const ece::WindowID & windowId, const ece::WindowState & state);
		void provideSettings(const ece::WindowID & windowId, ece::WindowSetting & settings);

		void provideVideoMode(const ece::VideoMode & videoMode);

		void attachToMonitor(const ece::WindowID & windowId, const short int monitorId, const ece::WindowSetting & settings);

		unsigned short int getNumberOfMonitors();
		
		void registerEventHandler(EventHandler * handler);
	};
}

#endif // WINDOWMANAGERNONE_HPP