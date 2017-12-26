#include <algorithm>

namespace ece
{
	template <class T, unsigned int Size>
	template <class U>
	inline Vector<T, Size>::Vector(const Vector<U, Size> & rhs): std::valarray<T>()
	{
		for (int i = 0; i < Size; ++i) {
			(*this)[i] = static_cast<T>(rhs[i]);
		}
	}

	template <class T, unsigned int Size>
	Vector<T, Size>::Vector(const std::initializer_list<T> &  il): std::valarray<T>(il)
	{
		if (this->size() != Size) {
			this->resize(Size);
		}
	}

	template <class T, unsigned int Size>
	Vector<T, Size> & Vector<T, Size>::operator=(const std::initializer_list<T> & il)
	{
		std::valarray<T>::operator=(il);
		return *this;
	}

	template <class T, unsigned int Size>
	inline const T & Vector<T, Size>::operator[](const unsigned int index) const { return std::valarray<T>::operator[](index); }

	template <class T, unsigned int Size>
	inline T & Vector<T, Size>::operator[](const unsigned int index) { return std::valarray<T>::operator[](index); }

	template <class T, unsigned int Size>
	inline Vector<T, Size> Vector<T, Size>::operator[](std::slice_array<T> slicearr) const
		{ Vector<T, Size>(std::move(std::valarray<T>::operator[](slicearr))); }

	template <class T, unsigned int Size>
	inline std::slice_array<T> Vector<T, Size>::operator[](std::slice_array<T> slicearr) { return std::valarray<T>::operator[](slicearr); }

	template <class T, unsigned int Size>
	inline Vector<T, Size> Vector<T, Size>::operator[](std::gslice_array<T> & gslicearr) const
		{ return Vector<T, Size>(std::move(std::valarray<T>::operator[](gslicearr))); }

	template <class T, unsigned int Size>
	inline std::gslice_array<T> Vector<T, Size>::operator[](std::gslice_array<T> & gslicearr)
		{ return std::valarray<T>::operator[](gslicearr); }

	template <class T, unsigned int Size>
	inline Vector<T, Size> Vector<T, Size>::operator[](const Vector<bool, Size> & maskarr) const
		{ return Vector<T, Size>(std::move(std::valarray<T>::operator[](maskarr))); }

//	template <class T, unsigned int Size>
//	inline std::mask_array<T> Vector<T, Size>::operator[](const Vector<bool, Size> & maskarr)
//		{ return std::valarray<T>::operator[](maskarr); }

//	template <class T, unsigned int Size>
//	inline Vector<T, Size> Vector<T, Size>::operator[](const Vector<bool, Size> & indarr) const
//		{ return Vector<T, Size>(std::move(std::valarray<T>::operator[](indarr))); }

//	template <class T, unsigned int Size>
//	inline std::indirect_array<T> Vector<T, Size>::operator[](const Vector<bool, Size> & indarr)
//		{ return std::valarray<T>::operator[](indarr); }

	template <class T, unsigned int Size>
	inline Vector<T, Size> Vector<T, Size>::operator+() const noexcept
		{ return Vector<T, Size>(std::move(std::valarray<T>::operator+())); }

	template <class T, unsigned int Size>
	inline Vector<T, Size> Vector<T, Size>::operator-() const noexcept
		{ return Vector<T, Size>(std::move(std::valarray<T>::operator-())); }

	template <class T, unsigned int Size>
	inline Vector<T, Size> Vector<T, Size>::operator~() const noexcept
		{ return Vector<T, Size>(std::move(std::valarray<T>::operator~())); }

	template <class T, unsigned int Size>
	inline Vector<bool, Size> Vector<T, Size>::operator!() const noexcept
		{ return Vector<bool, Size>(std::move(std::valarray<T>::operator!())); }

	template <class T, unsigned int Size>
	inline Vector<T, Size> & Vector<T, Size>::operator+=(const Vector<T, Size> & v)
	{
		std::valarray<T>::operator+=(v);
		return *this;
	}

	template <class T, unsigned int Size>
	inline Vector<T, Size> & Vector<T, Size>::operator-=(const Vector<T, Size> & v)
	{
		std::valarray<T>::operator-=(v);
		return *this;
	}

