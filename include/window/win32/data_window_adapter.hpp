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

#ifndef DATA_WINDOW_ADAPTER_HPP
#define DATA_WINDOW_ADAPTER_HPP

#include "window/event.hpp"

#include <Windows.h>

namespace ece
{
	namespace window
	{
		namespace common
		{
			/**
			 * @struct DataWindowAdapter
			 * @brief Win32 implementaion of the window adapter.
			 */
			struct DataWindowAdapter
			{
				/**
				 * @fn DataWindowAdapter(HWND windowId)
				 * @param[in] windowId The handle of the window.
				 * @brief Default constructor.
				 * @throw
				 */
				inline DataWindowAdapter(HWND windowId) : windowId(windowId) {}

				/**
				* @fn DataWindowAdapter(const DataWindowAdapter & copy) noexcept
				* @param[in] copy The implementation to copy from.
				* @brief Default copy constructor.
				* @throw noexcept
				*/
				DataWindowAdapter(const DataWindowAdapter & copy) noexcept = default;

				/**
				* @fn DataWindowAdapter(DataWindowAdapter && move) noexcept
				* @param[in] copy The implementation to move.
				* @brief Default move constructor.
				* @throw noexcept
				*/
				DataWindowAdapter(DataWindowAdapter && move) noexcept = default;

				DataWindowAdapter & operator=(const DataWindowAdapter & copy) noexcept = default;

				/**
				 * @property _windowId
				 * @brief The handle of the window.
				 */
				HWND windowId;
			};

			/**
			 * @struct WindowMessage
			 * @brief Win32 implementation for a window message/notification, including input messages.
			 */
			struct WindowMessage
			{
				/**
				 * @property _windowId
				 * @brief The window concerned by the message.
				 */
				HWND windowId;

				/**
				 * @property _message
				 * @brief The content of the message.
				 */
				UINT message;

				/**
				 * @property _wParam
				 * @brief Some parameters of the message.
				 */
				WPARAM wParam;

				/**
				 * @property _lParam
				 * @brief Some extra parameters of the message.
				 */
				LPARAM lParam;
			};
		} // namespace common

		namespace win32
		{
			/**
			 * @var className
			 * @brief The name of the type of window to register to the win32 window system.
			 */
			static constexpr auto className = LPCWSTR{ L"ECE Window" };

			/**
			 * @fn void registerPattern()
			 * @brief Register a type of window to the win32 window system.
			 * @throw
			 */
			void registerPattern();

			/**
			 * @fn LRESULT CALLBACK processMessages(HWND windowId, UINT message, WPARAM wParam, LPARAM lParam)
			 * @param[in] windowId The window concerned by the message.
			 * @param[in] message The content of the message.
			 * @param[in] wParam Some parameters of the message.
			 * @param[in] lParam Some extra parameters of the message.
			 * @return If it has failed or not.
			 * @brief A win32 callback to process a messae handle from the system.
			 * @throw
			 */
			LRESULT CALLBACK processMessagesCallback(HWND windowId, UINT message, WPARAM wParam, LPARAM lParam);
		} // namespace win32
	} // namespace window
} // namespace ece

#endif // DATA_WINDOW_ADAPTER_HPP

