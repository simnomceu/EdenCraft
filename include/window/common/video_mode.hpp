/*
	
	oooooooooooo       .o8                          .oooooo.                       .o88o.     .   
	`888'     `8      "888                         d8P'  `Y8b                      888 `"   .o8   
	 888          .oooo888   .ooooo.  ooo. .oo.   888          oooo d8b  .oooo.   o888oo  .o888oo 
	 888oooo8    d88' `888  d88' `88b `888P"Y88b  888          `888""8P `P  )88b   888      888   
	 888    "    888   888  888ooo888  888   888  888           888      .oP"888   888      888   
	 888       o 888   888  888    .o  888   888  `88b    ooo   888     d8(  888   888      888 . 
	o888ooooood8 `Y8bod88P" `Y8bod8P' o888o o888o  `Y8bood8P'  d888b    `Y888""8o o888o     "888" 

															oooooo   oooooo     oooo  o8o                    .o8                             
															 `888.    `888.     .8'   `"'                   "888                             
															  `888.   .8888.   .8'   oooo  ooo. .oo.    .oooo888   .ooooo.  oooo oooo    ooo 
															   `888  .8'`888. .8'    `888  `888P"Y88b  d88' `888  d88' `88b  `88. `88.  .8'  
																`888.8'  `888.8'      888   888   888  888   888  888   888   `88..]88..8'   
																 `888'    `888'       888   888   888  888   888  888   888    `888'`888'    
																  `8'      `8'       o888o o888o o888o `Y8bod88P" `Y8bod8P'     `8'  `8'    


				This file is part of EdenCraft Engine - Window module.
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

#ifndef VIDEO_MODE_HPP
#define VIDEO_MODE_HPP

#include "window/config.hpp"

namespace ece
{
	namespace window
	{
		namespace common
		{
			/**
			 * @class VideoMode
			 * @brief Store all the parameters of the video mode for a window.
			 * Store all the parameters of the video mode for a window. It is used for read and write operation.
			 */
			class ECE_WINDOW_API VideoMode
			{
			public:
				/**
				 * @fn constexpr VideoMode()
				 * @brief Default constructor.
				 * @throw noexcept
				 */
				inline constexpr VideoMode() noexcept;

				/**
				 * @fn VideoMode(const VideoMode & copy) noexcept
				 * @param[in] copy The video mode to copy from.
				 * @brief Default copy constructor.
				 * @throw noexcept
				 */
				VideoMode(const VideoMode & copy) noexcept = default;

				/**
				 * @fn VideoMode(VideoMode && copy) noexcept
				 * @param[in] move The video mode to move.
				 * @brief Default move constructor.
				 * @throw noexcept
				 */
				VideoMode(VideoMode && move) noexcept = default;

				/**
				 * @fn ~VideoMode()
				 * @brief Default destructor.
				 * @throw noexcept
				 */
				inline ~VideoMode() noexcept;

				/**
				 * @fn VideoMode & operator=(const VideoMode & copy) noexcept
				 * @param[in] copy The video mode to copy from.
				 * @return The video mode copied.
				 * @brief Default copy assignment operator.
				 * @throw noexcept
				 */
				VideoMode & operator=(const VideoMode & copy) noexcept = default;

				/**
				 * @fn VideoMode & operator=(VideoMode && move) noexcept
				 * @param[in] move The video mode to move.
				 * @return The video mode moved.
				 * @brief Default move assignment operator.
				 * @throw noexcept
				 */
				VideoMode & operator=(VideoMode && move) noexcept = default;

				/**
				 * @fn bool operator==(const VideoMode & rightOperand) const
				 * @param[in] rightoperand The video mode to compare to.
				 * @return True, if both video modes are equal, false else.
				 * @brief Compare two video modes for equality.
				 * @throw
				 */
				bool operator==(const VideoMode & rightOperand) const;

				/**
				 * @fn bool operator!=(const VideoMode & rightOperand) const
				 * @param[in] rightoperand The video mode to compare to.
				 * @return True, if both video modes are not equal, false else.
				 * @brief Compare two video modes for non-equality.
				 * @throw
				 */
				inline bool operator!=(const VideoMode & rightOperand) const;

				/**
				 * @fn void setRefreshRate(const unsigned short int refreshRate)
				 * @param[in] refreshRate The rate of refreshing to set.
				 * @brief Set the frame rate limit.
				 * @throw
				 */
				void setRefreshRate(const unsigned short int refreshRate);

				/**
				 * @fn unsigned short int getRefreshRate() const noexcept
				 * @return The current rate of refreshing.
				 * @brief Get the current rate of refreshing frames.
				 * @throw noexcept
				 */
				inline auto getRefreshRate() const noexcept;

				/**
				 * @fn bool hasChanged() const noexcept
				 * @return True if the video mode has changed, false lse.
				 * @brief Check if the video mode has changed or not since the last time it has been used.
				 * @throw noexcept
				 */
				inline auto hasChanged() const noexcept;

				/**
				 * @fn void applyChanges() noexcept
				 * @brief Apply the changes in the video mode.
				 * @throw noexcept
				 */
				inline void applyChanges() noexcept;

			private:
				/**
				 * @property _refreshRate
				 * @brief The rate of refreshing for each frames.
				 */
				unsigned short int _refreshRate;

				/**
				 * @property _changed
				 * @brief  Tag to indicate that the video mode has changed without being updated.
				 */
				bool _changed;
			};
		} // namespace common
	} // namespace window
} // namespace ece

#include "window/common/video_mode.inl"

#endif // VIDEO_MODE_HPP
