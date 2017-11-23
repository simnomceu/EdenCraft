#ifndef BASE_WINDOW_HPP
#define BASE_WINDOW_HPP

#include "utility/mathematics/rectangle.hpp"
//#include "window/window/window_setting.hpp"
#include "window/common/video_mode.hpp"
#include "window/window_old/window.inl"

#include "core/event/emitter.hpp"
//#include "event/input_event.hpp"

namespace ece
{
	class BaseWindow: public Emitter
	{
	public:
	//	static const Signal::SignalID WINDOW_OPENED = 0;
	//	static const Signal::SignalID WINDOW_CLOSED = 1;
	//	static const Signal::SignalID WINDOW_RESIZED = 2;
	//	static const Signal::SignalID WINDOW_MOVED = 3;
	//	static const Signal::SignalID WINDOW_RENAMED = 4;

	//	BaseWindow(const ece::WindowSetting & settings);
	//	inline BaseWindow(const ece::WindowSetting & settings, const ece::VideoMode & videoMode);
	//	BaseWindow(const BaseWindow & copy) = delete;
	//	inline BaseWindow(BaseWindow && move);
	//	inline ~BaseWindow();

	//	BaseWindow & operator=(const BaseWindow & copy) = delete;
	//	BaseWindow & operator=(BaseWindow && move);

		virtual void open(const ece::VideoMode & videoMode);
		inline virtual void onRefresh();
	//	void close();

		bool shouldClosed() const;

	//	void applySettings(const ece::WindowSetting & settings);
	//	inline const ece::WindowSetting & getSettings();

	//	void setTitle(const std::string & title);
	//	void setBounds(const ece::Rectangle<unsigned int> & bounds);
		void setState(const ece::WindowState state);

		void attachToMonitor(const int monitorIdIn);

//		const bool pollEvent(InputEvent & event);
//		const bool waitEvent(InputEvent & event);

		void display();

	protected:

	private:
		short int windowId;

//		ece::WindowSetting settings;

		ece::VideoMode videoMode;
	};
}

#include "window/window_old/base_window.inl"

#endif // BASE_WINDOW_HPP