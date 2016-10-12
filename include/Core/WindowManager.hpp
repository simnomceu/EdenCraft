#pragma once

#include <string>

#include "Rectangle.hpp"
#include "Vector.hpp"

namespace Utils
{
	class WindowManager
	{
	public:
		virtual ~WindowManager() {}

		virtual short int openWindow() = 0;
		virtual void closeWindow(const short int windowId) = 0;

		virtual void setTitle(const short int windowId, const std::string & title) = 0;

		virtual void setBounds(const short int windowId, const Utils::Rectangle<unsigned int> & bounds) = 0;
		virtual void setPosition(const short int windowId, const Utils::Vector2ui & position) = 0;
		virtual void setSize(const short int windowId, const Utils::Vector2ui & size) = 0;
		virtual Rectangle<unsigned int> getBounds(const short int windowId) = 0;
		virtual Vector2ui getPosition(const short int windowId) = 0;
		virtual Vector2ui getSize(const short int windowId) = 0;
	};
}