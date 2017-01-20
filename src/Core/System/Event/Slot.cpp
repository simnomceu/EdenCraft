#include "Core\System\Event\Slot.hpp"

#include "Core\System\Event\Emitter.hpp"
#include "Core\System\EventService.hpp"

namespace ece
{
	Slot::Slot(const GlobalSlotID id, const Handle & handle) : id(id), handle(handle), dirty(false)
	{
	}

	void Slot::trigger(const Emitter & emitter, const Signal::SignalID signal)
	{
		this->handle(emitter, signal);
	}

	const Slot::GlobalSlotID & Slot::getId() const
	{
		return this->id;
	}

	const bool Slot::isDirty() const
	{
		return this->dirty;
	}

	void Slot::setDirty(const bool dirty)
	{
		this->dirty = dirty;
	}
}
