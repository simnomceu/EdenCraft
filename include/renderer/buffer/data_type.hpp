/*

	oooooooooooo       .o8                          .oooooo.                       .o88o.     .
	`888'     `8      "888                         d8P'  `Y8b                      888 `"   .o8
	 888          .oooo888   .ooooo.  ooo. .oo.   888          oooo d8b  .oooo.   o888oo  .o888oo
	 888oooo8    d88' `888  d88' `88b `888P"Y88b  888          `888""8P `P  )88b   888      888
	 888    "    888   888  888ooo888  888   888  888           888      .oP"888   888      888
	 888       o 888   888  888    .o  888   888  `88b    ooo   888     d8(  888   888      888 .
	o888ooooood8 `Y8bod88P" `Y8bod8P' o888o o888o  `Y8bood8P'  d888b    `Y888""8o o888o     "888"

															ooooooooo.                               .o8
															`888   `Y88.                            "888
															 888   .d88'  .ooooo.  ooo. .oo.    .oooo888   .ooooo.  oooo d8b  .ooooo.  oooo d8b
															 888ooo88P'  d88' `88b `888P"Y88b  d88' `888  d88' `88b `888""8P d88' `88b `888""8P
															 888`88b.    888ooo888  888   888  888   888  888ooo888  888     888ooo888  888
															 888  `88b.  888    .o  888   888  888   888  888    .o  888     888    .o  888
															o888o  o888o `Y8bod8P' o888o o888o `Y8bod88P" `Y8bod8P' d888b    `Y8bod8P' d888b



				This file is part of EdenCraft Engine - Renderer module.
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

#ifndef DATA_TYPE_HPP
#define DATA_TYPE_HPP

#include "renderer/config.hpp"
#include "renderer/pch.hpp"

namespace ece
{
	namespace renderer
	{
		namespace buffer
		{
			enum class DataType : unsigned short int
			{
				BYTE = 0x00,
				UNSIGNED_BYTE = 0x01,
				SHORT = 0x02,
				UNSIGNED_SHORT = 0x03,
				INT = 0x04,
				UNSIGNED_INT = 0x05,
				HALF_FLOAT = 0x06,
				FLOAT = 0x07,
				DOUBLE = 0x08,
				FIXED = 0x09,
				INT_2_10_10_10_REV = 0x10,
				UNSIGNED_INT_2_10_10_10_REV = 0x11,
				UNSIGNED_INT_10F_11F_11F_REV = 0x12
			};

			template <class T> static inline constexpr auto dataType();

			template <> inline auto dataType<char>();
			template <> inline auto dataType<unsigned char>();
			template<> inline auto dataType<short int>();
			template<> inline auto dataType<unsigned short int>();
			template<> inline auto dataType<int>();
			template<> inline auto dataType<unsigned int>();
			template<> inline auto dataType<float>();
			template<> inline auto dataType<double>();
		} // namespace buffer
	} // namespace renderer
} // namespace ece

#include "renderer/buffer/data_type.inl"

#endif // INDEX_BUFFER_HPP