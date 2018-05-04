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

namespace ece
{
	namespace graphic
	{
		namespace renderable
		{
			/**
			 * @enum UniformType
			 * @brief The type of uniform.
			 */
			enum UniformType : unsigned short int
			{
				OTHER = 0,
				NUMERICAL = 1,
				VERTEX3 = 2,
				VERTEX4 = 3,
				MATRIX3X3 = 4,
				MATRIX4x4 = 5
			};

			/**
			 * @class BaseUniform
			 * @brief
			 */
			class BaseUniform
			{
			public:
				/**
				 * @fn constexpr BaseUniform() noexcept
				 * @brief Default constructor.
				 * @throw noexcept
				 */
				constexpr BaseUniform() noexcept = default;

				/**
				 * @fn BaseUniform(const BaseUniform & copy) noexcept
				 * @param[in] copy The BaseUniform to copy from.
				 * @brief Default copy constructor.
				 * @throw noexcept
				 */
				BaseUniform(const BaseUniform & copy) noexcept = default;

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
				 * @fn BaseUniform & operator=(const BaseUniform & copy) noexcept
				 * @param[in] copy The BaseUniform to copy from.
				 * @return The BaseUniform copied.
				 * @brief Default copy assignment operator.
				 * @throw noexcept
				 */
				BaseUniform & operator=(const BaseUniform & copy) noexcept = default;

				/**
				 * @fn BaseUniform & operator=(BaseUniform && move) noexcept
				 * @param[in] move The BaseUniform to move from.
				 * @return The BaseUniform moved.
				 * @brief Default move assignment operator.
				 * @throw noexcept
				 */
				BaseUniform & operator=(BaseUniform && move) noexcept = default;

				/**
				 * @fn std::string getLocation() const
				 * @return The string location.
				 * @brief Get the string location of the uniform.
				 * @throw
				 */
				 //		virtual std::string getLocation() const = 0;

						 /**
						  * @fn UniformType getType() const
						  * @return The type of uniform.
						  * @brief Get the type of uniform.
						  * @throw
						  */
				virtual UniformType getType() const = 0;
			};
		} // namespace renderable
	} // namespace graphic
} // namespace ece

#endif // BASE_UNIFORM_HPP