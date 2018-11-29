/*

	oooooooooooo       .o8                          .oooooo.                       .o88o.     .
	`888'     `8      "888                         d8P'  `Y8b                      888 `"   .o8
	 888          .oooo888   .ooooo.  ooo. .oo.   888          oooo d8b  .oooo.   o888oo  .o888oo
	 888oooo8    d88' `888  d88' `88b `888P"Y88b  888          `888""8P `P  )88b   888      888
	 888    "    888   888  888ooo888  888   888  888           888      .oP"888   888      888
	 888       o 888   888  888    .o  888   888  `88b    ooo   888     d8(  888   888      888 .
	o888ooooood8 `Y8bod88P" `Y8bod8P' o888o o888o  `Y8bood8P'  d888b    `Y888""8o o888o     "888"

															oooooooooo.               .o8        .o8       oooo            oooooo     oooo           oooo  oooo
															`888'   `Y8b             "888       "888       `888             `888.     .8'            `888  `888
															 888     888 oooo  oooo   888oooo.   888oooo.   888   .ooooo.    `888.   .8'    .ooooo.   888   888   .ooooo.  oooo    ooo
															 888oooo888' `888  `888   d88' `88b  d88' `88b  888  d88' `88b    `888. .8'    d88' `88b  888   888  d88' `88b  `88.  .8'
															 888    `88b  888   888   888   888  888   888  888  888ooo888     `888.8'     888   888  888   888  888ooo888   `88..8'
															 888    .88P  888   888   888   888  888   888  888  888    .o      `888'      888   888  888   888  888    .o    `888'
															o888bood8P'   `V88V"V8P'  `Y8bod8P'  `Y8bod8P' o888o `Y8bod8P'       `8'       `Y8bod8P' o888o o888o `Y8bod8P'     .8'
																																										   .o..P'
																																										   `Y8P'



				This file is part of EdenCraft Engine - MoreCube sample.
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

#include "assets.hpp"

#include "core/resource.hpp"
#include "renderer/image.hpp"

void Assets::loadTexture(const std::string & name, const std::string & path)
{
	auto blue0 = ece::makeResource<ece::Texture2D>(name);
	blue0->loadFromFile(ece::Texture::TypeTarget::TEXTURE_2D, path);
	blue0->bind(ece::Texture::Target::TEXTURE_2D);
}

void Assets::loadAssets()
{
	Assets::loadTexture("blue0", "../../examples/bubble_volley/assets/0b.bmp");
	Assets::loadTexture("blue1", "../../examples/bubble_volley/assets/1b.bmp");
	Assets::loadTexture("blue2", "../../examples/bubble_volley/assets/2b.bmp");
	Assets::loadTexture("blue3", "../../examples/bubble_volley/assets/3b.bmp");
	Assets::loadTexture("blue4", "../../examples/bubble_volley/assets/4b.bmp");

	Assets::loadTexture("red0", "../../examples/bubble_volley/assets/0r.bmp");
	Assets::loadTexture("red1", "../../examples/bubble_volley/assets/1r.bmp");
	Assets::loadTexture("red2", "../../examples/bubble_volley/assets/2r.bmp");
	Assets::loadTexture("red3", "../../examples/bubble_volley/assets/3r.bmp");
	Assets::loadTexture("red4", "../../examples/bubble_volley/assets/4r.bmp");

	Assets::loadTexture("ball", "../../examples/bubble_volley/assets/ball01.bmp");
	Assets::loadTexture("key", "../../examples/bubble_volley/assets/key.bmp");
	Assets::loadTexture("pokal", "../../examples/bubble_volley/assets/pokal.bmp");
	Assets::loadTexture("strand1", "../../examples/bubble_volley/assets/strand1.bmp");
	Assets::loadTexture("titel", "../../examples/bubble_volley/assets/titel.bmp");

	Assets::loadTexture("f0", "../../examples/bubble_volley/assets/f0.bmp");
	Assets::loadTexture("f1", "../../examples/bubble_volley/assets/f1.bmp");
	Assets::loadTexture("f2", "../../examples/bubble_volley/assets/f2.bmp");
	Assets::loadTexture("f3", "../../examples/bubble_volley/assets/f3.bmp");
	Assets::loadTexture("f4", "../../examples/bubble_volley/assets/f4.bmp");
	Assets::loadTexture("f5", "../../examples/bubble_volley/assets/f5.bmp");
	Assets::loadTexture("f6", "../../examples/bubble_volley/assets/f6.bmp");
	Assets::loadTexture("f7", "../../examples/bubble_volley/assets/f7.bmp");
	Assets::loadTexture("f8", "../../examples/bubble_volley/assets/f8.bmp");
	Assets::loadTexture("f9", "../../examples/bubble_volley/assets/f9.bmp");
	Assets::loadTexture("f10", "../../examples/bubble_volley/assets/f10.bmp");
}