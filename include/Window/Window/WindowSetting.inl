namespace ece
{
	inline WindowSetting::WindowSetting() : titleWindow(""), bounds(), state(ece::NO_OPTIONS) {}

	inline void WindowSetting::setTitle(const std::string & title) { this->titleWindow = title; }

	inline void WindowSetting::setBounds(const ece::Rectangle<unsigned int>& bounds) { this->bounds = bounds; }

	inline void WindowSetting::setState(const ece::WindowState & state) { this->state = state; }

	inline const std::string & WindowSetting::getTitle() const { return this->titleWindow; }

	inline const ece::Rectangle<unsigned int>& WindowSetting::getBounds() const { return this->bounds; }

	inline const ece::WindowState & WindowSetting::getState() const { return this->state; }
}