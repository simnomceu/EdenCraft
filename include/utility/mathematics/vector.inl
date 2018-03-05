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

#include <algorithm>

/**
 * @remark Any Vector(std::move(std::valarray)) should be change to a static_cast<Vector>(std::valarray) as it is faster.
 * Or maybe adding an helper cast method would help ?
 * like Vector::operator std::valarray() ?
 */

namespace ece
{
	template <class T, unsigned int Size, typename enabled>
	inline Vector<T, Size, enabled>::Vector(): std::valarray<T>(static_cast<T>(0), Size) {}

	template <class T, unsigned int Size, typename enabled>
	template <class U>
	inline Vector<T, Size, enabled>::Vector(const Vector<U, Size> & rhs): std::valarray<T>()
	{
		for (unsigned int i = 0; i < Size; ++i) {
			(*this)[i] = static_cast<T>(rhs[i]);
		}
	}

	template <class T, unsigned int Size, typename enabled>
	Vector<T, Size, enabled>::Vector(const std::initializer_list<T> &  il): std::valarray<T>(il)
	{
		if (this->size() != Size) {
			this->resize(Size);
		}
	}

	template <class T, unsigned int Size, typename enabled>
	inline Vector<T, Size, enabled>::Vector(std::valarray<T> && move) : std::valarray<T>(move) {}

	template <class T, unsigned int Size, typename enabled>
	Vector<T, Size, enabled> & Vector<T, Size, enabled>::operator=(const std::initializer_list<T> & il)
	{
		std::valarray<T>::operator=(il);
		return *this;
	}

	template <class T, unsigned int Size, typename enabled>
	inline const T & Vector<T, Size, enabled>::operator[](const unsigned int index) const { return std::valarray<T>::operator[](index); }

	template <class T, unsigned int Size, typename enabled>
	inline T & Vector<T, Size, enabled>::operator[](const unsigned int index) { return std::valarray<T>::operator[](index); }

	template <class T, unsigned int Size, typename enabled>
	inline Vector<T, Size, enabled> Vector<T, Size, enabled>::operator[](std::slice_array<T> slicearr) const
		{ return static_cast<Vector<T, Size, enabled>>(std::valarray<T>::operator[](slicearr)); }

	template <class T, unsigned int Size, typename enabled>
	inline std::slice_array<T> Vector<T, Size, enabled>::operator[](std::slice_array<T> slicearr) { return std::valarray<T>::operator[](slicearr); }

	template <class T, unsigned int Size, typename enabled>
	inline Vector<T, Size, enabled> Vector<T, Size, enabled>::operator[](std::gslice_array<T> & gslicearr) const
		{ return Vector<T, Size, enabled>(std::move(std::valarray<T>::operator[](gslicearr))); }

	template <class T, unsigned int Size, typename enabled>
	inline std::gslice_array<T> Vector<T, Size, enabled>::operator[](std::gslice_array<T> & gslicearr)
		{ return std::valarray<T>::operator[](gslicearr); }

//	template <class T, unsigned int Size, typename enabled>
//	inline Vector<T, Size, enabled> Vector<T, Size, enabled>::operator[](const Vector<bool, Size> & boolarr) const
//		{ return Vector<T, Size, enabled>(std::move(std::valarray<T>::operator[](boolarr))); }

//	template <class T, unsigned int Size, typename enabled>
//	inline std::mask_array<T> Vector<T, Size, enabled>::operator[](const Vector<bool, Size> & maskarr)
//		{ return std::valarray<T>::operator[](maskarr); }

//	template <class T, unsigned int Size, typename enabled>
//	inline Vector<T, Size, enabled> Vector<T, Size, enabled>::operator[](const Vector<bool, Size> & indarr) const
//		{ return Vector<T, Size, enabled>(std::move(std::valarray<T>::operator[](indarr))); }

//	template <class T, unsigned int Size, typename enabled>
//	inline std::indirect_array<T> Vector<T, Size, enabled>::operator[](const Vector<bool, Size> & indarr)
//		{ return std::valarray<T>::operator[](indarr); }

	template <class T, unsigned int Size, typename enabled>
	inline Vector<T, Size, enabled> Vector<T, Size, enabled>::operator+() const noexcept
		{ return Vector<T, Size, enabled>(std::move(std::valarray<T>::operator+())); }

	template <class T, unsigned int Size, typename enabled>
	inline Vector<T, Size, enabled> Vector<T, Size, enabled>::operator-() const noexcept
		{ return Vector<T, Size, enabled>(std::move(std::valarray<T>::operator-())); }

