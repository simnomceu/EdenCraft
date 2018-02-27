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


#ifndef RESOURCE_HPP
#define RESOURCE_HPP

#include "utility/enum.hpp"

#include <string>

namespace ece
{
	/**
	 * @class Resource
	 * @brief A resource is an external content that can be loaded and saved.
	 */
	class Resource
	{
	public:
		/**
		 * @fn Resource() noexcept 
		 * @brief Default constructor.
		 * @throw noexcept
		 */
		Resource() noexcept = default;

		/**
		 * @fn Resource(const Resource & copy) 
		 * @param[in] copy The resource to copy from.
		 * @brief Default copy constructor.
		 * @throw
		 */
		Resource(const Resource & copy) = default;

		/**
		 * @fn Resource(Resource && move) noexcept 
		 * @param[in] move The resource to move.
		 * @brief Default move constructor.
		 * @throw noexcept
		 */
		Resource(Resource && move) noexcept = default;

		inline virtual ~Resource() = 0;
		
		/**
		 * @fn Resource & operator=(const Resource & copy)
		 * @param[in] copy The resource to copy from.
		 * @return The resource copied.
		 * @brief Default copy assignment operator.
		 * @throw
		 */
		Resource & operator=(const Resource & copy) = default;

		/** 
		 * @fn Resource & operator=(Resource && move) noexcept 
		 * @param[in] move The resource to move.
		 * @return The resource moved.
		 * @brief Default move assignment operator.
		 * @throw noexcept
		 */
		Resource & operator=(Resource && move) noexcept = default;

		/**
		 * @fn void setType(const ResourceType & type)
		 * @param[in] type The new type of the resource.
		 * @brief Modify the type of the resource.
		 * @throw
		 */
		inline void setType(const ResourceType & type);

		/**
		 * @fn void setName(const std::string & name)
		 * @param[in] name The new name of the resource.
		 * @brief Modify the name of the resource.
		 * @throw
		 */
		inline void setName(const std::string & name);

		/**
		 * @fn const ResourceType & getType() const
		 * @return The type of the resource.
		 * @brief Get the type of the resource.
		 * @throw
		 */
		inline const ResourceType & getType() const;

		/**
		 * @fn const std::string & getName() const
		 * @return The name of the resource.
		 * @brief Get the name of the resource.
		 * @throw
		 */
		inline const std::string & getName() const;

	protected:
		/**
		 * @property _type
		 * @brief The type of the resource.
		 */
		ResourceType _type;

		/**
		 * @property _name
		 * @brief The name of the resource.
		 */
		std::string _name;
	};
}

#include "core/resource/resource.inl"

#endif // RESOURCE_HPP