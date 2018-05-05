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

#ifndef MODULE_HPP
#define MODULE_HPP

#include "core/module/base_module.hpp"
#include "core/module/module_method.hpp"

namespace ece
{
	namespace core
	{
		namespace module
		{
			/**
			 * @class Module
			 * @extends BaseModule
			 * @tparam T The object defined as a module
			 * @brief Generalize module for any object.
			 */
			template <class T>
			class Module : public BaseModule
			{
			public:
				Module() = delete;

				/**
				 * @fn Module(const ModuleMethodHandle<T> & init, const ModuleMethodHandle<T> & update, const ModuleMethodHandle<T> & terminate)
				 * @param[in] init The method to initialize the module.
				 * @param[in] update The method to update the module.
				 * @param[in] terminate The method to terminate the module.
				 * @brief Build a module, using its lifecycle methods.
				 * @throw
				 */
				inline Module(const ModuleMethodHandle<T> & init = ModuleMethod<T>::VOID, const ModuleMethodHandle<T> & update = ModuleMethod<T>::VOID, const ModuleMethodHandle<T> & terminate = ModuleMethod<T>::VOID);

				/**
				 * @fn Module(const Module & copy) noexcept
				 * @param[in] copy The module to copy from.
				 * @brief Default copy constructor.
				 * @throw noexcept
				 */
				Module(const Module & copy) noexcept = default;

				/**
				 * @fn Module(Module && move) noexcept
				 * @param[in] move The module to move.
				 * @brief Default move constructor.
				 * @throw noexcept
				 */
				Module(Module && move) noexcept = default;

				/**
				 * @fn ~Module() noexcept
				 * @brief Default destructor.
				 * @throw noexcept
				 */
				~Module() noexcept = default;

				/**
				 * @fn Module & operator=(const Module & copy) noexcept
				 * @param[in] copy The module to copy from.
				 * @return The module copied.
				 * @brief Default copy assignment operator.
				 * @throw noexcept
				 */
				Module & operator=(const Module & copy) noexcept = default;

				/**
				 * @fn Module & operator=(Module && move) noexcept
				 * @param[in] move The module to move.
				 * @return The module moved.
				 * @brief Default move assignment operator.
				 * @throw noexcept
				 */
				Module & operator=(Module && move) noexcept = default;

				/**
				 * @fn T & get()
				 * @return The object referenced as a module.
				 * @brief Get the object referenced.
				 * @throw
				 */
				inline T & get();

				/**
				 * @fn void init()
				 * @brief Hook to initialize the module.
				 * @throw
				 * @see void BaseModule::init()
				 */
				inline virtual void init() override;

				/**
				 * @fn void update()
				 * @brief Hook to update the module.
				 * @throw
				 * @see void BaseModule::update()
				 */
				inline virtual void update() override;

				/**
				 * @fn void terminate()
				 * @brief Hook to terminate the module.
				 * @throw
				 * @see void BaseModule::terminate()
				 */
				inline virtual void terminate() override;

			private:
				/**
				 * @property _module
				 * @brief The object referenced as a module.
				 */
				T _module;

				/**
				 * @property _initHandle
				 * @brief The hook used to initialized the module.
				 */
				ModuleMethod<T> _initHandle;

				/**
				 * @property _updateHandle
				 * @brief The hook used to update the module.
				 */
				ModuleMethod<T> _updateHandle;

				/**
				 * @property _terminateHandle
				 * @brief The hook used to terminate the module.
				 */
				ModuleMethod<T> _terminateHandle;
			};
		} // namespace module
	} // namespace core
} // namespace ece

#include "core/module/module.inl"

#endif // MODULE_HPP
