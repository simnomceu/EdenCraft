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

#ifndef PARSER_BMP_HPP
#define PARSER_BMP_HPP

#include "utility/config.hpp"
#include "utility/pch.hpp"
#include "utility/file_system.hpp"
#include "utility/indexing.hpp"
#include "utility/types.hpp"

namespace ece
{
	namespace utility
	{
		namespace formats
		{
			namespace bitmap
			{
				/**
				 * @class ParserBMP
				 * @extends Parser
				 * @brief A parser to load/save BMP images from/to memory, file, or string.
				 * @see Parser
				 */
				class ECE_UTILITY_API ParserBMP : public Parser
				{
				public:
					/**
					 * @fn ParserBMP() noexcept
					 * @brief Default constructor.
					 * @throw noexcept
					 */
					inline ParserBMP() noexcept;

					/**
					 * @fn ParserBMP(const ParserBMP & copy)
					 * @param[in] copy The parser to copy from.
					 * @brief Default copy constructor.
					 * @throw
					 */
					ParserBMP(const ParserBMP & copy) = default;

					/**
					 * @fn ParserBMP() noexcept
					 * @param[in] move The parser to move.
					 * @brief Default move constructor.
					 * @throw noexcept
					 */
					ParserBMP(ParserBMP && move) noexcept = default;

					/**
					 * @fn ~ParserBMP() noexcept
					 * @brief Default destructor.
					 * @throw noexcept
					 */
					~ParserBMP() noexcept = default;

					/**
					 * @fn ParserBMP & operator=(const ParserBMP & copy)
					 * @param[in] copy The parser to copy from.
					 * @return The parser copied.
					 * @brief Default copy assignment operator.
					 * @throw
					 */
					ParserBMP & operator=(const ParserBMP & copy) = default;

					/**
					 * @fn ParserBMP & operator=(ParserBMP && move) noexcept
					 * @param[in] move The parser to move.
					 * @return The parser moved.
					 * @brief Default move assignment operator.
					 * @throw noexcept.
					 */
					ParserBMP & operator=(ParserBMP && move) noexcept = default;

					/**
					 * @fn void load(std::istream & stream)
					 * @param[inout] stream The stream to load through.
					 * @brief Load and parse data through a stream.
					 * @throw
					 * @see void Parser::load(std::istream & stream)
					 */
					virtual void load(std::istream & stream) override;

					/**
					 * @fn void save(std::ostream & stream)
					 * @param[inout] stream The stream to save through.
					 * @brief Formate and save data through a stream.
					 * @throw
					 * @see void Parser::save(std::ostream & stream)
					 */
					virtual void save(std::ostream & stream) override;


					/**
					 * @fn Dynamic2DArray<std::array<std::byte, 3>> & getPixels()
					 * @return The image currently loaded.
					 * @brief Get the image currently loaded.
					 * @throw noexcept
					 */
					inline auto & getPixels() noexcept;

					/**
					 * @fn const Dynamic2DArray<std::array<std::byte, 3>> & getPixels() const
					 * @return The image currently loaded.
					 * @brief Get the image currently loaded.
					 * @throw noexcept
					 */
					inline auto getPixels() const noexcept;

				private:
					Dynamic2DArray<std::array<std::uint8_t, 3>> _pixels;
				};
			} // namespace bitmap
		} // namespace formats
	} // namespace utility
} // namespace ece

#include "utility/formats/bitmap/parser_bmp.inl"

#endif // PARSER_BMP_HPP
