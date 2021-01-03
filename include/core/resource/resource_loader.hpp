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

#ifndef RESOURCE_LOADER_HPP
#define RESOURCE_LOADER_HPP

#include "core/config.hpp"
#include "core/pch.hpp"
#include "core/resource/resource_handler.hpp"

namespace ece
{
	namespace core
	{
		namespace resource
		{
			/**
			 * @class Loader
			 * @brief
			 */
			class ECE_CORE_API ResourceLoader
			{
			public:
				/**
				 * @fn constexpr ResourceLoader() noexcept
				 * @brief Default constructor.
				 * @throw noexcept
				 */
				constexpr ResourceLoader() noexcept = default;

				/**
				 * @fn ResourceLoader(const ResourceLoader & copy) noexcept
				 * @param[in] copy The ResourceLoader to copy from.
				 * @brief Default copy constructor.
				 * @throw noexcept
				 */
				ResourceLoader(const ResourceLoader & copy) noexcept = default;

				/**
				 * @fn ResourceLoader(ResourceLoader && move) noexcept
				 * @param[in] move The Loader to move.
				 * @brief Default move constructor.
				 * @throw noexcept
				 */
				ResourceLoader(ResourceLoader && move) noexcept = default;

				/**
				 * @fn ~ResourceLoader() noexcept
				 * @brief Default destructor.
				 * @throw noexcept
				 */
				~ResourceLoader() noexcept = default;

				/**
				 * @fn ResourceLoader & operator=(const ResourceLoader & copy) noexcept
				 * @param[in] copy The ResourceLoader to copy from.
				 * @return The ResourceLoader copied.
				 * @brief Default copy assignment operator.
				 * @throw noexcept
				 */
				ResourceLoader & operator=(const ResourceLoader & copy) noexcept = default;

				/**
				 * @fn ResourceLoader & operator=(ResourceLoader && move) noexcept
				 * @param[in] move The ResourceLoader to move.
				 * @return The ResourceLoader moved.
				 * @brief Default move assignment operator.
				 * @throw noexcept
				 */
				ResourceLoader & operator=(ResourceLoader && move) noexcept = default;

				/**
				 * @fn void loadFromFile(const std::filesystem::path & filename)
				 * @param[in] filename The name of the file to load data from.
				 * @brief Load and parse data from a file.
				 * @throw
				 */
				std::vector<ResourceHandler> loadFromFile(const std::filesystem::path & filename);

				/**
				 * @fn void loadFromString(const std::string & content)
				 * @param[in] content The string content to load data from.
				 * @brief Load and parse data from a string.
				 * @throw
				 */
				std::vector<ResourceHandler> loadFromString(const std::string & identifier, const std::string & extension, const std::string & content);

				/**
				 * @fn void loadFromStream(std::istream & stream)
				 * @param[inout] stream The stream to load through.
				 * @brief Load and parse data through a stream.
				 * @throw
				 */
				std::vector<ResourceHandler> loadFromStream(const std::string & identifier, const std::string & extension, std::istream & stream);

				/**
				 * @fn void saveToFile(const std::filesystem::path & filename)
				 * @param[out] filename The name of the file to save into.
				 * @brief Formate and save data into a file.
				 * @throw
				 */
				void saveToFile(const std::filesystem::path & filename, const std::vector<ResourceHandler> & resources);

				/**
				 * @fn void saveToString(std::string & content)
				 * @param[out] content The string buffer to save into.
				 * @brief Formate and save data into a string buffer.
				 * @throw
				 */
				void saveToString(std::string & content, const std::vector<ResourceHandler> & resources, const std::string & extension);

				/**
				 * @fn void saveToStream(const std::ostream & stream)
				 * @param[inout] stream The stream to save through.
				 * @brief Formate and save data through a stream.
				 * @throw
				 */
				void saveToStream(std::ostream & stream, const std::vector<ResourceHandler> & resources, const std::string & extension);
			};
		} // namespace resource
	} // namespace core
} // namespace ece

#endif // RESOURCE_LOADER_HPP