	template <class T, unsigned int Size>
	inline Vector<T, Size> & Vector<T, Size>::operator*=(const Vector<T, Size> & v)
	{
		std::valarray<T>::operator*=(v);
		return *this;
	}

	template <class T, unsigned int Size>
	inline Vector<T, Size> & Vector<T, Size>::operator/=(const Vector<T, Size> & v)
	{
		std::valarray<T>::operator/=(v);
		return *this;
	}

	template <class T, unsigned int Size>
	inline Vector<T, Size> & Vector<T, Size>::operator%=(const Vector<T, Size> & v)
	{
		std::valarray<T>::operator%=(v);
		return *this;
	}

	template <class T, unsigned int Size>
	inline Vector<T, Size> & Vector<T, Size>::operator&=(const Vector<T, Size> & v)
	{
		std::valarray<T>::operator&=(v);
		return *this;
	}

	template <class T, unsigned int Size>
	inline Vector<T, Size> & Vector<T, Size>::operator|=(const Vector<T, Size> & v)
	{
		std::valarray<T>::operator|=(v);
		return *this;
	}
		
	template <class T, unsigned int Size>
	inline Vector<T, Size> & Vector<T, Size>::operator^=(const Vector<T, Size> & v)
	{
		std::valarray<T>::operator^=(v);
		return *this;
	}

	template <class T, unsigned int Size>
	inline Vector<T, Size> & Vector<T, Size>::operator<<=(const Vector<T, Size> & v)
	{
		std::valarray<T>::operator<<=(v);
		return *this;
	}

	template <class T, unsigned int Size>
	inline Vector<T, Size> & Vector<T, Size>::operator>>=(const Vector<T, Size> & v)
	{
		std::valarray<T>::operator>>=(v);
		return *this;
	}

	template <class T, unsigned int Size>
	inline Vector<T, Size> & Vector<T, Size>::operator+=(const T & val)
	{
		std::valarray<T>::operator+=(val);
		return *this;
	}

	template <class T, unsigned int Size>
	inline Vector<T, Size> & Vector<T, Size>::operator-=(const T & val)
	{
		std::valarray<T>::operator-=(val);
		return *this;
	}

	template <class T, unsigned int Size>
	inline Vector<T, Size> & Vector<T, Size>::operator*=(const T & val)
	{
		std::valarray<T>::operator*=(val);
		return *this;
	}

	template <class T, unsigned int Size>
	inline Vector<T, Size> & Vector<T, Size>::operator/=(const T & val)
	{
		std::valarray<T>::operator/=(val);
		return *this;
	}

	template <class T, unsigned int Size>
	inline Vector<T, Size> & Vector<T, Size>::operator%=(const T & val)
	{
		std::valarray<T>::operator%=(val);
		return *this;
	}

	template <class T, unsigned int Size>
	inline Vector<T, Size> & Vector<T, Size>::operator&=(const T & val)
	{
		std::valarray<T>::operator&=(val);
		return *this;
	}

	template <class T, unsigned int Size>
	inline Vector<T, Size> & Vector<T, Size>::operator|=(const T & val)
	{
		std::valarray<T>::operator|=(val);
		return *this;
	}

	template <class T, unsigned int Size>
	inline Vector<T, Size> & Vector<T, Size>::operator^=(const T & val)
	{
		std::valarray<T>::operator^=(val);
		return *this;
	}

	template <class T, unsigned int Size>
	inline Vector<T, Size> & Vector<T, Size>::operator<<=(const T & val)
	{
		std::valarray<T>::operator<<=(val);
		return *this;
	}

	template <class T, unsigned int Size>
	inline Vector<T, Size> & Vector<T, Size>::operator>>=(const T & val)
	{
		std::valarray<T>::operator>>=(val);
		return *this;
	}

	template <class T, unsigned int Size>
	inline Vector<T, Size> Vector<T, Size>::shift(int count) const { return Vector<T, Size>(std::move(std::valarray<T>::shift(count))); }

	template <class T, unsigned int Size>
	inline Vector<T, Size> Vector<T, Size>::cshift(int count) const { return Vector<T, Size>(std::move(std::valarray<T>::cshift(count))); }

	template <class T, unsigned int Size>
	inline Vector<T, Size> Vector<T, Size>::apply(T func(T)) const { return Vector<T, Size>(std::move(std::valarray<T>::apply(func))); }

