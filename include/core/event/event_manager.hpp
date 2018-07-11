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


#ifndef EVENT_MANAGER_HPP
#define EVENT_MANAGER_HPP

#include "core/config.hpp"
#include "core/event/base_event_manager.hpp"
#include "core/event/connection.hpp"

#include <vector>
#include <memory>

namespace ece
{
	namespace core
	{
		namespace event
		{
			/**
			 * @class EventManager
			 * @extends BaseEventManager
			 * @brief To manage events through a service.
			 */
			class ECE_CORE_API EventManager : public BaseEventManager
			{
			public:
				/**
				 * @fn EventManager()
				 * @brief Default constructor.
				 * @throw
				 */
				inline EventManager();

				/**
				 * @fn Slot::GlobalSlotID addSlot(const Slot::Handle & handle)
				 * @param[in] handle The action for the slot to create.
				 * @return The global id of the slot created.
				 * @brief Create and register a new slot.
				 * @throw
				 * @see Slot::GlobalSlotID BaseEventManager::addSlot(const Slot::Handle & handle)
				 */
				virtual Slot::GlobalSlotID addSlot(const Slot::Handle & handle) override;

				/**
				 * @fn Signal::GlobalSignalID addSignal()
				 * @return The global id of the signal created.
				 * @brief Create and register a new signal.
				 * @throw
				 * @see Signal::GlobalSignalID BaseEventManager::addSignal()
				 */
				virtual Signal::GlobalSignalID addSignal() override;

				/**
				 * @fn void eraseSlot(const Listener & listener, const Slot::SlotID & slot)
				 * @param[in] listener The owner of the slot.
				 * @param[in] slot The slot to erase.
				 * @brief Erase a specific slot.
				 * If that slot does not exist, nothing happens.
				 * @throw
				 * @see void BaseEventManager::eraseSlot(const Listener & listener, const Slot::SlotID & slot)
				 */
				virtual void eraseSlot(const Listener & listener, const Slot::SlotID & slot) override;

				/**
				 * @fn void eraseSignal(const Emitter & emitter, const Signal::SignalID & signal)
				 * @param[in] emitter The owner of the signal.
				 * @param[in] signal The signal to erase.
				 * @brief Erase a specific signal.
				 * If that signal does not exist, nothing happens.
				 * @throw
				 * @see void BaseEventManager::eraseSignal(const Emitter & emitter, const Signal::SignalID & signal)
				 */
				virtual void eraseSignal(const Emitter & emitter, const Signal::SignalID & signal) override;

				/**
				 * @fn void connect(const Listener & listener, const Slot::SlotID & slot, const Emitter & emitter, const Signal::SignalID & signal)
				 * @param[in] listener The owner of the slot.
				 * @param[in] slot The slot to connect.
				 * @param[in] emitter The owner of the signal.
				 * @param[in] signal The signal to connect.
				 * @brief Connect a signal and a slot together.
				 * If they are already connected, nothing happens
				 * @throw
				 * @see void BaseEventManager::connect(const Listener & listener, const Slot::SlotID & slot, const Emitter & emitter, const Signal::SignalID & signal)
				 */
				virtual void connect(const Listener & listener, const Slot::SlotID & slot, const Emitter & emitter, const Signal::SignalID & signal) override;

				/**
				 * @fn void disconnect(const Listener & listener, const Slot::SlotID & slot, const Emitter & emitter, const Signal::SignalID & signal)
				 * @param[in] listener The owner of the slot.
				 * @param[in] slot The slot to disconnect.
				 * @param[in] emitter The owner of the signal.
				 * @param[in] signal The signal to disconnect.
				 * @brief Disconnect a signal and a slot.
				 * If they are not connected, nothing happens.
				 * @throw
				 * @see void BaseEventManager::disconnect(const Listener & listener, const Slot::SlotID & slot, const Emitter & emitter, const Signal::SignalID & signal)
				 */
				virtual void disconnect(const Listener & listener, const Slot::SlotID & slot, const Emitter & emitter, const Signal::SignalID & signal) override;

				/**
				 * @fn void disconnectAll(const Listener & listener, const Slot::SlotID & slot)
				 * @param[in] listener The owner of the slot.
				 * @param[in] slot The slot to disconnect.
				 * @brief Disconnect the slot from all signals connected.
				 * If it is not connected, nothing happens.
				 * @throw
				 * @see void BaseEventManager::disconnectAll(const Listener & listener, const Slot::SlotID & slot)
				 */
				virtual void disconnectAll(const Listener & listener, const Slot::SlotID & slot) override;

				/**
				 * @fn void disconnectAll(const Emitter & emitter, const Signal::SignalID & signal)
				 * @param[in] emitter The owner of the signal.
				 * @param[in] signal The signal to disconnect.
				 * @brief Disconnect the signal from all slots connected.
				 * If it is not connected, nothing happens.
				 * @throw
				 * @see void BaseEventManager::disconnectAll(const Emitter & emitter, const Signal::SignalID & signal)
				 */
				virtual void disconnectAll(const Emitter & emitter, const Signal::SignalID & signal) override;

				/**
				 * @fn void broadcast(const Emitter & emitter, const Signal::SignalID & signal)
				 * @param[in] emitter The owner of the signal.
				 * @param[in] signal The signal to broadcast.
				 * @brief Broadcast a signal to all slots connected, to trigger them.
				 * @throw
				 * @see void broadcast(const Emitter & emitter, const Signal::SignalID & signal)
				 */
				virtual void broadcast(const Emitter & emitter, const Signal::SignalID & signal) override;

				/**
				 * @fn void clear()
				 * @brief Clear the entire manager, and erase all slots, signals, and connections.
				 * @throw
				 * @see void clear()
				 */
				virtual void clear() override;

			private:
				/**
				 * @fn Slot::GlobalSlotID getSlotID()
				 * @return A slot id available.
				 * @brief Generate a new slot id.
				 * @throw
				 * @remark Maybe renaming that method name which is not clear at all.
				 */
				inline Slot::GlobalSlotID getSlotID();

				/**
				 * @fn Signal::GlobalSignalID getSignalID()
				 * @return A signal id available.
				 * @brief Generate a new signal id.
				 * @throw
				 * @remark Maybe renaming that method name which is not clear at all.
				 */
				inline Signal::GlobalSignalID getSignalID();

				/**
				 * @property _signals
				 * @brief The list of signals registered.
				 */
				std::vector<Signal> _signals;

				/**
				 * @property _slots
				 * @brief The list of slots registered.
				 */
				std::vector<Slot> _slots;

				/**
				 * @property _connections
				 * @brief The list of connections registered.
				 */
				std::vector<Connection> _connections;

				/**
				 * @property _signalsNotReady
				 * @brief The list of signals that need to be initialized.
				 */
				std::vector<Signal> _signalsNotReady;

				/**
				 * @property _slotsNotReady
				 * @brief The list of slots that need to be initialized.
				 */
				std::vector<Slot> _slotsNotReady;

				/**
				 * @property _connectionsNotReady
				 * @brief The list of connections that need to be initialized.
				 */
				std::vector<Connection> _connectionsNotReady;

				/**
				 * @property _signalsAvailable
				 * @brief To generate the next available signal id.
				 */
				UniqueID _signalsAvailable;

				/**
				 * @property _slotsAvailable
				 * @brief To generate the next available slot id.
				 */
				UniqueID _slotsAvailable;
			};
		} // namespace event
	} // namespace core
} // namespace ece

#include "core/event/event_manager.inl"

#endif // EVENT_MANAGER_HPP
