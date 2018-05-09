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

#include "core/event/emitter.hpp"

namespace ece
{
	namespace window
	{
		namespace window_event
		{
			using core::event::Emitter;
			using core::event::Signal;

			/**
			 * @class EventHandler
			 * @extends Emitter
			 * @brief Manage input events.
			 * @remark Need to be refactored as it seems to be useless in this state.
			 */
			class EventHandler : public Emitter
			{
			public:
				const Signal::SignalID KEY_PRESSED = 0;
				const Signal::SignalID KEY_RELEASED = 1;
				const Signal::SignalID MOUSE_BUTTON_PRESSED = 2;
				const Signal::SignalID MOUSE_BUTTON_RELEASED = 3;
				const Signal::SignalID MOUSE_WHEEL_SCROLLED = 4;

				/**
				 * @fn EventHandler & getInstance()
				 * @return The unique instance of the handler
				 * @brief Get the unique instance of the handler.
				 * @throw
				 */
				static EventHandler & getInstance();

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

				/**
				 * void produceKeyEvent(const int key, const int scancode, const int action, const int mods)
				 * @param[in] key The keyboard keycode of the event.
				 * @param[in] scancode The keyboard keycode of the event for special keys.
				 * @param[in] action The action performed on the key (pressed, released, double tap, ...).
				 * @param[in] mods The keymode used (alt, ctrl, shift, ...).
				 * @brief Produce a keyboard key event.
				 * @throw
				 */
				void produceKeyEvent(const int key, const int scancode, const int action, const int mods);

				/**
				 * @fn void produceMouseButtonEvent(const int button, const int action, const int mods)
				 * @param[in] button The mouse button of the event.
				 * @param[in] action The action performed on the key (pressed, released, double tap, ...).
				 * @param[in] mods he keymode used (alt, ctrl, shift, ...).
				 * @brief Produce a mouse button event.
				 * @throw
				 */
				inline void produceMouseButtonEvent(const int button, const int action, const int mods);

			private:
				/**
				 * @fn EventHandler()
				 * @brief Default constructor.
				 * It is private to guarantee the singleton.
				 * @throw
				 */
				EventHandler();
			};
		} // namespace windpw_event
	} // namespace window
} // namespace ece

#include "window/window_event/event_handler.inl"

#endif // EVENT_HANDLER_HPP
