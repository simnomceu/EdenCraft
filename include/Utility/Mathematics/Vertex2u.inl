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
	inline Vertex2u<T>::Vertex2u() : std::array<T, 2>{ 0, 0 } {}

	template <class T>
	inline Vertex2u<T>::Vertex2u(const T x, const T y) : std::array<T, 2>{ x, y } {}

	template <class T>
	template <typename V>
	inline Vertex2u<T>::Vertex2u(const Vertex2u<V> & copy) :
		std::array<T, 2>{ static_cast<T>(copy[0]), static_cast<T>(copy[1]) } {}

	template <class T>
	template <typename V>
	Vertex2u<T> & Vertex2u<T>::operator=(const Vertex2u<V> & copy)
	{
		(*this)[0] = static_cast<T>(copy[0]);
		(*this)[1] = static_cast<T>(copy[1]);
		return *this;
	}

	template<class T>
	template<typename V>
	inline Vertex2u<T>& Vertex2u<T>::operator/=(const V value)
	{
		(*this)[0] /= value;
		(*this)[1] /= value;
		return *this;
	}

	template<class T>
	template<typename V>
	inline Vertex2u<T>& Vertex2u<T>::operator*=(const V value)
	{
		(*this)[0] *= value;
		(*this)[1] *= value;
		return *this;
	}

	template<class T>
	inline Vertex2u<T>& Vertex2u<T>::operator+=(const Vertex2u<T> value)
	{
		(*this)[0] += value[0];
		(*this)[1] += value[1];
		return *this;
	}

	template<class T>
	inline Vertex2u<T>& Vertex2u<T>::operator-=(const Vertex2u<T> value)
	{
		(*this)[0] -= value[0];
		(*this)[1] -= value[1];
		return *this;
	}

	template<class T>
	template<typename V>
	inline Vertex2u<T> Vertex2u<T>::operator/(const V value) const
	{
		return Vertex2u<T>((*this)[0] / value, (*this)[1] / value);
	}

	template<class T>
	template<typename V>
	inline Vertex2u<T> Vertex2u<T>::operator*(const V value) const
	{
		return Vertex2u<T>((*this)[0] * value, (*this)[1] * value);
	}

	template<class T>
	inline Vertex2u<T> Vertex2u<T>::operator+(const Vertex2u<T> value) const
	{
		return Vertex2u<T>((*this)[0] + value[0], (*this)[1] + value[1]);
	}

	template<class T>
	inline Vertex2u<T> Vertex2u<T>::operator-(const Vertex2u<T> value) const
	{
		return Vertex2u<T>((*this)[0] - value[0], (*this)[1] - value[1]);
	}

	template<class T>
	inline Vertex2u<T> Vertex2u<T>::operator-() const
	{
		return Vertex2u<T>(-(*this)[0], -(*this)[1]);
	}

	template<class T>
	inline bool Vertex2u<T>::operator==(const Vertex2u<T> & rightOperand) const
	{
		return (*this)[0] == rightOperand[0] && (*this)[1] == rightOperand[1];
	}

	template<class T>
	inline void Vertex2u<T>::normalize()
	{
		this->operator/=(this->magnitude());
	}

	template<class T>
	inline T Vertex2u<T>::magnitude() const
	{
		return sqrt(this->dot(*this));
	}

	template<class T>
	inline T Vertex2u<T>::dot(const Vertex2u<T> & rightOperand) const
	{
		return (*this)[0] * rightOperand[0]
			+ (*this)[1] * rightOperand[1];
	}

	template<class T>
	inline T Vertex2u<T>::distanceFrom(const Vertex2u<T> & rightOperand) const
	{
		return this->operator-(rightOperand).magnitude();
	}
}