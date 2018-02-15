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

#include <array>
#include <vector>

#include "utility/file_system/parser.hpp"

namespace ece
{
	/**
	 * @class ParserBMP
	 * @extends Parser
	 * @brief A parser to load/save BMP images from/to memory, file, or string.
	 * @see Parser
	 */
	class ParserBMP : public Parser
	{
	public:
		struct RGB24 // TODO: only useful for Bitmap 24bits
		{
			std::byte red;
			std::byte green;
			std::byte blue;
		};

		/**
		 * @fn ParserBMP() noexcept
		 * @brief Default constructor.
		 * @throw noexcept
		 */
		ParserBMP() noexcept = default;

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
		 * @fn void loadFromFile(const std::string & filename)
		 * @param[in] filename The name of the file to load data from.
		 * @brief Load and parse data from a file.
		 * @throw
		 * @see void Parser::loadFromFile(const std::string & filename)
		 */
		virtual void loadFromFile(const std::string & filename) override;

		/**
		 * @fn void loadFromString(const std::string & content)
		 * @param[in] content The string content to load data from.
		 * @brief Load and parse data from a string.
		 * @throw
		 * @see void Parser::loadFromString(const std::string & content)
		 */
		virtual void loadFromString(const std::string & content) override;

		/**
		 * @fn void loadFromMemory(const void * content)
		 * @param[in] content The memory buffer to load data from.
		 * @brief Load and parse data from memory.
		 * @throw
		 * @see void Parser::loadFromMemory(const void * content)
		 */
		virtual void loadFromMemory(const void * content) override;

		/**
		 * @fn void saveToFile(const std::string & filename)
		 * @param[out] filename The name of the file to save into.
		 * @brief Formate and save data into a file.
		 * @throw
		 * @see void Parser::saveToFile(const std::string & filename)
		 */
		virtual void saveToFile(const std::string & filename) override;

		/**
		 * @fn void saveToString(std::string & content)
		 * @param[out] content The string buffer to save into.
		 * @brief Formate and save data into a string buffer.
		 * @throw
		 * @see void Parser::saveToString(std::string & content)
		 */
		virtual void saveToString(std::string & content) override;

		/**
		 * @fn void saveToMemory(void * content)
		 * @param[out] content The memory to save into.
		 * @brief Formate and save data into memory.
		 * @throw
		 * @see void ParsersaveToString(std::string & content)
		 */
		virtual void saveToMemory(void * content) override;

		/**
		 * @fn std::vector<RGB24> & getBuffer()
		 * @return The buffer of pixels.
		 * @brief Get the buffer containing the image pixels.
		 * @throw
		 */
		std::vector<RGB24> & getBuffer();

		/**
		 * @fn unsigned int getWidth() const
		 * @return The image width.
		 * @brief Get the image width.
		 * @throw
		 */
		unsigned int getWidth() const;

		/**
		 * @fn unsigned int getHeight() const
		 * @return The image height.
		 * @brief Get the image height.
		 * @throw
		 */
		unsigned int getHeight() const;

	private:
		/**
		 * @struct BMPHeader
		 * @brief The header of a BMP file according to the file format specification.
		 */
		struct BMPHeader
		{
			std::array<uint8_t, 2> magic;
			uint32_t size;
			uint32_t reserved;
			uint32_t pixelsOffset;
		};

		/**
		 * @struct BMPDIB
		 * @brief The internal data about the image, according to the file format specification.
		 */
		struct BMPDIB
		{
			uint32_t size;
			uint32_t width;
			uint32_t height;
			uint16_t planes;
			uint16_t bpp;
			uint32_t compression;
			uint32_t imageSize;
			uint32_t xPixelPerMeter;
			uint32_t yPixelPerMeter;
			uint32_t nbColors;
			uint32_t nbMajorColors;
		};

		/**
		 * @property _buffer
		 * @brief The image pixels.
		 */
		std::vector<RGB24> _buffer;

		/**
		 * @property _width
		 * @brief The image width.
		 */
		unsigned int _width;

		/**
		 * @property _height
		 * @brief The image height.
		 */
		unsigned int _height;
	};
}

#endif // PARSER_BMP_HPP