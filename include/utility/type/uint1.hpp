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
			template <std::size_t I, typename enabled = std::enable_if_t<I < 8>>
				class uint1_t
				{
				public:
					uint1_t() : _a(0) {}

					uint1_t<I, enabled> & operator=(bool v)
					{
						this->_a |= (char)(v << I);
						return *this;
					}

					operator bool() const
					{
						return (bool)((this->_a & (1 << I)) >> I);
					}

					friend std::ostream & operator<<(std::ostream & stream, uint1_t & bit)
					{
						stream << (bool)bit;
						return stream;
					}

				private:
					unsigned char _a;
				};

				class Bitset;
				template <std::size_t I, typename enabled = std::enable_if_t<I < 8>> uint1_t<I> & get(Bitset & bitset) { throw std::runtime_error("Hoho"); }
				template <> uint1_t<0> & get(Bitset & bitset);
				template <> uint1_t<1> & get(Bitset & bitset);
				template <> uint1_t<2> & get(Bitset & bitset);
				template <> uint1_t<3> & get(Bitset & bitset);
				template <> uint1_t<4> & get(Bitset & bitset);
				template <> uint1_t<5> & get(Bitset & bitset);
				template <> uint1_t<6> & get(Bitset & bitset);
				template <> uint1_t<7> & get(Bitset & bitset);

				class Bitset
				{
				public:
					friend uint1_t<0> & get<>(Bitset & bitset);
					friend uint1_t<1> & get<>(Bitset & bitset);
					friend uint1_t<2> & get<>(Bitset & bitset);
					friend uint1_t<3> & get<>(Bitset & bitset);
					friend uint1_t<4> & get<>(Bitset & bitset);
					friend uint1_t<5> & get<>(Bitset & bitset);
					friend uint1_t<6> & get<>(Bitset & bitset);
					friend uint1_t<7> & get<>(Bitset & bitset);

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
				template <> uint1_t<0> & get(Bitset & bitset) { return bitset.bitset.a0; }
				template <> uint1_t<1> & get(Bitset & bitset) { return bitset.bitset.a1; }
				template <> uint1_t<2> & get(Bitset & bitset) { return bitset.bitset.a2; }
				template <> uint1_t<3> & get(Bitset & bitset) { return bitset.bitset.a3; }
				template <> uint1_t<4> & get(Bitset & bitset) { return bitset.bitset.a4; }
				template <> uint1_t<5> & get(Bitset & bitset) { return bitset.bitset.a5; }
				template <> uint1_t<6> & get(Bitset & bitset) { return bitset.bitset.a6; }
				template <> uint1_t<7> & get(Bitset & bitset) { return bitset.bitset.a7; }

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

				/*int main()
				{
				   std::cerr << (0b10000000 >> 4) << std::endl;

					return 0;
				}*/
		} // namespace type
	} // namespace utility
} // namespace ece

#endif // UINT1_HPP