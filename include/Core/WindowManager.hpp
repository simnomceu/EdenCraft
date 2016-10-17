#pragma once

#include <string>

#include "Core/Geom/Rectangle.hpp"
#include "Core\Geom\Vector.hpp"

namespace Utils
{
	class WindowManager
	{
	public:
		virtual ~WindowManager() {}

		virtual short int openWindow() = 0;
		virtual void closeWindow(const short int windowId) = 0;

		virtual void attachToMonitor(const short int windowId, const short int monitorId) = 0;

		virtual void setTitle(const short int windowId, const std::string & title) = 0;

		virtual void setBounds(const short int windowId, const Geom::Rectangle<unsigned int> & bounds) = 0;
		virtual void setPosition(const short int windowId, const Geom::Vector2ui & position) = 0;
		virtual void setSize(const short int windowId, const Geom::Vector2ui & size) = 0;
		virtual Geom::Rectangle<unsigned int> getBounds(const short int windowId) = 0;
		virtual Geom::Vector2ui getPosition(const short int windowId) = 0;
		virtual Geom::Vector2ui getSize(const short int windowId) = 0;
	};
}