	template <class T, unsigned int Size, typename enabled>
	template <typename forward, typename>
	inline Vector<T, Size, enabled> Vector<T, Size, enabled>::operator~() const noexcept
		{ return Vector<T, Size, enabled>(std::move(std::valarray<T>::operator~())); }

	template <class T, unsigned int Size, typename enabled>
	template <typename forward, typename>
	inline Vector<bool, Size> Vector<T, Size, enabled>::operator!() const noexcept
		{ return Vector<bool, Size>(std::move(std::valarray<T>::operator!())); }

	template <class T, unsigned int Size, typename enabled>
	inline Vector<T, Size, enabled> & Vector<T, Size, enabled>::operator+=(const Vector<T, Size, enabled> & v)
	{
		std::valarray<T>::operator+=(v);
		return *this;
	}

	template <class T, unsigned int Size, typename enabled>
	inline Vector<T, Size, enabled> & Vector<T, Size, enabled>::operator-=(const Vector<T, Size, enabled> & v)
	{
		std::valarray<T>::operator-=(v);
		return *this;
	}

	template <class T, unsigned int Size, typename enabled>
	inline Vector<T, Size, enabled> & Vector<T, Size, enabled>::operator*=(const Vector<T, Size, enabled> & v)
	{
		std::valarray<T>::operator*=(v);
		return *this;
	}

	template <class T, unsigned int Size, typename enabled>
	inline Vector<T, Size, enabled> & Vector<T, Size, enabled>::operator/=(const Vector<T, Size, enabled> & v)
	{
		std::valarray<T>::operator/=(v);
		return *this;
	}

	template <class T, unsigned int Size, typename enabled>
	template <typename forward, typename>
	inline Vector<T, Size, enabled> & Vector<T, Size, enabled>::operator%=(const Vector<T, Size, enabled> & v)
	{
		std::valarray<T>::operator%=(v);
		return *this;
	}

	template <class T, unsigned int Size, typename enabled>
	template <typename forward, typename>
	inline Vector<T, Size, enabled> & Vector<T, Size, enabled>::operator&=(const Vector<T, Size, enabled> & v)
	{
		std::valarray<T>::operator&=(v);
		return *this;
	}

	template <class T, unsigned int Size, typename enabled>
	template <typename forward, typename>
	inline Vector<T, Size, enabled> & Vector<T, Size, enabled>::operator|=(const Vector<T, Size, enabled> & v)
	{
		std::valarray<T>::operator|=(v);
		return *this;
	}

	template <class T, unsigned int Size, typename enabled>
	template <typename forward, typename>
	inline Vector<T, Size, enabled> & Vector<T, Size, enabled>::operator^=(const Vector<T, Size, enabled> & v)
	{
		std::valarray<T>::operator^=(v);
		return *this;
	}

	template <class T, unsigned int Size, typename enabled>
	template <typename forward, typename>
	inline Vector<T, Size, enabled> & Vector<T, Size, enabled>::operator<<=(const Vector<T, Size, enabled> & v)
	{
		std::valarray<T>::operator<<=(v);
		return *this;
	}

	template <class T, unsigned int Size, typename enabled>
	template <typename forward, typename>
	inline Vector<T, Size, enabled> & Vector<T, Size, enabled>::operator>>=(const Vector<T, Size, enabled> & v)
	{
		std::valarray<T>::operator>>=(v);
		return *this;
	}

	template <class T, unsigned int Size, typename enabled>
	inline Vector<T, Size, enabled> & Vector<T, Size, enabled>::operator+=(const T & val)
	{
		std::valarray<T>::operator+=(val);
		return *this;
	}

	template <class T, unsigned int Size, typename enabled>
	inline Vector<T, Size, enabled> & Vector<T, Size, enabled>::operator-=(const T & val)
	{
		std::valarray<T>::operator-=(val);
		return *this;
	}

	template <class T, unsigned int Size, typename enabled>
	inline Vector<T, Size, enabled> & Vector<T, Size, enabled>::operator*=(const T & val)
	{
		std::valarray<T>::operator*=(val);
		return *this;
	}

	template <class T, unsigned int Size, typename enabled>
	inline Vector<T, Size, enabled> & Vector<T, Size, enabled>::operator/=(const T & val)
	{
		std::valarray<T>::operator/=(val);
		return *this;
	}

	template <class T, unsigned int Size, typename enabled>
	template <typename forward, typename>
	inline Vector<T, Size, enabled> & Vector<T, Size, enabled>::operator%=(const T & val)
	{
		std::valarray<T>::operator%=(val);
		return *this;
	}

