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
		static const Signal::SignalID WINDOW_OPENED = 0;
		static const Signal::SignalID WINDOW_CLOSED = 1;
		static const Signal::SignalID WINDOW_RESIZED = 2;
		static const Signal::SignalID WINDOW_MOVED = 3;
		static const Signal::SignalID WINDOW_RENAMED = 4;

		BaseWindow(const ece::WindowSetting & settings);
		BaseWindow(const ece::WindowSetting & settings, const ece::VideoMode & videoMode);
		BaseWindow(const BaseWindow & copy) = delete;
		BaseWindow(BaseWindow && move);
		~BaseWindow();

		BaseWindow & operator=(const BaseWindow & copy) = delete;
		BaseWindow & operator=(BaseWindow && move);

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