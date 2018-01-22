#include "window/common/window.hpp"

#include "window/common/window_adapter.hpp"

#include "window/window_event/input_event.hpp"

#include <iostream>

namespace ece
{
	Window::Window():Emitter(), _adapter(std::make_shared<WindowAdapter>()), _videoMode(), _ups(0)
	{
		this->addSignal(WINDOW_OPENED);
		this->addSignal(WINDOW_CLOSED);
		this->addSignal(WINDOW_RESIZED);
		this->addSignal(WINDOW_MOVED);
		this->addSignal(WINDOW_RENAMED);
	}

	Window::Window(const Window & copy):Emitter(copy), _adapter(static_cast<WindowAdapter*>(copy._adapter.get())), _ups(copy._ups)
	{
	}

	Window::Window(Window && move): Emitter(move), _adapter(std::move(_adapter)), _ups(std::move(move._ups))
	{
	}

	Window::~Window()
	{
		std::cout << "window destroyed" << std::endl;
	}

	Window & Window::operator=(const Window & copy)
	{
		Emitter::operator=(copy);
		this->_adapter.reset(copy._adapter.get());
		this->_ups = copy._ups;

		return *this;
	}

	Window & Window::operator=(Window && move)
	{
		Emitter::operator=(move);
		this->_adapter = std::move(move._adapter);
		this->_ups = std::move(move._ups);

		return *this;
	}

	void Window::open()
	{
		if (!this->isOpened()) {
			this->_adapter->createWindow();
			this->emit(WINDOW_OPENED);
		}
	}

	void Window::open(const WindowSetting & /*settings*/)
	{
	}

	void Window::close()
	{
		if (this->isOpened()) {
			this->_adapter->deleteWindow();
			this->emit(WINDOW_CLOSED);
		}
	}

	bool Window::isOpened() const
	{
		return this->_adapter->isWindowCreated();
	}

	WindowSetting Window::getSettings() const
	{
		WindowSetting settings;
		settings._title = this->getTitle();

		return settings;
	}

	void Window::setSettings(const WindowSetting & settings)
	{
		this->setTitle(settings._title);
		this->setPosition(settings._position);
	}

	const std::string & Window::getTitle() const
	{
		return this->_adapter.get()->getTitle();
	}

	void Window::setTitle(const std::string & title)
	{
		this->_adapter.get()->setTitle(title);
	}

	void Window::setPosition(const IntVertex2u & position)
	{
		auto oldPosition = this->_adapter.get()->getPosition();
		if (!(oldPosition == position)) { // TODO : overload operator!= for vertex classes
			this->_adapter.get()->setPosition(position);
			this->emit(WINDOW_MOVED);
		}
	}

	void Window::setMinimumSize(const IntVertex2u & /*size*/)
	{
	}

	void Window::setMaximumSize(const IntVertex2u & /*size*/)
	{
	}

	void Window::maximize()
	{
		if (this->isOpened()) {
			this->_adapter.get()->maximize();
		}
	}

	void Window::minimize()
	{
		if (this->isOpened()) {
			this->_adapter.get()->minimize();
		}
	}

	void Window::setFullscreen(const bool /*fullscreen*/)
	{
	}

	void Window::enableDoubleClick(const bool /*enabled*/)
	{
	}

	bool Window::isDoubleClickEnabled() const
	{
		return false;
	}

	void Window::enableKeyRepeat(const bool enabled)
	{
		this->_adapter->enableKeyRepeat(enabled);
	}

	bool Window::isKeyRepeatedEnabled() const
	{
		return false;
	}

	void Window::limitUPS(const int limit)
	{
		this->_ups.setUPS(limit);
	}

	bool Window::waitEvent(InputEvent & event)
	{
		if (this->isOpened()) {
			while (!this->_adapter.get()->hasEvents()) {
				this->_adapter.get()->processEvent(true);
			}
			event = this->_adapter.get()->popEvent();
			return true;
		}
		return false;
	}

	bool Window::pollEvent(InputEvent & event)
	{
		if (this->isOpened()) {
			if (this->_ups.getLimit() == 0 || (this->_ups.getLimit() > 0 && this->_ups.isReadyToUpdate())) {
				this->_adapter.get()->processEvent(false);
				if (this->_adapter.get()->hasEvents()) {
					event = this->_adapter.get()->popEvent();
					return true;
				}
				return false;
			}
			return false;
		}
		return false;
	}

	std::weak_ptr<BaseWindowAdapter> Window::getAdapter() const
	{
		return this->_adapter;
	}

	VideoMode & Window::getVideoMode()
	{
		return this->_videoMode;
	}

	const VideoMode & Window::getVideoMode() const
	{
		return this->_videoMode;
	}

	void Window::updateVideoMode()
	{
		if (this->_videoMode.hasChanged()) {

			this->_videoMode.applyChanges();
		}
	}
}