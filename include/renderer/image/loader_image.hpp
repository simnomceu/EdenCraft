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

#ifndef LOADER_IMAGE_HPP
#define LOADER_IMAGE_HPP

#include "renderer/config.hpp"
#include "utility/file_system.hpp"
#include "renderer/image/image.hpp"
#include "utility/types.hpp"

namespace ece
{
	namespace renderer
	{
		namespace image
		{
			/**
			 * @class LoaderImage
			 * @brief
			 */
			class LoaderImage: public Loader
			{
			public:
				/**
				 * @fn constexpr LoaderImage() noexcept
				 * @brief Default constructor.
				 * @throw noexcept
				 */
				constexpr LoaderImage() noexcept = default;

				/**
				 * @fn LoaderImage(const LoaderImage & copy) noexcept
				 * @param[in] copy The LoaderImage to copy from.
				 * @brief Default copy constructor.
				 * @throw noexcept
				 */
				LoaderImage(const LoaderImage & copy) noexcept = default;

				/**
				 * @fn LoaderImage(LoaderImage && move) noexcept
				 * @param[in] move The LoaderImage to move.
				 * @brief Default move constructor.
				 * @throw noexcept
				 */
				LoaderImage(LoaderImage && move) noexcept = default;

				/**
				 * @fn ~LoaderImage() noexcept
				 * @brief Default destructor.
				 * @throw noexcept
				 */
				~LoaderImage() noexcept = default;

				/**
				 * @fn LoaderImage & operator=(const LoaderImage & copy) noexcept
				 * @param[in] copy The LoaderImage to copy from.
				 * @return The LoaderImage copied.
				 * @brief Default copy assignment operator.
				 * @throw noexcept
				 */
				LoaderImage & operator=(const LoaderImage & copy) noexcept = default;

				/**
				 * @fn LoaderImage & operator=(LoaderImage && move) noexcept
				 * @param[in] move The LoaderImage to move.
				 * @return The LoaderImage moved.
				 * @brief Default move assignment operator.
				 * @throw noexcept
				 */
				LoaderImage & operator=(LoaderImage && move) noexcept = default;

				virtual auto getImage() -> Image<RGBA32> & = 0;
				virtual auto getImage() const -> const Image<RGBA32> & = 0;
			};
		} // namespace image
	} // namespace renderer
} // namespace ece

#endif // LOADER_IMAGE_HPP