	template <class T, unsigned int Size>
	inline Vector<T, Size> Vector<T, Size>::apply(T func(const T&)) const { return Vector<T, Size>(std::move(std::valarray<T>::apply(func))); }

	template <class T, unsigned int Size>
	inline Vector<T, Size> Vector<T, Size>::operator+(const Vector<T, Size> & rhs) const
		{ return Vector<T, Size>(std::move(std::operator+(*this, rhs))); }

	template <class T, unsigned int Size>
	inline Vector<T, Size> Vector<T, Size>::operator-(const Vector<T, Size> & rhs) const
		{ return Vector<T, Size>(std::move(std::operator-(*this, rhs))); }

	template <class T, unsigned int Size>
	inline Vector<T, Size> Vector<T, Size>::operator*(const Vector<T, Size> & rhs) const
		{ return Vector<T, Size>(std::move(std::operator*(*this, rhs))); }

	template <class T, unsigned int Size>
	inline Vector<T, Size> Vector<T, Size>::operator/(const Vector<T, Size> & rhs) const
		{ return Vector<T, Size>(std::move(std::valarray<T>::operator/(rhs))); }

	template <class T, unsigned int Size>
	inline Vector<T, Size> Vector<T, Size>::operator%(const Vector<T, Size> & rhs) const
		{ return Vector<T, Size>(std::move(std::valarray<T>::operator%(rhs))); }

	template <class T, unsigned int Size>
	inline Vector<T, Size> Vector<T, Size>::operator&(const Vector<T, Size> & rhs) const
		{ return Vector<T, Size>(std::move(std::valarray<T>::operator&(rhs))); }

	template <class T, unsigned int Size>
	inline Vector<T, Size> Vector<T, Size>::operator|(const Vector<T, Size> & rhs) const
		{ return Vector<T, Size>(std::move(std::valarray<T>::operator|(rhs))); }

	template <class T, unsigned int Size>
	inline Vector<T, Size> Vector<T, Size>::operator^(const Vector<T, Size> & rhs) const
		{ return Vector<T, Size>(std::move(std::valarray<T>::operator^(rhs))); }

	template <class T, unsigned int Size>
	inline Vector<T, Size> Vector<T, Size>::operator<<(const Vector<T, Size> & rhs) const
		{ return Vector<T, Size>(std::move(std::valarray<T>::operator<<(rhs))); }

	template <class T, unsigned int Size>
	inline Vector<T, Size> Vector<T, Size>::operator>>(const Vector<T, Size> & rhs) const
		{ return Vector<T, Size>(std::move(std::valarray<T>::operator>>(rhs))); }

	template <class T, unsigned int Size>
	inline Vector<T, Size> Vector<T, Size>::operator&&(const Vector<T, Size> & rhs) const
		{ return Vector<T, Size>(std::move(std::valarray<T>::operator&&(rhs))); }

	template <class T, unsigned int Size>
	inline Vector<T, Size> Vector<T, Size>::operator||(const Vector<T, Size> & rhs) const
		{ return Vector<T, Size>(std::move(std::valarray<T>::operator||(rhs))); }

	template <class T, unsigned int Size>
	inline Vector<T, Size> Vector<T, Size>::operator+(const T & rhs) const
		{ return Vector<T, Size>(std::move(std::operator+(*this, rhs))); }

	template <class T, unsigned int Size>
	inline Vector<T, Size> Vector<T, Size>::operator-(const T & rhs) const
		{ return Vector<T, Size>(std::move(std::operator-(*this, rhs))); }

	template <class T, unsigned int Size>
	inline Vector<T, Size> Vector<T, Size>::operator*(const T & rhs) const
		{ return Vector<T, Size>(std::move(std::operator*(*this, rhs))); }

	template <class T, unsigned int Size>
	inline Vector<T, Size> Vector<T, Size>::operator/(const T & rhs) const
		{ return Vector<T, Size>(std::move(std::operator/(*this, rhs))); }

	template <class T, unsigned int Size>
	inline Vector<T, Size> Vector<T, Size>::operator%(const T & rhs) const
		{ return Vector<T, Size>(std::move(std::operator%(*this, rhs))); }

	template <class T, unsigned int Size>
	inline Vector<T, Size> Vector<T, Size>::operator&(const T & rhs) const
		{ return Vector<T, Size>(std::move(std::operator&(*this, rhs))); }

