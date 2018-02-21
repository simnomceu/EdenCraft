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


#ifndef CONNECTION_HPP
#define CONNECTION_HPP

#include "core/event/signal.hpp"
#include "core/event/slot.hpp"

namespace ece
{
	/**
	 * @class Connection
	 * @brief A connection between a slot and a signal.
	 */
	class Connection final
	{
	public:
		Connection() = delete;

		/**
		 * @fn Connection(const Slot::GlobalSlotID slot, const Signal::GlobalSignalID signal) noexcept
		 * @param[in] slot The slot to connect to.
		 * @param[in] signal The signal to connect to.
		 * @brief Default constructor.
		 * @throw noexcept
		 */
		inline Connection(const Slot::GlobalSlotID slot, const Signal::GlobalSignalID signal) noexcept;
		
		/**
		 * @fn Connection(const Connection & copy) noexcept
		 * @param[in] copy The connection to copy from.
		 * @brief Default copy constructor.
		 * @throw noexcept
		 */
		Connection(const Connection & copy) noexcept = default;

		/**
		 * @fn Connection(Connection && move) noexcept 
		 * @param[in] move The connection to move.
		 * @brief Default move constructor.
		 * @throw noexcept
		 */
		Connection(Connection && move) noexcept = default;

		/**
		 * @fn ~Connection() noexcept 
		 * @brief Default destructor.
		 * @throw noexcept
		 */
		~Connection() noexcept = default;

		/**
		 * @fn Connection & operator=(const Connection & copy) noexcept
		 * @param[in] copy The connection to copy from.
		 * @return The connection copied.
		 * @brief Default copy assignment operator.
		 * @throw noexcept
		 */
		Connection & operator=(const Connection & copy) noexcept = default;

		/**
		 * @fn Connection & operator=(Connection && move) noexcept 
		 * @param[in] move The connection to move.
		 * @return The connection moved.
		 * @brief Default move assignment operator.
		 * @throw noexcept
		 */
		Connection & operator=(Connection && move) noexcept = default;

		/**
		 * @fn bool operator==(const Connection & rightOperand)
		 * @param[in] rightOperand The connection to compare to.
		 * @return True, if both connections are equal, false else.
		 * @brief Check if both connections are equal or not.
		 * @throw
		 */
		inline bool operator==(const Connection & rightOperand);

		/**
		 * @fn const Slot::GlobalSlotID getSlot() const
		 * @return The connected slot.
		 * @brief Get the connected slot related to this connection.
		 * @throw
		 */
		inline const Slot::GlobalSlotID getSlot() const;

		/**
		 * @fn const Slot::GlobalSlotID getSignal() const
		 * @return The connected signal.
		 * @brief Get the connected signal related to this connection.
		 * @throw
		 */
		inline const Slot::GlobalSlotID getSignal() const;

		/**
		 * @fn void setDirty(const bool dirty)
		 * @param[in] dirty The new value of the tag.
		 * @brief Modify the dirty tag of the connection.
		 * @throw 
		 */
		inline void setDirty(const bool dirty);

		/**
		 * @fn const bool isDirty() const
		 * @return True if the connection should be destroyed, else false.
		 * @brief Check if the connection is dirt or not.
		 * @throw
		 */
		inline const bool isDirty() const;

	private:
		/**
		 * @property _slot
		 * @brief The connected slot, related to this connection.
		 */
		Slot::GlobalSlotID _slot;

		/**
		 * @property _signal
		 * @brief The connected signal, related to this connection.
		 */
		Signal::GlobalSignalID _signal;

		/**
		 * @property _dirty
		 * @brief The dirty tag of the connection. If true, the connection need to be destroyed.
		 */
		bool _dirty;
	};
}

#include "core/event/connection.inl"

#endif // CONNECTION_HPP
