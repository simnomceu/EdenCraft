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

#ifndef SYSTEM_HPP
#define SYSTEM_HPP

#include "core/config.hpp"

namespace ece
{
	namespace core
	{
		namespace ecs
		{
			/**
			 * @class System
			 * @brief A system handle some specific kinds of components and do operations on them.
			 */
			class ECE_CORE_API System
			{
			public:
				/**
				 * @fn constexpr System() noexcept
				 * @brief Default constructor.
				 * @throw noexcept
				 */
				constexpr System() noexcept = default;

				/**
				 * @fn System(const System & copy) noexcept
				 * @param[in] copy The System to copy from.
				 * @brief Default copy constructor.
				 * @throw noexcept
				 */
				System(const System & copy) noexcept = default;

				/**
				 * @fn System(System && move) noexcept
				 * @param[in] move The System to move.
				 * @brief Default move constructor.
				 * @throw noexcept
				 */
				System(System && move) noexcept = default;

				/**
				 * @fn ~System() noexcept
				 * @brief Default destructor.
				 * @throw noexcept
				 */
				inline virtual ~System() noexcept = 0;

				/**
				 * @fn System & operator=(const System & copy) noexcept
				 * @param[in] copy The System to copy from.
				 * @return The System copied.
				 * @brief Default copy assignment operator.
				 * @throw noexcept
				 */
				System & operator=(const System & copy) noexcept = default;

				/**
				 * @fn System & operator=(System && move) noexcept
				 * @param[in] move The System to move.
				 * @return The System moved.
				 * @brief Default move assignment operator.
				 * @throw noexcept
				 */
				System & operator=(System && move) noexcept = default;

				virtual void update() = 0;
			};
		} // namespace ecs
	} // namespace core
} // namespace ece

#include "core/ecs/system.inl"

#endif // SYSTEM_HPP
