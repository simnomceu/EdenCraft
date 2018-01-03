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
 * @file utility/time/update_per_second.hpp
 * @author IsilinBN (casa2pir@hotmail.fr)
 * @date January, 3rd 2018
 * @copyright ----------
 * @brief Define an UPS counter.
 **/

#ifndef UPDATE_PER_SECOND_HPP
#define UPDATE_PER_SECOND_HPP

#include "utility/time/chrono.hpp"

namespace ece
{
	/**
	 * @class UpdatePerSecond
	 * @brief UPS counter.
	 */
	class UpdatePerSecond
	{
	public:
		UpdatePerSecond() = delete;

		/**
		 * @fn UpdatePerSecond(const int UPS)
		 * @param[in] UPS
		 * @brief 
		 * @throw
		 */
		inline UpdatePerSecond(const int UPS);

		/**
		 * @fn UpdatePerSecond(const UpdatePerSecond & copy) noexcept
		 * @param[in] copy The counter to copy from.
		 * @brief Default copy constructor.
		 * @throw noexcept
		 */
		UpdatePerSecond(const UpdatePerSecond & copy) noexcept = default;

		/**
		 * @fn UpdatePerSecond(UpdatePerSecond && move) noexcept
		 * @param[in] move The counter to move.
		 * @brief Default move constructor.
		 * @throw noexcept
		 */
		UpdatePerSecond(UpdatePerSecond && move) noexcept = default;

		/**
		 * @fn ~UpdatePerSecond() noexcept
		 * @brief Default destructor.
		 * @throw noexcept
		 */
		~UpdatePerSecond() noexcept = default;

		/**
		 * @fn UpdatePerSecond & operator=(const UpdatePerSecond & copy) noexcept 
		 * @param[in] copy The counter to copy from.
		 * @return The counter copied.
		 * @brief Default copy assignment operator.
		 * @throw noexcept
		 */
		UpdatePerSecond & operator=(const UpdatePerSecond & copy) noexcept = default;
		
		/**
		 * @fn UpdatePerSecond & operator=(UpdatePerSecond && move) noexcept
		 * @param[in] move The counter to move.
		 * @return The counter moved.
		 * @brief Default move assignment operator.
		 * @throw noexcept
		 */
		UpdatePerSecond & operator=(UpdatePerSecond && move) noexcept = default;

		/**
		 * @fn bool isReadyToUpdate()
		 * @return True if The UPS limit is reach, false else.
		 * @brief Indicates if the counter has reached the limit or not.
		 * @throw
		 */
		bool isReadyToUpdate();

		/**
		 * @fn int getLimit() const noexcept
		 * @return The UPS limit set.
		 * @brief Get the current limit set.
		 * @throw noexcept.
		 */
		inline int getLimit() const noexcept;

		/**
		 * @fn double getUPS() const noexcept
		 * @return The current UPS.
		 * @brief Get the current UPS.
		 * @throw noexcept.
		 */
		inline double getUPS() const noexcept;

		/**
		 * @fn void setUPS(const int limit)
		 * @param[in] limit The UPS limit to set.
		 * @brief Set the UPS limit.
		 * @throw
		 */
		void setUPS(const int limit);

	private:
		/**
		 * @property chrono
		 * @brief Chrono used to measure the elapsed time between two frames.
		 */
		Chrono chrono;

		/**
		 * @property rate
		 * @brief The framerate of the counter.
		 */
		float rate;

		/**
		 * @property nbFrames
		 * @brief The number of frames since the counter started.
		 */
		long int nbFrames;

		/**
		 * @property average
		 * @fn The average UPS computed.
		 */
		double average;
	};

}

#include "utility/time/update_per_second.inl"

#endif // UPDATE_PER_SECOND_HPP