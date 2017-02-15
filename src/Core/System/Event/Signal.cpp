#include "Core\System\Event\Signal.hpp"

namespace ece
{
	Signal::Signal(const GlobalSignalID id): id(id), dirty(false)
	{
	}

	const Signal::GlobalSignalID Signal::getId() const
	{
		return this->id;
	}

	const bool Signal::isDirty() const
	{
		return this->dirty;
	}

	void Signal::setDirty(const bool dirty)
	{
		this->dirty = dirty;
	}
}
