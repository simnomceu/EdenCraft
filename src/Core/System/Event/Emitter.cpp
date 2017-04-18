#include "System\Event\Emitter.hpp"

#include "Debug\Exception.hpp"
#include "Debug\Exception.hpp"

#include <iostream>

namespace ece
{
	void Emitter::addSignal(const Signal::SignalID signal)
	{
		try {
			if (this->signals.find(signal) == this->signals.end()) {
				this->signals[signal] = this->consumer.consume()->addSignal();
			}
		}
		catch (MemoryAccessException & e) {
			// TODO: use logger
			std::cerr << "Signal cannot be added: " << e.what() << std::endl;
		}
	}

	void Emitter::removeSignal(const Signal::SignalID signal)
	{
		try {
			this->consumer.consume()->eraseSignal(*this, signal);

			this->signals.erase(signal);
		}
		catch (MemoryAccessException & e) {
			// TODO: use logger
			std::cerr << "Signal cannot be erased: " << e.what() << std::endl;
		}
	}

	void Emitter::emit(const Signal::SignalID signal)
	{
		try {
			this->consumer.consume()->broadcast(*this, signal);
		}
		catch (MemoryAccessException & e) {
			// TODO: use logger
			std::cerr << "Signal cannot be broadcasted: " << e.what() << std::endl;
		}
	}

	const Signal::GlobalSignalID Emitter::getSignal(const Signal::SignalID signal) const
	{
		if (this->signals.find(signal) == this->signals.end()) {
			throw OutOfRangeException::makeException("signal", signal);
		}
		return this->signals.at(signal);
	}

	void Emitter::clear()
	{
		try {
			for (auto it = this->signals.begin(); it != this->signals.end(); ++it) {
				this->consumer.consume()->eraseSignal(*this, it->first);
			}
			this->signals.clear();
		}
		catch (MemoryAccessException & e) {
			// TODO: use logger
			std::cerr << "Emitter cannot be cleared: " << e.what() << std::endl;
		}
	}

	void Emitter::connect(const Signal::SignalID signal, const Listener & listener, const Slot::SlotID slot)
	{
		try {
			this->consumer.consume()->connect(listener, slot, *this, signal);
		}
		catch (MemoryAccessException & e) {
			// TODO: use logger
			std::cerr << "Signal cannot be connected to a slot: " << e.what() << std::endl;
		}
	}

	void Emitter::disconnect(const Signal::SignalID signal, const Listener & listener, const Slot::SlotID slot)
	{
		try {
			this->consumer.consume()->disconnect(listener, slot, *this, signal);
		}
		catch (MemoryAccessException & e) {
			// TODO: use logger
			std::cerr << "Signal cannot be disconnected from a slot: " << e.what() << std::endl;
		}
	}

	void Emitter::disconnectAll()
	{
		try {
			for (auto it = this->signals.begin(); it != this->signals.end(); ++it) {
				this->consumer.consume()->disconnectAll(*this, it->second);
			}
		}
		catch (MemoryAccessException & e) {
			// TODO: use logger
			std::cerr << "Signal cannot be disconnected from slots: " << e.what() << std::endl;
		}
	}
}
