#include "Core\Window\WindowSetting.hpp"

#include "Core\Window\Window.inl"

namespace ece
{
	WindowSetting::WindowSetting(): titleWindow(""), bounds(), state(ece::NO_OPTIONS)
	{
	}

	WindowSetting::~WindowSetting()
	{
	}

	void WindowSetting::setTitle(const std::string & title)
	{
		this->titleWindow = title;
	}

	void WindowSetting::setBounds(const ece::Rectangle<unsigned int>& bounds)
	{
		this->bounds = bounds;
	}

	void WindowSetting::setState(const ece::WindowState & state)
	{
		this->state = state;
	}

	const std::string & WindowSetting::getTitle() const
	{
		return this->titleWindow;
	}

	const ece::Rectangle<unsigned int>& WindowSetting::getBounds() const
	{
		return this->bounds;
	}
	const ece::WindowState & WindowSetting::getState() const
	{
		return this->state;
	}
}
