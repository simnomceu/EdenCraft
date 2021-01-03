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
#include "utility/formats.hpp"
#include "utility/algorithm.hpp"

void Assets::loadTexture(const std::string & name, const std::string & path)
{
	ece::INFO << "Starting loading `" << name << "` from `" << path << "`..." << ece::flush;

	auto file = std::ifstream(path, std::ios::binary | std::ios::in);
	if (!file.is_open()) {
		throw ece::FileException(ece::FileCodeError::BAD_PATH, path);
	}
	auto parser = ece::ParserBMP{};
	parser.load(file);
	ece::INFO << "`" << name << "` loaded correctly from `" << path << "`." << ece::flush;
}

void Assets::loadAssets()
{
	auto compressed8 = std::vector<std::uint8_t>{ 0x03, 0x04, 0x05, 0x06, 0x00, 0x03, 0x45, 0x56, 0x67, 0x00, 0x02, 0x78, 0x00, 0x02, 0x05, 0x01, 0x02, 0x78, 0x00, 0x00, 0x09, 0x1E, 0x00, 0x01 };
	auto result8 = ece::uncompressRLE8(compressed8, 32, 4);
	for (auto j = std::size_t{ 0 }; j < 4; ++j) {
		for (auto i = std::size_t{ 0 }; i < 32; ++i) {
			if (result8[j * 32 + i] < 10) {
				ece::SYSTEM << 0;
			}
			ece::SYSTEM << std::hex << (int)result8[j * 32 + i] << ' ';
		}
		ece::SYSTEM << ece::flush;
	}
	ece::SYSTEM << ece::flush << ece::flush;

	auto compressed4 = std::vector<std::uint8_t>{ 0x03, 0x04, 0x05, 0x06, 0x00, 0x06, 0x45, 0x56, 0x67, 0x00, 0x04, 0x78, 0x00, 0x02, 0x05, 0x01, 0x04, 0x78, 0x00, 0x00, 0x09, 0x1E, 0x00, 0x01 };
	auto result4 = ece::uncompressRLE4(compressed4, 32, 4);
	for (auto j = std::size_t{ 0 }; j < 4; ++j) {
		for (auto i = std::size_t{ 0 }; i < 32; ++i) {
			ece::SYSTEM << std::hex << (int)result4[j * 32 + i] << ' ';
		}
		ece::SYSTEM << ece::flush;
	}
	ece::SYSTEM << ece::flush << ece::flush;

	assertAnyExceptionThrown(Assets::loadTexture("b-badbitcount", "../../examples/bmp_loader/assets/b/badbitcount.bmp"));
	assertAnyExceptionThrown(Assets::loadTexture("b-badbitssize", "../../examples/bmp_loader/assets/b/badbitssize.bmp"));
	assertAnyExceptionThrown(Assets::loadTexture("b-baddens1", "../../examples/bmp_loader/assets/b/baddens1.bmp"));
	assertAnyExceptionThrown(Assets::loadTexture("b-baddens2", "../../examples/bmp_loader/assets/b/baddens2.bmp"));
	assertAnyExceptionThrown(Assets::loadTexture("b-badfilesize", "../../examples/bmp_loader/assets/b/badfilesize.bmp"));
	assertAnyExceptionThrown(Assets::loadTexture("b-badheadersize", "../../examples/bmp_loader/assets/b/badheadersize.bmp"));
	assertAnyExceptionThrown(Assets::loadTexture("b-badpalettesize", "../../examples/bmp_loader/assets/b/badpalettesize.bmp"));
	assertAnyExceptionThrown(Assets::loadTexture("b-badplanes", "../../examples/bmp_loader/assets/b/badplanes.bmp"));
	assertAnyExceptionThrown(Assets::loadTexture("b-badrle", "../../examples/bmp_loader/assets/b/badrle.bmp"));
	assertAnyExceptionThrown(Assets::loadTexture("b-badrle4", "../../examples/bmp_loader/assets/b/badrle4.bmp"));
//	assertAnyExceptionThrown(Assets::loadTexture("b-badrle4bis", "../../examples/bmp_loader/assets/b/badrle4bis.bmp")); // no errors ?
	assertAnyExceptionThrown(Assets::loadTexture("b-badrle4ter", "../../examples/bmp_loader/assets/b/badrle4ter.bmp"));
//	assertAnyExceptionThrown(Assets::loadTexture("b-badrlebis", "../../examples/bmp_loader/assets/b/badrlebis.bmp")); // no errors ?
	assertAnyExceptionThrown(Assets::loadTexture("b-badrleter", "../../examples/bmp_loader/assets/b/badrleter.bmp"));
	assertAnyExceptionThrown(Assets::loadTexture("b-badwidth", "../../examples/bmp_loader/assets/b/badwidth.bmp"));
	assertAnyExceptionThrown(Assets::loadTexture("b-pal8badindex", "../../examples/bmp_loader/assets/b/pal8badindex.bmp"));
	assertAnyExceptionThrown(Assets::loadTexture("b-reallybig", "../../examples/bmp_loader/assets/b/reallybig.bmp"));
	assertAnyExceptionThrown(Assets::loadTexture("b-rgb16-880", "../../examples/bmp_loader/assets/b/rgb16-880.bmp"));
	assertAnyExceptionThrown(Assets::loadTexture("b-rletopdown", "../../examples/bmp_loader/assets/b/rletopdown.bmp"));
	assertAnyExceptionThrown(Assets::loadTexture("b-shortfile", "../../examples/bmp_loader/assets/b/shortfile.bmp"));

	assertAnyExceptionThrown(Assets::loadTexture("q-pal1huff", "../../examples/bmp_loader/assets/q/pal1huff.bmp"));
	assertNoExceptionThrown(Assets::loadTexture("q-pal1p1", "../../examples/bmp_loader/assets/q/pal1p1.bmp"));
	assertNoExceptionThrown(Assets::loadTexture("q-pal2", "../../examples/bmp_loader/assets/q/pal2.bmp"));
	assertNoExceptionThrown(Assets::loadTexture("q-pal2color", "../../examples/bmp_loader/assets/q/pal2color.bmp"));
 	assertNoExceptionThrown(Assets::loadTexture("q-pal4rlecut", "../../examples/bmp_loader/assets/q/pal4rlecut.bmp"));
	assertNoExceptionThrown(Assets::loadTexture("q-pal4rletrns", "../../examples/bmp_loader/assets/q/pal4rletrns.bmp"));
	assertNoExceptionThrown(Assets::loadTexture("q-pal8offs", "../../examples/bmp_loader/assets/q/pal8offs.bmp"));
//	assertNoExceptionThrown(Assets::loadTexture("q-pal8os2-hs", "../../examples/bmp_loader/assets/q/pal8os2-hs.bmp")); // Weird bitmap.header.size value of 26 ...
	assertAnyExceptionThrown(Assets::loadTexture("q-pal8os2sp", "../../examples/bmp_loader/assets/q/pal8os2sp.bmp"));
	assertAnyExceptionThrown(Assets::loadTexture("q-pal8os2-sz", "../../examples/bmp_loader/assets/q/pal8os2-sz.bmp"));
	assertNoExceptionThrown(Assets::loadTexture("q-pal8os2v2", "../../examples/bmp_loader/assets/q/pal8os2v2.bmp"));
//	assertNoExceptionThrown(Assets::loadTexture("q-pal8os2v2-16", "../../examples/bmp_loader/assets/q/pal8os2v2-16.bmp"));
	assertAnyExceptionThrown(Assets::loadTexture("q-pal8os2v2-40sz", "../../examples/bmp_loader/assets/q/pal8os2v2-40sz.bmp"));
	assertAnyExceptionThrown(Assets::loadTexture("q-pal8os2v2-sz", "../../examples/bmp_loader/assets/q/pal8os2v2-sz.bmp"));
	assertAnyExceptionThrown(Assets::loadTexture("q-pal8oversizepal", "../../examples/bmp_loader/assets/q/pal8oversizepal.bmp"));
	assertNoExceptionThrown(Assets::loadTexture("q-pal8rlecut", "../../examples/bmp_loader/assets/q/pal8rlecut.bmp"));
	assertNoExceptionThrown(Assets::loadTexture("q-pal8rletrns", "../../examples/bmp_loader/assets/q/pal8rletrns.bmp"));
	assertNoExceptionThrown(Assets::loadTexture("q-rgb16-231", "../../examples/bmp_loader/assets/q/rgb16-231.bmp"));
	assertNoExceptionThrown(Assets::loadTexture("q-rgb16-3103", "../../examples/bmp_loader/assets/q/rgb16-3103.bmp"));
	assertNoExceptionThrown(Assets::loadTexture("q-rgb16faketrns", "../../examples/bmp_loader/assets/q/rgb16faketrns.bmp"));
	assertNoExceptionThrown(Assets::loadTexture("q-rgb24jpeg", "../../examples/bmp_loader/assets/q/rgb24jpeg.bmp"));
	assertNoExceptionThrown(Assets::loadTexture("q-rgb24largepal", "../../examples/bmp_loader/assets/q/rgb24largepal.bmp"));
	assertNoExceptionThrown(Assets::loadTexture("q-rgb24lprof", "../../examples/bmp_loader/assets/q/rgb24lprof.bmp"));
	assertNoExceptionThrown(Assets::loadTexture("q-rgb24png", "../../examples/bmp_loader/assets/q/rgb24png.bmp"));
	assertNoExceptionThrown(Assets::loadTexture("q-rgb24prof", "../../examples/bmp_loader/assets/q/rgb24prof.bmp"));
	assertNoExceptionThrown(Assets::loadTexture("q-rgb24prof2", "../../examples/bmp_loader/assets/q/rgb24prof2.bmp"));
	assertNoExceptionThrown(Assets::loadTexture("q-rgb32-7187", "../../examples/bmp_loader/assets/q/rgb32-7187.bmp"));
	assertNoExceptionThrown(Assets::loadTexture("q-rgb32-111110", "../../examples/bmp_loader/assets/q/rgb32-111110.bmp"));
	assertNoExceptionThrown(Assets::loadTexture("q-rgb32fakealpha", "../../examples/bmp_loader/assets/q/rgb32fakealpha.bmp"));
	assertNoExceptionThrown(Assets::loadTexture("q-rgb32h52", "../../examples/bmp_loader/assets/q/rgb32h52.bmp"));
	assertNoExceptionThrown(Assets::loadTexture("q-rgb32-xbgr", "../../examples/bmp_loader/assets/q/rgb32-xbgr.bmp"));
	assertNoExceptionThrown(Assets::loadTexture("q-rgba16-1924", "../../examples/bmp_loader/assets/q/rgba16-1924.bmp"));
	assertNoExceptionThrown(Assets::loadTexture("q-rgba16-4444", "../../examples/bmp_loader/assets/q/rgba16-4444.bmp"));
	assertNoExceptionThrown(Assets::loadTexture("q-rgba16-5551", "../../examples/bmp_loader/assets/q/rgba16-5551.bmp"));
	assertNoExceptionThrown(Assets::loadTexture("q-rgba32", "../../examples/bmp_loader/assets/q/rgba32.bmp"));
	assertNoExceptionThrown(Assets::loadTexture("q-rgba32-61754", "../../examples/bmp_loader/assets/q/rgba32-61754.bmp"));
	assertNoExceptionThrown(Assets::loadTexture("q-rgba32-81284", "../../examples/bmp_loader/assets/q/rgba32-81284.bmp"));
	assertNoExceptionThrown(Assets::loadTexture("q-rgba32-1010102", "../../examples/bmp_loader/assets/q/rgba32-1010102.bmp"));
	assertNoExceptionThrown(Assets::loadTexture("q-rgba32abf", "../../examples/bmp_loader/assets/q/rgba32abf.bmp"));
	assertNoExceptionThrown(Assets::loadTexture("q-rgba32h56", "../../examples/bmp_loader/assets/q/rgba32h56.bmp"));

	assertNoExceptionThrown(Assets::loadTexture("g-pal1", "../../examples/bmp_loader/assets/g/pal1.bmp"));
	assertNoExceptionThrown(Assets::loadTexture("g-pal1bg", "../../examples/bmp_loader/assets/g/pal1bg.bmp"));
	assertNoExceptionThrown(Assets::loadTexture("g-pal1wb", "../../examples/bmp_loader/assets/g/pal1wb.bmp"));
	assertNoExceptionThrown(Assets::loadTexture("g-pal4", "../../examples/bmp_loader/assets/g/pal4.bmp"));
	assertNoExceptionThrown(Assets::loadTexture("g-pal4gs", "../../examples/bmp_loader/assets/g/pal4gs.bmp"));
	assertNoExceptionThrown(Assets::loadTexture("g-pal4rle", "../../examples/bmp_loader/assets/g/pal4rle.bmp"));
	assertNoExceptionThrown(Assets::loadTexture("g-pal8", "../../examples/bmp_loader/assets/g/pal8.bmp"));
	assertNoExceptionThrown(Assets::loadTexture("g-pal8-0", "../../examples/bmp_loader/assets/g/pal8-0.bmp"));
	assertNoExceptionThrown(Assets::loadTexture("g-pal8gs", "../../examples/bmp_loader/assets/g/pal8gs.bmp"));
	assertNoExceptionThrown(Assets::loadTexture("g-pal8nonsquare", "../../examples/bmp_loader/assets/g/pal8nonsquare.bmp"));
	assertNoExceptionThrown(Assets::loadTexture("g-pal8os2", "../../examples/bmp_loader/assets/g/pal8os2.bmp"));
	assertNoExceptionThrown(Assets::loadTexture("g-pal8rle", "../../examples/bmp_loader/assets/g/pal8rle.bmp"));
	assertNoExceptionThrown(Assets::loadTexture("g-pal8topdown", "../../examples/bmp_loader/assets/g/pal8topdown.bmp"));
	assertNoExceptionThrown(Assets::loadTexture("g-pal8v4", "../../examples/bmp_loader/assets/g/pal8v4.bmp"));
	assertNoExceptionThrown(Assets::loadTexture("g-pal8v5", "../../examples/bmp_loader/assets/g/pal8v5.bmp"));
	assertNoExceptionThrown(Assets::loadTexture("g-pal8w124", "../../examples/bmp_loader/assets/g/pal8w124.bmp"));
	assertNoExceptionThrown(Assets::loadTexture("g-pal8w125", "../../examples/bmp_loader/assets/g/pal8w125.bmp"));
	assertNoExceptionThrown(Assets::loadTexture("g-pal8w126", "../../examples/bmp_loader/assets/g/pal8w126.bmp"));
	assertNoExceptionThrown(Assets::loadTexture("g-rgb16", "../../examples/bmp_loader/assets/g/rgb16.bmp"));
	assertNoExceptionThrown(Assets::loadTexture("g-rgb16-565", "../../examples/bmp_loader/assets/g/rgb16-565.bmp"));
	assertNoExceptionThrown(Assets::loadTexture("g-rgb16-565pal", "../../examples/bmp_loader/assets/g/rgb16-565pal.bmp"));
	assertNoExceptionThrown(Assets::loadTexture("g-rgb16bfdef", "../../examples/bmp_loader/assets/g/rgb16bfdef.bmp"));
	assertNoExceptionThrown(Assets::loadTexture("g-rgb24", "../../examples/bmp_loader/assets/g/rgb24.bmp"));
	assertNoExceptionThrown(Assets::loadTexture("g-rgb24pal", "../../examples/bmp_loader/assets/g/rgb24pal.bmp"));
	assertNoExceptionThrown(Assets::loadTexture("g-rgb32", "../../examples/bmp_loader/assets/g/rgb32.bmp"));
	assertNoExceptionThrown(Assets::loadTexture("g-rgb32bf", "../../examples/bmp_loader/assets/g/rgb32bf.bmp"));
	assertNoExceptionThrown(Assets::loadTexture("g-rgb32bfdef", "../../examples/bmp_loader/assets/g/rgb32bfdef.bmp"));
}