/*

	oooooooooooo       .o8                          .oooooo.                       .o88o.     .   
	`888'     `8      "888                         d8P'  `Y8b                      888 `"   .o8   
	 888          .oooo888   .ooooo.  ooo. .oo.   888          oooo d8b  .oooo.   o888oo  .o888oo 
	 888oooo8    d88' `888  d88' `88b `888P"Y88b  888          `888""8P `P  )88b   888      888   
	 888    "    888   888  888ooo888  888   888  888           888      .oP"888   888      888   
	 888       o 888   888  888    .o  888   888  `88b    ooo   888     d8(  888   888      888 . 
	o888ooooood8 `Y8bod88P" `Y8bod8P' o888o o888o  `Y8bood8P'  d888b    `Y888""8o o888o     "888" 

															  .oooooo.                                
															 d8P'  `Y8b                               
															888           .ooooo.  oooo d8b  .ooooo.  
															888          d88' `88b `888""8P d88' `88b 
															888          888   888  888     888ooo888 
															`88b    ooo  888   888  888     888    .o 
															 `Y8bood8P'  `Y8bod8P' d888b    `Y8bod8P' 
                                          
                                          

				This file is part of EdenCraft Engine - Core module.
				Copyright(C) 2018 Pierre Casati (@IsilinBN)

				This program is free software : you can redistribute it and/or modify
				it under the terms of the GNU General Public License as published by
				the Free Software Foundation, either version 3 of the License, or
				(at your option) any later version.

				This program is distributed in the hope that it will be useful,
				but WITHOUT ANY WARRANTY; without even the implied warranty of
				MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.See the
				GNU General Public License for more details.

				You should have received a copy of the GNU General Public License
				along with this program.If not, see <http://www.gnu.org/licenses/>.

*/


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
