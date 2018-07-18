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

#ifndef EVENT_QUEUE_HPP
#define EVENT_QUEUE_HPP

#include "window/config.hpp"
#include "window/window_event/input_event.hpp"

#include <queue>

namespace ece
{
	namespace window
	{
		namespace common
		{
			using window_event::InputEvent;

			/**
			 * @class EventQueue
			 * @extends std::queue<InputEvent>
			 * @brief To manage the events produced by window inputs.
			 * @see InputEvent
			 * @see http://en.cppreference.com/w/cpp/container/queue
			 */
			class ECE_WINDOW_API EventQueue : private std::queue<InputEvent>
			{
			public:
				/**
				 * @fn EventQueue()
				 * @brief Default constructor.
				 * @throw
				 */
				EventQueue() = default;

				/**
				 * @fn EventQueue(const EventQueue & copy)
				 * @param[in] copy The queue to copy from.
				 * @brief Default copy constructor.
				 * @throw
				 */
				EventQueue(const EventQueue & copy) = default;

				/**
				 * @fn EventQueue(EventQueue && move)
				 * @param[in] move The queue to move.
				 * @brief Default move constructor.
				 * @throw
				 */
				EventQueue(EventQueue && move) = default;

				/**
				 * @fn ~EventQueue() noexcept
				 * @brief Default destructor.
				 * @throw noexcept
				 */
				~EventQueue() noexcept = default;

				/**
				 * @fn EventQueue & operator=(const EventQueue & copy)
				 * @param[in] copy The queue to copy from.
				 * @return The queue copied.
				 * @brief Default copy assignment operator.
				 * @throw
				 */
				EventQueue & operator=(const EventQueue & copy) = default;

				/**
				 * @fn EventQueue & operator=(EventQueue && move) noexcept
				 * @param[in] move The queue to move.
				 * @return The queue moved.
				 * @brief Default move assignment operator.
				 * @throw
				 */
				EventQueue & operator=(EventQueue && move) noexcept = default;

				/**
				 * @see http://en.cppreference.com/w/cpp/container/queue/push
				 */
				using std::queue<InputEvent>::push;

				/**
				* @see http://en.cppreference.com/w/cpp/container/queue/pop
				*/
				using std::queue<InputEvent>::pop;

				/**
				* @see http://en.cppreference.com/w/cpp/container/queue/empty
				*/
				using std::queue<InputEvent>::empty;

				/**
				* @see http://en.cppreference.com/w/cpp/container/queue/front
				*/
				using std::queue<InputEvent>::front;

				/**
				* @see http://en.cppreference.com/w/cpp/container/queue/back
				*/
				using std::queue<InputEvent>::back;
			};
		} // namespace common
	} // namespace window
} // namespace ece

#endif // EVENT_QUEUE_HPP
