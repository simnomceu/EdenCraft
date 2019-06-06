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

#ifndef EVENT_HANDLER_HPP
#define EVENT_HANDLER_HPP

#include "window/pch.hpp"
#include "window/config.hpp"
#include "core/signal.hpp"
#include "window/event/input_event.hpp"

namespace ece
{
	namespace window
	{
		namespace common
		{
			class Window;
		}

		namespace event
		{
			using common::Window;

			/**
			 * @class EventHandler
			 * @extends Emitter
			 * @brief Manage input events.
			 * @remark Need to be refactored as it seems to be useless in this state.
			 */
			class ECE_WINDOW_API EventHandler
			{
			public:
				/**
				* @fn EventHandler()
				* @brief Default constructor.
				* It is private to guarantee the singleton.
				* @throw
				*/
				inline EventHandler(Window & owner);

				/**
				 * @fn EventHandler(const EventHandler & copy)
				 * @param[in] copy The handler to copy from.
				 * @brief Default copy constructor.
				 * @throw
				 */
				EventHandler(const EventHandler & copy) = default;

				/**
				 * @fn EventHandler(EventHandler && move)
				 * @param[in] move
				 * @brief Default move constructor.
				 * @throw
				 */
				EventHandler(EventHandler && move) = default;

				/**
				 * @fn ~EventHandler()
				 * @brief Default constructor.
				 * @throw noexcept
				 */
				inline ~EventHandler() noexcept = default;

				/**
				 * @fn EventHandler & operator=(const EventHandler & copy)
				 * @param[in] copy The handler to copy from.
				 * @return The handler copied.
				 * @brief Default copy assignment operator.
				 * @throw
				 */
				EventHandler & operator=(const EventHandler & copy) = default;

				/**
				 * @fn EventHandler & operator=(EventHandler && move) noexcept
				 * @param[in] move The handler to move.
				 * @return The handler moved.
				 * @brief Default move assignment operator.
				 * @throw noexcept
				 */
				EventHandler & operator=(EventHandler && move) noexcept = default;

				void process(const InputEvent & event);

				Signal<const InputEvent &, Window &> onKeyPressed;
				Signal<const InputEvent &, Window &> onKeyReleased;
				Signal<const InputEvent &, Window &> onMouseButtonPressed;
				Signal<const InputEvent &, Window &> onMouseButtonReleased;
				Signal<const InputEvent &, Window &> onMouseWheelScrolled;
				Signal<const InputEvent &, Window &> onMouseMoved;
				Signal<const InputEvent &, Window &> onCharWritten;

			private:
				Window & _owner;
			};
		} // namespace event
	} // namespace window
} // namespace ece

#include "window/event/event_handler.inl"

#endif // EVENT_HANDLER_HPP
