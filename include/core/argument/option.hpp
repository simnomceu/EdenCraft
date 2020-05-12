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

#ifndef OPTION_HPP
#define OPTION_HPP

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
			 * @class Option
			 * @brief A command line argument.
			 */
			class ECE_CORE_API Option
			{
			public:
				Option() = delete;

				/**
				 * @fn Option(const std::string & name, const std::shared_ptr<OptionValue> & value, const std::function<void(const std::string &)> & command)
				 * @param[in] name The name of the argument.
				 * @param[in] value The set of valid values.
				 * @param[in] command The command to execute with this argument.
				 * @brief Default constructor.
				 * @throw
				 */
				inline Option(const std::string & name, const std::shared_ptr<OptionValue> & value, const std::function<void(const std::string &)> & command);

				/**
				 * @fn Option(const Option & copy)
				 * @param[in] copy The option to copy from.
				 * @brief Default copy constructor.
				 * @throw
				 */
				Option(const Option & copy) = default;

				/**
				 * Option(Option && move)
				 * @param[in] move The option to move.
				 * @brief Default move constructor.
				 * @throw
				 */
				Option(Option && move) noexcept = default;

				/**
				 * @fn ~Option() noexcept
				 * @brief Default destructor.
				 * @throw noexcept
				 */
				~Option() noexcept = default;

				/**
				 * @fn Option & operator=(const Option & copy)
				 * @param[in] copy The option to copy from.
				 * @return The option copied.
				 * @brief Default copy assignment operator.
				 * @throw
				 */
				Option & operator=(const Option & copy) = default;

				/**
				 * @fn Option & operator=(Option && move)
				 * @param[in] move The option to move.
				 * @return The option moved.
				 * @brief Default move assignment operator.
				 * @throw
				 */
				Option & operator=(Option && move) noexcept = default;

				/**
				 * @fn bool apply(const std::string & optionName, const std::string & optionValue)
				 * @param[in] optionName The name of the option to apply.
				 * @param[in] optionValue The value of the option to apply.
				 * @return True if the option is applied successfully, false if it does not match the option or if the value is incorrect.
				 * @brief Try to apply the command linked to this option.
				 * @throw
				 */
				auto apply(const std::string & optionName, const std::string & optionValue = "") -> bool;
				
				inline void setOptional(bool optional) noexcept;
				inline bool isOptional() const noexcept;

				inline const std::string & getName() const noexcept;

			private:
				/**
				 * @property _name
				 * @brief The option name.
				 */
				std::string _name;

				/**
				 * @property _value
				 * @brief The option value.
				 */
				std::shared_ptr<OptionValue> _value;

				/**
				 * @property _command
				 * @brief The command linked to the command line option.
				 */
				std::function<void(const std::string &)> _command;

				bool _optional;
			};
		} // namespace argument
	} // namespace core
} // namespace ece

#include "core/argument/option.inl"

#endif // OPTION_HPP