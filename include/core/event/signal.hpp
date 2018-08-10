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

#ifndef SERVICE_SIGNAL_HPP
#define SERVICE_SIGNAL_HPP

#include "core/config.hpp"

namespace ece
{
	namespace core
	{
		namespace event
		{
			/**
			 * @class Signal
			 * @brief The signal is an event which can triggered action linked to.
			 */
			class ECE_CORE_API Signal final
			{
			public:
				/**
				 * @typedef SignalID
				 * @brief The id of the signal, relative to its owner.
				 */
				using SignalID = unsigned int;

				/**
				 * @typedef GlobalSignalID
				 * @brief The global id of the signal.
				 */
				using GlobalSignalID = unsigned int;

				static const Signal::GlobalSignalID INVALID_SIGNAL = 0;

				Signal() = delete;

				/**
				 * @fn Signal(const GlobalSignalID & id)
				 * @param[in] id The global id to use.
				 * @brief Build a signal with a specific global id.
				 */
				inline Signal(const GlobalSignalID & id);

				/**
				 * @fn Signal(const Signal & copy)
				 * @param[in] copy The signal to copy from.
				 * @brief Default copy constructor.
				 * @throw
				 */
				Signal(const Signal & copy) = default;

				/**
				 * @fn Signal(Signal && move)
				 * @param[in] move The signal to move.
				 * @brief Default move constructor.
				 */
				Signal(Signal && move) = default;

				/**
				 * @fn ~Signal()
				 * @brief Default destructor.
				 * @throw
				 */
				~Signal() = default;

				/**
				 * @fn Signal & operator=(const Signal & copy)
				 * @param[in] copy The signal to copy from.
				 * @return The signal copied.
				 * @brief Default copy assignment operator.
				 * @throw
				 */
				Signal & operator=(const Signal & copy) = default;

				/**
				 * @fn Signal & operator=(Signal && move)
				 * @param[in] move The signal to move.
				 * @return The signal moved.
				 * @brief Default move assignment operator.
				 * @throw
				 */
				Signal & operator=(Signal && move) = default;

				/**
				 * @fn const GlobalSignalID & getId() const
				 * @return The global id of the signal.
				 * @brief Get the global id of the signal.
				 * @throw
				 */
				inline const GlobalSignalID & getId() const;

				/**
				 * @fn bool isDirty() const
				 * @return True if the signal should be destroyed, else false.
				 * @brief Check if the signal is dirt or not.
				 * @throw
				 */
				inline bool isDirty() const;

				/**
				 * @fn void setDirty(const bool dirty)
				 * @param[in] dirty The new value of the tag.
				 * @brief Modify the dirty tag of the signal.
				 * @throw
				 */
				inline void setDirty(const bool dirty);

			private:
				/**
				 * @property _id
				 * @brief The global id of the signal.
				 */
				GlobalSignalID _id;

				/**
				 * @property _dirty
				 * @brief The dirty tag of the signal. If true, the signal need to be destroyed.
				 */
				bool _dirty;
			};
		} // namespace event
	} // namespace core
} // namespace ece

#include "core/event/signal.inl"

#endif // SERVICE_SIGNAL_HPP
