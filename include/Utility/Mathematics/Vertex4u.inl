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

namespace ece
{
	template <class T>
	inline Vertex4u<T>::Vertex4u() : std::array<T, 4>{ 0, 0, 0, 0 } {}

	template <class T>
	inline Vertex4u<T>::Vertex4u(const T x, const T y, const T z, const T w) : std::array<T, 4>{ x, y, z, w } {}

	template <class T>
	inline Vertex4u<T>::Vertex4u(const Vertex3u<T> & xyz, const T w): std::array<T, 4>{ xyz[0], xyz[1], xyz[2], w } {}

	template <class T>
	template <typename V>
	inline Vertex4u<T>::Vertex4u(const Vertex4u<V> & copy) :
		std::array<T, 4>{ static_cast<T>(copy[0]), static_cast<T>(copy[1]), static_cast<T>(copy[2]), static_cast<T>(copy[3]) } {}

	template <class T>
	template <typename V>
	Vertex4u<T> & Vertex4u<T>::operator=(const Vertex4u<V> & copy)
	{
		(*this)[0] = static_cast<T>(copy[0]);
		(*this)[1] = static_cast<T>(copy[1]);
		(*this)[2] = static_cast<T>(copy[2]);
		(*this)[3] = static_cast<T>(copy[3]);
		return *this;
	}

	template<class T>
	template<typename V>
	inline Vertex4u<T>& Vertex4u<T>::operator/=(const V value)
	{
		(*this)[0] /= value;
		(*this)[1] /= value;
		(*this)[2] /= value;
		(*this)[3] /= value;
		return *this;
	}

	template<class T>
	template<typename V>
	inline Vertex4u<T>& Vertex4u<T>::operator*=(const V value)
	{
		(*this)[0] *= value;
		(*this)[1] *= value;
		(*this)[2] *= value;
		(*this)[3] *= value;
		return *this;
	}

	template<class T>
	inline Vertex4u<T>& Vertex4u<T>::operator+=(const Vertex4u<T> value)
	{
		(*this)[0] += value[0];
		(*this)[1] += value[1];
		(*this)[2] += value[2];
		(*this)[3] += value[3];
		return *this;
	}

	template<class T>
	inline Vertex4u<T>& Vertex4u<T>::operator-=(const Vertex4u<T> value)
	{
		(*this)[0] -= value[0];
		(*this)[1] -= value[1];
		(*this)[2] -= value[2];
		(*this)[3] -= value[3];
		return *this;
	}

	template<class T>
	template<typename V>
	inline Vertex4u<T> Vertex4u<T>::operator/(const V value) const
	{
		return Vertex4u<T>((*this)[0] / value, (*this)[1] / value, (*this)[2] / value, (*this)[3] / value);
	}

	template<class T>
	template<typename V>
	inline Vertex4u<T> Vertex4u<T>::operator*(const V value) const
	{
		return Vertex4u<T>((*this)[0] * static_cast<T>(value), (*this)[1] * static_cast<T>(value), (*this)[2] * static_cast<T>(value), (*this)[3] * static_cast<T>(value));
	}

	template<class T>
	inline Vertex4u<T> Vertex4u<T>::operator+(const Vertex4u<T> value) const
	{
		return Vertex4u<T>((*this)[0] + value[0], (*this)[1] + value[1], (*this)[2] + value[2], (*this)[3] + value[3]);
	}

	template<class T>
	inline Vertex4u<T> Vertex4u<T>::operator-(const Vertex4u<T> value) const
	{
		return Vertex4u<T>((*this)[0] - value[0], (*this)[1] - value[1], (*this)[2] - value[2], (*this)[3] - value[3]);
	}

	template<class T>
	inline Vertex4u<T> Vertex4u<T>::operator-() const
	{
		return Vertex4u<T>(-(*this)[0], -(*this)[1], -(*this)[2], -(*this)[3]);
	}

	template<class T>
	inline bool Vertex4u<T>::operator==(const Vertex4u<T> & rightOperand) const
	{
		return (*this)[0] == rightOperand[0] && (*this)[1] == rightOperand[1] 
			&& (*this)[2] == rightOperand[2] && (*this)[3] == rightOperand[3];
	}

	template<class T>
	inline void Vertex4u<T>::normalize()
	{
		this->operator/=(this->magnitude());
	}

	template<class T>
	inline T Vertex4u<T>::magnitude() const
	{
		return sqrt(this->dot(*this));
	}

	template<class T>
	inline T Vertex4u<T>::dot(const Vertex4u<T> & rightOperand) const
	{
		return (*this)[0] * rightOperand[0]
			+ (*this)[1] * rightOperand[1]
			+ (*this)[2] * rightOperand[2]
			+ (*this)[3] * rightOperand[3];
	}

	template<class T>
	inline T Vertex4u<T>::distanceFrom(const Vertex4u<T> & rightOperand) const
	{
		return this->operator-(rightOperand).magnitude();
	}
}