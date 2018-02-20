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

#ifndef LIFECYCLE_HPP
#define LIFECYCLE_HPP

#include "core/event/emitter.hpp"
#include "core/event/signal.hpp"

namespace ece
{
	/**
	 * @class Lifecycle
	 * @extends Emitter
	 * @brief Lifecycle of an application.
	 * @remark Need to be refactored as it seems to have renderer dependencies that it shouldn't.
	 */
	class Lifecycle: public Emitter
	{
	public:
		const Signal::SignalID PRE_INIT = 0;
		const Signal::SignalID POST_INIT = 1;
		const Signal::SignalID PRE_PROCESS = 2;
		const Signal::SignalID PRE_UPDATE = 3;
		const Signal::SignalID POST_UPDATE = 4;
		const Signal::SignalID POST_RENDER = 5;
		const Signal::SignalID PRE_TERMINATE = 6;
		const Signal::SignalID POST_TERMINATE = 7;

		/**
		 * @fn Lifecycle()
		 * @brief Default constructor.
		 * @throw
		 */
		Lifecycle();

		/**
		 * @fn Lifecycle(const Lifecycle & copy)
		 * @param[in] copy The lifecycle to copy from.
		 * @brief Default copy constructor.
		 * @throw
		 */
		Lifecycle(const Lifecycle & copy) = default;

		/**
		 * @fn Lifecycle(Lifecycle && move)
		 * @param[in] move The lifecycle to move.
		 * @brief Default move constructor.
		 * @throw
		 */
		Lifecycle(Lifecycle && move) = default;

		/**
		 * @fn ~Lifecycle() noexcept
		 * @brief Default destructor.
		 * @throw noexcept
		 */
		~Lifecycle() noexcept = default;

		/**
		 * @fn Lifecycle & operator=(const Lifecycle & copy) noexcept
		 * @param[in] copy The lifecycle to copy from.
		 * @return The lifecycle copied.
		 * @throw noexcept
		 */
		Lifecycle & operator=(const Lifecycle & copy) noexcept = default;

		/**
		 * @fn Lifecycle & operator=(Lifecycle && move) noexcept
		 * @param[in] move The lifecycle to move.
		 * @return The lifecycle moved.
		 * @throw
		 */
		Lifecycle & operator=(Lifecycle && move) noexcept = default;

		/**
		 * @fn void preInit()
		 * @brief Signal triggered before the initialization of the application.
		 */
		inline void preInit();

		/**
		 * @fn void postInit()
		 * @brief Signal triggered after the initialization of the application.
		 */
		inline void postInit();

		/**
		 * @fn void preProcess()
		 * @brief Signal triggered before the events processing of the application.
		 */
		inline void preProcess();

		/**
		 * @fn void preUpdate()
		 * @brief Signal triggered before the logic update of the application.
		 */
		inline void preUpdate();

		/**
		 * @fn void postUpdate()
		 * @brief Signal triggered after the logic update of the application.
		 */
		inline void postUpdate();

		/**
		 * @fn void postRender()
		 * @brief Signal triggered before the initialization of the application.
		 */
		inline void postRender();

		/**
		 * @fn void preTerminate()
		 * @brief Signal triggered before the termination of the application.
		 */
		inline void preTerminate();

		/**
		 * @fn void postTerminate()
		 * @brief Signal triggered after the termination of the application.
		 */
		inline void postTerminate();

		/**
		 * @fn void onPreInit(const Listener & listener, const unsigned int slot)
		 * @param[in] listener The callback owner.
		 * @param[in] slot The callback to call.
		 * @brief Register a callback on pre-init event.
		 */
		inline void onPreInit(const Listener & listener, const unsigned int slot);

		/**
		 * @fn void onPostInit(const Listener & listener, const unsigned int slot)
		 * @param[in] listener The callback owner.
		 * @param[in] slot The callback to call.
		 * @brief Register a callback on post-init event.
		 */
		inline void onPostInit(const Listener & listener, const unsigned int slot);

		/**
		 * @fn void onPreProcess(const Listener & listener, const unsigned int slot)
		 * @param[in] listener The callback owner.
		 * @param[in] slot The callback to call.
		 * @brief Register a callback on pre-process event.
		 */
		inline void onPreProcess(const Listener & listener, const unsigned int slot);

		/**
		 * @fn void onPreUpdate(const Listener & listener, const unsigned int slot)
		 * @param[in] listener The callback owner.
		 * @param[in] slot The callback to call.
		 * @brief Register a callback on pre-update event.
		 */
		inline void onPreUpdate(const Listener & listener, const unsigned int slot);

		/**
		 * @fn void onPostUpdate(const Listener & listener, const unsigned int slot)
		 * @param[in] listener The callback owner.
		 * @param[in] slot The callback to call.
		 * @brief Register a callback on post-update event.
		 */
		inline void onPostUpdate(const Listener & listener, const unsigned int slot);

		/**
		 * @fn void onPostRender(const Listener & listener, const unsigned int slot)
		 * @param[in] listener The callback owner.
		 * @param[in] slot The callback to call.
		 * @brief Register a callback on post-render event.
		 */
		inline void onPostRender(const Listener & listener, const unsigned int slot);

		/**
		 * @fn void onPreTerminate(const Listener & listener, const unsigned int slot)
		 * @param[in] listener The callback owner.
		 * @param[in] slot The callback to call.
		 * @brief Register a callback on pre-terminate event.
		 */
		inline void onPreTerminate(const Listener & listener, const unsigned int slot);

		/**
		 * @fn void onPostTerminate(const Listener & listener, const unsigned int slot)
		 * @param[in] listener The callback owner.
		 * @param[in] slot The callback to call.
		 * @brief Register a callback on post-terminate event.
		 */
		inline void onPostTerminate(const Listener & listener, const unsigned int slot);
	};
}

#include "core/application/lifecycle.inl"

#endif // LIFECYCLE_HPP
