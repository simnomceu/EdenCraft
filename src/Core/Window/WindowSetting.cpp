#include "Core\Window\WindowSetting.hpp"

#include "Core\Window\Window.inl"

namespace ece
{
	WindowSetting::WindowSetting(): titleWindow(""), tagOptions(ece::NO_OPTIONS), bounds()
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

	std::string & WindowSetting::getTitle()
	{
		return this->titleWindow;
	}

	ece::Rectangle<unsigned int>& WindowSetting::getBounds()
	{
		return this->bounds;
	}

	void WindowSetting::setTagOptions(const WindowTag & tagOptions)
	{
		this->tagOptions = tagOptions;
	}
	bool WindowSetting::isInFullscreen() const
	{
		return (this->tagOptions & ece::FULLSCREEN) == ece::FULLSCREEN;
	}
	bool WindowSetting::isUsingToolbar() const
	{
		return (this->tagOptions & ece::TOOLBAR) == ece::TOOLBAR;
	}
	bool WindowSetting::isResizable() const
	{
		return (this->tagOptions & ece::RESIZABLE) == ece::RESIZABLE;
	}
	bool WindowSetting::isInitiallyVisible() const
	{
		return (this->tagOptions & ece::VISIBLE) == ece::VISIBLE;
	}
	bool WindowSetting::isInitiallyFocused() const
	{
		return (this->tagOptions & ece::FOCUSED) == ece::FOCUSED;
	}
	bool WindowSetting::isAutoIconifying() const
	{
		return (this->tagOptions & ece::AUTO_ICONIFY) == ece::AUTO_ICONIFY;
	}
	bool WindowSetting::isFloating() const
	{
		return (this->tagOptions & ece::FLOATING) == ece::FLOATING;
	}
	bool WindowSetting::isInitiallyMaximized() const
	{
		return (this->tagOptions & ece::MAXIMIZED) == ece::MAXIMIZED;
	}
}
