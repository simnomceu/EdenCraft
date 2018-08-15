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

#ifndef BASE_WINDOW_ADAPTER_HPP
#define BASE_WINDOW_ADAPTER_HPP

#include "window/config.hpp"
#include "window/event/input_event.hpp"
#include "window/event/event_queue.hpp"
#include "utility/pattern/pimpl.hpp"

#include <memory>
#include <string>

namespace ece
{
	namespace window
	{
		namespace common
		{
			using utility::pattern::Pimpl;
			using utility::mathematics::IntVector2u;

			/**
			 * @struct DataWindowAdapter
			 * @brief Platform implementaion of the window adapter.
			 */
			struct DataWindowAdapter;

			/**
			 * @struct WindowMessage
			 * @brief Platform implementation for a window message/notification, including input messages.
			 */
			struct WindowMessage;

			/**
			 * @class BaseWindowAdapter
			 * @brief Base pattern for adapting window method to use the platform implementation.
			 */
			class ECE_WINDOW_API BaseWindowAdapter
			{
			public:
				/**
				 * @fn BaseWindowAdapter()
				 * @brief Default constructor.
				 * @throw
				 */
				BaseWindowAdapter();

				/**
				 * @fn BaseWindowAdapter(const BaseWindowAdapter & copy)
				 * @param[in] copy The adapter to copy from.
				 * @brief Default copy constructor.
				 * @throw
				 */
				BaseWindowAdapter(const BaseWindowAdapter & copy) = default;

				/**
				 * @fn BaseWindowAdapter(BaseWindowAdapter && move)
				 * @param[in] move The adapter to move.
				 * @brief Default move constructor.
				 * @throw
				 */
				BaseWindowAdapter(BaseWindowAdapter && move) = default;

				/**
				 * @fn ~BaseWindowAdapter() noexcept
				 * @brief Default destructor.
				 * @throw
				 */
				virtual ~BaseWindowAdapter() noexcept = 0;

				/**
				 * @fn BaseWindowAdapter & operator=(const BaseWindowAdapter & copy)
				 * @param[in] copy The adapter to copy from.
				 * @return The adapter copied.
				 * @brief Default copy assignment operator.
				 * throw
				 */
				BaseWindowAdapter & operator=(const BaseWindowAdapter & copy) = default;

				/**
				 * @fn BaseWindowAdapter & operator=(BaseWindowAdapter && move)
				 * @param[in] move The adapter to move.
				 * @return The adapter moved.
				 * @brief Default move assignment operator.
				 * @throw
				 */
				BaseWindowAdapter & operator=(BaseWindowAdapter && move) = default;

				/**
				 * @fn void createWindow()
				 * @brief Generate a window.
				 * @throw
				 * @see void BaseWindowAdapter::createWindow()
				 */
				virtual void createWindow() = 0;

				/**
				 * @fn void deleteWindow()
				 * @brief Delete a window.
				 * If that window does not exist, the behaviour is unknown.
				 * @throw
				 */
				virtual void deleteWindow() = 0;

				/**
				 * @fn bool isWindowCreated() const
				 * @return True if window exist, false else.
				 * @brief Check if the window is existing or not.
				 * @throw
				 */
				virtual bool isWindowCreated() const = 0;

				/**
				 * @fn void setTitle(const std::string & title)
				 * @param[in] title The title to set.
				 * @brief Set the window title.
				 * @throw
				 */
				virtual void setTitle(const std::string & title) = 0;

				/**
				 * @fn std::string getTitle() const
				 * @return The title of the window.
				 * @brief Get the window title.
				 * @throw
				 */
				virtual std::string getTitle() const = 0;

				/**
				 * @fn void setPosition(const IntVector2u & position)
				 * @param[in] position The position to set the window to.
				 * @brief Set the window to the position.
				 * throw
				 */
				virtual void setPosition(const IntVector2u & position) = 0;

				/**
				 * @fn IntVector2u getPosition() const
				 * @return The window position.
				 * @brief Get the position of the window.
				 * @throw
				 */
				virtual IntVector2u getPosition() const = 0;

				/**
				 * @fn IntVector2u getSize() const
				 * @return The window size.
				 * @brief Get the size of the window.
				 * @throw
				 */
				virtual IntVector2u getSize() const = 0;

				/**
				 * @fn void minimize()
				 * @brief Set the window to its minimum size.
				 * @throw
				 */
				virtual void minimize() = 0;

				/**
				 * @fn void maximize()
				 * @brief Set the window to its maximum size.
				 * @throw
				 */
				virtual void maximize() = 0;

				/**
				 * @fn void enableKeyRepeat(const bool enabled)
				 * @param[in] enabled Switch parameter to set.
				 * @brief Enable or disable the key repeating.
				 * @throw
				 */
				void enableKeyRepeat(const bool enabled);

				/**
				 * @fn void processEvent(const bool blocking)
				 * @param[in] blocking Block the thread until an event has been processed.
				 * @brief Process a window event.
				 * @throw
				 */
				virtual void processEvent(const bool blocking) = 0;

				/**
				 * @fn bool hasEvents() const
				 * @return True, if there is new events in the queue, false else.
				 * @brief Check if there is new events to process or not.
				 * @throw
				 */
				bool hasEvents() const;

				/**
				 * @fn InputEvent popEvent()
				 * @return The first event of the queue.
				 * @brief Get the first event of the queue to process.
				 * It gets an empty event if the queue is empty.
				 * @throw
				 */
				InputEvent popEvent();

				/**
				 * @fn Pimpl<DataWindowAdapter> & getImpl()
				 * @return The platform implementation of the window.
				 * @brief Get the platform implementation of the window.
				 * @throw
				 */
				virtual Pimpl<DataWindowAdapter> & getImpl() = 0;

			protected:
				/**
				 * @fn void pushEvent(const InputEvent & nextEvent)
				 * @param[in] nextEvent The new event to add.
				 * @brief Add a new event to the end of the queue.
				 * @throw
				 */
				void pushEvent(const InputEvent & nextEvent);

				/**
				 * @fn InputEvent & lastEvent()
				 * @return The last event of the queue.
				 * @brief Get the last event of the queue.
				 * It is not removed from the queue.
				 * @throw
				 */
				InputEvent & lastEvent();

				/**
				 * @property _keyRepeat
				 * @brief Switch parameter to enable or disable key repeating.
				 */
				bool _keyRepeat;

			private:
				/**
				 * @property _eventQueue
				 * @brief The queue of events produced by the window.
				 */
				EventQueue _eventQueue;
			};
		} // namespace common
	} // namespace window
} // namespace ece

#endif // BASE_WINDOW_ADAPTER_HPP
