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

#ifndef MODULE_METHOD_HPP
#define MODULE_METHOD_HPP

#include <functional>

namespace ece
{
	namespace core
	{
		namespace module
		{
			/**
			 * @typedef ModuleMethodHandle
			 * @tparam T The object defined as a module.
			 * @brief The base signature of the module hooks.
			 */
			template <class T> using ModuleMethodHandle = std::function<void(T &)>;

			/**
			 * @fn ModuleMethod
			 * @extends ModuleMethodHandle<T>
			 * @tparam T The object defined as a module.
			 * @brief Extended handle for module hooks.
			 */
			template <class T>
			class ModuleMethod : protected ModuleMethodHandle<T>
			{
			public:
				static const ModuleMethodHandle<T> VOID;

				ModuleMethod() = delete;

				/**
				 * @fn ModuleMethod(const ModuleMethodHandle<T> & copy)
				 * @param[in] copy The standart function object to cast.
				 * @brief Default cast constructor from a standart function object.
				 * @throw
				 */
				inline ModuleMethod(const ModuleMethodHandle<T> & copy);

				/**
				 * @fn ModuleMethod(const ModuleMethod & copy) noexcept
				 * @param[in] copy The method to copy from.
				 * @brief Default copy constructor.
				 * @throw noexcept
				 */
				ModuleMethod(const ModuleMethod & copy) noexcept = default;

				/**
				 * @fn ModuleMethod(ModuleMethod && move) noexcept
				 * @param[in] move The method to move.
				 * @brief Default move constructor.
				 * @throw noexcept
				 */
				ModuleMethod(ModuleMethod && move) noexcept = default;

				/**
				 * @fn ~ModuleMethod() noexcept
				 * @brief Default destructor.
				 * @throw noexcept
				 */
				~ModuleMethod() noexcept = default;

				/**
				 * @fn ModuleMethod & operator=(const ModuleMethod & copy) noexcept
				 * @param[in] copy The method to copy from.
				 * @return The method copied.
				 * @brief Default assignment operator.
				 * @throw noexcept
				 */
				ModuleMethod & operator=(const ModuleMethod & copy) noexcept = default;

				/**
				 * @fn ModuleMethod & operator=(ModuleMethod && move) noexcept
				 * @param[in] move The method to move.
				 * @return The method moved.
				 * @brief Default move assignment operator.
				 * @throw noexcept
				 */
				ModuleMethod & operator=(ModuleMethod && move) noexcept = default;

				/**
				 * @see http://en.cppreference.com/w/cpp/utility/functional/function/operator%28%29.html
				 */
				using ModuleMethodHandle<T>::operator();
			};
		} // namespace module
	} // namespace core
} // namespace ece

#include "core/module/module_method.inl"

#endif // MODULE_METHOD_HPP
