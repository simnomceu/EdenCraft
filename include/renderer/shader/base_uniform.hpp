/*

	oooooooooooo       .o8                          .oooooo.                       .o88o.     .   
	`888'     `8      "888                         d8P'  `Y8b                      888 `"   .o8   
	 888          .oooo888   .ooooo.  ooo. .oo.   888          oooo d8b  .oooo.   o888oo  .o888oo 
	 888oooo8    d88' `888  d88' `88b `888P"Y88b  888          `888""8P `P  )88b   888      888   
	 888    "    888   888  888ooo888  888   888  888           888      .oP"888   888      888   
	 888       o 888   888  888    .o  888   888  `88b    ooo   888     d8(  888   888      888 . 
	o888ooooood8 `Y8bod88P" `Y8bod8P' o888o o888o  `Y8bood8P'  d888b    `Y888""8o o888o     "888" 

															  .oooooo.                                  oooo         o8o            
															 d8P'  `Y8b                                 `888         `"'            
															888           oooo d8b  .oooo.   oo.ooooo.   888 .oo.   oooo   .ooooo.  
															888           `888""8P `P  )88b   888' `88b  888P"Y88b  `888  d88' `"Y8 
															888     ooooo  888      .oP"888   888   888  888   888   888  888       
															`88.    .88'   888     d8(  888   888   888  888   888   888  888   .o8 
															 `Y8bood8P'   d888b    `Y888""8o  888bod8P' o888o o888o o888o `Y8bod8P' 
																							  888                                   
																							 o888o                                  
                                                                       
                                          
                                     
				This file is part of EdenCraft Engine - Graphic module.
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

#ifndef BASE_UNIFORM_HPP
#define BASE_UNIFORM_HPP

#include <string>

#include "renderer/config.hpp"
#include "renderer/opengl/handle.hpp"

namespace ece
{
	namespace renderer
	{
		namespace shader
		{
			using opengl::Handle;

			/**
			 * @class BaseUniform
			 * @brief
			 */
			class ECE_RENDERER_API BaseUniform
			{
			public:
				/**
				 * @fn BaseUniform() noexcept
				 * @brief Default constructor.
				 * @throw noexcept
				 */
				BaseUniform() noexcept = default;

				/**
				 * @fn BaseUniform(const BaseUniform & copy)
				 * @param[in] copy The BaseUniform to copy from.
				 * @brief Default copy constructor.
				 * @throw noexcept
				 */
				BaseUniform(const BaseUniform & copy) = default;

				/**
				 * @fn BaseUniform(BaseUniform && move) noexcept
				 * @param[in] move The BaseUniform to move.
				 * @brief Default move constructor.
				 * @throw noexcept
				 */
				BaseUniform(BaseUniform && move) noexcept = default;

				/**
				 * @fn ~BaseUniform() noexcept
				 * @brief Default destructor.
				 * @throw noexcept
				 */
				~BaseUniform() noexcept = default;

				/**
				 * @fn BaseUniform & operator=(const BaseUniform & copy)
				 * @param[in] copy The BaseUniform to copy from.
				 * @return The BaseUniform copied.
				 * @brief Default copy assignment operator.
				 * @throw noexcept
				 */
				BaseUniform & operator=(const BaseUniform & copy) = default;

				/**
				 * @fn BaseUniform & operator=(BaseUniform && move) noexcept
				 * @param[in] move The BaseUniform to move from.
				 * @return The BaseUniform moved.
				 * @brief Default move assignment operator.
				 * @throw noexcept
				 */
				BaseUniform & operator=(BaseUniform && move) noexcept = default;

				/**
				 * @fn bool isOwned() const noexcept
				 * @return True if it has an owner, false else.
				 * @brief Check if the uniform is already set in a shader program or not.
				 * @throw noexcept
				 */
				inline bool isOwned() const noexcept;

				/**
				 * @fn Handle getOwner() const noexcept
				 * @return The owner of the uniform.
				 * @brief Get the owner of the uniform.
				 * @throw noexcept
				 */
				inline Handle getOwner() const noexcept;

				/**
				 * @fn const std::string & getName() const noexcept
				 * @return The string location.
				 * @brief Get the string name of the uniform.
				 * @throw noexcept
				 */
				inline const std::string & getName() const noexcept;

				/**
				 * @fn Handle getLocation() const
				 * @return The location of the uniform.
				 * @brief Get the location of the uniform in the owner program.
				 * @throw
				 */
				Handle getLocation() const;

				inline void setOwner(const Handle owner);

				inline void setName(const std::string & name);

			protected:
				Handle _owner;
				std::string _name;

				void guard() const;
			};
		} // namespace shader
	} // namespace renderer
} // namespace ece

#include "renderer/shader/base_uniform.inl"

#endif // BASE_UNIFORM_HPP