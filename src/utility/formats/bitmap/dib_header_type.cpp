/*

	oooooooooooo       .o8                          .oooooo.                       .o88o.     .
	`888'     `8      "888                         d8P'  `Y8b                      888 `"   .o8
	 888          .oooo888   .ooooo.  ooo. .oo.   888          oooo d8b  .oooo.   o888oo  .o888oo
	 888oooo8    d88' `888  d88' `88b `888P"Y88b  888          `888""8P `P  )88b   888      888
	 888    "    888   888  888ooo888  888   888  888           888      .oP"888   888      888
	 888       o 888   888  888    .o  888   888  `88b    ooo   888     d8(  888   888      888 .
	o888ooooood8 `Y8bod88P" `Y8bod8P' o888o o888o  `Y8bood8P'  d888b    `Y888""8o o888o     "888"

															ooooo     ooo     .    o8o  oooo   o8o      .
															`888'     `8'   .o8    `"'  `888   `"'    .o8
															 888       8  .o888oo oooo   888  oooo  .o888oo oooo    ooo
															 888       8    888   `888   888  `888    888    `88.  .8'
															 888       8    888    888   888   888    888     `88..8'
															 `88.    .8'    888 .  888   888   888    888 .    `888'
															   `YbodP'      "888" o888o o888o o888o   "888"     .8'
																											.o..P'
																											`Y8P'

				This file is part of EdenCraft Engine - Utility module.
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

#include "utility/pch.hpp"
#include "utility/formats/bitmap/dib_header_type.hpp"


namespace ece
{
	namespace utility
	{
		namespace formats
		{
			namespace bitmap
			{
				std::string to_string(DIBHeaderType type)
				{
					switch (type) {
					case DIBHeaderType::BITMAPCOREHEADER: return "BITMAPCOREHEADER"; break;
					case DIBHeaderType::OS21XBITMAPHEADER: return "OS21XBITMAPHEADER"; break;
					case DIBHeaderType::OS22XBITMAPHEADER: return "OS22XBITMAPHEADER"; break;
					case DIBHeaderType::BITMAPINFOHEADER: return "BITMAPINFOHEADER"; break;
					case DIBHeaderType::BITMAPV2INFOHEADER: return "BITMAPV2INFOHEADER"; break;
					case DIBHeaderType::BITMAPV3INFOHEADER: return "BITMAPV3INFOHEADER"; break;
					case DIBHeaderType::BITMAPV4HEADER: return "BITMAPV4HEADER"; break;
					case DIBHeaderType::BITMAPV5HEADER: return "BITMAPV5HEADER"; break;
					default: throw std::runtime_error("Unknown value for DIBHeaderType enumeration."); break;
					}
				}

				DIBHeaderType getType(std::size_t size)
				{
					switch (size) {
					case 12: return DIBHeaderType::BITMAPCOREHEADER; break;
					case 64: return DIBHeaderType::OS22XBITMAPHEADER; break;
					case 16: return DIBHeaderType::OS22XBITMAPHEADER; break;
					case 40: return DIBHeaderType::BITMAPINFOHEADER; break;
					case 52: return DIBHeaderType::BITMAPV2INFOHEADER; break;
					case 56: return DIBHeaderType::BITMAPV3INFOHEADER; break;
					case 108: return DIBHeaderType::BITMAPV4HEADER; break;
					case 124: return DIBHeaderType::BITMAPV5HEADER; break;
					default: throw std::runtime_error("Unknown size for DIBHeaderType enumeration."); break;
					}
				}

				std::size_t getSize(DIBHeaderType type)
				{
					switch (type) {
					case DIBHeaderType::BITMAPCOREHEADER: return 12; break;
					case DIBHeaderType::OS21XBITMAPHEADER: return 12; break;
					case DIBHeaderType::OS22XBITMAPHEADER: return 64; break;
					case DIBHeaderType::BITMAPINFOHEADER: return 40; break;
					case DIBHeaderType::BITMAPV2INFOHEADER: return 52; break;
					case DIBHeaderType::BITMAPV3INFOHEADER: return 56; break;
					case DIBHeaderType::BITMAPV4HEADER: return 108; break;
					case DIBHeaderType::BITMAPV5HEADER: return 124; break;
					default: throw std::runtime_error("Unknown size for DIBHeaderType enumeration."); break;
					}
				}
			} // namespace bitmap
		} // namespace formats
	} // namespace utility
} // namespace ece