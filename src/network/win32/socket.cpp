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

#include "network/pch.hpp"
#include "network/common/socket.hpp"
#include "network/win32/data_socket.hpp"
#include "utility/log.hpp"

namespace ece
{
    namespace network
    {
        namespace common
        {
            Socket::Socket(): _data(makePimpl<DataSocket>()) {}

            void Socket::open()
            {
                //Create a RAW Socket
                INFO << "Creating RAW socket..." << ece::flush;
                this->_data.get()->handle = socket(AF_INET, SOCK_RAW, IPPROTO_IP);
                if (this->_data.get()->handle == INVALID_SOCKET)
                {
                	ERROR << "Failed to create raw socket." << ece::flush;
                }
                else {
                    INFO << "RAW socket created." << ece::flush;
                }
            }

            void Socket::close()
            {
                closesocket(this->_data.get()->handle);
                INFO << "Socket closed." << flush;
            }

            void Socket::bind(IPAddress & address)
            {
                auto dest = sockaddr_in{};
                dest.sin_addr.s_addr = *reinterpret_cast<in_addr_t *>(&address.address);
                dest.sin_family = address.type;
                dest.sin_port = 0;

        		INFO << "Binding socket to local system and port 0 ..." << flush;
        		if (::bind(this->_data.get()->handle, reinterpret_cast<sockaddr *>(&dest), sizeof(dest)) == SOCKET_ERROR)
        		{
        			ERROR << "bind(" << inet_ntoa(address.address) << ") failed." << flush;
        		} else {
        		    INFO << "Binding successful" << flush;
                }
            }
        } // namespace common
    } // namespace network
} // namespace ece
