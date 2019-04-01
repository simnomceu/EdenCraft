/*

	oooooooooooo       .o8                          .oooooo.                       .o88o.     .
	`888'     `8      "888                         d8P'  `Y8b                      888 `"   .o8
	 888          .oooo888   .ooooo.  ooo. .oo.   888          oooo d8b  .oooo.   o888oo  .o888oo
	 888oooo8    d88' `888  d88' `88b `888P"Y88b  888          `888""8P `P  )88b   888      888
	 888    "    888   888  888ooo888  888   888  888           888      .oP"888   888      888
	 888       o 888   888  888    .o  888   888  `88b    ooo   888     d8(  888   888      888 .
	o888ooooood8 `Y8bod88P" `Y8bod8P' o888o o888o  `Y8bood8P'  d888b    `Y888""8o o888o     "888"

															ooooo      ooo               .                                       oooo
															`888b.     `8'             .o8                                       `888
															 8 `88b.    8   .ooooo.  .o888oo oooo oooo    ooo  .ooooo.  oooo d8b  888  oooo
															 8   `88b.  8  d88' `88b   888    `88. `88.  .8'  d88' `88b `888""8P  888 .8P'
															 8     `88b.8  888ooo888   888     `88..]88..8'   888   888  888      888888.
															 8       `888  888    .o   888 .    `888'`888'    888   888  888      888 `88b.
															o8o        `8  `Y8bod8P'   "888"     `8'  `8'     `Y8bod8P' d888b    o888o o888o


				This file is part of EdenCraft Engine - Network module.
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

#ifndef UDP_HEADER_HPP
#define UDP_HEADER_HPP

namespace ece
{
	namespace network
	{
		namespace protocol
		{
			struct UDPHeader
			{
				std::uint16_t source;
				std::uint16_t destination;
				std::uint16_t length;
				std::uint16_t checksum;

				inline std::string to_string() const;
			};
		} // namespace protocol
	} // namespace network
} // namespace ece

#include "network/protocol/udp_header.inl"

#endif // UDP_HEADER_HPP