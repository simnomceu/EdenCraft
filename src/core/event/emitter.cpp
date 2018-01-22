#include "core/event/emitter.hpp"

#include "utility/debug/exception.hpp"
#include "utility/debug/exception.hpp"

#include <iostream>

namespace ece
{
	void Emitter::addSignal(const Signal::SignalID signal)
	{
		try {
			if (this->_signals.find(signal) == this->_signals.end()) {
				this->_signals[signal] = this->_consumer.consume()->addSignal();
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
			this->_consumer.consume()->eraseSignal(*this, signal);

			this->_signals.erase(signal);
		}
		catch (MemoryAccessException & e) {
			// TODO: use logger
			std::cerr << "Signal cannot be erased: " << e.what() << std::endl;
		}
	}

	void Emitter::emit(const Signal::SignalID signal)
	{
		try {
			this->_consumer.consume()->broadcast(*this, signal);
		}
		catch (MemoryAccessException & e) {
			// TODO: use logger
			std::cerr << "Signal cannot be broadcasted: " << e.what() << std::endl;
		}
	}

	const Signal::GlobalSignalID Emitter::getSignal(const Signal::SignalID signal) const
	{
		if (this->_signals.find(signal) == this->_signals.end()) {
			throw OutOfRangeException("signal", signal);
		}
		return this->_signals.at(signal);
	}

	void Emitter::clear()
	{
		try {
			for (auto it = this->_signals.begin(); it != this->_signals.end(); ++it) {
				this->_consumer.consume()->eraseSignal(*this, it->first);
			}
			this->_signals.clear();
		}
		catch (MemoryAccessException & e) {
			// TODO: use logger
			std::cerr << "Emitter cannot be cleared: " << e.what() << std::endl;
		}
	}

	void Emitter::connect(const Signal::SignalID signal, const Listener & listener, const Slot::SlotID slot)
	{
		try {
			this->_consumer.consume()->connect(listener, slot, *this, signal);
		}
		catch (MemoryAccessException & e) {
			// TODO: use logger
			std::cerr << "Signal cannot be connected to a slot: " << e.what() << std::endl;
		}
	}

	void Emitter::disconnect(const Signal::SignalID signal, const Listener & listener, const Slot::SlotID slot)
	{
		try {
			this->_consumer.consume()->disconnect(listener, slot, *this, signal);
		}
		catch (MemoryAccessException & e) {
			// TODO: use logger
			std::cerr << "Signal cannot be disconnected from a slot: " << e.what() << std::endl;
		}
	}

	void Emitter::disconnectAll()
	{
		try {
			for (auto it = this->_signals.begin(); it != this->_signals.end(); ++it) {
				this->_consumer.consume()->disconnectAll(*this, it->second);
			}
		}
		catch (MemoryAccessException & e) {
			// TODO: use logger
			std::cerr << "Signal cannot be disconnected from slots: " << e.what() << std::endl;
		}
	}
}
