namespace ece
{
//	inline BaseWindow::BaseWindow(const ece::WindowSetting & settings, const ece::VideoMode & videoMode) : Emitter(), windowId(-1), settings(), videoMode() {}

//	inline BaseWindow::BaseWindow(BaseWindow && copy) : Emitter(), windowId(-1), settings(), videoMode() {}

//	inline BaseWindow::~BaseWindow() { this->close(); }

	inline void BaseWindow::onRefresh() {}

	inline const ece::WindowSetting & BaseWindow::getSettings() { return this->settings; }
}