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


#ifndef RESOURCE_HANDLER_HPP
#define RESOURCE_HANDLER_HPP

#include "core/config.hpp"

#include <memory>
#include <string>

namespace ece
{
	namespace core
	{
		namespace resource
		{
			/**
			 * @class ResourceHandler
			 * @brief To handle a resource.
			 * @remark How useful is it ?
			 */
			template <class Resource>
			class ECE_CORE_API ResourceHandler
			{
			public:
				inline constexpr ResourceHandler() noexcept;

				/**
				 * @fn ResourceHandler(const std::shared_ptr<Resource> & resource)
				 * @param[in] resource The resource to handle
				 * @brief Build a handler for a specific resource.
				 * @throw
				 */
				inline ResourceHandler(const std::shared_ptr<Resource> & resource);

				/**
				 * @fn ResourceHandler(const ResourceHandler & copy) noexcept
				 * @param[in] copy The handler to copy from.
				 * @brief Default copy constructor.
				 * @throw noexcept
				 */
				ResourceHandler(const ResourceHandler & copy) noexcept = default;

				/**
				 * @fn ResourceHandler(ResourceHandler && move) noexcept
				 * @param[in] move The handler to move.
				 * @brief Default move constructor.
				 * @throw noexcept
				 */
				ResourceHandler(ResourceHandler && move) noexcept = default;

				/**
				 * @fn ~ResourceHandler() noexcept
				 * @brief Default destructor.
				 * @throw noexcept
				 */
				~ResourceHandler() noexcept = default;

				/**
				 * @fn ResourceHandler & operator=(const ResourceHandler & copy) noexcept
				 * @param[in] copy The handler to copy from.
				 * @return The handler copied.
				 * @brief Default copy assignment operator.
				 * @throw noexcept
				 */
				ResourceHandler & operator=(const ResourceHandler & copy) noexcept = default;

				/**
				 * @fn ResourceHandler & operator=(ResourceHandler && move) noexcept
				 * @param[in] move The handler to move.
				 * @return The handler moved.
				 * @brief Default move assignment operator.
				 * @throw noexcept
				 */
				ResourceHandler & operator=(ResourceHandler && move) noexcept = default;

				/**
				 * @fn std::weak_ptr<Resource> operator->()
				 * @return The resource handled.
				 * @brief Get The resource handled.
				 */
				inline std::shared_ptr<Resource> operator->();

				/**
				 * @fn std::weak_ptr<Resource> operator*()
				 * @return The resource handled.
				 * @brief Get The resource handled.
				 */
				inline std::shared_ptr<Resource> operator*();

				inline bool isDirty() const;

			private:
				std::weak_ptr<Resource> _resource;
			};
		} // namespace resource
	} // namespace core
} // namespace ece

#include "core/resource/resource_handler.inl"

#endif // RESOURCE_HANDLER_HPP