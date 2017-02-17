#include "Core\Window\Event\Event.hpp"

namespace ece
{
	Event::Event(): type(NONE)
	{
	}
	const Event::EventType Event::getType() const
	{
		return this->type;
	}

	void Event::setType(const Event::EventType type)
	{
		this->type = type;
	}
}
