#ifndef BASEWINDOW_HPP
#define BASEWINDOW_HPP

#include "Core\Geom\Rectangle.hpp"
#include "Core\Window\WindowSetting.hpp"
#include "Core\Window\VideoMode.hpp"
#include "Core\Window\Window.inl"

#include "Core\System\Emitter.hpp"

namespace ece
{
	class BaseWindow: public Emitter
	{
	public:
		BaseWindow(const ece::WindowSetting & settings);
		BaseWindow(const ece::WindowSetting & settings, const ece::VideoMode & videoMode);
		BaseWindow(const BaseWindow & copy);
		BaseWindow(BaseWindow && copy);
		~BaseWindow();

		BaseWindow & operator=(const BaseWindow & rightOperand);
		BaseWindow & operator=(BaseWindow && rightOperand);

		void open(const ece::VideoMode & videoMode);
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