#ifndef EMITTER_HPP
#define EMITTER_HPP

#include "System\Event\Signal.hpp"
#include "System\Event\EventManagerConsumer.hpp"

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
		EventManagerConsumer consumer;
		std::map<Signal::SignalID, Signal::GlobalSignalID> signals;
	};
}

#include "System\Event\Emitter.inl"

#endif // EMITTER_HPP