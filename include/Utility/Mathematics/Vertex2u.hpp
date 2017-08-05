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
				Copyright(C) 2017 Pierre Casati (@IsilinBN)

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

#ifndef VERTEX2U_HPP
#define VERTEX2U_HPP

#include <array>

namespace ece
{
	template <class T>
	class Vertex2u: protected std::array<T, 2>
	{
	public:
		inline Vertex2u();
		inline Vertex2u(const T x, const T y);
		Vertex2u(const Vertex2u<T> & copy) = default;
		Vertex2u(Vertex2u<T> && move) = default;
		template <typename V> inline Vertex2u(const Vertex2u<V> & copy);

		~Vertex2u() = default;

		Vertex2u<T> & operator=(const Vertex2u<T> & copy) = default;
		Vertex2u<T> & operator=(Vertex2u<T> && move) = default;
		template <typename V> Vertex2u<T> & operator=(const Vertex2u<V> & copy);

		template <typename V> inline Vertex2u<T> & operator/=(const V value);
		template <typename V> inline Vertex2u<T> & operator*=(const V value);
		inline Vertex2u<T> & operator+=(const Vertex2u<T> value);
		inline Vertex2u<T> & operator-=(const Vertex2u<T> value);

		template <typename V> inline Vertex2u<T> operator/(const V value) const;
		template <typename V> inline Vertex2u<T> operator*(const V value) const;
		inline Vertex2u<T> operator+(const Vertex2u<T> value) const;
		inline Vertex2u<T> operator-(const Vertex2u<T> value) const;

		inline Vertex2u<T> operator-() const;

		inline bool operator==(const Vertex2u<T> & rightOperand) const;

		inline void normalize();
		inline T magnitude() const;
		inline T dot(const Vertex2u<T> & rightOperand) const;
		inline T distanceFrom(const Vertex2u<T> & rightOperand) const;

		using std::array<T, 2>::operator[];
	};

	typedef Vertex2u<float> FloatVertex2u;
	typedef Vertex2u<int> IntVertex2u;
	typedef Vertex2u<double> DoubleVertex2u;

	typedef Vertex2u<float> FloatPoint2u;
	typedef Vertex2u<int> IntPoint2u;
	typedef Vertex2u<double> DoublePoint2u;
}

#include "Mathematics\Vertex2u.inl"

#endif // VERTEX2U_HPP
