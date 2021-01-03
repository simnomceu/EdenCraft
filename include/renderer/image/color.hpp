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

#ifndef COLOR_HPP
#define COLOR_HPP

#include "utility/types.hpp"

namespace ece
{
	namespace renderer
	{
		namespace image
		{
			using Color = RGBA32;

			static const auto WHITE = Color{ 255, 255, 255, 100 };
			static const auto SILVER = Color{ 192, 192, 192, 100 };
			static const auto GRAY = Color{ 128, 128, 128, 100 };
			static const auto BLACK = Color{ 0, 0, 0, 100 };
			static const auto RED = Color{ 255, 0, 0, 100 };
			static const auto MAROON = Color{ 128, 0, 0, 100 };
			static const auto YELLOW = Color{ 255, 255, 0, 100 };
			static const auto OLIVE = Color{ 128, 128, 0, 100 };
			static const auto LIME = Color{ 192, 255, 0, 100 };
			static const auto GREEN = Color{ 0, 255, 0, 100 };
			static const auto CYAN = Color{ 0, 255, 255, 100 };
			static const auto TEAL = Color{ 0, 128, 128, 100 };
			static const auto BLUE = Color{ 0, 0, 255, 100 };
			static const auto NAVY = Color{ 0, 0, 128, 100 };
			static const auto FUSHIA = Color{ 255, 0, 255, 100 };
			static const auto PURPLE = Color{ 128, 0, 128, 100 };
			static const auto VIOLET = Color{ 128, 0, 255, 100 };
		} // namespace image
	} // namespace renderer
} // namespace ece

#endif // COLOR_HPP
