#include "window/window_refactor/base_window_adapter.hpp"

namespace ece
{
	BaseWindowAdapter::~BaseWindowAdapter() {}

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