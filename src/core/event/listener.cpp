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


#include "core/event/listener.hpp"

#include "utility/debug/exception.hpp"

#include <iostream>

namespace ece
{
	namespace core
	{
		namespace event
		{
			using utility::debug::MemoryAccessException;
			using utility::debug::OutOfRangeException;

			void Listener::addSlot(const Slot::SlotID & slot, const Slot::Handle & handle)
			{
				try {
					if (this->_slots.find(slot) == this->_slots.end()) {
						this->_slots[slot] = this->_consumer.consume()->addSlot(handle);
					}
				}
				catch (MemoryAccessException & e) {
					// TODO: use the logger
					std::cerr << "Slot cannot be added: " << e.what() << std::endl;
				}
			}

			void Listener::removeSlot(const Slot::SlotID & slot)
			{
				try {
					this->_consumer.consume()->eraseSlot(*this, slot);

					this->_slots.erase(slot);
				}
				catch (MemoryAccessException & e) {
					// TODO: use the logger
					std::cerr << "Slot cannot be removed: " << e.what() << std::endl;
				}
			}

			Slot::GlobalSlotID Listener::getSlotID(const Slot::SlotID & slot) const
			{
				if (this->_slots.find(slot) == this->_slots.end()) {
					throw OutOfRangeException("slot", slot);
				}
				return this->_slots.at(slot);
			}

			void Listener::connect(const Slot::SlotID & slot, const Emitter & emitter, const Signal::SignalID & signal)
			{
				try {
					if (this->_slots.find(slot) != this->_slots.end()) {
						this->_consumer.consume()->connect(*this, slot, emitter, signal);
					}
				}
				catch (MemoryAccessException & e) {
					// TODO: use the logger
					std::cerr << "Slot cannot be connected to a signal: " << e.what() << std::endl;
				}
			}

			void Listener::disconnect(const Slot::SlotID & slot, const Emitter & emitter, const Signal::SignalID & signal)
			{
				try {
					if (this->_slots.find(slot) != this->_slots.end()) {
						this->_consumer.consume()->disconnect(*this, slot, emitter, signal);
					}
				}
				catch (MemoryAccessException & e) {
					// TODO: use the logger
					std::cerr << "Slot cannot be disconnected from a signal: " << e.what() << std::endl;
				}
			}

			void Listener::disconnectAll()
			{
				try {
					for (auto it = this->_slots.begin(); it != this->_slots.end(); ++it) {
						this->_consumer.consume()->disconnectAll(*this, it->second);
					}
				}
				catch (MemoryAccessException & e) {
					// TODO: use the logger
					std::cerr << "Slot cannot be disconnected from signals: " << e.what() << std::endl;
				}
			}

			void Listener::clear()
			{
				try {
					for (auto it = this->_slots.begin(); it != this->_slots.end(); ++it) {
						this->_consumer.consume()->eraseSlot(*this, it->first);
					}
					this->_slots.clear();
				}
				catch (MemoryAccessException & e) {
					// TODO: use the logger
					std::cerr << "Listener cannot be cleared: " << e.what() << std::endl;
				}
			}
		} // namespace event
	} // namespace core
} // namespace ece
