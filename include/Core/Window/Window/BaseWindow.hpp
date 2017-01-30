#ifndef BASEWINDOW_HPP
#define BASEWINDOW_HPP

#include "Core\Geom\Rectangle.hpp"
#include "Core\Window\Window\WindowSetting.hpp"
#include "Core\Window\Window\VideoMode.hpp"
#include "Core\Window\Window\Window.inl"

#include "Core\System\Event\Emitter.hpp"
#include "Core\Window\Event\Event.hpp"

namespace ece
{
	class BaseWindow: public Emitter
	{
	public:
		const Signal::SignalID WINDOW_OPENED = 0;
		const Signal::SignalID WINDOW_CLOSED = 1;
		const Signal::SignalID WINDOW_RESIZED = 2;
		const Signal::SignalID WINDOW_MOVED = 3;
		const Signal::SignalID WINDOW_RENAMED = 4;

		BaseWindow(const ece::WindowSetting & settings);
		BaseWindow(const ece::WindowSetting & settings, const ece::VideoMode & videoMode);
		BaseWindow(const BaseWindow & copy);
		BaseWindow(BaseWindow && copy);
		~BaseWindow();

		BaseWindow & operator=(const BaseWindow & rightOperand);
		BaseWindow & operator=(BaseWindow && rightOperand);

		void open(const ece::VideoMode & videoMode);
		void close();

		bool shouldClosed() const;

		void applySettings(const ece::WindowSetting & settings);
		const ece::WindowSetting & getSettings();

		void setTitle(const std::string & title);
		void setBounds(const ece::Rectangle<unsigned int> & bounds);
		void setState(const ece::WindowState state);

		void attachToMonitor(const int monitorIdIn);

		const bool pollEvent(Event & event);
		const bool waitEvent(Event & event);

	protected:

	private:
		short int windowId;

		ece::WindowSetting settings;

		ece::VideoMode videoMode;
	};
}

#endif // BASEWINDOW_HPP