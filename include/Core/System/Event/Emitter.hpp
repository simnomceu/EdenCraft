#ifndef EMITTER_HPP
#define EMITTER_HPP

#include "Core\System\Event\Signal.hpp"
#include "Core\System\Event\EventManagerConsumer.hpp"

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
		virtual ~Emitter() = 0;

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

#endif // EMITTER_HPP