	template <class T, unsigned int Size>
	inline Vector<T, Size> Vector<T, Size>::operator|(const T & rhs) const
		{ return Vector<T, Size>(std::move(std::operator|(*this, rhs))); }

	template <class T, unsigned int Size>
	inline Vector<T, Size> Vector<T, Size>::operator^(const T & rhs) const
		{ return Vector<T, Size>(std::move(std::operator^(*this, rhs))); }

	template <class T, unsigned int Size>
	inline Vector<T, Size> Vector<T, Size>::operator<<(const T & rhs) const
		{ return Vector<T, Size>(std::move(std::operator<<(*this, rhs))); }

	template <class T, unsigned int Size>
	inline Vector<T, Size> Vector<T, Size>::operator>>(const T & rhs) const
		{ return Vector<T, Size>(std::move(std::operator>>(*this, rhs))); }

	template <class T, unsigned int Size>
	inline Vector<T, Size> Vector<T, Size>::operator&&(const T & rhs) const
		{ return Vector<T, Size>(std::move(std::operator&&(*this, rhs))); }

	template <class T, unsigned int Size>
	inline Vector<T, Size> Vector<T, Size>::operator||(const T & rhs) const
		{ return Vector<T, Size>(std::move(std::operator||(*this, rhs))); }

	template <class T, unsigned int Size>
	bool Vector<T, Size>::operator==(const Vector<T, Size> & rhs) const { return std::operator==(*this, rhs).min(); }

//	template <class T, unsigned int Size>
//	Vector<bool, Size> Vector<T, Size>::operator==(const Vector<T, Size> & rhs)
//		{ return Vector<T, Size>(std::move(std::valarray<T>::operator==(rhs))); }

	template <class T, unsigned int Size>
	Vector<bool, Size> Vector<T, Size>::operator!=(const Vector<T, Size> & rhs)
		{ return Vector<bool, Size>(std::move(std::valarray<T>::operator!=(rhs))); }

	template <class T, unsigned int Size>
	Vector<bool, Size> Vector<T, Size>::operator<(const Vector<T, Size> & rhs)
		{ return Vector<bool, Size>(std::move(std::valarray<T>::operator<(rhs))); }

	template <class T, unsigned int Size>
	Vector<bool, Size> Vector<T, Size>::operator<=(const Vector<T, Size> & rhs)
		{ return Vector<bool, Size>(std::move(std::valarray<T>::operator<=(rhs))); }

	template <class T, unsigned int Size>
	Vector<bool, Size> Vector<T, Size>::operator>(const Vector<T, Size> & rhs)
		{ return Vector<bool, Size>(std::move(std::valarray<T>::operator>(rhs))); }

	template <class T, unsigned int Size>
	Vector<bool, Size> Vector<T, Size>::operator>=(const Vector<T, Size> & rhs)
		{ return Vector<bool, Size>(std::move(std::valarray<T>::operator>=(rhs))); }

	template <class T, unsigned int Size>
	Vector<bool, Size> Vector<T, Size>::operator==(const T & rhs)
		{ return Vector<bool, Size>(std::move(std::valarray<T>::operator==(rhs))); }

	template <class T, unsigned int Size>
	Vector<bool, Size> Vector<T, Size>::operator!=(const T & rhs)
		{ return Vector<bool, Size>(std::move(std::valarray<T>::operator!=(rhs))); }

	template <class T, unsigned int Size>
	Vector<bool, Size> Vector<T, Size>::operator<(const T & rhs)
		{ return Vector<bool, Size>(std::move(std::valarray<T>::operator<(rhs))); }

	template <class T, unsigned int Size>
	Vector<bool, Size> Vector<T, Size>::operator<=(const T & rhs)
		{ return Vector<bool, Size>(std::move(std::valarray<T>::operator<=(rhs))); }

	template <class T, unsigned int Size>
	Vector<bool, Size> Vector<T, Size>::operator>(const T & rhs)
		{ return Vector<bool, Size>(std::move(std::valarray<T>::operator>(rhs))); }

	template <class T, unsigned int Size>
	Vector<bool, Size> Vector<T, Size>::operator>=(const T & rhs)
		{ return Vector<bool, Size>(std::move(std::valarray<T>::operator>=(rhs))); }

