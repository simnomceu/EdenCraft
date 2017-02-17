#ifndef WINDOWSETTING_HPP
#define WINDOWSETTING_HPP

#include <string>

#include "Core\Geom\Rectangle.hpp"
#include "Core\Window\Window\Window.inl"

namespace ece
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
		void setBounds(const ece::Rectangle<unsigned int> & bounds);
		void setState(const ece::WindowState & state);

		const std::string & getTitle() const;
		const ece::Rectangle<unsigned int> & getBounds() const;
		const ece::WindowState & getState() const;

	private:
		std::string titleWindow;

		ece::Rectangle<unsigned int> bounds;

		ece::WindowState state;
	};
}

#endif // WINDOWSETTING_HPP
