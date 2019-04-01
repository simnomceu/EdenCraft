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
			inline std::string TCPHeader::to_string() const
			{
				std::stringstream stream;

				stream << "\nTCP Header\n";
				stream << " |-Source Port : " << ntohs(this->source) << "\n";
				stream << " |-Destination Port : " << ntohs(this->destination) << "\n";
				stream << " |-Sequence Number : " << ntohl(this->sequence) << "\n";
				stream << " |-Acknowledge Number : " << ntohl(this->acknowledgment) << "\n";
				stream << " |-Header Length : " << (unsigned int)this->dataOffset << " DWORDS or " << (unsigned int)this->dataOffset * 4 << " BYTES\n";
				stream << " |-ECN-nonce Flag: " << (unsigned int)this->ecnFlag << "\n";
				stream << " |-CWR Flag : " << (unsigned int)this->cwrFlag << "\n";
				stream << " |-ECN Flag : " << (unsigned int)this->ecnFlag << "\n";
				stream << " |-Urgent Flag : " << (unsigned int)this->urgFlag << "\n";
				stream << " |-Acknowledgement Flag : " << (unsigned int)this->ackFlag << "\n";
				stream << " |-Push Flag : " << (unsigned int)this->pshFlag << "\n";
				stream << " |-Reset Flag : " << (unsigned int)this->rstFlag << "\n";
				stream << " |-Synchronise Flag : " << (unsigned int)this->synFlag << "\n";
				stream << " |-Finish Flag : " << (unsigned int)this->finFlag << "\n";
				stream << " |-Window : " << ntohs(this->windowSize) << "\n";
				stream << " |-Checksum : " << ntohs(this->checksum) << "\n";
				stream << " |-Urgent Pointer : " << this->urgentPointer << "\n";

				return stream.str();
			}
		} // namespace protocol
	} // namespace network
} // namespace ece