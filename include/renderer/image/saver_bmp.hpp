/*

	oooooooooooo       .o8                          .oooooo.                       .o88o.     .
	`888'     `8      "888                         d8P'  `Y8b                      888 `"   .o8
	 888          .oooo888   .ooooo.  ooo. .oo.   888          oooo d8b  .oooo.   o888oo  .o888oo
	 888oooo8    d88' `888  d88' `88b `888P"Y88b  888          `888""8P `P  )88b   888      888
	 888    "    888   888  888ooo888  888   888  888           888      .oP"888   888      888
	 888       o 888   888  888    .o  888   888  `88b    ooo   888     d8(  888   888      888 .
	o888ooooood8 `Y8bod88P" `Y8bod8P' o888o o888o  `Y8bood8P'  d888b    `Y888""8o o888o     "888"

															ooooooooo.                               .o8
															`888   `Y88.                            "888
															 888   .d88'  .ooooo.  ooo. .oo.    .oooo888   .ooooo.  oooo d8b  .ooooo.  oooo d8b
															 888ooo88P'  d88' `88b `888P"Y88b  d88' `888  d88' `88b `888""8P d88' `88b `888""8P
															 888`88b.    888ooo888  888   888  888   888  888ooo888  888     888ooo888  888
															 888  `88b.  888    .o  888   888  888   888  888    .o  888     888    .o  888
															o888o  o888o `Y8bod8P' o888o o888o `Y8bod88P" `Y8bod8P' d888b    `Y8bod8P' d888b



				This file is part of EdenCraft Engine - Renderer module.
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

#ifndef SAVER_BMP_HPP
#define SAVER_BMP_HPP

#include "renderer/config.hpp"
#include "utility/file_system.hpp"
#include "renderer/image/image.hpp"
#include "utility/types.hpp"
#include "core/format.hpp"

namespace ece
{
	namespace renderer
	{
		namespace image
		{
			/**
			 * @class SaverBMP
			 * @brief
			 */
			class ECE_RENDERER_API SaverBMP: public Saver
			{
			public:
				/**
				 * @fn constexpr SaverBMP() noexcept
				 * @brief Default constructor.
				 * @throw noexcept
				 */
				constexpr SaverBMP() noexcept = default;

				/**
				 * @fn SaverBMP(const SaverBMP & copy) noexcept
				 * @param[in] copy The SaverBMP to copy from.
				 * @brief Default copy constructor.
				 * @throw noexcept
				 */
				SaverBMP(const SaverBMP & copy) noexcept = default;

				/**
				 * @fn SaverBMP(SaverBMP && move) noexcept
				 * @param[in] move The SaverBMP to move.
				 * @brief Default move constructor.
				 * @throw noexcept
				 */
				SaverBMP(SaverBMP && move) noexcept = default;

				/**
				 * @fn ~SaverBMP() noexcept
				 * @brief Default destructor.
				 * @throw noexcept
				 */
				~SaverBMP() noexcept = default;

				/**
				 * @fn SaverBMP & operator=(const SaverBMP & copy) noexcept
				 * @param[in] copy The SaverBMP to copy from.
				 * @return The SaverBMP copied.
				 * @brief Default copy assignment operator.
				 * @throw noexcept
				 */
				SaverBMP & operator=(const SaverBMP & copy) noexcept = default;

				/**
				 * @fn SaverBMP & operator=(SaverBMP && move) noexcept
				 * @param[in] move The SaverBMP to move.
				 * @return The SaverBMP moved.
				 * @brief Default move assignment operator.
				 * @throw noexcept
				 */
				SaverBMP & operator=(SaverBMP && move) noexcept = default;

				/**
				 * @fn void saveToFile(const std::filesystem::path & filename)
				 * @param[out] filename The name of the file to save into.
				 * @brief Formate and save data into a file.
				 * @throw
				 */
				virtual void save(StreamInfoOut info) override;

				virtual auto isBinary() const noexcept -> bool override { return true; }
			};
		} // namespace image
	} // namespace renderer
} // namespace ece

#endif // SAVER_BMP_HPP