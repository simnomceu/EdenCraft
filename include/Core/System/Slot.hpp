#ifndef SLOT_HPP
#define SLOT_HPP

#include "Core\System\Event.inl"

#include <functional>

namespace ece
{
	class Emitter;

	class Slot
	{
	public:
		using GlobalSlotID = unsigned int;
		using Handle = std::function<void(const ece::Emitter & emitter, const ece::SignalID signal)>;

		Slot() = default;
		Slot(const Handle & handle);
		Slot(const Slot & copy);
		Slot(Slot && move);

		Slot & operator=(const Slot & copy);
		Slot & operator=(Slot && move);

		void trigger(const ece::Emitter & emitter, const ece::SignalID signal);

		const GlobalSlotID & getId() const;

	private:
		GlobalSlotID id;
		Handle handle;
	};


}

#endif // SLOT_HPP
