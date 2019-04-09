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

namespace ece
{
	namespace network
	{
		namespace protocol
		{
			inline std::string IPv4Header::to_string() const
			{
				std::stringstream stream;

				struct sockaddr_in src, dest;
				std::memset(&src, 0, sizeof(src));
				src.sin_addr.s_addr = this->source;

				std::memset(&dest, 0, sizeof(dest));
				dest.sin_addr.s_addr = this->destination;

				stream <<  "\nIP Header\n";
				stream <<  " |-IP Version : " << (unsigned int)this->version << "\n";
				stream <<  " |-IP Header Length : " << (unsigned int)this->internetHeaderLength << " DWORDS or " << ((unsigned int)(this->internetHeaderLength)) * 4 << " Bytes\n";
				stream <<  " |-Type Of Service : " << (unsigned int)this->dscp << "\n";
				stream <<  " |-IP Total Length : " << ntohs(this->totalLength) << " Bytes(Size of Packet)\n";
				stream <<  " |-Identification : " << ntohs(this->identification) << "\n";
				stream <<  " |-Reserved ZERO Field : " << (unsigned int)this->reservedFlag << "\n";
				stream <<  " |-Dont Fragment Field : " << (unsigned int)this->dfFlag << "\n";
				stream <<  " |-More Fragment Field : " << (unsigned int)this->mfFlag << "\n";
				stream <<  " |-TTL : " << (unsigned int)this->ttl << "\n";
				stream <<  " |-Protocol : " << (unsigned int)this->protocol << "\n";
				stream <<  " |-Checksum : " << ntohs(this->checksum) << "\n";
				stream <<  " |-Source IP : " << inet_ntoa(src.sin_addr) << "\n";
				stream <<  " |-Destination IP : " << inet_ntoa(dest.sin_addr) << "\n";

				return stream.str();
			}
		} // namespace protocol
	} // namespace network
} // namespace ece
