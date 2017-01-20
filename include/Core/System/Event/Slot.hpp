#ifndef SLOT_HPP
#define SLOT_HPP

#include <functional>

#include "Core\System\Event\Signal.hpp"

namespace ece
{
	class Emitter;

	class Slot final
	{
	public:
		using SlotID = unsigned int;
		using GlobalSlotID = unsigned int;
		using Handle = std::function<void(const Emitter & emitter, const Signal::SignalID signal)>;

		static const Slot::GlobalSlotID INVALID_SLOT = -1;

		Slot() = delete;
		Slot(const GlobalSlotID id, const Handle & handle);
		Slot(const Slot & copy) = default;
		Slot(Slot && move) = default;
		~Slot() = default;

		Slot & operator=(const Slot & copy) = default;
		Slot & operator=(Slot && move) = default;

		void trigger(const Emitter & emitter, const Signal::SignalID signal);

		const GlobalSlotID & getId() const;

		const bool isDirty() const;
		void setDirty(const bool dirty);

	private:
		GlobalSlotID id;
		Handle handle;
		bool dirty;
	};
}

#endif // SLOT_HPP
