#ifndef EVENTMANAGERNONE_HPP
#define EVENTMANAGERNONE_HPP

#include "Core\System\Event\BaseEventManager.hpp"

namespace ece
{
	class EventManagerNone : public BaseEventManager
	{
	public:
		virtual const Slot::GlobalSlotID addSlot(const Slot::Handle & handle);
		virtual const Signal::GlobalSignalID addSignal();

		virtual void eraseSlot(const Listener & listener, const Slot::SlotID slot);
		virtual void eraseSignal(const Emitter & emitter, const Signal::SignalID signal);

		virtual void connect(const Listener & listener, const Slot::SlotID slot, const Emitter & emitter, const Signal::SignalID signal);
		virtual void disconnect(const Listener & listener, const Slot::SlotID slot, const Emitter & emitter, const Signal::SignalID signal);
		virtual void disconnectAll(const Listener & listener, const Slot::SlotID slot);
		virtual void disconnectAll(const Emitter & emitter, const Signal::SignalID signal);

		virtual void broadcast(const Emitter & emitter, const Signal::SignalID signal);
		virtual void clear();
	};
}

#endif // EVENTMANAGERNONE_HPP
