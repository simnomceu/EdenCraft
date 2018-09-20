/*

	oooooooooooo       .o8                          .oooooo.                       .o88o.     .
	`888'     `8      "888                         d8P'  `Y8b                      888 `"   .o8
	 888          .oooo888   .ooooo.  ooo. .oo.   888          oooo d8b  .oooo.   o888oo  .o888oo
	 888oooo8    d88' `888  d88' `88b `888P"Y88b  888          `888""8P `P  )88b   888      888
	 888    "    888   888  888ooo888  888   888  888           888      .oP"888   888      888
	 888       o 888   888  888    .o  888   888  `88b    ooo   888     d8(  888   888      888 .
	o888ooooood8 `Y8bod88P" `Y8bod8P' o888o o888o  `Y8bood8P'  d888b    `Y888""8o o888o     "888"

															ooooo     ooo     .    o8o  oooo   o8o      .
															`888'     `8'   .o8    `"'  `888   `"'    .o8
															 888       8  .o888oo oooo   888  oooo  .o888oo oooo    ooo
															 888       8    888   `888   888  `888    888    `88.  .8'
															 888       8    888    888   888   888    888     `88..8'
															 `88.    .8'    888 .  888   888   888    888 .    `888'
															   `YbodP'      "888" o888o o888o o888o   "888"     .8'
																											.o..P'
																											`Y8P'

				This file is part of EdenCraft Engine - Utility module.
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

#ifndef PARSER_JSON_HPP
#define PARSER_JSON_HPP

#include "utility/config.hpp"
#include "utility/file_system/parser.hpp"
#include "utility/formats/json/object_json.hpp"

namespace ece
{
    namespace utility
    {
		namespace formats
		{
			namespace json
			{
				using file_system::Parser;

				/**
				 * @class ParserJSON
				 * @extends Parser
				 * @brief A parser to load/save JSON tree from/to memory, file, or string.
				 * @see Parser
				 * @remarks Have to break coupling with ObjectJSON.
				 */
				class ECE_UTILITY_API ParserJSON : public Parser
				{
				public:
					/**
					 * @fn ParserJSON() noexcept
					 * @brief Unique constructor for a ParserJSON. No stream is opened, and no JSON tree is generated.
					 * @throw noexcept
					 */
					inline ParserJSON() noexcept;

					/**
					 * @fn void load(std::istream & stream)
					 * @param[inout] stream The stream to load through.
					 * @brief Load and parse data through a stream.
					 * @see void Parser::load(std::istream & stream)
					 * @throw
					 */
					virtual void load(std::istream & stream) override;

					/**
					 * @fn void save(std::ostream & stream)
					 * @param[inout] stream The stream to save through.
					 * @brief Formate and save data through a stream.
					 * @see void Parser::save(std::ostream & stream)
					 * @throw
					 */
					virtual void save(std::ostream & stream) override;

					/**
					 * @fn std::shared_ptr<ObjectJSON> getObject() const
					 * @return The root of the JSON tree from the current stream.
					 * @brief An accessor to the root of the JSON tree generated. If no JSON file is opened, the pointer is nullptr.
					 * @remark Decoupling JSONObject from this class, shall remove this method.
					 * @throw
					 */
					inline std::shared_ptr<ObjectJSON> getObject() const;

				protected:
					/**
					 * @property _pathname
					 * @brief The pathname of the JSON file opened. It is empty if not stream is opened.
					 * @remark It should not be an internal property as the JSON object can be loaded throw different ways (memory, ...).
					 */
					std::string _pathname;

					/**
					 * @property _contentJSON
					 * @brief The root of the last JSON parsed. If no JSON has been parsed yet, the property is empty.
					 * @remark It should not be an internal property but an output of the Parser.
					 */
					std::shared_ptr<ObjectJSON> _contentJSON;
				};
			} // namespace json
		} // namespace formats
    } // namespace utility
} // namespace ece

#include "utility/formats/json/parser_json.inl"

#endif // PARSER_JSON_HPP
