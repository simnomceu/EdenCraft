#ifndef BASE_WINDOW_HPP
#define BASE_WINDOW_HPP

#include "mathematics\rectangle.hpp"
#include "window\window_setting.hpp"
#include "window\video_mode.hpp"
#include "window\window.inl"

#include "event\emitter.hpp"
#include "event\input_event.hpp"

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
		inline BaseWindow(const ece::WindowSetting & settings, const ece::VideoMode & videoMode);
		BaseWindow(const BaseWindow & copy) = delete;
		inline BaseWindow(BaseWindow && copy);
		inline ~BaseWindow();

		BaseWindow & operator=(const BaseWindow & rightOperand) = delete;
		BaseWindow & operator=(BaseWindow && rightOperand);

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

		const bool pollEvent(InputEvent & event);
		const bool waitEvent(InputEvent & event);

		void display();

	protected:

	private:
		short int windowId;

		ece::WindowSetting settings;

		ece::VideoMode videoMode;
	};
}

#include "window\base_window.inl"

#endif // BASE_WINDOW_HPP