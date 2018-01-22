#include "window/common/base_window_adapter.hpp"

namespace ece
{
	BaseWindowAdapter::BaseWindowAdapter(): _keyRepeat(true), _eventQueue() {}

	BaseWindowAdapter::~BaseWindowAdapter() {}

	void BaseWindowAdapter::enableKeyRepeat(const bool enabled)
	{
		this->_keyRepeat = enabled;
	}

	bool BaseWindowAdapter::hasEvents() const
	{
		return !this->_eventQueue.empty();
	}

	InputEvent BaseWindowAdapter::popEvent()
	{
		if (!this->hasEvents()) {
			throw std::exception();
		}
		auto firstEvent = this->_eventQueue.front();
		this->_eventQueue.pop();
		return firstEvent;
	}

	void BaseWindowAdapter::pushEvent(const InputEvent & nextEvent)
	{
		this->_eventQueue.push(nextEvent);
	}

	InputEvent & BaseWindowAdapter::lastEvent()
	{
		return this->_eventQueue.back();
	}
}