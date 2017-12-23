namespace ece
{
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
	inline const T & Vector<T, Size>::operator[](const unsigned int index) const { return (*this)[index]; }

	template <class T, unsigned int Size>
	inline T & Vector<T, Size>::operator[](const unsigned index) { return (*this)[index]; }

	template <class T, unsigned int Size>
	inline Vector<T, Size> Vector<T, Size>::operator[](std::slice_array<T> slicearr) const
		{ return static_cast<Vector<T, Size>(std::valarray<T>::operator[](slicearr)); }

	template <class T, unsigned int Size>
	inline std::slice_array<T> Vector<T, Size>::operator[](std::slice_array<T> slicearr)
		{ return std::valarray<T>::operator[](slicearr); }

	template <class T, unsigned int Size>
	inline Vector<T, Size> Vector<T, Size>::operator[](std::gslice_array<T> & gslicearr) const
		{ return static_cast<Vector<T, Size>(std::valarray<T>::operator[](gslicearr)); }

	template <class T, unsigned int Size>
	inline std::gslice_array<T> Vector<T, Size>::operator[](std::gslice_array<T> & gslicearr)
		{ return std::valarray<T>::operator[](gslicearr); }

	template <class T, unsigned int Size>
	inline Vector<T, Size> Vector<T, Size>::operator[](const std::Vector<bool, Size> & maskarr) const
		{ return static_cast<Vector<T, Size>(std::valarray<T>::operator[](maskarr)); }

	template <class T, unsigned int Size>
	inline std::mask_array<T> Vector<T, Size>::operator[](const std::Vector<bool, Size> & maskarr)
		{ return std::valarray<T>::operator[](maskarr); }

	template <class T, unsigned int Size>
	inline Vector<T, Size> Vector<T, Size>::operator[](const std::Vector<bool, Size> & indarr) const
		{ return static_cast<Vector<T, Size>(std::valarray<T>::operator[](indarr)); }

	template <class T, unsigned int Size>
	inline std::indirect_array<T> Vector<T, Size>::operator[](const std::Vector<bool, Size> & indarr)
		{ return std::valarray<T>::operator[](indarr); }

	template <class T, unsigned int Size>
	inline Vector<T, Size> Vector<T, Size>::operator+() const noexcept
		{ return static_cast<Vector<T, Size>(std::valarray<T>::operator+()); }

	template <class T, unsigned int Size>
	inline Vector<T, Size> Vector<T, Size>::operator-() const noexcept
		{ return static_cast<Vector<T, Size>(std::valarray<T>::operator-()); }

	template <class T, unsigned int Size>
	inline Vector<T, Size> Vector<T, Size>::operator~() const noexcept
		{ return static_cast<Vector<T, Size>(std::valarray<T>::operator~()); }

	template <class T, unsigned int Size>
	inline Vector<bool, Size> Vector<T, Size>::operator!() const noexcept
		{ return static_cast<Vector<T, Size>(std::valarray<T>::operator!()); }

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
	inline Vector<T, Size> Vector<T, Size>::shift(int count) const { return static_cast<Vector<T, Size>(std::valarray<T>::shift(count)); }

	template <class T, unsigned int Size>
	inline Vector<T, Size> Vector<T, Size>::cshift(int count) const { return static_cast<Vector<T, Size>(std::valarray<T>::cshift(count)); }

	template <class T, unsigned int Size>
	inline Vector<T, Size> Vector<T, Size>::apply(T func(T)) const { return static_cast<Vector<T, Size>(std::valarray<T>::apply(func)); }

	template <class T, unsigned int Size>
	inline Vector<T, Size> Vector<T, Size>::apply(T func(const T&)) const { return static_cast<Vector<T, Size>(std::valarray<T>::apply(func)); }

	template <class T, unsigned int Size>
	inline Vector<T, Size> Vector<T, Size>::operator+(const Vector<T, Size> & rhs) const
		{ return static_cast<Vector<T, Size>(std::valarray<T>::operator+(rhs)); }

	template <class T, unsigned int Size>
	inline Vector<T, Size> Vector<T, Size>::operator-(const Vector<T, Size> & rhs) const
		{ return static_cast<Vector<T, Size>(std::valarray<T>::operator-(rhs)); }

	template <class T, unsigned int Size>
	inline Vector<T, Size> Vector<T, Size>::operator*(const Vector<T, Size> & rhs) const
		{ return static_cast<Vector<T, Size>(std::valarray<T>::operator*(rhs)); }

	template <class T, unsigned int Size>
	inline Vector<T, Size> Vector<T, Size>::operator/(const Vector<T, Size> & rhs) const
		{ return static_cast<Vector<T, Size>(std::valarray<T>::operator/(rhs)); }

	template <class T, unsigned int Size>
	inline Vector<T, Size> Vector<T, Size>::operator%(const Vector<T, Size> & rhs) const
		{ return static_cast<Vector<T, Size>(std::valarray<T>::operator%(rhs)); }

	template <class T, unsigned int Size>
	inline Vector<T, Size> Vector<T, Size>::operator&(const Vector<T, Size> & rhs) const
		{ return static_cast<Vector<T, Size>(std::valarray<T>::operator&(rhs)); }

	template <class T, unsigned int Size>
	inline Vector<T, Size> Vector<T, Size>::operator|(const Vector<T, Size> & rhs) const
		{ return static_cast<Vector<T, Size>(std::valarray<T>::operator|(rhs)); }

	template <class T, unsigned int Size>
	inline Vector<T, Size> Vector<T, Size>::operator^(const Vector<T, Size> & rhs) const
		{ return static_cast<Vector<T, Size>(std::valarray<T>::operator^(rhs)); }

	template <class T, unsigned int Size>
	inline Vector<T, Size> Vector<T, Size>::operator<<(const Vector<T, Size> & rhs) const
		{ return static_cast<Vector<T, Size>(std::valarray<T>::operator<<(rhs)); }

	template <class T, unsigned int Size>
	inline Vector<T, Size> Vector<T, Size>::operator>>(const Vector<T, Size> & rhs) const
		{ return static_cast<Vector<T, Size>(std::valarray<T>::operator>>(rhs)); }

	template <class T, unsigned int Size>
	inline Vector<T, Size> Vector<T, Size>::operator&&(const Vector<T, Size> & rhs) const
		{ return static_cast<Vector<T, Size>(std::valarray<T>::operator&&(rhs)); }

	template <class T, unsigned int Size>
	inline Vector<T, Size> Vector<T, Size>::operator||(const Vector<T, Size> & rhs) const
		{ return static_cast<Vector<T, Size>(std::valarray<T>::operator||(rhs)); }

	template <class T, unsigned int Size>
	inline Vector<T, Size> Vector<T, Size>::operator+(const T & rhs) const
		{ return static_cast<Vector<T, Size>(std::valarray<T>::operator+(rhs)); }

	template <class T, unsigned int Size>
	inline Vector<T, Size> Vector<T, Size>::operator-(const T & rhs) const
		{ return static_cast<Vector<T, Size>(std::valarray<T>::operator-(rhs)); }

	template <class T, unsigned int Size>
	inline Vector<T, Size> Vector<T, Size>::operator*(const T & rhs) const
		{ return static_cast<Vector<T, Size>(std::valarray<T>::operator*(rhs)); }

	template <class T, unsigned int Size>
	inline Vector<T, Size> Vector<T, Size>::operator/(const T & rhs) const
		{ return static_cast<Vector<T, Size>(std::valarray<T>::operator/(rhs)); }

	template <class T, unsigned int Size>
	inline Vector<T, Size> Vector<T, Size>::operator%(const T & rhs) const
		{ return static_cast<Vector<T, Size>(std::valarray<T>::operator%(rhs)); }

	template <class T, unsigned int Size>
	inline Vector<T, Size> Vector<T, Size>::operator&(const T & rhs) const
		{ return static_cast<Vector<T, Size>(std::valarray<T>::operator&(rhs)); }

	template <class T, unsigned int Size>
	inline Vector<T, Size> Vector<T, Size>::operator|(const T & rhs) const
		{ return static_cast<Vector<T, Size>(std::valarray<T>::operator|(rhs)); }

	template <class T, unsigned int Size>
	inline Vector<T, Size> Vector<T, Size>::operator^(const T & rhs) const
		{ return static_cast<Vector<T, Size>(std::valarray<T>::operator^(rhs)); }

	template <class T, unsigned int Size>
	inline Vector<T, Size> Vector<T, Size>::operator<<(const T & rhs) const
		{ return static_cast<Vector<T, Size>(std::valarray<T>::operator<<(rhs)); }

	template <class T, unsigned int Size>
	inline Vector<T, Size> Vector<T, Size>::operator>>(const T & rhs) const
		{ return static_cast<Vector<T, Size>(std::valarray<T>::operator>>(rhs)); }

	template <class T, unsigned int Size>
	inline Vector<T, Size> Vector<T, Size>::operator&&(const T & rhs) const
		{ return static_cast<Vector<T, Size>(std::valarray<T>::operator&&(rhs)); }

	template <class T, unsigned int Size>
	inline Vector<T, Size> Vector<T, Size>::operator||(const T & rhs) const
		{ return static_cast<Vector<T, Size>(std::valarray<T>::operator||(rhs)); }

	template <class T, unsigned int Size>
	Vector<bool, Size> Vector<T, Size>::operator==(const Vector<T, Size> & rhs)
		{ return static_cast<Vector<bool, Size>(std::valarray<T>::operator==(rhs)); }

	template <class T, unsigned int Size>
	Vector<bool, Size> Vector<T, Size>::operator!=(const Vector<T, Size> & rhs)
		{ return static_cast<Vector<bool, Size>(std::valarray<T>::operator!=(rhs)); }

	template <class T, unsigned int Size>
	Vector<bool, Size> Vector<T, Size>::operator<(const Vector<T, Size> & rhs)
		{ return static_cast<Vector<bool, Size>(std::valarray<T>::operator<(rhs)); }

	template <class T, unsigned int Size>
	Vector<bool, Size> Vector<T, Size>::operator<=(const Vector<T, Size> & rhs)
		{ return static_cast<Vector<bool, Size>(std::valarray<T>::operator<=(rhs)); }

	template <class T, unsigned int Size>
	Vector<bool, Size> Vector<T, Size>::operator>(const Vector<T, Size> & rhs)
		{ return static_cast<Vector<bool, Size>(std::valarray<T>::operator>(rhs)); }

	template <class T, unsigned int Size>
	Vector<bool, Size> Vector<T, Size>::operator>=(const Vector<T, Size> & rhs)
		{ return static_cast<Vector<bool, Size>(std::valarray<T>::operator>=(rhs)); }

	template <class T, unsigned int Size>
	Vector<bool, Size> Vector<T, Size>::operator==(const T & rhs)
		{ return static_cast<Vector<bool, Size>(std::valarray<T>::operator==(rhs)); }

	template <class T, unsigned int Size>
	Vector<bool, Size> Vector<T, Size>::operator!=(const T & rhs)
		{ return static_cast<Vector<bool, Size>(std::valarray<T>::operator!=(rhs)); }

	template <class T, unsigned int Size>
	Vector<bool, Size> Vector<T, Size>::operator<(const T & rhs)
		{ return static_cast<Vector<bool, Size>(std::valarray<T>::operator<(rhs)); }

	template <class T, unsigned int Size>
	Vector<bool, Size> Vector<T, Size>::operator<=(const T & rhs)
		{ return static_cast<Vector<bool, Size>(std::valarray<T>::operator<=(rhs)); }

	template <class T, unsigned int Size>
	Vector<bool, Size> Vector<T, Size>::operator>(const T & rhs)
		{ return static_cast<Vector<bool, Size>(std::valarray<T>::operator>(rhs)); }

	template <class T, unsigned int Size>
	Vector<bool, Size> Vector<T, Size>::operator>=(const T & rhs)
		{ return static_cast<Vector<bool, Size>(std::valarray<T>::operator>=(rhs)); }

	template <class T, unsigned int Size>
	inline Vector<T, Size> Vector<T, Size>::abs() const { return static_cast<Vector<T, Size>(std::abs(*this)); }

	template <class T, unsigned int Size>
	inline Vector<T, Size> Vector<T, Size>::exp() const { return static_cast<Vector<T, Size>(std::exp(*this)); }

	template <class T, unsigned int Size>
	inline Vector<T, Size> Vector<T, Size>::log() const { return static_cast<Vector<T, Size>(std::log(*this)); }

	template <class T, unsigned int Size>
	inline Vector<T, Size> Vector<T, Size>::log10() const { return static_cast<Vector<T, Size>(std::log10(*this)); }

	template <class T, unsigned int Size>
	inline Vector<T, Size> Vector<T, Size>::pow(const Vector<T, Size> & exp) const { return static_cast<Vector<T, Size>(std::pow(*this, exp)); }

	template <class T, unsigned int Size>
	inline Vector<T, Size> Vector<T, Size>::pow(const T & exp) const { return static_cast<Vector<T, Size>(std::pow(*this, exp)); }

	template <class T, unsigned int Size>
	inline Vector<T, Size> Vector<T, Size>::sqrt() const { return static_cast<Vector<T, Size>(std::sqrt(*this)); }

	template <class T, unsigned int Size>
	inline Vector<T, Size> Vector<T, Size>::sin() const { return static_cast<Vector<T, Size>(std::sin(*this)); }

	template <class T, unsigned int Size>
	inline Vector<T, Size> Vector<T, Size>::cos() const { return static_cast<Vector<T, Size>(std::cos(*this)); }

	template <class T, unsigned int Size>
	inline Vector<T, Size> Vector<T, Size>::tan() const { return static_cast<Vector<T, Size>(std::tan(*this)); }

	template <class T, unsigned int Size>
	inline Vector<T, Size> Vector<T, Size>::asin() const { return static_cast<Vector<T, Size>(std::asin(*this)); }

	template <class T, unsigned int Size>
	inline Vector<T, Size> Vector<T, Size>::acos() const { return static_cast<Vector<T, Size>(std::acos(*this)); }

	template <class T, unsigned int Size>
	inline Vector<T, Size> Vector<T, Size>::atan() const { return static_cast<Vector<T, Size>(std::atan(*this)); }

	template <class T, unsigned int Size>
	inline Vector<T, Size> Vector<T, Size>::atan2(const Vector<T, Size> & x) const { return static_cast<Vector<T, Size>(std::atan2(*this, x)); }

	template <class T, unsigned int Size>
	inline Vector<T, Size> Vector<T, Size>::atan2(const T & x) const { return static_cast<Vector<T, Size>(std::atan2(*this, x)); }

	template <class T, unsigned int Size>
	inline Vector<T, Size> Vector<T, Size>::sinh() const { return static_cast<Vector<T, Size>(std::sinh(*this)); }

	template <class T, unsigned int Size>
	inline Vector<T, Size> Vector<T, Size>::cosh() const { return static_cast<Vector<T, Size>(std::cosh(*this)); }

	template <class T, unsigned int Size>
	inline Vector<T, Size> Vector<T, Size>::tanh() const { return static_cast<Vector<T, Size>(std::tanh(*this)); }
}