	template <class T, unsigned int Size>
	inline Vector<T, Size> Vector<T, Size>::abs() const { return Vector<T, Size>(std::move(std::abs(*this))); }

	template <class T, unsigned int Size>
	inline Vector<T, Size> Vector<T, Size>::exp() const { return Vector<T, Size>(std::move(std::exp(*this))); }

	template <class T, unsigned int Size>
	inline Vector<T, Size> Vector<T, Size>::log() const { return Vector<T, Size>(std::move(std::log(*this))); }

	template <class T, unsigned int Size>
	inline Vector<T, Size> Vector<T, Size>::log10() const { return Vector<T, Size>(std::move(std::log10(*this))); }

	template <class T, unsigned int Size>
	inline Vector<T, Size> Vector<T, Size>::pow(const Vector<T, Size> & exp) const { return Vector<T, Size>(std::move(std::pow(*this, exp))); }

	template <class T, unsigned int Size>
	inline Vector<T, Size> Vector<T, Size>::pow(const T & exp) const { return Vector<T, Size>(std::move(std::pow(*this, exp))); }

	template <class T, unsigned int Size>
	inline Vector<T, Size> Vector<T, Size>::sqrt() const { return Vector<T, Size>(std::move(std::sqrt(*this))); }

	template <class T, unsigned int Size>
	inline Vector<T, Size> Vector<T, Size>::sin() const { return Vector<T, Size>(std::move(std::sin(*this))); }

	template <class T, unsigned int Size>
	inline Vector<T, Size> Vector<T, Size>::cos() const { return Vector<T, Size>(std::move(std::cos(*this))); }

	template <class T, unsigned int Size>
	inline Vector<T, Size> Vector<T, Size>::tan() const { return Vector<T, Size>(std::move(std::tan(*this))); }

	template <class T, unsigned int Size>
	inline Vector<T, Size> Vector<T, Size>::asin() const { return Vector<T, Size>(std::move(std::asin(*this))); }

	template <class T, unsigned int Size>
	inline Vector<T, Size> Vector<T, Size>::acos() const { return Vector<T, Size>(std::move(std::acos(*this))); }

	template <class T, unsigned int Size>
	inline Vector<T, Size> Vector<T, Size>::atan() const { return Vector<T, Size>(std::move(std::atan(*this))); }

	template <class T, unsigned int Size>
	inline Vector<T, Size> Vector<T, Size>::atan2(const Vector<T, Size> & x) const { return Vector<T, Size>(std::move(std::atan2(*this, x))); }

	template <class T, unsigned int Size>
	inline Vector<T, Size> Vector<T, Size>::atan2(const T & x) const { return Vector<T, Size>(std::move(std::atan2(*this, x))); }

	template <class T, unsigned int Size>
	inline Vector<T, Size> Vector<T, Size>::sinh() const { return Vector<T, Size>(std::move(std::sinh(*this))); }

	template <class T, unsigned int Size>
	inline Vector<T, Size> Vector<T, Size>::cosh() const { return Vector<T, Size>(std::move(std::cosh(*this))); }

	template <class T, unsigned int Size>
	inline Vector<T, Size> Vector<T, Size>::tanh() const { return Vector<T, Size>(std::move(std::tanh(*this))); }

	template <class T, unsigned int Size>
	inline void Vector<T, Size>::normalize() { this->operator/=(this->magnitude()); }

	template <class T, unsigned int Size>
	inline T Vector<T, Size>::magnitude() const { return std::sqrt(this->dot(*this)); }

	template <class T, unsigned int Size>
	inline Vector<T, Size> Vector<T, Size>::cross(const Vector<T, Size> & rightOperand) const 
	{
		static_assert(Size == 3 || Size == 4 || Size == 7, "This method does not exist in that dimension.");
		return Vector<T, Size>();
	}

	template <class T, unsigned int Size>
	inline T Vector<T, Size>::dot(const Vector<T, Size> & rightOperand) const { return this->operator*(rightOperand).sum(); }

	template <class T, unsigned int Size>
	inline T Vector<T, Size>::distanceFrom(const Vector<T, Size> & rightOperand) const { return this->operator-(rightOperand).magnitude(); }

	template <class T, unsigned int Size>
	inline Vector<T, Size>::Vector(std::valarray<T> && move): std::valarray<T>(move) {}
}