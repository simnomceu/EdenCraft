#ifndef BASEWINDOW_HPP
#define BASEWINDOW_HPP

#include "Geom\Rectangle.hpp"
#include "Window\WindowSetting.hpp"
#include "Window\VideoMode.hpp"
#include "Window\Window.inl"

#include "System\Event\Emitter.hpp"
#include "Event\Event.hpp"

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
<<<<<<< develop:include/Window/Window/BaseWindow.hpp
		inline BaseWindow(const ece::WindowSetting & settings, const ece::VideoMode & videoMode);
		BaseWindow(const BaseWindow & copy) = delete;
		inline BaseWindow(BaseWindow && copy);
		inline ~BaseWindow();

		BaseWindow & operator=(const BaseWindow & rightOperand) = delete;
		BaseWindow & operator=(BaseWindow && rightOperand);
=======
		BaseWindow(const ece::WindowSetting & settings, const ece::VideoMode & videoMode);
		BaseWindow(const BaseWindow & copy) = delete;
		BaseWindow(BaseWindow && move);
		~BaseWindow();

		BaseWindow & operator=(const BaseWindow & copy) = delete;
		BaseWindow & operator=(BaseWindow && move);
>>>>>>> Add some improvements for windows.:include/Core/Window/Window/BaseWindow.hpp

		virtual void open(const ece::VideoMode & videoMode);
		inline virtual void onRefresh();
		void close();

		bool shouldClosed() const;

		void applySettings(const ece::WindowSetting & settings);
		inline const ece::WindowSetting & getSettings();

		void setTitle(const std::string & title);
		void setBounds(const ece::Rectangle<unsigned int> & bounds);
		void setState(const ece::WindowState state);

		void attachToMonitor(const int monitorIdIn);

		const bool pollEvent(Event & event);
		const bool waitEvent(Event & event);

		void display();

	protected:

	private:
		short int windowId;

		ece::WindowSetting settings;

		ece::VideoMode videoMode;
	};
}

#include "Window\BaseWindow.inl"

#endif // BASEWINDOW_HPP