#ifndef WINDOWSETTING_HPP
#define WINDOWSETTING_HPP

#include <string>

#include "Geom\Rectangle.hpp"
#include "Window\Window.inl"

namespace ece
{
	class WindowSetting
	{
	public:
		inline WindowSetting();
		WindowSetting(const WindowSetting & copy) = default;
		WindowSetting(WindowSetting && copy) = default;

		~WindowSetting() = default;

		WindowSetting & operator=(const WindowSetting & copy) = default;
		WindowSetting & operator=(WindowSetting && copy) = default;

		inline void setTitle(const std::string & title);
		inline void setBounds(const ece::Rectangle<unsigned int> & bounds);
		inline void setState(const ece::WindowState & state);

		inline const std::string & getTitle() const;
		inline const ece::Rectangle<unsigned int> & getBounds() const;
		inline const ece::WindowState & getState() const;

	private:
		std::string titleWindow;

		ece::Rectangle<unsigned int> bounds;

		ece::WindowState state;
	};
}

#include "Window\WindowSetting.inl"

#endif // WINDOWSETTING_HPP
