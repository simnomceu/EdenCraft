#include "window_refactor/window.hpp"

#ifdef __unix__
#include "x11/window_adapter.hpp"
#elif __WINDOW__
#include "wgl/window_adapter.hpp"
#elif __OSX__
#include "cocoa/window_adapter.hpp"
#else
#include "wgl/window_adapter.hpp"
#endif

namespace ece
{
	Window::Window(): adapter(std::make_unique<WindowAdapter>()), title()
	{
	}

	Window::Window(const std::string & title): adapter(std::make_unique<WindowAdapter>()), title(title)
	{
	}

	Window::Window(const Window & copy): adapter(static_cast<WindowAdapter*>(copy.adapter.get())), title(copy.title)
	{
	}

	Window::Window(Window && move): adapter(std::move(adapter)), title(std::move(title))
	{
	}

	Window::~Window()
	{
		this->adapter.release();
	}

	Window & Window::operator=(const Window & copy)
	{
		this->adapter.reset(copy.adapter.get());
		this->title = copy.title;

		return *this;
	}

	Window & Window::operator=(Window && move)
	{
		this->adapter = std::move(move.adapter);
		this->title = std::move(move.title);

		return *this;
	}

	void Window::open()
	{
		if (!this->isOpened()) {
			this->adapter->createWindow();
		}
	}

	void Window::close()
	{
		if (this->isOpened()) {
			this->adapter->deleteWindow();
		}
	}

	bool Window::isOpened() const
	{
		return this->adapter->isWindowCreated();
	}

	const std::string & Window::getTitle() const
	{
		return this->title;
	}

	void Window::setTitle(const std::string & title)
	{
		this->title = title;
		this->adapter.get()->setTitle(this->title);
	}

	void Window::setBounds(const ece::Rectangle<unsigned int>& bounds)
	{
	}

	void Window::setPosition(const ece::IntVertex2u & position)
	{
	}

	void Window::setMinimumSize(const ece::IntVertex2u & size)
	{
	}

	void Window::setMaximumSize(const ece::IntVertex2u & size)
	{
	}

	void Window::maximize()
	{
	}

	void Window::minimize()
	{
	}

	void Window::setFullscreen(const bool fullscreen)
	{
	}
}