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

#ifndef APPLICATION_HPP
#define APPLICATION_HPP

#include <memory>
#include <vector>

#include "core/argument/argument_analyzer.hpp"
#include "core/module/module_manager.hpp"
#include "core/event/emitter.hpp"
#include "core/application/lifecycle.hpp"

namespace ece
{
	/**
	 * @class Application
	 * @brief A general application to handle core concepts.
	 */
	class Application
	{
	public:
		/**
		 * @fn Application()
		 * @brief Default application.
		 * @throw
		 */
		Application();

		/**
		 * @fn Application(int argc, char * argv[])
		 * @param[in] argc The number of arguments passed to the program.
		 * @param[in] argv The list of arguments passed.
		 * @brief Build an application with an external communication of arguments throw the command-line.
		 * @throw
		 */
		Application(int argc, char * argv[]);

		Application(const Application & copy) = delete;
		Application(Application && move) = delete;

		/**
		 * @fn ~Application()
		 * @brief Default destructor.
		 * @throw
		 */
		inline ~Application();

		Application & operator=(const Application & copy) = delete;
		Application & operator=(Application && move) = delete;

		/**
		 * @fn void run()
		 * @brief Start the application.
		 * @throw
		 */
		void run();

		/**
		 * @fn void stop()
		 * @brief Stop the application.
		 * @throw
		 */
		inline void stop();

		/**
		 * @fn ArgumentAnalyzer & getArgumentAnalyzer()
		 * @return The argument analyzer of the application.
		 */
		inline ArgumentAnalyzer & getArgumentAnalyzer();

		/**
		 * @fn T & addModule(const ModuleMethodHandle<T> & init = ModuleMethod<T>::VOID, const ModuleMethodHandle<T> & update = ModuleMethod<T>::VOID, const ModuleMethodHandle<T> & terminate = ModuleMethod<T>::VOID)
		 * @tparam T The type of module.
		 * @param[in] init The hook to init the module.
		 * @param[in] update The hook to update the module.
		 * @param[in] terminate The hook to terminate the module.
		 * @brief Add a module to the application.
		 * @throw
		 */
		template <class T> inline T & addModule(const ModuleMethodHandle<T> & init = ModuleMethod<T>::VOID, const ModuleMethodHandle<T> & update = ModuleMethod<T>::VOID, const ModuleMethodHandle<T> & terminate = ModuleMethod<T>::VOID);

		/**
		 * @fn void removeModule()
		 * @tparam T The type of module.
		 * @brief Remove the module.
		 * @throw
		 */
		template <class T> inline void removeModule();

		/**
		 * @fn T & getModule()
		 * @tparam T The type of module.
		 * @brief Get a module.
		 * @throw
		 */
		template <class T> inline T & getModule();

		/**
		 * @fn void onPreInit(const Listener & listener, const unsigned int slot)
		 * @param[in] listener The callback owner.
		 * @param[in] slot The callback to call.
		 * @brief Register a callback on pre-init event.
		 * @throw
		 * @see void Lifecycle::onPreInit(const Listener & listener, const unsigned int slot)
		 */
		inline void onPreInit(const Listener & listener, const unsigned int slot);

		/**
		 * @fn void onPostInit(const Listener & listener, const unsigned int slot)
		 * @param[in] listener The callback owner.
		 * @param[in] slot The callback to call.
		 * @brief Register a callback on post-init event.
		 * @throw
		 * @see void Lifecycle::onPostInit(const Listener & listener, const unsigned int slot)
		 */
		inline void onPostInit(const Listener & listener, const unsigned int slot);

		/**
		 * @fn void onPreProcess(const Listener & listener, const unsigned int slot)
		 * @param[in] listener The callback owner.
		 * @param[in] slot The callback to call.
		 * @brief Register a callback on pre-process event.
		 * @throw
		 * @see void Lifecycle::onPreProcess(const Listener & listener, const unsigned int slot)
		 */
		inline void onPreProcess(const Listener & listener, const unsigned int slot);

		/**
		 * @fn void onPreUpdate(const Listener & listener, const unsigned int slot)
		 * @param[in] listener The callback owner.
		 * @param[in] slot The callback to call.
		 * @brief Register a callback on pre-update event.
		 * @throw
		 * @see void Lifecycle::onPreUpdate(const Listener & listener, const unsigned int slot)
		 */
		inline void onPreUpdate(const Listener & listener, const unsigned int slot);

		/**
		 * @fn void onPostUpdate(const Listener & listener, const unsigned int slot)
		 * @param[in] listener The callback owner.
		 * @param[in] slot The callback to call.
		 * @brief Register a callback on post-update event.
		 * @throw
		 * @see void Lifecycle::onPostUpdate(const Listener & listener, const unsigned int slot)
		 */
		inline void onPostUpdate(const Listener & listener, const unsigned int slot);

		/**
		 * @fn void onPostRender(const Listener & listener, const unsigned int slot)
		 * @param[in] listener The callback owner.
		 * @param[in] slot The callback to call.
		 * @brief Register a callback on post-render event.
		 * @throw
		 * @see void Lifecycle::onPostRender(const Listener & listener, const unsigned int slot)
		 */
		inline void onPostRender(const Listener & listener, const unsigned int slot);

		/**
		 * @fn void onPreTerminate(const Listener & listener, const unsigned int slot)
		 * @param[in] listener The callback owner.
		 * @param[in] slot The callback to call.
		 * @brief Register a callback on pre-terminate event.
		 * @throw
		 * @see void Lifecycle::onPreTerminate(const Listener & listener, const unsigned int slot)
		 */
		inline void onPreTerminate(const Listener & listener, const unsigned int slot);

		/**
		 * @fn void onPostTerminate(const Listener & listener, const unsigned int slot)
		 * @param[in] listener The callback owner.
		 * @param[in] slot The callback to call.
		 * @brief Register a callback on post-terminate event.
		 * @throw
		 * @see void Lifecycle::onPostTerminate(const Listener & listener, const unsigned int slot)
		 */
		inline void onPostTerminate(const Listener & listener, const unsigned int slot);

	protected:
		/**
		 * @fn const bool isRunning() const
		 * @return True if the application is running, false else.
		 * @brief Check if the application is running or not.
		 * @throw
		 */
		inline const bool isRunning() const;

		/**
		 * @property _running
		 * @brief Tag to indication that the application is running or not.
		 */
		bool _running;

		/**
		 * @property _moduleManager
		 * @brief To manage the modules of the application.
		 */
		ModuleManager _moduleManager;

	private:
		/**
		 * @fn void init()
		 * @brief Initialize the application.
		 * @throw
		 */
		void init();

		/**
		 * void update()
		 * @brief Update the logic of the application.
		 * @throw
		 */
		void update();

		/**
		 * void processEvents()
		 * @brief Process all the events.
		 * @throw
		 */
		void processEvents();

		/**
		 * @fn void render()
		 * @brief Render the new frame.
		 * @throw
		 * @remark It should not be in the core.
		 */
		void render();

		/**
		 * @fn void terminate()
		 * @brief Terminate the application.
		 */
		void terminate();

		/**
		 * @property _lifecycle
		 * @brief The lifecycle of the application.
		 */
		std::shared_ptr<Lifecycle> _lifecycle;
	};
}

#include "core/application/application.inl"

#endif // APPLICATION_HPP