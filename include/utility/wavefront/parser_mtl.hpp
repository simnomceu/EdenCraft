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

#ifndef PARSER_MTL_HPP
#define PARSER_MTL_HPP

#include "utility/config.hpp"
#include "utility/wavefront/material_mtl.hpp"

#include <vector>

namespace ece
{
	namespace utility
	{
		namespace wavefront
		{
			/**
			 * @class ParserMTL
			 * @brief
			 */
			class ECE_UTILITY_API ParserMTL
			{
			public:
				/**
				 * @fn ParserMTL() noexcept
				 * @brief Default constructor.
				 * @throw noexcept
				 */
				inline ParserMTL() noexcept;

				/**
				 * @fn ParserMTL(const ParserMTL & copy)
				 * @param[in] copy The ParserMTL to copy from.
				 * @brief Default copy constructor.
				 * @throw
				 */
				ParserMTL(const ParserMTL & copy) = default;

				/**
				 * @fn ParserMTL(ParserMTL && move) noexcept
				 * @param[in] move The ParserMTL to move.
				 * @brief Default move constructor.
				 * @throw noexcept
				 */
				ParserMTL(ParserMTL && move) noexcept = default;

				/**
				 * @fn ~ParserMTL() noexcept
				 * @brief Default destructor.
				 * @throw noexcept
				 */
				~ParserMTL() noexcept = default;

				/**
				 * @fn ParserMTL & operator=(const ParserMTL & copy)
				 * @param[in] copy The ParserMTL to copy from.
				 * @return The ParserMTL copied.
				 * @brief Default copy assignment operator.
				 * @throw
				 */
				ParserMTL & operator=(const ParserMTL & copy) = default;

				/**
				 * @fn ParserMTL & operator=(ParserMTL && move) noexcept
				 * @param[in] move The ParserMTL to move.
				 * @return The ParserMTL moved.
				 * @brief Default move assignment operator.
				 * @throw noexcept
				 */
				ParserMTL & operator=(ParserMTL && move) noexcept = default;

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

				inline const std::vector<MaterialMTL> & getMaterials() const;

			private:
				std::vector<MaterialMTL> _materials;
				std::vector<MaterialMTL>::iterator _currentMaterial;

				void processLine(const std::string & line);
				std::vector<MaterialMTL>::iterator addMaterial(const std::string & name);
			};
		} // namespace wavefront
	} // namespace utility
} // namespace ece

#include "utility/wavefront/parser_mtl.inl"

#endif // PARSER_MTL_HPP