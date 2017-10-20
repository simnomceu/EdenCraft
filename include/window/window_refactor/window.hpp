#ifndef WINDOW_HPP
#define WINDOW_HPP

#include <string>
#include <memory>

#include "window_refactor/base_window_adapter.hpp"
#include "mathematics/rectangle.hpp"
#include "mathematics/vertex2u.hpp"

namespace ece
{
	class Window
	{
	public:
		Window();
		Window(const std::string & title);
		Window(const Window & copy);
		Window(Window && move);

		~Window();

		Window & operator=(const Window & copy);
		Window & operator=(Window && move);

		void open();
		void close();
		bool isOpened() const;

		const std::string & getTitle() const;
		void setTitle(const std::string & title);
		void setBounds(const ece::Rectangle<unsigned int> & bounds);
		void setPosition(const ece::IntVertex2u & position);
		void setMinimumSize(const ece::IntVertex2u & size);
		void setMaximumSize(const ece::IntVertex2u & size);
		void maximize();
		void minimize();
		void setFullscreen(const bool fullscreen);

	private:
		std::unique_ptr<BaseWindowAdapter> adapter;

		std::string title;
	};
}

#endif // WINDOW_HPP
