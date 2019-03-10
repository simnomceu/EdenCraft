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

#ifndef UINT1_HPP
#define UINT1_HPP

#include "utility/config.hpp"
#include "utility/pch.hpp"

namespace ece
{
	namespace utility
	{
		namespace type
		{
			class uint1
			{
			public:
				uint1 & operator&=( const uint1 & rhs )
				{
					this->operator=(this->operator bool() & rhs.operator bool());
					return *this;
				}

				uint1 & operator|=( const uint1 & rhs )
				{
					this->operator=(this->operator bool() & rhs.operator bool());
					return *this;
				}

				uint1 & operator^=( const uint1 & rhs )
				{
					this->operator=(this->operator bool() ^ rhs.operator bool());
					return *this;
				}

				uint1 operator~() const
				{
					this->operator=(~this->operator bool());
					return *this;
				}

//				friend uint1 operator&(const uint1 & lhs, const uint1 & rhs);
//				friend uint1 operator|(const uint1 & lhs, const uint1 & rhs);
//				friend uint1 operator^(const uint1 & lhs, const uint1 & rhs);

				virtual uint1 & operator=(bool v) = 0;
				virtual operator bool() const = 0;

				friend std::ostream & operator<<(std::ostream & stream, uint1 & bit)
				{
					stream << (bool)bit;
					return stream;
				}

				friend std::istream & operator>>(std::istream & stream, uint1 & bit)
				{
					auto val = false;
					stream >> val;
					this->operator=(val);
					return stream;
				}
			};

			template <std::size_t I, typename enabled = std::enable_if_t<I < 8>>
			class uint1_t: public uint1
			{
			public:
				uint1_t() : _a(0) {}

				virtual uint1 & operator=(bool v) override
				{
					this->_a |= (char)(v << I);
					return *this;
				}

				virtual operator bool() const override
				{
					return (bool)((this->_a & (1 << I)) >> I);
				}

			private:
				unsigned char _a;
			};

			class Bitset;
			template <std::size_t I, typename enabled = std::enable_if_t<I < 8>> uint1 & get(Bitset & bitset) { throw std::runtime_error("Hoho"); }
			template <> uint1 & get<0>(Bitset & bitset);
			template <> uint1 & get<1>(Bitset & bitset);
			template <> uint1 & get<2>(Bitset & bitset);
			template <> uint1 & get<3>(Bitset & bitset);
			template <> uint1 & get<4>(Bitset & bitset);
			template <> uint1 & get<5>(Bitset & bitset);
			template <> uint1 & get<6>(Bitset & bitset);
			template <> uint1 & get<7>(Bitset & bitset);

			class Bitset
			{
			public:
				friend uint1 & get<0>(Bitset & bitset);
				friend uint1 & get<1>(Bitset & bitset);
				friend uint1 & get<2>(Bitset & bitset);
				friend uint1 & get<3>(Bitset & bitset);
				friend uint1 & get<4>(Bitset & bitset);
				friend uint1 & get<5>(Bitset & bitset);
				friend uint1 & get<6>(Bitset & bitset);
				friend uint1 & get<7>(Bitset & bitset);

				Bitset() = default;

				friend std::ostream & operator<<(std::ostream & stream, Bitset & bitset)
				{
					stream << bitset.bitset.a0 << bitset.bitset.a1 << bitset.bitset.a2 << bitset.bitset.a3 << bitset.bitset.a4 << bitset.bitset.a5 << bitset.bitset.a6 << bitset.bitset.a7;
					return stream;
				}

			private:
				union Internal
				{
					uint1_t<0> a0;
					uint1_t<1> a1;
					uint1_t<2> a2;
					uint1_t<3> a3;
					uint1_t<4> a4;
					uint1_t<5> a5;
					uint1_t<6> a6;
					uint1_t<7> a7;

					Internal() { std::memset(this, 0, sizeof(*this)); }
				};
				Internal bitset;
			};
			template <> uint1 & get<0>(Bitset & bitset) { return bitset.bitset.a0; }
			template <> uint1 & get<1>(Bitset & bitset) { return bitset.bitset.a1; }
			template <> uint1 & get<2>(Bitset & bitset) { return bitset.bitset.a2; }
			template <> uint1 & get<3>(Bitset & bitset) { return bitset.bitset.a3; }
			template <> uint1 & get<4>(Bitset & bitset) { return bitset.bitset.a4; }
			template <> uint1 & get<5>(Bitset & bitset) { return bitset.bitset.a5; }
			template <> uint1 & get<6>(Bitset & bitset) { return bitset.bitset.a6; }
			template <> uint1 & get<7>(Bitset & bitset) { return bitset.bitset.a7; }

		/*		int main()
				{

					std::cerr << sizeof(uint1_t<0>) << std::endl;
					std::cerr << sizeof(Bitset) << std::endl;

					Bitset test;
					std::cerr << test << std::endl;
					get<0>(test) = true;
					std::cerr << test << std::endl;
					get<4>(test) = true;
					std::cerr << test << std::endl;
					get<5>(test) = true;
					std::cerr << test << std::endl;
					get<6>(test) = true;
					std::cerr << test << std::endl;

					return 0;
				}*/
		} // namespace type
	} // namespace utility
} // namespace ece

#endif // UINT1_HPP
