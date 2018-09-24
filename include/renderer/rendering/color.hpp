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

#include "renderer/image.hpp"

namespace ece
{
	namespace renderer
	{
		namespace rendering
		{
			using Color = image::RGBA32;

			static const Color WHITE(255, 255, 255, 100);
			static const Color SILVER(192, 192, 192, 100);
			static const Color GRAY(128, 128, 128, 100);
			static const Color BLACK(0, 0, 0, 100);
			static const Color RED(255, 0, 0, 100);
			static const Color MAROON(128, 0, 0, 100);
			static const Color YELLOW(255, 255, 0, 100);
			static const Color OLIVE(128, 128, 0, 100);
			static const Color LIME(192, 255, 0, 100);
			static const Color GREEN(0, 255, 0, 100);
			static const Color CYAN(0, 255, 255, 100);
			static const Color TEAL(0, 128, 128, 100);
			static const Color BLUE(0, 0, 255, 100);
			static const Color NAVY(0, 0, 128, 100);
			static const Color FUSHIA(255, 0, 255, 100);
			static const Color PURPLE(128, 0, 128, 100);
			static const Color VIOLET(128, 0, 255, 100);
		} // namespace rendering
	} // namespace renderer
} // namespace ece

#endif // COLOR_HPP
