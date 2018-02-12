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

#ifndef LISTENER_HPP
#define LISTENER_HPP

#include "core/event/slot.hpp"
#include "core/event/event_manager_consumer.hpp"

#include <map>

namespace ece
{
	class Emitter;

	class Listener
	{
	public:
		Listener() = default;
		Listener(const Listener & copy) = default;
		Listener(Listener && move) = default;
		inline virtual ~Listener() = 0;

		Listener & operator=(const Listener & copy) = default;
		Listener & operator=(Listener && move) = default;

		void addSlot(const Slot::SlotID slot, const Slot::Handle & handle);
		void removeSlot(const Slot::SlotID slot);

		const Slot::GlobalSlotID getSlotID(const Slot::SlotID slot) const;

		void connect(const Slot::SlotID slot, const Emitter & emitter, const Signal::SignalID signal);
		void disconnect(const Slot::SlotID slot, const Emitter & emitter, const Signal::SignalID signal);
		void disconnectAll();

		void clear();

	private:
		EventManagerConsumer _consumer;
		std::map<Slot::SlotID, Slot::GlobalSlotID> _slots;
	};
}

#include "core/event/listener.inl"

#endif // LISTENER_HPP
