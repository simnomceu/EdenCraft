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
			ece::EventManagerLocator::getService().eraseSignal(it->second);
		}
	}

	void Emitter::addSignal(const ece::SignalID signal)
	{
		if (this->signals.find(signal) == this->signals.end()) {
			this->signals[signal] = ece::EventManagerLocator::getService().getSignalID();
		}
	}

	void Emitter::removeSignal(const ece::SignalID signal)
	{
		ece::EventManagerLocator::getService().eraseSignal(this->signals[signal]);

		this->signals.erase(signal);
	}

	void Emitter::emit(const ece::SignalID signal)
	{
		ece::EventManagerLocator::getService().broadcast(*this, this->signals[signal]);
	}

	const ece::GlobalSignalID Emitter::getSignal(const ece::SignalID signal) const
	{
		return this->signals.at(signal);
	}
}
