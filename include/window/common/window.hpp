#ifndef WINDOW_HPP
#define WINDOW_HPP

#include <string>
#include <memory>

#include "window/common/base_window_adapter.hpp"
#include "utility/mathematics/vector2u.hpp"
#include "core/event/emitter.hpp"
#include "window/common/video_mode.hpp"
#include "window/common/window_setting.hpp"
#include "utility/time/update_per_second.hpp"

namespace ece
{
	class InputEvent;

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
		void enableKeyRepeat(const bool enabled);
		bool isKeyRepeatedEnabled() const;
		void limitUPS(const int limit);

		bool waitEvent(InputEvent & event);
		bool pollEvent(InputEvent & event);

		std::weak_ptr<BaseWindowAdapter> getAdapter() const;
		VideoMode & getVideoMode();
		const VideoMode & getVideoMode() const;

		virtual void updateVideoMode();

	protected:
		std::shared_ptr<BaseWindowAdapter> _adapter;
		VideoMode _videoMode;
		UpdatePerSecond _ups;
	};
}

#endif // WINDOW_HPP
