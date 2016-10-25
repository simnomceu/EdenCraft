#include "Core\System\Emitter.hpp"

#include "Core\System\EventManagerLocator.hpp"

namespace ece
{
	void Emitter::addSignal(const ece::SignalID & signal)
	{
		ece::EventManagerLocator::getService().registerSignal(signal);
	}

	void Emitter::emit(const ece::SignalID & signal)
	{
		ece::EventManagerLocator::getService().broadcast(signal);
	}
}
