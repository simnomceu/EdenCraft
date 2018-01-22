#ifndef EMITTER_HPP
#define EMITTER_HPP

#include "core/event/signal.hpp"
#include "core/event/event_manager_consumer.hpp"

#include <map>

namespace ece
{
	class Listener;

	class Emitter
	{
	public:
		Emitter() = default;
		Emitter(const Emitter & copy) = default;
		Emitter(Emitter && move) = default;
		inline virtual ~Emitter() = 0;

		Emitter & operator=(const Emitter & copy) = default;
		Emitter & operator=(Emitter && move) = default;

		void addSignal(const Signal::SignalID signal);
		void removeSignal(const Signal::SignalID signal);

		void emit(const Signal::SignalID signal);

		const Signal::GlobalSignalID getSignal(const Signal::SignalID signal) const;

		void clear();

		void connect(const Signal::SignalID signal, const Listener & listener, const Slot::SlotID slot);
		void disconnect(const Signal::SignalID signal, const Listener & listener, const Slot::SlotID slot);
		void disconnectAll();

	private:
		EventManagerConsumer _consumer;
		std::map<Signal::SignalID, Signal::GlobalSignalID> _signals;
	};
}

#include "core/event/emitter.inl"

#endif // EMITTER_HPP