	template <class T, unsigned int Size, typename enabled>
	template <typename forward, typename>
	inline Vector<T, Size, enabled> & Vector<T, Size, enabled>::operator&=(const T & val)
	{
		std::valarray<T>::operator&=(val);
		return *this;
	}

	template <class T, unsigned int Size, typename enabled>
	template <typename forward, typename>
	inline Vector<T, Size, enabled> & Vector<T, Size, enabled>::operator|=(const T & val)
	{
		std::valarray<T>::operator|=(val);
		return *this;
	}

	template <class T, unsigned int Size, typename enabled>
	template <typename forward, typename>
	inline Vector<T, Size, enabled> & Vector<T, Size, enabled>::operator^=(const T & val)
	{
		std::valarray<T>::operator^=(val);
		return *this;
	}

	template <class T, unsigned int Size, typename enabled>
	template <typename forward, typename>
	inline Vector<T, Size, enabled> & Vector<T, Size, enabled>::operator<<=(const T & val)
	{
		std::valarray<T>::operator<<=(val);
		return *this;
	}

	template <class T, unsigned int Size, typename enabled>
	template <typename forward, typename>
	inline Vector<T, Size, enabled> & Vector<T, Size, enabled>::operator>>=(const T & val)
	{
		std::valarray<T>::operator>>=(val);
		return *this;
	}

	template <class T, unsigned int Size, typename enabled>
	inline Vector<T, Size, enabled> Vector<T, Size, enabled>::shift(int count) const { return Vector<T, Size, enabled>(std::move(std::valarray<T>::shift(count))); }

	template <class T, unsigned int Size, typename enabled>
	inline Vector<T, Size, enabled> Vector<T, Size, enabled>::cshift(int count) const { return Vector<T, Size, enabled>(std::move(std::valarray<T>::cshift(count))); }

	template <class T, unsigned int Size, typename enabled>
	inline Vector<T, Size, enabled> Vector<T, Size, enabled>::apply(T func(T)) const { return Vector<T, Size, enabled>(std::move(std::valarray<T>::apply(func))); }

	template <class T, unsigned int Size, typename enabled>
	inline Vector<T, Size, enabled> Vector<T, Size, enabled>::apply(T func(const T&)) const { return Vector<T, Size, enabled>(std::move(std::valarray<T>::apply(func))); }

	template <class T, unsigned int Size, typename enabled>
	inline Vector<T, Size, enabled> Vector<T, Size, enabled>::operator+(const Vector<T, Size, enabled> & rhs) const
		{ return Vector<T, Size, enabled>(std::move(std::operator+(*this, rhs))); }

	template <class T, unsigned int Size, typename enabled>
	inline Vector<T, Size, enabled> Vector<T, Size, enabled>::operator-(const Vector<T, Size, enabled> & rhs) const
		{ return Vector<T, Size, enabled>(std::move(std::operator-(*this, rhs))); }

	template <class T, unsigned int Size, typename enabled>
	inline Vector<T, Size, enabled> Vector<T, Size, enabled>::operator*(const Vector<T, Size, enabled> & rhs) const
		{ return Vector<T, Size, enabled>(std::move(std::operator*(*this, rhs))); }

	template <class T, unsigned int Size, typename enabled>
	inline Vector<T, Size, enabled> Vector<T, Size, enabled>::operator/(const Vector<T, Size, enabled> & rhs) const
		{ return Vector<T, Size, enabled>(std::move(std::operator/(*this, rhs))); }

	template <class T, unsigned int Size, typename enabled>
	template <typename forward, typename>
	inline Vector<T, Size, enabled> Vector<T, Size, enabled>::operator%(const Vector<T, Size, enabled> & rhs) const
		{ return Vector<T, Size, enabled>(std::move(std::operator%(*this, rhs))); }

	template <class T, unsigned int Size, typename enabled>
	template <typename forward, typename>
	inline Vector<T, Size, enabled> Vector<T, Size, enabled>::operator&(const Vector<T, Size, enabled> & rhs) const
		{ return Vector<T, Size, enabled>(std::move(std::operator&(*this, rhs))); }

	template <class T, unsigned int Size, typename enabled>
	template <typename forward, typename>
	inline Vector<T, Size, enabled> Vector<T, Size, enabled>::operator|(const Vector<T, Size, enabled> & rhs) const
		{ return Vector<T, Size, enabled>(std::move(std::operator|(*this, rhs))); }

