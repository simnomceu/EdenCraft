/*
	
	oooooooooooo       .o8                          .oooooo.                       .o88o.     .   
	`888'     `8      "888                         d8P'  `Y8b                      888 `"   .o8   
	 888          .oooo888   .ooooo.  ooo. .oo.   888          oooo d8b  .oooo.   o888oo  .o888oo 
	 888oooo8    d88' `888  d88' `88b `888P"Y88b  888          `888""8P `P  )88b   888      888   
	 888    "    888   888  888ooo888  888   888  888           888      .oP"888   888      888   
	 888       o 888   888  888    .o  888   888  `88b    ooo   888     d8(  888   888      888 . 
	o888ooooood8 `Y8bod88P" `Y8bod8P' o888o o888o  `Y8bood8P'  d888b    `Y888""8o o888o     "888" 

															ooooo     ooo     .    o8o  oooo   o8o      .
															`888'     `8'   .o8    `"'  `888   `"'    .o8
															 888       8  .o888oo oooo   888  oooo  .o888oo oooo    ooo
															 888       8    888   `888   888  `888    888    `88.  .8'
															 888       8    888    888   888   888    888     `88..8'
															 `88.    .8'    888 .  888   888   888    888 .    `888'
															   `YbodP'      "888" o888o o888o o888o   "888"     .8'
																											.o..P'
																											`Y8P'

				This file is part of EdenCraft Engine - Utility module.
				Copyright(C) 2017 Pierre Casati (@IsilinBN)

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

/**
 * @file utility/time/chrono.hpp
 * @author IsilinBN (casa2pir@hotmail.fr)
 * @date January, 3rd 2018
 * @copyright ----------
 * @brief Define a chrono.
 **/

#ifndef CHRONO_HPP
#define CHRONO_HPP

#include <chrono>

namespace ece
{
	/**
	 * @class Chrono
	 * @brief Define a chrono to measure durations.
	 */
	class Chrono
	{
	public:
		/**
		 * @fn constexpr Chrono()
		 * @brief Default constructor. Timer is initialized to 0-time.
		 * @throw
		 */
		inline constexpr Chrono();

		/**
		 * @fn Chrono(const Chrono & copy)
		 * @param[in] copy The chrono to copy from.
		 * @brief Default copy constructor.
		 * @throw noexcept
		 */
		Chrono(const Chrono & copy) noexcept = default;

		/**
		 * @fn Chrono(Chrono && move)
		 * @param[in] move The chrono to move.
		 * @brief Default move constructor.
		 * @throw noexcept
		 */
		Chrono(Chrono && move) noexcept = default;

		/**
		 * @fn ~Chrono()
		 * @brief Default destructor.
		 * @throw noexcept
		 */
		~Chrono() noexcept = default;

		/**
		 * @fn Chrono & operator=(const Chrono & copy)
		 * @param[in] copy The chrono to copy from.
		 * @return The chrono copied.
		 * @brief Default copy assignment operator.
		 * @throw noexcept
		 */
		Chrono & operator=(const Chrono & copy) noexcept = default;

		/**
		 * @fn Chrono & operator=(Chrono && move)
		 * @param[in] move The chrono to move.
		 * @return The chrono moved.
		 * @brief Default move assignment operator.
		 * @throw noexcept
		 */
		Chrono & operator=(Chrono && move) noexcept = default;
		
		/**
		 * @fn void start()
		 * @brief Start the chrono
		 * @throw
		 */
		inline void start();

		/**
		 * @fn int reset()
		 * @return The elapsed time since last chrono start.
		 * @brief Reset the chrono and get the elapsed time.
		 * @throw
		 */
		int reset();

		/**
		 * @fn int getElapsedTime() const
		 * @return The elapsed time since last chrono start.
		 * @brief Get the elapsed time. Chrono is not stopped or reset.
		 * @throw
		 */
		int getElapsedTime() const;

	private:
		/**
		 * @property begin
		 * @brief The time point when chrono has started.
		 */
		std::chrono::time_point<std::chrono::system_clock> begin;
	};
}

#include "utility/time/chrono.inl"

#endif // CHRONO_HPP
