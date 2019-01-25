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

#ifndef STRING_STREAM_HPP
#define STRING_STREAM_HPP

#include "utility/config.hpp"
#include "utility/pch.hpp"

namespace ece
{
	namespace utility
	{
		namespace string
		{
			/**
			 * @class StringStream
			 * @brief
			 */
			class ECE_UTILITY_API StringStream
			{
			public:
				/**
				 * @fn constexpr StringStream() noexcept
				 * @brief Default constructor.
				 * @throw noexcept
				 */
				inline StringStream(const std::string & data) noexcept;

				/**
				 * @fn StringStream(const StringStream & copy) noexcept
				 * @param[in] copy The StringStream to copy from.
				 * @brief Default copy constructor.
				 * @throw noexcept
				 */
				StringStream(const StringStream & copy) noexcept = default;

				/**
				 * @fn StringStream(StringStream && move) noexcept
				 * @param[in] move The StringStream to move.
				 * @brief Default move constructor.
				 * @throw noexcept
				 */
				StringStream(StringStream && move) noexcept = default;

				/**
				 * @fn ~StringStream() noexcept
				 * @brief Default destructor.
				 * @throw noexcept
				 */
				~StringStream() noexcept = default;

				/**
				 * @fn StringStream & operator=(const StringStream & copy) noexcept
				 * @param[in] copy The StringStream to copy from.
				 * @return The StringStream copied.
				 * @brief Default copy assignment operator.
				 * @throw noexcept
				 */
				StringStream & operator=(const StringStream & copy) noexcept = default;

				/**
				 * @fn StringStream & operator=(StringStream && move) noexcept
				 * @param[in] move The StringStream to move.
				 * @return The StringStream moved.
				 * @brief Default move assignment operator.
				 * @throw noexcept
				 */
				StringStream & operator=(StringStream && move) noexcept = default;

				inline void str(std::string data);
				inline const std::string & str() const;
				inline std::string substr() const;

				inline char get();
				inline std::string get(std::size_t count);
				inline char peek();
				inline std::string peek(std::size_t count);

				template <class T>
				StringStream & operator>>(T & value);

				template <class... Args>
				void scan(std::string pattern, Args ... args);

				inline bool eof() const;

				inline std::size_t count(char search);

				inline void ignore(std::vector<char> characters);

			private:
				std::string _data;

				std::size_t _cursor;
			};

			template <>
			inline StringStream & StringStream::operator>> <std::string>(std::string & value);
		} // namespace string
	} // namespace utility
} // namespace ece

#include "utility/string/string_stream.inl"

#endif // STRING_STREAM_HPP
