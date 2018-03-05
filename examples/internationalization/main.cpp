/*

	oooooooooooo       .o8                          .oooooo.                       .o88o.     .
	`888'     `8      "888                         d8P'  `Y8b                      888 `"   .o8
	 888          .oooo888   .ooooo.  ooo. .oo.   888          oooo d8b  .oooo.   o888oo  .o888oo
	 888oooo8    d88' `888  d88' `88b `888P"Y88b  888          `888""8P `P  )88b   888      888
	 888    "    888   888  888ooo888  888   888  888           888      .oP"888   888      888
	 888       o 888   888  888    .o  888   888  `88b    ooo   888     d8(  888   888      888 .
	o888ooooood8 `Y8bod88P" `Y8bod8P' o888o o888o  `Y8bood8P'  d888b    `Y888""8o o888o     "888"

	ooooo                 .                                                .    o8o                                  oooo   o8o                           .    o8o
	`888'               .o8                                              .o8    `"'                                  `888   `"'                         .o8    `"'
	 888  ooo. .oo.   .o888oo  .ooooo.  oooo d8b ooo. .oo.    .oooo.   .o888oo oooo   .ooooo.  ooo. .oo.    .oooo.    888  oooo    oooooooo  .oooo.   .o888oo oooo   .ooooo.  ooo. .oo.
	 888  `888P"Y88b    888   d88' `88b `888""8P `888P"Y88b  `P  )88b    888   `888  d88' `88b `888P"Y88b  `P  )88b   888  `888   d'""7d8P  `P  )88b    888   `888  d88' `88b `888P"Y88b
	 888   888   888    888   888ooo888  888      888   888   .oP"888    888    888  888   888  888   888   .oP"888   888   888     .d8P'    .oP"888    888    888  888   888  888   888
	 888   888   888    888 . 888    .o  888      888   888  d8(  888    888 .  888  888   888  888   888  d8(  888   888   888   .d8P'  .P d8(  888    888 .  888  888   888  888   888
	o888o o888o o888o   "888" `Y8bod8P' d888b    o888o o888o `Y888""8o   "888" o888o `Y8bod8P' o888o o888o `Y888""8o o888o o888o d8888888P  `Y888""8o   "888" o888o `Y8bod8P' o888o o888o




				This file is part of EdenCraft Engine - Internationalization sample.
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

#include <iostream>
#include "utility/locale/locale_loader.hpp"
#include "utility/locale/country.hpp"
#include "utility/locale/language.hpp"

auto main() -> int
{
	ece::LocaleLoader::setPath("../examples/internationalization/");

	ece::LocaleLoader loader("test");
	auto & resource = loader.getResource();
	std::cout << "########## Default Locale en_US ##########" << std::endl;
	std::cout << resource["helloworld"] << std::endl;
	std::cout << resource["example"] << std::endl;

	std::cout << std::endl;

	loader.changeLocale(ece::Localization(ece::FRENCH, ece::FRANCE));
	std::cout << "########## Locale fr_FR ##########" << std::endl;
	std::cout << resource["helloworld"] << std::endl;
	std::cout << resource["example"] << std::endl;

	return EXIT_SUCCESS;
}
