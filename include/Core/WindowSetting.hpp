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
		void setBounds(const Geom::Rectangle<unsigned int> & bounds);

		std::string & getTitle();
		Geom::Rectangle<unsigned int> & getBounds();

		void setTagOptions(const WindowTag & tagOptions);
		bool isInFullscreen() const;
		bool isUsingToolbar() const;
		bool isResizable() const;
		bool isInitiallyVisible() const;
		bool isInitiallyFocused() const;
		bool isAutoIconifying() const;
		bool isFloating() const;
		bool isInitiallyMaximized() const;

	private:
		std::string titleWindow;

		WindowTag tagOptions;

		Geom::Rectangle<unsigned int> bounds;
	};
}

#endif // WINDOWSETTING_HPP
