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

#include "libpng/pch.hpp"
#include "libpng/loader/loader_png.hpp"

#include "core/resource.hpp"

namespace ece
{
	namespace loader
	{
		std::vector<ResourceHandler> LoaderPNG::load(StreamInfoIn info)
		{
			std::vector<unsigned char> image;
			unsigned width, height;
			unsigned error = lodepng::decode(image, width, height, info.filename);

			//if there's an error, display it
			if (error) {
				ERROR << "decoder error " << error << ": " << lodepng_error_text(error) << flush;
			}

			auto resourceImage = ece::Image<ece::RGBA32>();
			resourceImage.resize(width, height);
			for (auto i = std::size_t{ 0 }; i < width * height * 4; i+=4) {
				resourceImage.data()[width * height - 1 - i / 4].r = image[i];
				resourceImage.data()[width * height - 1 - i / 4].g = image[i+1];
				resourceImage.data()[width * height - 1 - i / 4].b = image[i+2];
				resourceImage.data()[width * height - 1 - i / 4].a = image[i+3];
			}

			return { makeResource<ece::Image<ece::RGBA32>>(info.identifier, resourceImage) };
		}

		void LoaderPNG::save(ece::StreamInfoOut info)
		{
			auto resourceImage = info.resources[0].get<Image<RGBA32>>();

			auto image = std::vector<unsigned char>(resourceImage->getWidth() * resourceImage->getHeight());

			for (auto i = std::size_t{ 0 }; i < resourceImage->getWidth() * resourceImage->getHeight() * 4; i+=4) {
				image[i] = resourceImage->data()[resourceImage->getWidth() * resourceImage->getHeight() - 1 - i / 4].r;
				image[i+1] = resourceImage->data()[resourceImage->getWidth() * resourceImage->getHeight() - 1 - i / 4].g;
				image[i+2] = resourceImage->data()[resourceImage->getWidth() * resourceImage->getHeight() - 1 - i / 4].b;
				image[i+3] = resourceImage->data()[resourceImage->getWidth() * resourceImage->getHeight() - 1 - i / 4].a;
			}

			unsigned error = lodepng::encode(info.filename, image, resourceImage->getWidth(), resourceImage->getHeight());

			//if there's an error, display it
			if (error) {
				ece::ERROR << "encoder error " << error << ": " << lodepng_error_text(error) << ece::flush;
			}
		}
	} // namespace loader
} // namespace ece