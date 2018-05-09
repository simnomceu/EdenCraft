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

#ifndef SLOT_HPP
#define SLOT_HPP

#include <functional>

#include "core/event/signal.hpp"

namespace ece
{
	namespace core
	{
		namespace event
		{
			class Emitter;

			/**
			 * @class Slot
			 * @brief
			 */
			class Slot final
			{
			public:
				/**
				 * @typedef SlotID
				 * @brief Id to handle the slot, relating to its owner.
				 */
				using SlotID = unsigned int;

				/**
				 * @typedef GlobalSlotID
				 * @brief Global id of the slot.
				 */
				using GlobalSlotID = unsigned int;

				/**
				 * @typedef Handle
				 * @brief The action of the slot.
				 */
				using Handle = std::function<void(const Emitter & emitter, const Signal::SignalID signal)>;

				static const Slot::GlobalSlotID INVALID_SLOT = 0;

				Slot() = delete;

				/**
				 * @fn Slot(const GlobalSlotID & id, const Handle & handle)
				 * @param[in] id The global id of the slot.
				 * @param[in] handle The action of the slot.
				 * @brief Default constructor.
				 * @throw
				 */
				inline Slot(const GlobalSlotID & id, const Handle & handle);

				/**
				 * @fn Slot(const Slot & copy)
				 * @param[in] copy The slot to copy from.
				 * @brief Default copy constructor.
				 * @throw
				 */
				Slot(const Slot & copy) = default;

				/**
				 * @fn Slot(Slot && move)
				 * @param[in] move The slot to move.
				 * @brief Default move constructor.
				 * @throw
				 */
				Slot(Slot && move) = default;

				/**
				 * @fn ~Slot() noexcept
				 * @brief Default destructor.
				 * @throw noexcept
				 */
				~Slot() noexcept = default;

				/**
				 * @fn Slot & operator=(const Slot & copy)
				 * @param[in] copy The slot to copy from.
				 * @return The slot copied.
				 * @brief Default copy assignment operator.
				 * @throw
				 */
				Slot & operator=(const Slot & copy) = default;

				/**
				 * @fn Slot & operator=(Slot && move)
				 * @param[in] move The slot to move.
				 * @return The slot moved.
				 * @brief Default move assignment operator.
				 * @throw
				 */
				Slot & operator=(Slot && move) = default;

				/**
				 * @fn void trigger(const Emitter & emitter, const Signal::SignalID & signal)
				 * @param[in] emitter The emitter of the signal.
				 * @param[in] signal The signal which trigger the slot.
				 * @brief Trigger the slot.
				 * @throw
				 */
				inline void trigger(const Emitter & emitter, const Signal::SignalID & signal);

				/**
				 * @fn const GlobalSlotID & getId() const
				 * @return The global id of the slot.
				 * @brief Get the global id of the slot.
				 * @throw
				 */
				inline const GlobalSlotID & getId() const;

				/**
				 * @fn bool isDirty() const
				 * @return True if the slot should be destroyed, else false.
				 * @brief Check if the slot is dirt or not.
				 * @throw
				 */
				inline bool isDirty() const;

				/**
				 * @fn void setDirty(const bool dirty)
				 * @param[in] dirty The new value of the tag.
				 * @brief Modify the dirty tag of the slot.
				 * @throw
				 */
				inline void setDirty(const bool dirty);

			private:
				/**
				 * @property _id
				 * @brief The global id of the slot.
				 */
				GlobalSlotID _id;

				/**
				 * @property _handle
				 * @brief The action of the slot.
				 */
				Handle _handle;

				/**
				 * @property _dirty
				 * @brief The dirty tag of the slot. If true, the slot need to be destroyed.
				 */
				bool _dirty;
			};
		} // namespace event
	} // namespace core
} // namespace ece

#include "core/event/slot.inl"

#endif // SLOT_HPP
