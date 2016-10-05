#pragma once

#include "WindowManager.hpp"
namespace Utils
{
	class WindowManagerNone : public WindowManager
	{
	public:
		WindowManagerNone();
		~WindowManagerNone();

		short int openWindow();
		void closeWindow(const short int windowId);

		void setTitle(const short int windowId, const std::string & title);

		void setBounds(const short int windowId, const Utils::Rectangle<unsigned int> & bounds);
		void setPosition(const short int windowId, const Utils::Vector2ui & position);
		void setSize(const short int windowId, const Utils::Vector2ui & size);
		Rectangle<unsigned int> getBounds(const short int windowId);
		Vector2ui getPosition(const short int windowId);
		Vector2ui getSize(const short int windowId);
	};
}