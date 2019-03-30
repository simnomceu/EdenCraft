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

#ifndef BASE_RESOURCE_CONTAINER_HPP
#define BASE_RESOURCE_CONTAINER_HPP

#include "core/config.hpp"
#include "core/pch.hpp"

namespace ece
{
	namespace core
	{
		namespace resource
		{
			/**
			 * @class BaseResourceContainer
			 * @brief
			 */
			class ECE_CORE_API BaseResourceContainer
			{
			public:
				/**
				 * @fn constexpr BaseResourceContainer() noexcept
				 * @brief Default constructor.
				 * @throw noexcept
				 */
				constexpr BaseResourceContainer() noexcept = default;

				/**
				 * @fn BaseResourceContainer(const BaseResourceContainer & copy) noexcept
				 * @param[in] copy The BaseResourceContainer to copy from.
				 * @brief Default copy constructor.
				 * @throw noexcept
				 */
				BaseResourceContainer(const BaseResourceContainer & copy) noexcept = default;

				/**
				 * @fn BaseResourceContainer(BaseResourceContainer && move) noexcept
				 * @param[in] move The BaseResourceContainer to move.
				 * @brief Default move constructor.
				 * @throw noexcept
				 */
				BaseResourceContainer(BaseResourceContainer && move) noexcept = default;

				/**
				 * @fn ~BaseResourceContainer() noexcept
				 * @brief Default destructor.
				 * @throw noexcept
				 */
				~BaseResourceContainer() noexcept = default;

				/**
				 * @fn BaseResourceContainer & operator=(const BaseResourceContainer & copy) noexcept
				 * @param[in] copy The BaseResourceContainer to copy from.
				 * @return The BaseResourceContainer copied.
				 * @brief Default copy assignment operator.
				 * @throw noexcept
				 */
				BaseResourceContainer & operator=(const BaseResourceContainer & copy) noexcept = default;

				/**
				 * @fn BaseResourceContainer & operator=(BaseResourceContainer && move) noexcept
				 * @param[in] move The BaseResourceContainer to move.
				 * @return The BaseResourceContainer moved.
				 * @brief Default move assignment operator.
				 * @throw noexcept
				 */
				BaseResourceContainer & operator=(BaseResourceContainer && move) noexcept = default;


				virtual void remove(const std::string & key) = 0;
				virtual void remove(const std::vector<std::string> & keys) = 0;

				virtual void clear() = 0;
			};
		} // namespace resource
	} // namespace core
} // namespace ece

#endif // BASE_RESOURCE_CONTAINER_HPP