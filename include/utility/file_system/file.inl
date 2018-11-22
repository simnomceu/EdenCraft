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

#include "utility/debug.hpp"

namespace ece
{
    namespace utility
    {
        namespace file_system
        {
        	inline File::File() : _filename(), _stream() {}

        	inline File::File(const std::string & filename, const OpenMode & mode): _filename(filename), _stream()
        	{
        		this->_stream.open(this->_filename, static_cast<std::ios_base::openmode>(mode));
        	}

        	inline File::File(File && move): _filename(std::move(move._filename)), _stream(std::move(move._stream))
        	{
        		move.close();
        	}

        	inline File::~File() noexcept { this->_stream.close(); }

        	inline bool File::isOpen() const { return this->_stream.is_open(); }

        	template <class T>
        	File & File::operator>>(T & value)
        	{
        		this->_stream >> value;
        		return *this;
        	}

        	template <class T>
        	File & File::operator<<(T & value)
        	{
        		this->_stream << value;
        		return *this;
        	}

        	template <class T>
        	T File::read(const unsigned int size)
        	{
        		T data;
        		this->_stream.read(reinterpret_cast<char *>(&data), size);
        		return data;
        	}

        	template <class T>
        	void File::write(const T & value, const unsigned int size)
        	{
        		this->_stream.write(reinterpret_cast<const char *>(value), size);
        	}

			inline std::fstream & File::getStream() { return this->_stream; }

        	template <class T>
        	std::vector<T> File::parseToVector()
        	{
        		std::vector<T> content;
        		if (this->isOpen()) {
        			T value;
        			try {
        				while (this->_stream.good()) {
        					this->_stream >> value;
        					content.push_back(value);
        				}
        			}
        			catch (std::exception & /*e*/) {
        				throw FileException(FileCodeError::PARSE_ERROR, this->_filename);
        			}
        		}
        		return content;
        	}

        	inline void File::moveCursorTo(const unsigned int position)
        	{
        		this->_stream.seekg(position);
        	}
        } // namespace file_system
    } // namespace utility
} // namespace ece
