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

#ifndef PARSER_OBJ_HPP
#define PARSER_OBJ_HPP

#include "utility/config.hpp"
#include "utility/formats/wavefront/object_obj.hpp"
#include "utility/string.hpp"

#include <vector>

namespace ece
{
    namespace utility
    {
		namespace formats
		{
			namespace wavefront
			{
				// TODO add parser MKL

				/**
				 * @class ParserOBJ
				 * @extends Parser
				 * @brief A parser to load/save OBJ Wavefront structure from/to memory, file, or string.
				 * @remark The OBJ Wavefront structure is so much more complexe and should be refactored.
				 * @see Parser
				 */
				class ECE_UTILITY_API ParserOBJ
				{
				public:
					/**
					 * @fn ParserOBJ()
					 * @brief Unique constructor for a ParserOBJ. No OBJ is loaded.
					 * @throw
					 */
					inline ParserOBJ();

					/**
					 * @fn void load(std::istream & stream)
					 * @param[in] stream The stream to load through.
					 * @brief Load and parse data through a stream.
					 * @throw
					 */
					void load(std::istream & stream);

					/**
					 * @fn void save(const std::ostream & stream)
					 * @param[inout] stream The stream to save through.
					 * @brief Formate and save data through a stream.
					 * @throw
					 */
					void save(std::ostream & stream);

					inline std::vector<ObjectOBJ> & getObjects();
					inline const std::vector<ObjectOBJ> & getObjects() const;

					inline std::vector<std::string> & getMaterials();
					inline const std::vector<std::string> & getMaterials() const;

				private:
					std::vector<ObjectOBJ> _objects;
					std::vector<ObjectOBJ>::iterator _currentObject;
					std::vector<std::string> _materials;

					void processLine(StringStream & line);
					std::vector<ObjectOBJ>::iterator addObject(const std::string & name);
				};
			} // namespace wavefront
		} // namespace formats
    } // namespace utility
} // namespace ece

#include "utility/formats/wavefront/parser_obj.inl"

#endif // PARSER_OBJ_HPP
