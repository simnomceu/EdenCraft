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


#ifndef EMITTER_HPP
#define EMITTER_HPP

#include "core/event/signal.hpp"
#include "core/event/event_manager_consumer.hpp"

#include <map>

namespace ece
{
	class Listener;

	/**
	 * @class Emitter
	 * @brief An emitter to manage signals.
	 */
	class Emitter
	{
	public:
		/**
		 * @fn Emitter()
		 * @brief Default constructor.
		 * @throw
		 */
		Emitter() = default;

		/** 
		 * @fn Emitter(const Emitter & copy)
		 * @param[in] copy The emitter to copy from.
		 * @brief Default copy constructor.
		 * @throw
		 */
		Emitter(const Emitter & copy) = default;

		/**
		 * @fn Emitter(Emitter && move) 
		 * @param[in] move The emitter to move.
		 * @brief Default move constructor.
		 * @throw
		 */
		Emitter(Emitter && move) = default;

		inline virtual ~Emitter() = 0;

		/**
		 * @fn Emitter & operator=(const Emitter & copy) 
		 * @param[in] copy The emitter to copy from.
		 * @return The emitter copied.
		 * @brief Default copy assignment operator.
		 * @throw
		 */
		Emitter & operator=(const Emitter & copy) = default;

		/**
		 * @fn Emitter & operator=(Emitter && move) noexcept 
		 * @param[in] move The emitter to move.
		 * @return The emitter moved.
		 * @brief Default move assignment operator.
		 */
		Emitter & operator=(Emitter && move) noexcept = default;
		

		/**
		 * @fn void addSignal(const Signal::SignalID signal)
		 * @param[in] signal The signal to regiser.
		 * @brief Register a local signal and generate its global id.
		 * @throw
		 */
		void addSignal(const Signal::SignalID signal);

		/**
		 * @fn void removeSignal(const Signal::SignalID signal)
		 * @param[in] signal The signal to remove.
		 * @brief Remove a signal.
		 * It will be tagged dirty, to be destroyed later.
		 * @throw
		 */
		void removeSignal(const Signal::SignalID signal);

		/**
		 * @fn void emit(const Signal::SignalID signal)
		 * @param[in] signal The signal to emit.
		 * @brief Broadcast the signal to all slots connected.
		 * @throw
		 */
		void emit(const Signal::SignalID signal);
		
		/**
		 * @fn const Signal::GlobalSignalID getSignal(const Signal::SignalID signal) const
		 * @param[in] signal The local id of the signal.
		 * @return The corresponding global id of the signal.
		 * @brief Get the global id of the signal.
		 * @throw
		 */
		const Signal::GlobalSignalID getSignal(const Signal::SignalID signal) const;

		/**
		 * @fn void clear()
		 * @brief Disconnect and delete all signals of the emiter.
		 * @throw
		 */
		void clear();

		/**
		 * @fn void connect(const Signal::SignalID signal, const Listener & listener, const Slot::SlotID slot)
		 * @param[in] signal The signal to connect.
		 * @param[in] listener The owner of the slot to connect.
		 * @param[in] slot The slot to connect.
		 * @brief Connect a signal to a slot from a listener.
		 * If the connection already exists, nothing happen.
		 * @throw
		 */
		void connect(const Signal::SignalID signal, const Listener & listener, const Slot::SlotID slot);

		/**
		 * @fn void disconnect(const Signal::SignalID signal, const Listener & listener, const Slot::SlotID slot)
		 * @param[in] signal The signal to disconnect.
		 * @param[in] listener The owner of the slot to disconnect.
		 * @param[in] slot The slot to disconnect.
		 * @brief Disconnect a signal from a slot.
		 * If the connection does not exist, nothing happen.
		 * @throw
		 */
		void disconnect(const Signal::SignalID signal, const Listener & listener, const Slot::SlotID slot);

		/**
		 * @fn void disconnectAll()
		 * @brief Disconnect all signals from any slot.
		 * @throw
		 */
		void disconnectAll();

	private:
		/**
		 * @property _consumer
		 * @brief Pass to access the event manager.
		 */
		EventManagerConsumer _consumer;

		/**
		 * @property _signals
		 * @brief The list of signals of this emitter.
		 */
		std::map<Signal::SignalID, Signal::GlobalSignalID> _signals;
	};
}

#include "core/event/emitter.inl"

#endif // EMITTER_HPP