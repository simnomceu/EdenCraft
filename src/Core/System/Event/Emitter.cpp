#include "Core\System\Event\Emitter.hpp"

#include "Core\System\Event\EventService.hpp"

namespace ece
{
	Emitter::Emitter() : signals()
	{
	}

	Emitter::~Emitter()
	{
		for (auto it = this->signals.begin(); it != this->signals.end(); ++it) {
			ece::EventServiceLocator::getService().eraseSignal(it->second);
		}
	}

	void Emitter::addSignal(const ece::SignalID signal)
	{
		if (this->signals.find(signal) == this->signals.end()) {
			this->signals[signal] = ece::EventServiceLocator::getService().getSignalID();
			ece::EventServiceLocator::getService().addSignal(this->signals[signal]);
		}
	}

	void Emitter::removeSignal(const ece::SignalID signal)
	{
		ece::EventServiceLocator::getService().eraseSignal(this->signals[signal]);

		this->signals.erase(signal);
	}

	void Emitter::emit(const ece::SignalID signal)
	{
		ece::EventServiceLocator::getService().broadcast(*this, signal);
	}

	const ece::GlobalSignalID Emitter::getSignal(const ece::SignalID signal) const
	{
		return this->signals.at(signal);
	}
}
