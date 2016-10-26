#include "Core\System\Emitter.hpp"

#include "Core\System\EventManagerLocator.hpp"

namespace ece
{
	Emitter::Emitter() : signals()
	{
	}

	Emitter::~Emitter()
	{
		for (auto it = this->signals.begin(); it != this->signals.end(); ++it) {
			ece::EventManagerLocator::getService().eraseSignal(*it);
		}
	}

	void Emitter::addSignal(const ece::SignalID & signal)
	{
		if (std::find(this->signals.begin(), this->signals.end(), signal) == this->signals.end()) {
			this->signals.push_back(signal);
		}
		ece::EventManagerLocator::getService().registerSignal(signal);
	}

	void Emitter::removeSignal(const ece::SignalID & signal)
	{
		auto pos = std::find(this->signals.begin(), this->signals.end(), signal);
		if (pos != this->signals.end()) {
			this->signals.erase(pos);
		}
		ece::EventManagerLocator::getService().eraseSignal(signal);
	}

	void Emitter::emit(const ece::SignalID & signal)
	{
		if (std::find(this->signals.begin(), this->signals.end(), signal) != this->signals.end()) {
			ece::EventManagerLocator::getService().broadcast(signal);
		}
	}
}
