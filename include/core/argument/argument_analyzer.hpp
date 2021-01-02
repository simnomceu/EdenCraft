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

#ifndef ARGUMENT_ANALYZER_HPP
#define ARGUMENT_ANALYZER_HPP

#include "core/config.hpp"
#include "core/pch.hpp"
#include "core/argument/option.hpp"

namespace ece
{
	namespace core
	{
		namespace argument
		{
			/**
			 * @class ArgumentAnalyzer
			 * @brief Parser to analyze and process the command line arguments passed.
			 */
			class ECE_CORE_API ArgumentAnalyzer
			{
			public:
				/**
				 * @fn ArgumentAnalyzer() noexcept
				 * @brief Default constructor.
				 * @throw noexcept
				 */
				ArgumentAnalyzer() noexcept = default;

				/**
				 * @fn ArgumentAnalyzer(const ArgumentAnalyzer & copy)
				 * @param[in] copy The analyzer to copy from.
				 * @brief Default copy constructor.
				 * @throw
				 */
				ArgumentAnalyzer(const ArgumentAnalyzer & copy) = default;

				/**
				 * @fn ArgumentAnalyzer(ArgumentAnalyzer && move) noexcept
				 * @param[in] move The analyzer to move.
				 * @brief Default move constructor.
				 * @throw noexcept
				 */
				ArgumentAnalyzer(ArgumentAnalyzer && move) noexcept = default;

				/**
				 * @fn ~ArgumentAnalyzer() noexcept
				 * @brief Default destructor.
				 * @throw noexcept
				 */
				~ArgumentAnalyzer() noexcept = default;

				/**
				 * @fn ArgumentAnalyzer & operator=(const ArgumentAnalyzer & copy)
				 * @param[in] copy The analyzer to copy from.
				 * @return The analyzer copied.
				 * @brief Default copy assignment operator.
				 * @throw
				 */
				ArgumentAnalyzer & operator=(const ArgumentAnalyzer & copy) = default;

				/**
				 * @fn ArgumentAnalyzer & operator=(ArgumentAnalyzer && move) noexcept
				 * @param[in] move The analyzer to move.
				 * @return The analyzer moved.
				 * @brief Default move assignment operator.
				 * @throw noexcept
				 */
				ArgumentAnalyzer & operator=(ArgumentAnalyzer && move) noexcept = default;

				/**
				 * @fn void addOption(const Option & option)
				 * @param[in] option The argument to add to the command line.
				 * @brief Add an option argument available to the command line.
				 * @throw
				 */
				inline void addOption(const Option & option);

				/**
				 * @fn void setParameters(int argc, char * argv[])
				 * @param[in] argc The number of arguments to analyse.
				 * @param[in] argv The parameters to analyze.
				 * @brief Set the parameters to analyze.
				 * @throw
				 */
				void setParameters(int argc, char * argv[]);

				/**
				 * @fn void analyze()
				 * @brief Start to analyze the arguments.
				 */
				void analyze();

			private:
				/**
				 * @property _options
				 * @brief The available arguments for the application.
				 */
				std::vector<Option> _options;

				/**
				 * @property _parameters
				 * @brief The arguments passed through the command line.
				 */
				std::vector<std::pair<std::string, std::string>> _parameters;
			};
		} // namespace argument
	} // namespace core
} // namespace ece

#include "core/argument/argument_analyzer.inl"

#endif // ARGUMENT_ANALYZER_HPP