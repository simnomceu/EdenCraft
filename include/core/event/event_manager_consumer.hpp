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


#ifndef EVENT_MANAGER_CONSUMER_HPP
#define EVENT_MANAGER_CONSUMER_HPP

#include "core/event/event_manager.hpp"
#include "core/event/event_service.hpp"

namespace ece
{
	/**
	 * @class EventManagerConsumer
	 * @brief A pass to access the event manager service.
	 * @remark See how it is really used, and refactoring it according to that use.
	 */
	class EventManagerConsumer final
	{
	public:
		/**
		 * @fn EventManagerConsumer()
		 * @brief Default constructor.
		 * @throw
		 */
		inline EventManagerConsumer();

		/**
		 * @fn EventManagerConsumer(const EventManagerConsumer & copy) noexcept
		 * @param[in] copy The consumer to copy from.
		 * @brief Default copy constructor.
		 * @throw noexcept
		 */
		EventManagerConsumer(const EventManagerConsumer & copy) noexcept = default;

		/** 
		 * @fn EventManagerConsumer(EventManagerConsumer && move) noexcept 
		 * @param[in] move The consumer to move.
		 * @brief Default move constructor.
		 * @throw noexcept
		 */
		EventManagerConsumer(EventManagerConsumer && move) noexcept = default;

		/**
		 * @fn ~EventManagerConsumer() noexcept 
		 * @brief Default destructor.
		 * @throw noexcept
		 */
		~EventManagerConsumer() noexcept = default;

		/**
		 * @fn EventManagerConsumer & operator=(const EventManagerConsumer & copy) noexcept
		 * @param[in] copy The consumer to copy from.
		 * @return The consumer copied.
		 * @brief Default copy assignment operator.
		 * @throw noexcept
		 */
		EventManagerConsumer & operator=(const EventManagerConsumer & copy) noexcept = default;

		/**
		 * @fn EventManagerConsumer & operator=(EventManagerConsumer && move) noexcept 
		 * @param[in] move The consumer to move.
		 * @return The consumer moved.
		 * @brief Default move assignment operator.
		 * @throw noexcept
		 */
		EventManagerConsumer & operator=(EventManagerConsumer && move) noexcept = default;

		/**
		 * @fn const std::shared_ptr<BaseEventManager> consume()
		 * @return The current event manager service provide.
		 * @brief Consume the service provided.
		 * @throw
		 */
		const std::shared_ptr<BaseEventManager> consume();
	
	private:
		/**
		 * @property _eventManager
		 * @brief The event manager consumed.
		 */
		std::weak_ptr<BaseEventManager> _eventManager;
	};
}

#include "core/event/event_manager_consumer.inl"

#endif // EVENT_MANAGER_CONSUMER_HPP
