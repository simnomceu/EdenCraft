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


#ifndef BASE_EVENT_MANAGER_HPP
#define BASE_EVENT_MANAGER_HPP

#include "core/config.hpp"
#include "core/event/slot.hpp"
#include "core/event/signal.hpp"
#include "utility/indexing/unique_id.hpp"

namespace ece
{
	namespace core
	{
		namespace event
		{
			using utility::indexing::UniqueID;

			class EventManagerConsumer;
			class Listener;
			class Emitter;

			/**
			 * @class BaseEventManager
			 * @brief Base classe for default event manger service providing.
			 * @remark I'm not convinced it should be this kind of service here.
			 */
			class ECE_CORE_API BaseEventManager
			{
			public:
				/**
				 * @fn Slot::GlobalSlotID addSlot(const Slot::Handle & handle)
				 * @param[in] handle The action for the slot to create.
				 * @return The global id of the slot created.
				 * @brief Create and register a new slot.
				 * @throw
				 */
				virtual inline Slot::GlobalSlotID addSlot(const Slot::Handle & handle);

				/**
				 * @fn Signal::GlobalSignalID addSignal()
				 * @return The global id of the signal created.
				 * @brief Create and register a new signal.
				 * @throw
				 */
				virtual inline Signal::GlobalSignalID addSignal();

				/**
				 * @fn void eraseSlot(const Listener & listener, const Slot::SlotID & slot)
				 * @param[in] listener The owner of the slot.
				 * @param[in] slot The slot to erase.
				 * @brief Erase a specific slot.
				 * If that slot does not exist, nothing happens.
				 * @throw
				 */
				virtual inline void eraseSlot(const Listener & listener, const Slot::SlotID & slot);

				/**
				 * @fn void eraseSignal(const Emitter & emitter, const Signal::SignalID & signal)
				 * @param[in] emitter The owner of the signal.
				 * @param[in] signal The signal to erase.
				 * @brief Erase a specific signal.
				 * If that signal does not exist, nothing happens.
				 * @throw
				 */
				virtual inline void eraseSignal(const Emitter & emitter, const Signal::SignalID & signal);

				/**
				 * @fn void connect(const Listener & listener, const Slot::SlotID & slot, const Emitter & emitter, const Signal::SignalID & signal)
				 * @param[in] listener The owner of the slot.
				 * @param[in] slot The slot to connect.
				 * @param[in] emitter The owner of the signal.
				 * @param[in] signal The signal to connect.
				 * @brief Connect a signal and a slot together.
				 * If they are already connected, nothing happens
				 * @throw
				 */
				virtual inline void connect(const Listener & listener, const Slot::SlotID & slot, const Emitter & emitter, const Signal::SignalID & signal);

				/**
				 * @fn void disconnect(const Listener & listener, const Slot::SlotID & slot, const Emitter & emitter, const Signal::SignalID & signal)
				 * @param[in] listener The owner of the slot.
				 * @param[in] slot The slot to disconnect.
				 * @param[in] emitter The owner of the signal.
				 * @param[in] signal The signal to disconnect.
				 * @brief Disconnect a signal and a slot.
				 * If they are not connected, nothing happens.
				 * @throw
				 */
				virtual inline void disconnect(const Listener & listener, const Slot::SlotID & slot, const Emitter & emitter, const Signal::SignalID & signal);

				/**
				 * @fn void disconnectAll(const Listener & listener, const Slot::SlotID & slot)
				 * @param[in] listener The owner of the slot.
				 * @param[in] slot The slot to disconnect.
				 * @brief Disconnect the slot from all signals connected.
				 * If it is not connected, nothing happens.
				 * @throw
				 */
				virtual inline void disconnectAll(const Listener & listener, const Slot::SlotID & slot);

				/**
				 * @fn void disconnectAll(const Emitter & emitter, const Signal::SignalID & signal)
				 * @param[in] emitter The owner of the signal.
				 * @param[in] signal The signal to disconnect.
				 * @brief Disconnect the signal from all slots connected.
				 * If it is not connected, nothing happens.
				 * @throw
				 */
				virtual inline void disconnectAll(const Emitter & emitter, const Signal::SignalID & signal);

				/**
				 * @fn void broadcast(const Emitter & emitter, const Signal::SignalID & signal)
				 * @param[in] emitter The owner of the signal.
				 * @param[in] signal The signal to broadcast.
				 * @brief Broadcast a signal to all slots connected, to trigger them.
				 * @throw
				 */
				virtual void broadcast(const Emitter & emitter, const Signal::SignalID & signal);

				/**
				 * @fn void clear()
				 * @brief Clear the entire manager, and erase all slots, signals, and connections.
				 * @throw
				 */
				virtual void clear();
			};
		} // namespace event
	} // namespace core
} // namespace ece

#include "core/event/base_event_manager.inl"

#endif // BASE_EVENT_MANAGER_HPP
