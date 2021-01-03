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

#ifndef JSON_LOADER_HPP
#define JSON_LOADER_HPP

#include "core/config.hpp"
#include "core/pch.hpp"
#include "core/format/loader.hpp"
#include "core/format/saver.hpp"

namespace ece
{
	namespace core
	{
		namespace format
		{
			/**
			 * @class JSONLoader
			 * @brief
			 */
			class ECE_CORE_API JSONLoader: public Loader, public Saver
			{
			public:
				/**
				 * @fn constexpr JSONLoader() noexcept
				 * @brief Default constructor.
				 * @throw noexcept
				 */
				constexpr JSONLoader() noexcept = default;

				/**
				 * @fn JSONLoader(const JSONLoader & copy) noexcept
				 * @param[in] copy The JSONLoader to copy from.
				 * @brief Default copy constructor.
				 * @throw noexcept
				 */
				JSONLoader(const JSONLoader & copy) noexcept = default;

				/**
				 * @fn JSONLoader(JSONLoader && move) noexcept
				 * @param[in] move The JSONLoader to move.
				 * @brief Default move constructor.
				 * @throw noexcept
				 */
				JSONLoader(JSONLoader && move) noexcept = default;

				/**
				 * @fn ~JSONLoader() noexcept
				 * @brief Default destructor.
				 * @throw noexcept
				 */
				~JSONLoader() noexcept = default;

				/**
				 * @fn JSONLoader & operator=(const JSONLoader & copy) noexcept
				 * @param[in] copy The JSONLoader to copy from.
				 * @return The JSONLoader copied.
				 * @brief Default copy assignment operator.
				 * @throw noexcept
				 */
				JSONLoader & operator=(const JSONLoader & copy) noexcept = default;

				/**
				 * @fn JSONLoader & operator=(JSONLoader && move) noexcept
				 * @param[in] move The JSONLoader to move.
				 * @return The JSONLoader moved.
				 * @brief Default move assignment operator.
				 * @throw noexcept
				 */
				JSONLoader & operator=(JSONLoader && move) noexcept = default;

				/**
				 * @fn void loadFromFile(const std::filesystem::path & filename)
				 * @param[in] filename The name of the file to load data from.
				 * @brief Load and parse data from a file.
				 * @throw
				 */
				virtual std::vector<ResourceHandler> load(StreamInfoIn info) override;

				/**
				 * @fn void saveToFile(const std::filesystem::path & filename)
				 * @param[out] filename The name of the file to save into.
				 * @brief Formate and save data into a file.
				 * @throw
				 */
				virtual void save(StreamInfoOut info) override;
			};
		}
	}
}

#endif // JSON_LOADER_HPP