	template <class T, unsigned int Size, typename enabled>
	template <typename forward, typename>
	inline Vector<T, Size, enabled> Vector<T, Size, enabled>::operator^(const Vector<T, Size, enabled> & rhs) const
		{ return Vector<T, Size, enabled>(std::move(std::operator^(*this, rhs))); }

	template <class T, unsigned int Size, typename enabled>
	template <typename forward, typename>
	inline Vector<T, Size, enabled> Vector<T, Size, enabled>::operator<<(const Vector<T, Size, enabled> & rhs) const
		{ return Vector<T, Size, enabled>(std::move(std::operator<<(*this, rhs))); }

	template <class T, unsigned int Size, typename enabled>
	template <typename forward, typename>
	inline Vector<T, Size, enabled> Vector<T, Size, enabled>::operator>>(const Vector<T, Size, enabled> & rhs) const
		{ return Vector<T, Size, enabled>(std::move(std::operator>>(*this, rhs))); }

	template <class T, unsigned int Size, typename enabled>
	template <typename forward, typename>
	inline Vector<bool, Size> Vector<T, Size, enabled>::operator&&(const Vector<T, Size, enabled> & rhs) const
		{ return Vector<bool, Size>(std::move(std::operator&&(*this, rhs))); }

	template <class T, unsigned int Size, typename enabled>
	template <typename forward, typename>
	inline Vector<bool, Size> Vector<T, Size, enabled>::operator||(const Vector<T, Size, enabled> & rhs) const
		{ return Vector<bool, Size>(std::move(std::operator||(*this, rhs))); }

	template <class T, unsigned int Size, typename enabled>
	inline Vector<T, Size, enabled> Vector<T, Size, enabled>::operator+(const T & rhs) const
		{ return Vector<T, Size, enabled>(std::move(std::operator+(*this, rhs))); }

	template <class T, unsigned int Size, typename enabled>
	inline Vector<T, Size, enabled> Vector<T, Size, enabled>::operator-(const T & rhs) const
		{ return Vector<T, Size, enabled>(std::move(std::operator-(*this, rhs))); }

	template <class T, unsigned int Size, typename enabled>
	inline Vector<T, Size, enabled> Vector<T, Size, enabled>::operator*(const T & rhs) const
		{ return Vector<T, Size, enabled>(std::move(std::operator*(*this, rhs))); }

	template <class T, unsigned int Size, typename enabled>
	inline Vector<T, Size, enabled> Vector<T, Size, enabled>::operator/(const T & rhs) const
		{ return Vector<T, Size, enabled>(std::move(std::operator/(*this, rhs))); }

	template <class T, unsigned int Size, typename enabled>
	template <typename forward, typename>
	inline Vector<T, Size, enabled> Vector<T, Size, enabled>::operator%(const T & rhs) const
		{ return Vector<T, Size, enabled>(std::move(std::operator%(*this, rhs))); }

	template <class T, unsigned int Size, typename enabled>
	template <typename forward, typename>
	inline Vector<T, Size, enabled> Vector<T, Size, enabled>::operator&(const T & rhs) const
		{ return Vector<T, Size, enabled>(std::move(std::operator&(*this, rhs))); }

	template <class T, unsigned int Size, typename enabled>
	template <typename forward, typename>
	inline Vector<T, Size, enabled> Vector<T, Size, enabled>::operator|(const T & rhs) const
		{ return Vector<T, Size, enabled>(std::move(std::operator|(*this, rhs))); }

	template <class T, unsigned int Size, typename enabled>
	template <typename forward, typename>
	inline Vector<T, Size, enabled> Vector<T, Size, enabled>::operator^(const T & rhs) const
		{ return Vector<T, Size, enabled>(std::move(std::operator^(*this, rhs))); }

	template <class T, unsigned int Size, typename enabled>
	template <typename forward, typename>
	inline Vector<T, Size, enabled> Vector<T, Size, enabled>::operator<<(const T & rhs) const
		{ return Vector<T, Size, enabled>(std::move(std::operator<<(*this, rhs))); }

	template <class T, unsigned int Size, typename enabled>
	template <typename forward, typename>
	inline Vector<T, Size, enabled> Vector<T, Size, enabled>::operator>>(const T & rhs) const
		{ return Vector<T, Size, enabled>(std::move(std::operator>>(*this, rhs))); }

	template <class T, unsigned int Size, typename enabled>
	template <typename forward, typename>
	inline Vector<bool, Size> Vector<T, Size, enabled>::operator&&(const T & rhs) const
		{ return Vector<bool, Size>(std::move(std::operator&&(*this, rhs))); }

