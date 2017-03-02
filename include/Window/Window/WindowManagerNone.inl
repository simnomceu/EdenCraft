namespace ece
{
	inline ece::WindowID WindowManagerNone::openWindow(const ece::WindowTag & tag) { return -1; }

	inline void WindowManagerNone::closeWindow(const ece::WindowID & windowId) {}

	inline bool WindowManagerNone::windowShouldClose(const ece::WindowID & windowId) { return false; }

	inline void WindowManagerNone::setTitle(const ece::WindowID & windowId, const std::string & title) {}

	inline void WindowManagerNone::setBounds(const ece::WindowID & windowId, const ece::Rectangle<unsigned int>& bounds) {}

	inline void WindowManagerNone::setState(const ece::WindowID & windowId, const ece::WindowState & state) {}

	inline void WindowManagerNone::provideSettings(const ece::WindowID & windowId, ece::WindowSetting & settings) {}

	inline void WindowManagerNone::provideVideoMode(const ece::VideoMode & videoMode) {}

	inline void WindowManagerNone::attachToMonitor(const ece::WindowID & windowId, const short int monitorId, const ece::WindowSetting & settings) {}

	inline unsigned short int WindowManagerNone::getNumberOfMonitors() { return 0; }

	inline void WindowManagerNone::pollEvents(const ece::WindowID & windowId, Event & event) {}

	inline void WindowManagerNone::waitEvents(const ece::WindowID & windowId, Event & event) {}

	inline void WindowManagerNone::registerEventHandler(const ece::WindowID & windowId) {}

	inline void WindowManagerNone::displayOnWindow(const ece::WindowID & windowId) {}
}