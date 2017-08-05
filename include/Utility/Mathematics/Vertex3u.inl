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
	inline Vertex3u<T>::Vertex3u() : std::array<T, 3>{ 0, 0, 0 } {}

	template <class T>
	inline Vertex3u<T>::Vertex3u(const T x, const T y, const T z) : std::array<T, 3>{ x, y, z } {}

	template <class T>
	template <typename V>
	inline Vertex3u<T>::Vertex3u(const Vertex3u<V> & copy) :
		std::array<T, 3>{ static_cast<T>(copy[X]), static_cast<T>(copy[Y]), static_cast<T>(copy[Z]) }  {}

	template <class T>
	template <typename V>
	Vertex3u<T> & Vertex3u<T>::operator=(const Vertex3u<V> & copy)
	{
		(*this)[X] = static_cast<T>(copy[X]);
		(*this)[Y] = static_cast<T>(copy[Y]);
		(*this)[Z] = static_cast<T>(copy[Z]);
		return *this;
	}

	template<class T>
	template<typename V>
	inline Vertex3u<T>& Vertex3u<T>::operator/=(const V value)
	{
		(*this)[X] /= value;
		(*this)[Y] /= value;
		(*this)[Z] /= value;
		return *this;
	}

	template<class T>
	template<typename V>
	inline Vertex3u<T>& Vertex3u<T>::operator*=(const V value)
	{
		(*this)[X] *= value;
		(*this)[Y] *= value;
		(*this)[Z] *= value;
		return *this;
	}

	template<class T>
	inline Vertex3u<T>& Vertex3u<T>::operator+=(const Vertex3u<T> value)
	{
		(*this)[X] += value[X];
		(*this)[Y] += value[Y];
		(*this)[Z] += value[Z];
		return *this;
	}

	template<class T>
	inline Vertex3u<T>& Vertex3u<T>::operator-=(const Vertex3u<T> value)
	{
		(*this)[X] -= value[X];
		(*this)[Y] -= value[Y];
		(*this)[Z] -= value[Z];
		return *this;
	}

	template<class T>
	template<typename V>
	inline Vertex3u<T> Vertex3u<T>::operator/(const V value) const
	{
		return Vertex3u<T>((*this)[X] / value, (*this)[Y] / value, (*this)[Z] / value);
	}

	template<class T>
	template<typename V>
	inline Vertex3u<T> Vertex3u<T>::operator*(const V value) const
	{
		return Vertex3u<T>((*this)[X] * static_cast<T>(value), (*this)[Y] * static_cast<T>(value), (*this)[Z] * static_cast<T>(value));
	}

	template<class T>
	inline Vertex3u<T> Vertex3u<T>::operator+(const Vertex3u<T> value) const
	{
		return Vertex3u<T>((*this)[X] + value[X], (*this)[Y] + value[Y], (*this)[Z] + value[Z]);
	}

	template<class T>
	inline Vertex3u<T> Vertex3u<T>::operator-(const Vertex3u<T> value) const
	{
		return Vertex3u<T>((*this)[X] - value[X], (*this)[Y] - value[Y], (*this)[Z] - value[Z]);
	}

	template<class T>
	inline Vertex3u<T> Vertex3u<T>::operator-() const
	{
		return Vertex3u<T>(-(*this)[X], -(*this)[Y], -(*this)[Z]);
	}

	template<class T>
	inline bool Vertex3u<T>::operator==(const Vertex3u<T> & rightOperand) const
	{
		return (*this)[X] == rightOperand[X] && (*this)[Y] == rightOperand[Y] && (*this)[Z] == rightOperand[Z];
	}

	template<class T>
	inline void Vertex3u<T>::normalize()
	{
		this->operator/=(this->magnitude());
	}

	template<class T>
	inline T Vertex3u<T>::magnitude() const
	{
		return sqrt(this->dot(*this));
	}

	template<class T>
	inline Vertex3u<T> Vertex3u<T>::cross(const Vertex3u<T> & rightOperand) const
	{
		return Vertex3u<T>((*this)[Y] * rightOperand[Z] - (*this)[Z] * rightOperand[Y],
							(*this)[Z] * rightOperand[X] - (*this)[X] * rightOperand[Z],
							(*this)[X] * rightOperand[Y] - (*this)[Y] * rightOperand[X]);
	}

	template<class T>
	inline T Vertex3u<T>::dot(const Vertex3u<T> & rightOperand) const
	{
		return (*this)[X] * rightOperand[X]
			+ (*this)[Y] * rightOperand[Y]
			+ (*this)[Z] * rightOperand[Z];
	}

	template<class T>
	inline T Vertex3u<T>::distanceFrom(const Vertex3u<T> & rightOperand) const
	{
		return this->operator-(rightOperand).magnitude();
	}
}