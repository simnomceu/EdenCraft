#ifndef WINDOWSETTING_HPP
#define WINDOWSETTING_HPP

#include <string>

#include "Geom\Rectangle.hpp"
#include "Core\Window.inl"

namespace Utils
{
	class WindowSetting
	{
	public:
		WindowSetting();
		WindowSetting(const WindowSetting & copy) = default;
		WindowSetting(WindowSetting && copy) = default;

		~WindowSetting();

		WindowSetting & operator=(const WindowSetting & copy) = default;
		WindowSetting & operator=(WindowSetting && copy) = default;

		void setTitle(const std::string & title);
		void attachMonitor(const MonitorID & monitorId);
		void setTagOptions(const WindowTag & tagOptions);
		void setBounds(const Geom::Rectangle<unsigned int> & bounds);

		std::string & getTitle();
		MonitorID & getMonitorAttached();
		WindowTag getTagOptions() const;
		Geom::Rectangle<unsigned int> & getBounds();

	private:
		std::string titleWindow;

		MonitorID monitorId;

		WindowTag tagOptions;

		Geom::Rectangle<unsigned int> bounds;
	};
}

#endif // WINDOWSETTING_HPP
