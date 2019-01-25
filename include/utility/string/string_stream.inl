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

#include "utility/string/from_string.hpp"

namespace ece
{
	namespace utility
	{
		namespace string
		{
			inline StringStream::StringStream(const std::string & data) noexcept: _data(data), _cursor(0) {}

			inline void StringStream::str(std::string data)
			{
				this->_data = std::move(data);
				this->_cursor = 0;
			}

			inline const std::string & StringStream::str() const
			{
				return this->_data;
			}

			inline std::string StringStream::substr() const { return this->_data.substr(this->_cursor); }

			inline char StringStream::get()
			{
				char value = '\n';
				if (this->_cursor < this->_data.size()) {
					value = this->_data[this->_cursor];
				}
				++this->_cursor;
				return value;
			}

			inline std::string StringStream::get(std::size_t count)
			{
				std::string value;
				if (this->_cursor + count >= this->_data.size()) {
					value = this->_data.substr(this->_cursor);
				}
				else {
					value = this->_data.substr(this->_cursor, count);
				}

				this->_cursor += count + 1;
				return value;
			}

			inline char StringStream::peek()
			{
				if (this->_cursor >= this->_data.size()) {
					return '\n';
				}
				else {
					return this->_data[this->_cursor];
				}
			}

			inline std::string StringStream::peek(std::size_t count)
			{
				if (this->_cursor + count >= this->_data.size()) {
					return this->_data.substr(this->_cursor);
				}
				else {
					return this->_data.substr(this->_cursor, count);
				}
			}

			template <class T>
			StringStream & StringStream::operator>>(T & value)
			{
				auto end = this->_data.substr(this->_cursor).find_first_not_of("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789.,+-");
				if (end == std::string::npos) {
					end = this->_data.size();
				}

				value = from_string<T>(this->get(end));
				return *this;
			}

			template <>
			inline StringStream & StringStream::operator>> <std::string>(std::string & value)
			{
				auto end = this->_data.substr(this->_cursor).find_first_of(' ');
				if (end == std::string::npos) {
					end = this->_data.size();
				}

				value = this->get(end);
				return *this;
			}

			template <class... Args>
			void StringStream::scan(std::string pattern, Args ... args)
			{
				int count = 0;
				auto search = std::string{ std::move(pattern) + "%n" };
#ifdef _MSC_VER
#pragma warning( push )
#pragma warning( disable: 4996 )
#endif
				auto check = std::sscanf(&this->_data[this->_cursor], search.data(), args..., &count);
				if (!check) {
					throw std::runtime_error("Error while trying to scan with StringStream");
				}
#ifdef _MSC_VER
#pragma warning( pop )
#endif
				this->_cursor += count;
			}

			inline bool StringStream::eof() const { return this->_cursor >= this->_data.size() ||this->_data[this->_cursor] == '\0'; }

			inline std::size_t StringStream::count(char search) { return std::count(this->_data.begin() + this->_cursor, this->_data.end(), search); }

			inline void StringStream::ignore(std::vector<char> characters)
			{
				for (auto c : characters) {
					this->_data.erase(std::remove_if(this->_data.begin(), this->_data.end(), [c](char it) { return c == it; }), this->_data.end());
				}
			}
		} // namespace string
	} // namespace utility
} // namespace ece