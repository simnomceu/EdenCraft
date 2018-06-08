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

#ifndef UNIFORM_HPP
#define UNIFORM_HPP

#include "renderer/resource/base_uniform.hpp"

namespace ece
{
	namespace renderer
	{
		namespace resource
		{
			/**
			 * @class Uniform
			 * @tparam T the type of data of the uniform.
			 * @brief A uniform as defined in OpenGL.
			 */
			template <class T>
			class Uniform : public BaseUniform
			{
			public:
				/**
				 * @fn Uniform(const Handle owner, const std::string & location, const T & data)
				 * @param[in] location The location of the uniform.
				 * @param[in] data The data to set.
				 * @brief Build a uniform from its location and the data to set.
				 * @throw
				 */
				Uniform(const Handle owner, const std::string & location, const T & data);

				/**
				 * @fn constexpr Uniform() noexcept
				 * @brief Default constructor.
				 * @throw noexcept
				 */
				constexpr Uniform() noexcept = default;

				/**
				 * @fn Uniform(const Uniform & copy) noexcept
				 * @param[in] copy The Uniform to copy from.
				 * @brief Default copy constructor.
				 * @throw noexcept
				 */
				Uniform(const Uniform & copy) noexcept = default;

				/**
				 * @fn Uniform(Uniform && move) noexcept
				 * @param[in] move The Uniform to move.
				 * @brief Default move constructor.
				 * @throw noexcept
				 */
				Uniform(Uniform && move) noexcept = default;

				/**
				 * @fn ~Uniform() noexcept
				 * @brief Default destructor.
				 * @throw noexcept
				 */
				~Uniform() noexcept = default;

				/**
				 * @fn Uniform & operator=(const Uniform & copy) noexcept
				 * @param[in] copy The Uniform to copy from.
				 * @return The Uniform copied.
				 * @brief Default copy assignment operator.
				 * @throw noexcept
				 */
				Uniform & operator=(const Uniform & copy) noexcept = default;

				/**
				 * @fn Uniform & operator=(Uniform && move) noexcept
				 * @param[in] move The Uniform to move from.
				 * @return The Uniform moved.
				 * @brief Default move assignment operator.
				 * @throw noexcept
				 */
				Uniform & operator=(Uniform && move) noexcept = default;

				/**
				 * @fn T getData() const
				 * @return The content of the uniform.
				 * @brief Get the data content of the uniform.
				 * @throw
				 */
				T getData() const;

				/**
				 * @fn void setData(const T & data)
				 * @param[in] data The data to set.
				 * @brief Set the content of the uniform.
				 * @throw
				 */
				void setData(const T & data);
			};
		} // namespace renderer
	} // namespace resource
} // namespace ece

#include "renderer/resource/uniform.inl"

#endif // UNIFORM_HPP