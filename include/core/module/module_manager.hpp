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

#ifndef MODULE_MANAGER_HPP
#define MODULE_MANAGER_HPP

#include "core/config.hpp"
#include "core/pch.hpp"
#include "core/module/module.hpp"

namespace ece
{
	namespace core
	{
		namespace module
		{
			/**
			 * @class ModuleManager
			 * @brief Manage all the module  of an application.
			 */
			class ECE_CORE_API ModuleManager
			{
			public:
				/**
				 * @fn ModuleManager() noexcept
				 * @brief Default constructor.
				 * @throw noexcept
				 */
				ModuleManager() noexcept = default;

				/**
				 * @fn ModuleManager(const ModuleManager & copy)
				 * @param[in] copy The manager to copy from.
				 * @brief Default copy constructor.
				 * @throw
				 */
				ModuleManager(const ModuleManager & copy) = default;

				/**
				 * @fn ModuleManager(ModuleManager && move) noexcept
				 * @param[in] move The manager to move.
				 * @brief Default move constructor.
				 * @throw noexcept
				 */
				ModuleManager(ModuleManager && move) noexcept = default;

				/**
				 * @fn ~ModuleManager() noexcept
				 * @brief Default destructor.
				 * @throw noexcept
				 */
				~ModuleManager() noexcept = default;

				/**
				 * @fn ModuleManager & operator=(const ModuleManager & copy)
				 * @param[in] copy The manager to copy from.
				 * @return The manager copied.
				 * @brief Default copy assignment operator.
				 * @throw
				 */
				ModuleManager & operator=(const ModuleManager & copy) = default;

				/**
				 * @fn ModuleManager & operator=(ModuleManager && move) noexcept
				 * @param[in] move The manager to move.
				 * @return The manager moved.
				 * @brief Default move assignment operator.
				 * @throw
				 */
				ModuleManager & operator=(ModuleManager && move) noexcept = default;

				/**
				 * @fn T & add(const ModuleMethodHandle<T> & init, const ModuleMethodHandle<T> & update, const ModuleMethodHandle<T> & terminate)
				 * @tparam T The object defined as a module.
				 * @param[in] init The method to initialize the module.
				 * @param[in] update The method to update the module.
				 * @param[in] terminate The method to terminate the module.
				 * @return The object referenced as a module, built.
				 * @brief Build and register an object as a module.
				 * @throw
				 */
				template <class T>
				auto & add(const ModuleMethodHandle<T> & init = ModuleMethod<T>::VOID_METHOD, const ModuleMethodHandle<T> & update = ModuleMethod<T>::VOID_METHOD, const ModuleMethodHandle<T> & terminate = ModuleMethod<T>::VOID_METHOD);

				/**
				 * @fn void remove()
				 * @tparam T The object defined as a module.
				 * @brief Remove a module from the application.
				 * @throw
				 */
				template <class T>
				void remove();

				/**
				 * @fn T & get()
				 * @tparam T The object defined as a module.
				 * @return The object referenced as a module
				 * @brief Get a module.
				 * @throw
				 */
				template <class T>
				auto & get();

				/**
				 * @fn void initAll()
				 * @brief Initialize all the modules, in the order they have been registered.
				 * @throw
				 */
				void initAll();

				/**
				 * @fn void updateAll()
				 * @brief Update all the modules, in the order they have been registered.
				 * @throw
				 */
				void updateAll();

				/**
				 * @fn void terminateAll()
				 * @brief Terminate all the modules, in the order they have been registered.
				 * @throw
				 */
				void terminateAll();

			private:
				/**
				 * @property _modules
				 * @brief The list of modules registered.
				 */
				std::vector<std::shared_ptr<BaseModule>> _modules;
			};
		} // namespace module
	} // namespace core
} // namespace ece

#include "core/module/module_manager.inl"

#endif // MODULE_MANAGER_HPP