#include "window/common/base_window_adapter.hpp"

namespace ece
{
	BaseWindowAdapter::BaseWindowAdapter(): keyRepeat(true), eventQueue() {}

	BaseWindowAdapter::~BaseWindowAdapter() {}

	void BaseWindowAdapter::enableKeyRepeat(const bool enabled)
	{
		this->keyRepeat = enabled;
	}

	bool BaseWindowAdapter::hasEvents() const
	{
		return !this->eventQueue.empty();
	}

	InputEvent BaseWindowAdapter::popEvent()
	{
		if (!this->hasEvents()) {
			throw std::exception();
		}
		auto firstEvent = this->eventQueue.front();
		this->eventQueue.pop();
		return firstEvent;
	}

	void BaseWindowAdapter::pushEvent(const InputEvent & nextEvent)
	{
		this->eventQueue.push(nextEvent);
	}

	InputEvent & BaseWindowAdapter::lastEvent()
	{
		return this->eventQueue.back();
	}
}