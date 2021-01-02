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

#ifdef __linux__
	#define localtime_s(time, result) localtime_r(result, time)
#endif

namespace ece
{
    namespace utility
    {
        namespace log
        {

        inline Logger::Logger(): _target(std::cerr) {}

        inline void Logger::logError(const std::string & data) { this->log<ConsoleColor::RED>("ERROR", data); }

        inline void Logger::logWarning(const std::string & data) { this->log<ConsoleColor::YELLOW>("WARNING", data); }

        inline void Logger::logInfo(const std::string & data) { this->log<ConsoleColor::GREEN>("INFO", data); }

        inline void Logger::logSystem(const std::string & data) { this->log<ConsoleColor::MAGENTA>("SYSTEM", data); }

		using namespace std::string_literals;

		template <ConsoleColor Color>
		void Logger::log(const std::string & tag, const std::string & data)
		{
			auto result = std::time(nullptr);
			auto today = tm{};
			localtime_s(&today, &result);

			auto day = (today.tm_mday < 10 ? "0"s : ""s) + std::to_string(today.tm_mday);
			auto month = (today.tm_mon + 1 < 10 ? "0"s : ""s) + std::to_string(today.tm_mon + 1);
			auto year = std::to_string(today.tm_year + 1900);
			auto hour = (today.tm_hour < 10 ? "0"s : ""s) + std::to_string(today.tm_hour);
			auto min = (today.tm_min < 10 ? "0"s : ""s) + std::to_string(today.tm_min);
			auto sec = (today.tm_sec < 10 ? "0"s : ""s) + std::to_string(today.tm_sec);

			auto stream = std::stringstream();
			stream << "[" << day << "/" << month << "/" << year << " " << hour << ":" << min << ":" << sec << "][" << tag << "]" << data;
			this->_target << colorize<Color>(stream.str()) << std::endl;
		}
        } // namespace log
    } // namespace utility
} // namespace ece
