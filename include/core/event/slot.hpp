#ifndef SLOT_HPP
#define SLOT_HPP

#include <functional>

#include "core/event/signal.hpp"

namespace ece
{
	class Emitter;

	class Slot final
	{
	public:
		using SlotID = unsigned int;
		using GlobalSlotID = unsigned int;
		using Handle = std::function<void(const Emitter & emitter, const Signal::SignalID signal)>;

		static const Slot::GlobalSlotID INVALID_SLOT = 0;

		Slot() = delete;
		inline Slot(const GlobalSlotID id, const Handle & handle);
		Slot(const Slot & copy) = default;
		Slot(Slot && move) = default;
		~Slot() = default;

		Slot & operator=(const Slot & copy) = default;
		Slot & operator=(Slot && move) = default;

		inline void trigger(const Emitter & emitter, const Signal::SignalID signal);

		inline const GlobalSlotID & getId() const;

		inline const bool isDirty() const;
		inline void setDirty(const bool dirty);

	private:
		GlobalSlotID _id;
		Handle _handle;
		bool _dirty;
	};
}

#include "core/event/slot.inl"

#endif // SLOT_HPP
