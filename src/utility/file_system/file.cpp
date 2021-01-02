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
#include "utility/file_system/file.hpp"

#include "utility/debug.hpp"

#ifdef _WIN32
#	define stat _stat
#endif

namespace ece
{
    namespace utility
    {
        namespace file_system
        {
        	File::File(const File & copy) : _filename(copy._filename), _stream()
        	{
        		this->_stream.copyfmt(copy._stream);
        		this->_stream.clear(copy._stream.rdstate());
        		this->_stream.basic_fstream<char>::basic_ios<char>::rdbuf(copy._stream.rdbuf());
        	}

        	File & File::operator=(const File & copy)
        	{
				if (this != &copy) {
					this->_filename = copy._filename;
					this->_stream.copyfmt(copy._stream);
					this->_stream.clear(copy._stream.rdstate());
					this->_stream.basic_fstream<char>::basic_ios<char>::rdbuf(copy._stream.rdbuf());
				}
        		return *this;
        	}

        	File & File::operator=(File && move) noexcept
        	{
				if (this != &move) {
					this->_filename = std::move(move._filename);
					this->_stream = std::move(move._stream);
					move.close();
				}
        		return *this;
        	}

        	auto File::open(const std::filesystem::path & filename, const OpenMode & mode) -> bool
        	{
        		this->_stream.close();
        		if (!std::filesystem::is_regular_file(filename) && ((mode & OpenMode::out) != OpenMode::out)) {
        			throw FileException(FileCodeError::BAD_PATH, filename);
        		}
        		this->_filename = filename;
        		this->_stream.open(this->_filename, static_cast<std::ios_base::openmode>(mode));
        		return this->isOpen();
        	}

        	void File::close()
        	{
        		if (this->isOpen()) {
        			this->_stream.close();
        		}
        	}

			auto File::parseToString() -> std::string
        	{
				auto content = std::string{};
        		if (this->isOpen()) {
					auto line = std::string{};
        			while (this->_stream.good()) {
        				std::getline(this->_stream, line);
        				content.append(line + "\n");
        			}
        		}
        		return content;
        	}

        	template<>
			auto File::parseToVector<FloatVector3u>()
        	{
				auto content = std::vector<FloatVector3u>{};
        		if (this->isOpen()) {
					auto value = FloatVector3u{};
        			try {
        				while (this->_stream.good()) {
        					*this >> value[0] >> value[1] >> value[2];
        					content.push_back(value);
        				}
        			}
        			catch (std::exception & e) {
        				throw FileException(FileCodeError::PARSE_ERROR, this->_filename, e.what());
        			}
        		}
        		return content;
        	}
        } // namespace file_system
    } // namespace utility
} // namespace ece