	template <class T, unsigned int Size, typename enabled>
	template <typename forward, typename>
	inline Vector<bool, Size> Vector<T, Size, enabled>::operator||(const T & rhs) const
		{ return Vector<bool, Size>(std::move(std::operator||(*this, rhs))); }

	template <class T, unsigned int Size, typename enabled>
	bool Vector<T, Size, enabled>::operator==(const Vector<T, Size, enabled> & rhs) const { return std::operator==(*this, rhs).min(); }

//	template <class T, unsigned int Size, typename enabled>
//	Vector<bool, Size> Vector<T, Size, enabled>::operator==(const Vector<T, Size, enabled> & rhs)
//		{ return Vector<T, Size, enabled>(std::move(std::valarray<T>::operator==(rhs))); }

	template <class T, unsigned int Size, typename enabled>
	bool Vector<T, Size, enabled>::operator!=(const Vector<T, Size, enabled> & rhs)
		{ return std::operator!=(*this, rhs).min(); }

	template <class T, unsigned int Size, typename enabled>
	Vector<bool, Size> Vector<T, Size, enabled>::operator<(const Vector<T, Size, enabled> & rhs)
		{ return Vector<bool, Size>(std::move(std::operator<(*this, rhs))); }

	template <class T, unsigned int Size, typename enabled>
	Vector<bool, Size> Vector<T, Size, enabled>::operator<=(const Vector<T, Size, enabled> & rhs)
		{ return Vector<bool, Size>(std::move(std::operator<=(*this, rhs))); }

	template <class T, unsigned int Size, typename enabled>
	Vector<bool, Size> Vector<T, Size, enabled>::operator>(const Vector<T, Size, enabled> & rhs)
		{ return Vector<bool, Size>(std::move(std::operator>(*this, rhs))); }

	template <class T, unsigned int Size, typename enabled>
	Vector<bool, Size> Vector<T, Size, enabled>::operator>=(const Vector<T, Size, enabled> & rhs)
		{ return Vector<bool, Size>(std::move(std::operator>=(*this, rhs))); }

	template <class T, unsigned int Size, typename enabled>
	Vector<bool, Size> Vector<T, Size, enabled>::operator==(const T & rhs)
		{ return Vector<bool, Size>(std::move(std::operator==(*this, rhs))); }

	template <class T, unsigned int Size, typename enabled>
	Vector<bool, Size> Vector<T, Size, enabled>::operator!=(const T & rhs)
		{ return Vector<bool, Size>(std::move(std::operator!=(*this, rhs))); }

	template <class T, unsigned int Size, typename enabled>
	Vector<bool, Size> Vector<T, Size, enabled>::operator<(const T & rhs)
		{ return Vector<bool, Size>(std::move(std::operator<(*this, rhs))); }

	template <class T, unsigned int Size, typename enabled>
	Vector<bool, Size> Vector<T, Size, enabled>::operator<=(const T & rhs)
		{ return Vector<bool, Size>(std::move(std::operator<=(*this, rhs))); }

	template <class T, unsigned int Size, typename enabled>
	Vector<bool, Size> Vector<T, Size, enabled>::operator>(const T & rhs)
		{ return Vector<bool, Size>(std::move(std::operator>(*this, rhs))); }

	template <class T, unsigned int Size, typename enabled>
	Vector<bool, Size> Vector<T, Size, enabled>::operator>=(const T & rhs)
		{ return Vector<bool, Size>(std::move(std::operator>=(*this, rhs))); }

	template <class T, unsigned int Size, typename enabled>
	template <typename forward, typename>
	inline Vector<T, Size, enabled> Vector<T, Size, enabled>::abs() const { return Vector<T, Size, enabled>(std::move(std::abs(*this))); }

	template <class T, unsigned int Size, typename enabled>
	inline Vector<T, Size, enabled> Vector<T, Size, enabled>::exp() const { return Vector<T, Size, enabled>(std::move(std::exp(*this))); }

	template <class T, unsigned int Size, typename enabled>
	inline Vector<T, Size, enabled> Vector<T, Size, enabled>::log() const { return Vector<T, Size, enabled>(std::move(std::log(*this))); }

	template <class T, unsigned int Size, typename enabled>
	inline Vector<T, Size, enabled> Vector<T, Size, enabled>::log10() const { return Vector<T, Size, enabled>(std::move(std::log10(*this))); }

