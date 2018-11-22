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

#include "core/config.hpp"
#include "utility/pattern.hpp"

#include <functional>

namespace ece
{
	namespace core
	{
		namespace signal
		{
			/**
			 * @class Slot
			 * @brief
			 */
			template <class ... Args>
			class ECE_CORE_API Slot: public Observer<Args...>
			{
			public:
				/**
				 * @fn constexpr Slot() noexcept
				 * @brief Default constructor.
				 * @throw noexcept
				 */
				Slot(const std::function<void(Args...)> & callback) noexcept;

				/**
				 * @fn Slot(const Slot & copy) noexcept
				 * @param[in] copy The Slot to copy from.
				 * @brief Default copy constructor.
				 * @throw noexcept
				 */
				Slot(const Slot & copy) noexcept = default;

				/**
				 * @fn Slot(Slot && move) noexcept
				 * @param[in] move The Slot to move.
				 * @brief Default move constructor.
				 * @throw noexcept
				 */
				Slot(Slot && move) noexcept = default;

				/**
				 * @fn ~Slot() noexcept
				 * @brief Default destructor.
				 * @throw noexcept
				 */
				~Slot() noexcept = default;

				/**
				 * @fn Slot & operator=(const Slot & copy) noexcept
				 * @param[in] copy The Slot to copy from.
				 * @return The Slot copied.
				 * @brief Default copy assignment operator.
				 * @throw noexcept
				 */
				Slot & operator=(const Slot & copy) noexcept = default;

				/**
				 * @fn Slot & operator=(Slot && move) noexcept
				 * @param[in] move The Slot to move.
				 * @return The Slot moved.
				 * @brief Default move assignment operator.
				 * @throw noexcept
				 */
				Slot & operator=(Slot && move) noexcept = default;

				virtual void notify(Args&&... args) override;

			protected:
				std::function<void(Args...)> _callback;
			};
		} // namespace signal
	} // namespace core
} // namespace ece

#include "core/signal/slot.inl"

#endif // SLOT_HPP