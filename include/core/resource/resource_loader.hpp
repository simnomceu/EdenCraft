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


#ifndef RESOURCE_LOADER_HPP
#define RESOURCE_LOADER_HPP

#include <string>

#include "core/resource/resource_handler.hpp"

namespace ece
{
	namespace core
	{
		namespace resource
		{
			/**
			 * @class ResourceLoader
			 * @brief To load a resource.
			 */
			class ResourceLoader
			{
			public:
				/**
				 * @fn ResourceLoader() noexcept
				 * brief Default constructor.
				 * @throw noexcept
				 */
				ResourceLoader() = default;

				/**
				 * @fn ResourceLoader(const ResourceLoader & copy) noexcept
				 * @param[in] copy The loader to copy from.
				 * @brief Default copy constructor.
				 * @throw noexcept
				 */
				ResourceLoader(const ResourceLoader & copy) = default;

				/**
				 * @fn ResourceLoader(ResourceLoader && move) noexcept
				 * @param[in] move The loader to move.
				 * @brief Default move constructor.
				 * @throw noexcept
				 */
				ResourceLoader(ResourceLoader && move) = default;

				/**
				 * @fn ~ResourceLoader() noexcept
				 * @brief Default destructor.
				 * @throw noexcept
				 */
				inline virtual ~ResourceLoader() = 0;

				/**
				 * @fn ResourceLoader & operator=(const ResourceLoader & copy) noexcept
				 * @param[in] copy The loader to copy from.
				 * @return The loader copied.
				 * @brief Default copy assignment operator.
				 * @throw noexcept
				 */
				ResourceLoader & operator=(const ResourceLoader & copy) = default;

				/**
				 * @fn ResourceLoader & operator=(ResourceLoader && move) noexcept
				 * @param[in] move The loader to move.
				 * @return The loader moved.
				 * @brief Default move assignment operator.
				 * @throw noexcept
				 */
				ResourceLoader & operator=(ResourceLoader && move) = default;

				/**
				 * @fn void load(ResourceHandler & handler) const
				 * @param[in] handler The resource to load.
				 * @brief Load the resource.
				 * @throw
				 */
				virtual ResourceHandler load(const std::string & identifier) const = 0;
			};
		} // namespace resource
	} // namespace core
} // namespace ece

#include "core/resource/resource_loader.inl"

#endif // RESOURCE_LOADER_HPP