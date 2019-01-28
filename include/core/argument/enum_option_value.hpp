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

#ifndef ENUM_OPTION_VALUE_HPP
#define ENUM_OPTION_VALUE_HPP

#include "core/config.hpp"
#include "core/pch.hpp"
#include "core/argument/option_value.hpp"

namespace ece
{
	namespace core
	{
		namespace argument
		{
			/**
			 * @class IntegerOptionValue
			 * @extends OptionValue
			 * @brief An option as an enumeration argument.
			 */
			class ECE_CORE_API EnumOptionValue : public OptionValue
			{
			public:
				/**
				 * @fn EnumOptionValue() noexcept
				 * @brief Default constructor.
				 * @throw noexcept
				 */
				EnumOptionValue() noexcept = default;

				/**
				 * @fn EnumOptionValue(const EnumOptionValue & copy)
				 * @param[in] copy The option to copy from.
				 * @brief Default copy constructor.
				 * @throw
				 */
				EnumOptionValue(const EnumOptionValue & copy) = default;

				/**
				 * @fn EnumOptionValue(EnumOptionValue && move) noexcept
				 * @param[in] move The option to move from.
				 * @brief Default move constructor.
				 * @throw noexcept
				 */
				EnumOptionValue(EnumOptionValue && move) noexcept = default;

				/**
				 * @fn ~EnumOptionValue() noexcept
				 * @brief Default destructor.
				 * @throw noexcept
				 */
				~EnumOptionValue() noexcept = default;

				/**
				 * @fn EnumOptionValue & operator=(const EnumOptionValue & copy) noexcept
				 * @param[in] copy The option to copy from.
				 * @return The option copied.
				 * @brief Default copy assignment operator.
				 * @throw noexcept
				 */
				EnumOptionValue & operator=(const EnumOptionValue & copy) noexcept = default;

				/**
				 * @fn EnumOptionValue & operator=(EnumOptionValue && move) noexcept
				 * @param[in] move The option to move.
				 * @return The option moved.
				 * @brief Default move assignment operator.
				 * @throw noexcept
				 */
				EnumOptionValue & operator=(EnumOptionValue && move) noexcept = default;

				/**
				 * @fn bool isValid(const std::string & value)
				 * @param[in] value The value to check.
				 * @return True if the value is valid, false else.
				 * @brief Check if the value of the argument is valid.
				 * It should always be valid for a value in the enumeration field.
				 * @throw noexcept
				 * @see bool OptionValue::isValid(const std::string & value)
				 */
				inline virtual auto isValid(const std::string & value) -> bool override;

				/**
				 * @fn void addValue(const std::string & value)
				 * @param[in] value The value to add.
				 * @brief Add a value to the enumeration field to set it available.
				 * @throw
				 */
				inline void addValue(const std::string & value);

			private:
				/**
				 * @property _values
				 * @brief The list of values in the enumeration field.
				 */
				std::vector<std::string> _values;
			};
		} // namespace argument
	} // namespace core
} // namespace ece

#include "core/argument/enum_option_value.inl"

#endif // ENUM_OPTION_VALUE_HPP