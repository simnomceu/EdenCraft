#include "window_refactor/window.hpp"

#ifdef __unix__
#include "x11/window_adapter.hpp"
#elif __WINDOW__
#include "win32/window_adapter.hpp"
#elif __OSX__
#include "cocoa/window_adapter.hpp"
#else
#include "win32/window_adapter.hpp"
#endif

namespace ece
{
	Window::Window():Emitter(), adapter(std::make_shared<WindowAdapter>())
	{
		this->addSignal(WINDOW_OPENED);
		this->addSignal(WINDOW_CLOSED);
		this->addSignal(WINDOW_RESIZED);
		this->addSignal(WINDOW_MOVED);
		this->addSignal(WINDOW_RENAMED);
	}

	Window::Window(const Window & copy):Emitter(copy), adapter(static_cast<WindowAdapter*>(copy.adapter.get()))
	{
	}

	Window::Window(Window && move): Emitter(move), adapter(std::move(adapter))
	{
	}

	Window::~Window()
	{
		this->adapter.reset();
	}

	Window & Window::operator=(const Window & copy)
	{
		Emitter::operator=(copy);
		this->adapter.reset(copy.adapter.get());

		return *this;
	}

	Window & Window::operator=(Window && move)
	{
		Emitter::operator=(move);
		this->adapter = std::move(move.adapter);

		return *this;
	}

	void Window::open()
	{
		if (!this->isOpened()) {
			this->adapter->createWindow();
			this->emit(WINDOW_OPENED);
		}
	}

	void Window::open(const WindowSetting & settings)
	{
	}

	void Window::close()
	{
		if (this->isOpened()) {
			this->adapter->deleteWindow();
			this->emit(WINDOW_CLOSED);
		}
	}

	bool Window::isOpened() const
	{
		return this->adapter->isWindowCreated();
	}

	WindowSetting Window::getSettings() const
	{
		WindowSetting settings;
		settings.title = this->getTitle();

		return settings;
	}

	void Window::setSettings(const WindowSetting & settings)
	{
		this->setTitle(settings.title);
		this->setPosition(settings.position);
	}

	const std::string & Window::getTitle() const
	{
		return this->adapter.get()->getTitle();
	}

	void Window::setTitle(const std::string & title)
	{
		this->adapter.get()->setTitle(title);
	}

	void Window::setPosition(const IntVertex2u & position)
	{
		auto oldPosition = this->adapter.get()->getPosition();
		if (!(oldPosition == position)) { // TODO : overload operator!= for vertex classes
			this->adapter.get()->setPosition(position);
			this->emit(WINDOW_MOVED);
		}
	}

	void Window::setMinimumSize(const IntVertex2u & size)
	{
	}

	void Window::setMaximumSize(const IntVertex2u & size)
	{
	}

	void Window::maximize()
	{
		if (this->isOpened()) {
			this->adapter.get()->maximize();
		}
	}

	void Window::minimize()
	{
		if (this->isOpened()) {
			this->adapter.get()->minimize();
		}
	}

	void Window::setFullscreen(const bool fullscreen)
	{
	}

	void Window::enableDoubleClick(const bool enabled)
	{
	}

	bool Window::isDoubleClickEnabled() const
	{
		return false;
	}

	void Window::enableKeyRepeated(const bool enabled)
	{
	}

	bool Window::isKeyRepeatedEnabled() const
	{
		return false;
	}

	bool Window::waitEvent(InputEvent & event)
	{
		if (this->isOpened()) {
			while (!this->adapter.get()->hasEvents()) {
				this->adapter.get()->processEvent(true);
			}
			event = this->adapter.get()->popEvent();
			return true;
		}
		return false;
	}

	bool Window::pollEvent(InputEvent & event)
	{
		if (this->isOpened()) {
			this->adapter.get()->processEvent(false);
			if (this->adapter.get()->hasEvents()) {
				event = this->adapter.get()->popEvent();
				return true;
			}
			return false;
		}
		return false;
	}

	std::weak_ptr<BaseWindowAdapter> Window::getAdapter() const
	{
		return this->adapter;
	}
}