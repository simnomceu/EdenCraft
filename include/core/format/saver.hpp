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

#ifndef SAVER_HPP
#define SAVER_HPP

#include "core/config.hpp"
#include "core/pch.hpp"
#include "core/format/stream_info.hpp"

namespace ece
{
	namespace core
	{
		namespace format
		{
			/**
			 * @class Saver
			 * @brief
			 */
			class ECE_CORE_API Saver
			{
			public:
				/**
				 * @fn constexpr Saver() noexcept
				 * @brief Default constructor.
				 * @throw noexcept
				 */
				constexpr Saver() noexcept = default;

				/**
				 * @fn Saver(const Saver & copy) noexcept
				 * @param[in] copy The Saver to copy from.
				 * @brief Default copy constructor.
				 * @throw noexcept
				 */
				Saver(const Saver & copy) noexcept = default;

				/**
				 * @fn Saver(Saver && move) noexcept
				 * @param[in] move The Saver to move.
				 * @brief Default move constructor.
				 * @throw noexcept
				 */
				Saver(Saver && move) noexcept = default;

				/**
				 * @fn ~Saver() noexcept
				 * @brief Default destructor.
				 * @throw noexcept
				 */
				virtual ~Saver() noexcept = default;

				/**
				 * @fn Saver & operator=(const Saver & copy) noexcept
				 * @param[in] copy The Saver to copy from.
				 * @return The Saver copied.
				 * @brief Default copy assignment operator.
				 * @throw noexcept
				 */
				Saver & operator=(const Saver & copy) noexcept = default;

				/**
				 * @fn Saver & operator=(Saver && move) noexcept
				 * @param[in] move The Saver to move.
				 * @return The Saver moved.
				 * @brief Default move assignment operator.
				 * @throw noexcept
				 */
				Saver & operator=(Saver && move) noexcept = default;

        		/**
        		 * @fn void saveToFile(const std::filesystem::path & filename)
        		 * @param[out] filename The name of the file to save into.
        		 * @brief Formate and save data into a file.
        		 * @throw
        		 */
        		virtual void save(StreamInfoOut info) = 0;

				virtual auto isBinary() const noexcept -> bool { return false; }
			};
		} // namespace format
	} // namespace core
} // namespace ece

#endif // SAVER_HPP