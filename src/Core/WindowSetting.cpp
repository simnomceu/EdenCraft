#include "Core/WindowSetting.hpp"

#include "Core\Window.inl"

namespace Utils
{
	WindowSetting::WindowSetting(): titleWindow(""), monitorId(-1), tagOptions(Utils::NO_OPTIONS), bounds()
	{
	}

	WindowSetting::~WindowSetting()
	{
	}

	void WindowSetting::setTitle(const std::string & title)
	{
		this->titleWindow = title;
	}

	void WindowSetting::attachMonitor(const MonitorID & monitorId)
	{
		this->monitorId = monitorId;
	}

	void WindowSetting::setTagOptions(const WindowTag & tagOptions)
	{
		this->tagOptions = tagOptions;
	}

	void WindowSetting::setBounds(const Geom::Rectangle<unsigned int>& bounds)
	{
		this->bounds = bounds;
	}

	std::string & WindowSetting::getTitle()
	{
		return this->titleWindow;
	}

	MonitorID & WindowSetting::getMonitorAttached()
	{
		return this->monitorId;
	}
	WindowTag WindowSetting::getTagOptions() const
	{
		return this->tagOptions;
	}
	Geom::Rectangle<unsigned int>& WindowSetting::getBounds()
	{
		return this->bounds;
	}
}