	template <class T, unsigned int Size, typename enabled>
	inline Vector<T, Size, enabled> Vector<T, Size, enabled>::pow(const Vector<T, Size, enabled> & exp) const { return Vector<T, Size, enabled>(std::move(std::pow(*this, exp))); }

	template <class T, unsigned int Size, typename enabled>
	inline Vector<T, Size, enabled> Vector<T, Size, enabled>::pow(const T & exp) const { return Vector<T, Size, enabled>(std::move(std::pow(*this, exp))); }

	template <class T, unsigned int Size, typename enabled>
	inline Vector<T, Size, enabled> Vector<T, Size, enabled>::sqrt() const { return Vector<T, Size, enabled>(std::move(std::sqrt(*this))); }

	template <class T, unsigned int Size, typename enabled>
	inline Vector<T, Size, enabled> Vector<T, Size, enabled>::sin() const { return Vector<T, Size, enabled>(std::move(std::sin(*this))); }

	template <class T, unsigned int Size, typename enabled>
	inline Vector<T, Size, enabled> Vector<T, Size, enabled>::cos() const { return Vector<T, Size, enabled>(std::move(std::cos(*this))); }

	template <class T, unsigned int Size, typename enabled>
	inline Vector<T, Size, enabled> Vector<T, Size, enabled>::tan() const { return Vector<T, Size, enabled>(std::move(std::tan(*this))); }

	template <class T, unsigned int Size, typename enabled>
	inline Vector<T, Size, enabled> Vector<T, Size, enabled>::asin() const { return Vector<T, Size, enabled>(std::move(std::asin(*this))); }

	template <class T, unsigned int Size, typename enabled>
	inline Vector<T, Size, enabled> Vector<T, Size, enabled>::acos() const { return Vector<T, Size, enabled>(std::move(std::acos(*this))); }

	template <class T, unsigned int Size, typename enabled>
	inline Vector<T, Size, enabled> Vector<T, Size, enabled>::atan() const { return Vector<T, Size, enabled>(std::move(std::atan(*this))); }

	template <class T, unsigned int Size, typename enabled>
	inline Vector<T, Size, enabled> Vector<T, Size, enabled>::atan2(const Vector<T, Size, enabled> & x) const { return Vector<T, Size, enabled>(std::move(std::atan2(*this, x))); }

	template <class T, unsigned int Size, typename enabled>
	inline Vector<T, Size, enabled> Vector<T, Size, enabled>::atan2(const T & x) const { return Vector<T, Size, enabled>(std::move(std::atan2(*this, x))); }

	template <class T, unsigned int Size, typename enabled>
	inline Vector<T, Size, enabled> Vector<T, Size, enabled>::sinh() const { return Vector<T, Size, enabled>(std::move(std::sinh(*this))); }

	template <class T, unsigned int Size, typename enabled>
	inline Vector<T, Size, enabled> Vector<T, Size, enabled>::cosh() const { return Vector<T, Size, enabled>(std::move(std::cosh(*this))); }

	template <class T, unsigned int Size, typename enabled>
	inline Vector<T, Size, enabled> Vector<T, Size, enabled>::tanh() const { return Vector<T, Size, enabled>(std::move(std::tanh(*this))); }

	template <class T, unsigned int Size, typename enabled>
	inline Vector<double, Size> Vector<T, Size, enabled>::normalize() { return Vector<double, Size>(*this).operator/(this->magnitude()); }

	template <class T, unsigned int Size, typename enabled>
	inline double Vector<T, Size, enabled>::magnitude() const { return std::sqrt(this->dot(*this)); }

	template <class T, unsigned int Size, typename enabled>
	template <typename forward, typename>
	inline Vector<T, Size, enabled> Vector<T, Size, enabled>::cross(const Vector<T, Size, enabled> & rightOperand) const
	{
		return Vector<T, Size>{(*this)[1] * rightOperand[2] - (*this)[2] * rightOperand[1],
			(*this)[2] * rightOperand[0] - (*this)[0] * rightOperand[2],
			(*this)[0] * rightOperand[1] - (*this)[1] * rightOperand[0]};
	}

	template <class T, unsigned int Size, typename enabled>
	inline T Vector<T, Size, enabled>::dot(const Vector<T, Size, enabled> & rightOperand) const { return this->operator*(rightOperand).sum(); }

	template <class T, unsigned int Size, typename enabled>
	inline double Vector<T, Size, enabled>::distanceFrom(const Vector<T, Size, enabled> & rightOperand) const { return this->operator-(rightOperand).magnitude(); }
}
