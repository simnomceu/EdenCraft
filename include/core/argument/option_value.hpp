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

#ifndef OPTION_VALUE_HPP
#define OPTION_VALUE_HPP

#include "core/config.hpp"
#include "core/pch.hpp"

namespace ece
{
	namespace core
	{
		namespace argument
		{
			/**
			 * @class OptionValue
			 * @brief An option for a console argument.
			 */
			class ECE_CORE_API OptionValue
			{
			public:
				/**
				 * @fn OptionValue() noexcept
				 * @brief Default constructor.
				 * @throw noexcept
				 */
				OptionValue() noexcept = default;

				/**
				 * @fn OptionValue(const OptionValue & copy) noexcept
				 * @param[in] copy The option to copy from.
				 * @brief Default copy constructor.
				 * @throw noexcept
				 */
				OptionValue(const OptionValue & copy) noexcept = default;

				/**
				 * @fn OptionValue(OptionValue && move) noexcept
				 * @param[in] move The option to move.
				 * @brief Default move constructor.
				 * @throw noexcept
				 */
				OptionValue(OptionValue && move) noexcept = default;

				/**
				 * @fn ~OptionValue() noexcept
				 * @brief Default destructor.
				 * @throw noexcept
				 */
				~OptionValue() noexcept = default;

				/**
				 * @fn OptionValue & operator=(const OptionValue & copy) noexcept
				 * @param[in] copy The option to copy from.
				 * @return The option copied.
				 * @brief Default copy assignment operator.
				 * @throw noexcept
				 */
				OptionValue & operator=(const OptionValue & copy) noexcept = delete;

				/**
				 * @fn OptionValue & operator=(OptionValue && move) noexcept
				 * @param[in] move The option to move.
				 * @return The option moved.
				 * @brief Default move  assignment operator.
				 * @throw noexcept
				 */
				OptionValue & operator=(OptionValue && move) noexcept = delete;

				/**
				 * @fn bool isValid(const std::string & value)
				 * @param[in] value The value to check.
				 * @return True if the value is valid, false else.
				 * @brief Check if the value of the argument is valid.
				 * @throw noexcept
				 * @see bool OptionValue::isValid(const std::string & value)
				 */
				virtual auto isValid(const std::string & value) -> bool = 0;
			};
		} // namespace argument
	} // namespace core
} // namespace ece

#endif // OPTION_VALUE_HPP