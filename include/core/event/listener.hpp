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
	namespace core
	{
		namespace event
		{
			class Emitter;

			/**
			 * @class Listener
			 * @brief A listener to manage slots.
			 */
			class Listener
			{
			public:
				/**
				 * @fn Listener()
				 * @brief Default constructor.
				 * @throw
				 */
				Listener() = default;

				/**
				 * @fn Listener(const Listener & copy)
				 * @param[in] copy The listener to copy from.
				 * @brief Default copy constructor.
				 * @throw
				 */
				Listener(const Listener & copy) = default;

				/**
				 * @fn Listener(Listener && move)
				 * @param[in] move The listener to move.
				 * @brief Default move constructor.
				 * @throw
				 */
				Listener(Listener && move) = default;

				inline virtual ~Listener() = 0;

				/**
				 * @fn Listener & operator=(const Listener & copy)
				 * @param[in] copy The listener to copy from.
				 * @return The listener copied.
				 * @brief Default copy assignment operator.
				 * @throw
				 */
				Listener & operator=(const Listener & copy) = default;

				/**
				 * @fn Listener & operator=(Listener && move) noexcept
				 * @param[in] move The listener to move.
				 * @return The listener moved.
				 * @brief Default move assignment operator.
				 * @throw
				 */
				Listener & operator=(Listener && move) noexcept = default;

				/**
				 * @fn void addSlot(const Slot::SlotID & slot, const Slot::Handle & handle)
				 * @param[in] slot The slot to regiser.
				 * @param[in] handle The action of the slot to register.
				 * @brief Register a local slot and generate its global id.
				 * @throw
				 */
				void addSlot(const Slot::SlotID & slot, const Slot::Handle & handle);

				/**
				 * @fn void removeSlot(const Slot::SlotID & slot)
				 * @param[in] slot The slot to remove.
				 * @brief Remove a slot.
				 * It will be tagged dirty, to be destroyed later.
				 * @throw
				 */
				void removeSlot(const Slot::SlotID & slot);

				/**
				 * @fn Slot::GlobalSlotID getSlotID(const Slot::SlotID & slot) const
				 * @param[in] slot The local id of the slot.
				 * @return The corresponding global id of the slot.
				 * @brief Get the global id of the slot.
				 * @throw
				 */
				Slot::GlobalSlotID getSlotID(const Slot::SlotID & slot) const;

				/**
				 * @fn void connect(const Slot::SlotID & slot, const Emitter & emitter, const Signal::SignalID & signal)
				 * @param[in] slot The slot to connect.
				 * @param[in] emitter The owner of the signal to connect.
				 * @param[in] signal The signal to connect.
				 * @brief Connect a slot to a signal from an emitter.
				 * If the connection already exists, nothing happen.
				 * @throw
				 */
				void connect(const Slot::SlotID & slot, const Emitter & emitter, const Signal::SignalID & signal);

				/**
				 * @fn void disconnect(const Slot::SlotID & slot, const Emitter & emitter, const Signal::SignalID & signal)
				 * @param[in] slot The slot to disconnect.
				 * @param[in] emitter The owner of the signal to disconnect.
				 * @param[in] signal The signal to disconnect.
				 * @brief Disconnect a slot from a signal.
				 * If the connection does not exist, nothing happen.
				 * @throw
				 */
				void disconnect(const Slot::SlotID & slot, const Emitter & emitter, const Signal::SignalID & signal);

				/**
				 * @fn void disconnectAll()
				 * @brief Disconnect all slots from any signal.
				 * @throw
				 */
				void disconnectAll();

				/**
				 * @fn void clear()
				 * @brief Disconnect and delete all slots of the listener.
				 * @throw
				 */
				void clear();

			private:
				/**
				 * @property _consumer
				 * @brief Pass to access the event manager.
				 */
				EventManagerConsumer _consumer;

				/**
				 * @property _slots
				 * @brief The list of slots of this listener.
				 */
				std::map<Slot::SlotID, Slot::GlobalSlotID> _slots;
			};
		} // namespace event
	} // namespace core
} // namespace core

#include "core/event/listener.inl"

#endif // LISTENER_HPP
