#ifndef WINDOW_HPP
#define WINDOW_HPP

#include <string>
#include <memory>

#include "window_refactor/base_window_adapter.hpp"
#include "window_refactor/window_setting.hpp"
#include "mathematics/vertex2u.hpp"
#include "event/emitter.hpp"
#include "window_event/input_event.hpp"

namespace ece
{
	class Window: public Emitter
	{
	public:
		static const Signal::SignalID WINDOW_OPENED = 0;
		static const Signal::SignalID WINDOW_CLOSED = 1;
		static const Signal::SignalID WINDOW_RESIZED = 2;
		static const Signal::SignalID WINDOW_MOVED = 3;
		static const Signal::SignalID WINDOW_RENAMED = 4;

		Window();
		Window(const Window & copy);
		Window(Window && move);

		~Window();

		Window & operator=(const Window & copy);
		Window & operator=(Window && move);

		void open();
		void open(const WindowSetting & settings);
		void close();
		bool isOpened() const;

		WindowSetting getSettings() const;
		void setSettings(const WindowSetting & settings);

		const std::string & getTitle() const;
		void setTitle(const std::string & title);
		void setPosition(const IntVertex2u & position);
		void setMinimumSize(const IntVertex2u & size);
		void setMaximumSize(const IntVertex2u & size);
		void maximize();
		void minimize();
		void setFullscreen(const bool fullscreen);
		void enableDoubleClick(const bool enabled);
		bool isDoubleClickEnabled() const;
		void enableKeyRepeated(const bool enabled);
		bool isKeyRepeatedEnabled() const;

		bool waitEvent(InputEvent & event);
		bool pollEvent(InputEvent & event);

		std::weak_ptr<BaseWindowAdapter> getAdapter() const;

	private:
		std::shared_ptr<BaseWindowAdapter> adapter;
	};
}

#endif // WINDOW_HPP
