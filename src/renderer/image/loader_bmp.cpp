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

#include "renderer/pch.hpp"
#include "renderer/image/loader_bmp.hpp"

#include "utility/formats/bitmap.hpp"
#include "utility/debug.hpp"

namespace ece
{
	namespace renderer
	{
		namespace image
		{
			using utility::formats::bitmap::ParserBMP;

			void LoaderBMP::loadFromFile(const std::filesystem::path & filename)
			{
				auto file = std::ifstream(filename, std::ios::binary | std::ios::in);
				if (!file.is_open()) {
					throw FileException(FileCodeError::BAD_PATH, filename);
				}

				this->loadFromStream(file);
			}

			void LoaderBMP::loadFromString(const std::string & content)
			{
				auto stream = std::istringstream(content);
				if (!stream) {
					throw FileException(FileCodeError::PARSE_ERROR, "std::stringstream");
				}

				this->loadFromStream(stream);
			}

			void LoaderBMP::loadFromStream(std::istream & stream)
			{
				auto parser = ParserBMP{};
				parser.load(stream);

				auto & image = parser.getPixels();
				auto buffer = image.data();

				this->_image.resize(image.getWidth(), image.getHeight());
				for (auto i = std::size_t{ 0 }; i < image.getWidth() * image.getHeight(); ++i) {
					this->_image.data()[i].r = buffer[i][0];
					this->_image.data()[i].g = buffer[i][1];
					this->_image.data()[i].b = buffer[i][2];
					this->_image.data()[i].a = 255;
				}
			}
		} // namespace image
	} // namespace renderer
} // namespace ece