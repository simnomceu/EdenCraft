#ifndef BASEWINDOW_HPP
#define BASEWINDOW_HPP

#include "Core\Geom\Rectangle.hpp"
#include "Core\Window\WindowSetting.hpp"
#include "Core\Window\VideoMode.hpp"
#include "Core\Window\Window.inl"

namespace Window
{
	class BaseWindow
	{
	public:
		BaseWindow(const ece::WindowSetting & settings);
		BaseWindow(const BaseWindow & copy);
		BaseWindow(BaseWindow && copy);	
		~BaseWindow();

		BaseWindow & operator=(const BaseWindow & rightOperand);
		BaseWindow & operator=(BaseWindow && rightOperand);

		void open();
		void close();

		void display();

		void applySettings(const ece::WindowSetting & settings);
		const ece::WindowSetting & getSettings();

		void setTitle(const std::string & title);
		void setBounds(const ece::Rectangle<unsigned int> & bounds);
		void setState(const ece::WindowState state);

		void attachToMonitor(const int monitorIdIn);

	private:
		short int windowId;

		ece::WindowSetting settings;

		ece::VideoMode videoMode;
	};
}

#endif // BASEWINDOW_HPP