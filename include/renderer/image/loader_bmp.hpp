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

#ifndef LOADER_BMP_HPP
#define LOADER_BMP_HPP

#include "renderer/config.hpp"
#include "renderer/image/loader_image.hpp"

namespace ece
{
	namespace renderer
	{
		namespace image
		{
			/**
			 * @class LoaderBMP
			 * @brief
			 */
			class ECE_RENDERER_API LoaderBMP: public LoaderImage
			{
			public:
				/**
				 * @fn LoaderBMP() noexcept
				 * @brief Default constructor.
				 * @throw noexcept
				 */
				LoaderBMP() noexcept = default;

				/**
				 * @fn LoaderBMP(const LoaderBMP & copy) noexcept
				 * @param[in] copy The LoaderBMP to copy from.
				 * @brief Default copy constructor.
				 * @throw noexcept
				 */
				LoaderBMP(const LoaderBMP & copy) noexcept = default;

				/**
				 * @fn LoaderBMP(LoaderBMP && move) noexcept
				 * @param[in] move The LoaderBMP to move.
				 * @brief Default move constructor.
				 * @throw noexcept
				 */
				LoaderBMP(LoaderBMP && move) noexcept = default;

				/**
				 * @fn ~LoaderBMP() noexcept
				 * @brief Default destructor.
				 * @throw noexcept
				 */
				~LoaderBMP() noexcept = default;

				/**
				 * @fn LoaderBMP & operator=(const LoaderBMP & copy) noexcept
				 * @param[in] copy The LoaderBMP to copy from.
				 * @return The LoaderBMP copied.
				 * @brief Default copy assignment operator.
				 * @throw noexcept
				 */
				LoaderBMP & operator=(const LoaderBMP & copy) noexcept = default;

				/**
				 * @fn LoaderBMP & operator=(LoaderBMP && move) noexcept
				 * @param[in] move The LoaderBMP to move.
				 * @return The LoaderBMP moved.
				 * @brief Default move assignment operator.
				 * @throw noexcept
				 */
				LoaderBMP & operator=(LoaderBMP && move) noexcept = default;

				/**
				 * @fn void loadFromFile(const std::string & filename)
				 * @param[in] filename The name of the file to load data from.
				 * @brief Load and parse data from a file.
				 * @throw
				 */
				virtual void loadFromFile(const std::string & filename) override;

				/**
				 * @fn void loadFromString(const std::string & content)
				 * @param[in] content The string content to load data from.
				 * @brief Load and parse data from a string.
				 * @throw
				 */
				virtual void loadFromString(const std::string & content) override;

				/**
				 * @fn void loadFromStream(std::istream & stream)
				 * @param[inout] stream The stream to load through.
				 * @brief Load and parse data through a stream.
				 * @throw
				 */
				virtual void loadFromStream(std::istream & stream) override;

				inline virtual auto getImage() -> Image<RGBA32> & override;
				inline virtual auto getImage() const -> const Image<RGBA32> & override;

			private:
				Image<RGBA32> _image;
			};
		} // namespace image
	} // namespace renderer
} // namespace ece

#include "renderer/image/loader_bmp.inl"

#endif // LOADER_BMP_HPP