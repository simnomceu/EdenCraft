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

#ifndef FRAME_PER_SECOND_HPP
#define FRAME_PER_SECOND_HPP

#include "utility/time/update_per_second.hpp"

namespace ece
{
    namespace utility
    {
        namespace time
        {
        	/**
        	 * @class FramePerSecond
        	 * @extends UpdatePerSecond
        	 * @brief FPS counter.
        	 */
        	class FramePerSecond : private UpdatePerSecond
        	{
        	public:
        		/**
        		 * @enum FPSrate
        		 * @brief The FPS rate limit.
        		 * @remark Is it useful ?
        		 */
        		enum FPSrate : int
        		{
        			FRAME_30 = 30,
        			FRAME_60 = 60,
        			FRAME_120 = 120
        		};

        		FramePerSecond() = delete;

        		/**
        		 * @fn FramePerSecond(FPSrate rate = FRAME_60)
        		 * @param[in] rate The framerate limit to set.
        		 * @brief Default constructor.
        		 * @throw
        		 */
        		inline FramePerSecond(FPSrate rate = FRAME_60);

        		/**
        		 * @FramePerSecond(const FramePerSecond & copy) noexcept
        		 * @param[in] copy The counter to copy from.
        		 * @brief Default copy constructor.
        		 * @throw noexcept
        		 */
        		FramePerSecond(const FramePerSecond & copy) noexcept = default;

        		/**
        		 * @FramePerSecond(FramePerSecond && move) noexcept
        		 * @param[in@ move The counter to move.
        		 * @brief Default move constructor.
        		 * @throw noexcept
        		 */
        		FramePerSecond(FramePerSecond && move) noexcept = default;

        		/**
        		 * @fn ~FramePerSecond() noexcept
        		 * @brief Default destructor.
        		 * @throw noexcept
        		 */
        		~FramePerSecond() noexcept = default;

        		/**
        		 * @fn FramePerSecond & operator=(const FramePerSecond & copy) noexcept
        		 * @param[in] copy The counter to copy from.
        		 * @return The counter copied.
        		 * @brief Default copy assignment operator.
        		 * @throw noexcept
        		 */
        		FramePerSecond & operator=(const FramePerSecond & copy) noexcept = default;

        		/**
        		 * @fn FramePerSecond & operator=(FramePerSecond && move) noexcept
        		 * @param[in] move The counter to move.
        		 * @return The counter moved.
        		 * @brief Default move assignment operator.
        		 * @throw noexcept
        		 */
        		FramePerSecond & operator=(FramePerSecond && move) noexcept = default;

        		/**
        		 * @fn double getFPS() const noexcept
        		 * @return The current FPS.
        		 * @brief Get the current FPS.
        		 * @throw noexcept
        		 */
        		inline double getFPS() const noexcept;

        		/**
        		 * @see UpdatePerSecond::isReadyToUpdate
        		 */
        		using UpdatePerSecond::isReadyToUpdate;
        	};
        } // namespace time
    } // namespace utility
} // namespace ece

#include "utility/time/frame_per_second.inl"

#endif // FRAME_PER_SECOND_HPP
