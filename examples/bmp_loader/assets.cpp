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
#include "core/format.hpp"
#include "utility/debug.hpp"

void Assets::loadTexture(const std::string & name, const std::string & path)
{
	ece::INFO << "Starting loading `" << name << "` from `" << path << "`..." << ece::flush;
	auto texture = ece::makeResource<ece::Texture2D>(name);
	texture->bind(ece::Texture::Target::TEXTURE_2D);
	texture->loadFromFile(ece::Texture::TypeTarget::TEXTURE_2D, path);
	ece::INFO << "`" << name << "` loaded correctly from `" << path << "`." << ece::flush;
}

void Assets::loadAssets()
{
	assertAnyExceptionThrown(Assets::loadTexture("badbitcount", "../../examples/bmp_loader/assets/b/badbitcount.bmp"));
	assertAnyExceptionThrown(Assets::loadTexture("badbitssize", "../../examples/bmp_loader/assets/b/badbitssize.bmp"));
	assertAnyExceptionThrown(Assets::loadTexture("baddens1", "../../examples/bmp_loader/assets/b/baddens1.bmp"));
	assertAnyExceptionThrown(Assets::loadTexture("baddens2", "../../examples/bmp_loader/assets/b/baddens2.bmp"));
	assertAnyExceptionThrown(Assets::loadTexture("badfilesize", "../../examples/bmp_loader/assets/b/badfilesize.bmp"));
	assertAnyExceptionThrown(Assets::loadTexture("badheadersize", "../../examples/bmp_loader/assets/b/badheadersize.bmp"));
	assertAnyExceptionThrown(Assets::loadTexture("badpalettesize", "../../examples/bmp_loader/assets/b/badpalettesize.bmp"));
	assertAnyExceptionThrown(Assets::loadTexture("badplanes", "../../examples/bmp_loader/assets/b/badplanes.bmp"));
	assertAnyExceptionThrown(Assets::loadTexture("badrle", "../../examples/bmp_loader/assets/b/badrle.bmp"));
	assertAnyExceptionThrown(Assets::loadTexture("badrle4", "../../examples/bmp_loader/assets/b/badrle4.bmp"));
	assertAnyExceptionThrown(Assets::loadTexture("badrle4bis", "../../examples/bmp_loader/assets/b/badrle4bis.bmp"));
	assertAnyExceptionThrown(Assets::loadTexture("badrle4ter", "../../examples/bmp_loader/assets/b/badrle4ter.bmp"));
	assertAnyExceptionThrown(Assets::loadTexture("badrlebis", "../../examples/bmp_loader/assets/b/badrlebis.bmp"));
	assertAnyExceptionThrown(Assets::loadTexture("badrleter", "../../examples/bmp_loader/assets/b/badrleter.bmp"));
	assertAnyExceptionThrown(Assets::loadTexture("badwidth", "../../examples/bmp_loader/assets/b/badwidth.bmp"));
	assertAnyExceptionThrown(Assets::loadTexture("pal8badindex", "../../examples/bmp_loader/assets/b/pal8badindex.bmp"));
	assertAnyExceptionThrown(Assets::loadTexture("reallybig", "../../examples/bmp_loader/assets/b/reallybig.bmp"));
	assertAnyExceptionThrown(Assets::loadTexture("rgb16-880", "../../examples/bmp_loader/assets/b/rgb16-880.bmp"));
	//assertAnyExceptionThrown(Assets::loadTexture("rletopdown", "../../examples/bmp_loader/assets/b/rletopdown.bmp"));
	//assertAnyExceptionThrown(Assets::loadTexture("shortfile", "../../examples/bmp_loader/assets/b/shortfile.bmp"));
}