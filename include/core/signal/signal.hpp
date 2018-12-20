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

#ifndef SIGNAL_HPP
#define SIGNAL_HPP

#include "core/config.hpp"
#include "core/signal/signal_implementation.hpp"

namespace ece
{
	namespace core
	{
		namespace signal
		{
			/**
			 * @class Signal
			 * @brief
			 */
			template <class... Args>
			class ECE_CORE_API Signal
			{
			public:
				/**
				 * @fn Signal() noexcept
				 * @brief Default constructor.
				 * @throw noexcept
				 */
				Signal() noexcept;

				/**
				 * @fn Signal(const Signal & copy) noexcept
				 * @param[in] copy The Signal to copy from.
				 * @brief Default copy constructor.
				 * @throw noexcept
				 */
				Signal(const Signal & copy) noexcept = default;

				/**
				 * @fn Signal(Signal && move) noexcept
				 * @param[in] move The Signal to move.
				 * @brief Default move constructor.
				 * @throw noexcept
				 */
				Signal(Signal && move) noexcept = default;

				/**
				 * @fn ~Signal() noexcept
				 * @brief Default destructor.
				 * @throw noexcept
				 */
				~Signal() noexcept = default;

				/**
				 * @fn Signal & operator=(const Signal & copy) noexcept
				 * @param[in] copy The Signal to copy from.
				 * @return The Signal copied.
				 * @brief Default copy assignment operator.
				 * @throw noexcept
				 */
				Signal & operator=(const Signal & copy) noexcept = default;

				/**
				 * @fn Signal & operator=(Signal && move) noexcept
				 * @param[in] move The Signal to move.
				 * @return The Signal moved.
				 * @brief Default move assignment operator.
				 * @throw noexcept
				 */
				Signal & operator=(Signal && move) noexcept = default;

				auto connect(const std::function<void(Args...)> & callback);
				auto connect(std::function<void(Args...)> && callback);
				template <class T> auto connect(T & object, void (T::*method)(Args... args));
				template <class T> auto connect(std::weak_ptr<T> & object, void (T::*method)(Args... args));
				template <class T> auto connect(const T & object, void (T::*method)(Args... args) const);
				template <class T> auto connect(const std::weak_ptr<T> & object, void (T::*method)(Args... args) const);

				inline void disconnect(const std::shared_ptr<Slot<Args...>> & slot);

				inline void disconnectAll();

				inline void operator()(Args... args);

			private:
				std::shared_ptr<SignalImplementation<Args...>> _impl;
			};
		} // namespace signal
	} // namespace core
} // namespace ece

#include "core/signal/signal.inl"

#endif // SIGNAL_HPP