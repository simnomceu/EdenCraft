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

#ifndef LOG_CHANNEL_HPP
#define LOG_CHANNEL_HPP

#include "utility/pch.hpp"
#include "utility/config.hpp"

#ifdef _MSC_VER
#undef ERROR
#endif

namespace ece
{
	namespace utility
	{
		namespace log
		{
			class ECE_UTILITY_API LogChannel
			{
			public:
				enum class Channel
				{
					INFO = 0,
					WARNING = 1,
					ERROR = 2
				};

				struct Flush
				{
					inline void operator()(LogChannel & channel) { channel.flush(); }
				};

				inline LogChannel(Channel channel) noexcept;

				template <class T> LogChannel & operator<<(T data);

				void flush();

			private:
				Channel _channel;
				std::stringstream _buffer;
			};

			template<> ECE_UTILITY_API LogChannel & LogChannel::operator<< <LogChannel::Flush>(LogChannel::Flush data);

			ECE_UTILITY_EXTERN static LogChannel INFO = LogChannel(LogChannel::Channel::INFO);
			ECE_UTILITY_EXTERN static LogChannel WARNING = LogChannel(LogChannel::Channel::WARNING);
			ECE_UTILITY_EXTERN static LogChannel ERROR = LogChannel(LogChannel::Channel::ERROR);
			ECE_UTILITY_EXTERN static LogChannel::Flush flush = LogChannel::Flush();
		} // namespace log
	} // namespace utility
} // namespace ece

#include "utility/log/log_channel.inl"

#endif // LOG_CHANNEL_HPP
