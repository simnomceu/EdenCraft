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

#ifndef VERTEX4U_HPP
#define VERTEX4U_HPP

#include <array>
#include "utility/mathematics/vertex3u.hpp"

namespace ece
{
	template <class T>
	class Vertex4u : protected std::array<T, 4>
	{
	public:
		inline Vertex4u();
		inline Vertex4u(const T x, const T y, const T z, const T w);
		inline Vertex4u(const Vertex3u<T> & xyz, const T w);
		Vertex4u(const Vertex4u<T> & copy) = default;
		Vertex4u(Vertex4u<T> && move) = default;
		template <typename V> inline Vertex4u(const Vertex4u<V> & copy);

		~Vertex4u() = default;

		Vertex4u<T> & operator=(const Vertex4u<T> & copy) = default;
		Vertex4u<T> & operator=(Vertex4u<T> && move) = default;
		template <typename V> Vertex4u<T> & operator=(const Vertex4u<V> & copy);

		template <typename V> inline Vertex4u<T> & operator/=(const V value);
		template <typename V> inline Vertex4u<T> & operator*=(const V value);
		inline Vertex4u<T> & operator+=(const Vertex4u<T> value);
		inline Vertex4u<T> & operator-=(const Vertex4u<T> value);

		template <typename V> inline Vertex4u<T> operator/(const V value) const;
		template <typename V> inline Vertex4u<T> operator*(const V value) const;
		inline Vertex4u<T> operator+(const Vertex4u<T> value) const;
		inline Vertex4u<T> operator-(const Vertex4u<T> value) const;

		inline Vertex4u<T> operator-() const;

		inline bool operator==(const Vertex4u<T> & rightOperand) const;

		inline void normalize();
		inline T magnitude() const;
		inline T dot(const Vertex4u<T> & rightOperand) const;
		inline T distanceFrom(const Vertex4u<T> & rightOperand) const;

		using std::array<T, 4>::operator[];
	};

	typedef Vertex4u<float> FloatVertex4u;
	typedef Vertex4u<int> IntVertex4u;
	typedef Vertex4u<double> DoubleVertex4u;

	typedef Vertex4u<float> FloatPoint4u;
	typedef Vertex4u<int> IntPoint4u;
	typedef Vertex4u<double> DoublePoint4u;
}

#include "utility/mathematics/vertex4u.inl"

#endif // VERTEX4U_HPP
