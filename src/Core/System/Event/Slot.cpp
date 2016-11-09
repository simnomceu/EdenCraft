#include "Core\System\Event\Slot.hpp"

#include "Core\System\Event\Emitter.hpp"
#include "Core\System\EventService.hpp"

namespace ece
{
	Slot::Slot(const Handle & handle): id(ece::EventServiceLocator::getService().getSlotID()), handle(handle)
	{
	}

	Slot::Slot(const Slot & copy): id(ece::EventServiceLocator::getService().getSlotID()), handle(copy.handle)
	{
	}

	Slot::Slot(Slot && move): id(ece::EventServiceLocator::getService().getSlotID()), handle(std::move(move.handle))
	{
	}

	Slot & Slot::operator=(const Slot & copy)
	{
		this->handle = handle;
		return *this;
	}

	Slot & Slot::operator=(Slot && move)
	{
		this->handle = std::move(move.handle);
		return *this;
	}

	void Slot::trigger(const ece::Emitter & emitter, const ece::SignalID signal)
	{
		this->handle(emitter, signal);
	}

	const Slot::GlobalSlotID & Slot::getId() const
	{
		return this->id;
	}
}
