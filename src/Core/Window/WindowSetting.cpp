#include "Core\Window\WindowSetting.hpp"

#include "Core\Window\Window.inl"

namespace Utils
{
	WindowSetting::WindowSetting(): titleWindow(""), tagOptions(Utils::NO_OPTIONS), bounds()
	{
	}

	WindowSetting::~WindowSetting()
	{
	}

	void WindowSetting::setTitle(const std::string & title)
	{
		this->titleWindow = title;
	}

	void WindowSetting::setBounds(const Geom::Rectangle<unsigned int>& bounds)
	{
		this->bounds = bounds;
	}

	std::string & WindowSetting::getTitle()
	{
		return this->titleWindow;
	}

	Geom::Rectangle<unsigned int>& WindowSetting::getBounds()
	{
		return this->bounds;
	}

	void WindowSetting::setTagOptions(const WindowTag & tagOptions)
	{
		this->tagOptions = tagOptions;
	}
	bool WindowSetting::isInFullscreen() const
	{
		return (this->tagOptions & Utils::FULLSCREEN) == Utils::FULLSCREEN;
	}
	bool WindowSetting::isUsingToolbar() const
	{
		return (this->tagOptions & Utils::TOOLBAR) == Utils::TOOLBAR;
	}
	bool WindowSetting::isResizable() const
	{
		return (this->tagOptions & Utils::RESIZABLE) == Utils::RESIZABLE;
	}
	bool WindowSetting::isInitiallyVisible() const
	{
		return (this->tagOptions & Utils::VISIBLE) == Utils::VISIBLE;
	}
	bool WindowSetting::isInitiallyFocused() const
	{
		return (this->tagOptions & Utils::FOCUSED) == Utils::FOCUSED;
	}
	bool WindowSetting::isAutoIconifying() const
	{
		return (this->tagOptions & Utils::AUTO_ICONIFY) == Utils::AUTO_ICONIFY;
	}
	bool WindowSetting::isFloating() const
	{
		return (this->tagOptions & Utils::FLOATING) == Utils::FLOATING;
	}
	bool WindowSetting::isInitiallyMaximized() const
	{
		return (this->tagOptions & Utils::MAXIMIZED) == Utils::MAXIMIZED;
	}
}
