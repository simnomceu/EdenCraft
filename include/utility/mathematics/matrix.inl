namespace ece
{
	template <class T, unsigned int M, unsigned int N>
	inline Matrix<T, M, N> Matrix<T, M, N>::Identity()
	{
		Matrix<T, M, N> tmp();
		tmp[std::slice(0, M, M + 1)] = 1;
		return  tmp;
	}

	template <class T, unsigned int M, unsigned int N>
	inline Matrix<T, M, N>::Matrix(const std::initializer_list<T> & il): std::valarray<T>(il) {}

	template <class T, unsigned int M, unsigned int N>
	inline Matrix<T, M, N>::Matrix(std::valarray<T> && move): std::valarray<T>(move) {}

	template <class T, unsigned int M, unsigned int N>
	inline Matrix<T, M, N> & Matrix<T, M, N>::operator=(const std::initializer_list<T> & il) { std::valarray<T>::operator=(il); }

	template <class T, unsigned int M, unsigned int N>
	inline const Vector<T, M> & Matrix<T, M, N>::operator[](const unsigned int index) const
		{ return Vector<T, M>(std::move(std::valarray<T>::operator[](std::slice(index, M, 1)))); }

	template <class T, unsigned int M, unsigned int N>
	inline Vector<T, M> & Matrix<T, M, N>::operator[](const unsigned int index)
		{ return Vector<T, M>(std::move(std::valarray<T>::operator[](std::slice(index, M, 1)))); }

	template <class T, unsigned int M, unsigned int N>
	inline const Vector<T, M> & Matrix<T, M, N>::row(const unsigned int index) const
		{ return Vector<T, M>(std::move(std::valarray<T>::operator[](std::slice(index, M, 1)))); }

	template <class T, unsigned int M, unsigned int N>
	inline Vector<T, M> & Matrix<T, M, N>::row(const unsigned int index)
		{ return Vector<T, M>(std::move(std::valarray<T>::operator[](std::slice(index, M, 1)))); }

	template <class T, unsigned int M, unsigned int N>
	inline const Vector<T, M> & Matrix<T, M, N>::column(const unsigned int index) const
		{ return Vector<T, M>(std::move(std::valarray<T>::operator[](std::slice(index, N, M)))); }

	template <class T, unsigned int M, unsigned int N>
	inline Vector<T, M> & Matrix<T, M, N>::column(const unsigned int index)
		{ return Vector<T, M>(std::move(std::valarray<T>::operator[](std::slice(index, N, M)))); }

	template <class T, unsigned int M, unsigned int N>
	inline Matrix<T, M, N> Matrix<T, M, N>::operator+() const noexcept { return Matrix<T, M, N>(std::move(std::valarray<T>::operator+())); }

	template <class T, unsigned int M, unsigned int N>
	inline Matrix<T, M, N> Matrix<T, M, N>::operator-() const noexcept { return Matrix<T, M, N>(std::move(std::valarray<T>::operator-())); }

	template <class T, unsigned int M, unsigned int N>
	inline Matrix<T, M, N> Matrix<T, M, N>::operator~() const noexcept { return Matrix<T, M, N>(std::move(std::valarray<T>::operator~())); }

	template <class T, unsigned int M, unsigned int N>
	inline Matrix<bool, M, N> Matrix<T, M, N>::operator!() const noexcept { return Matrix<T, M, N>(std::move(std::valarray<T>::operator!())); }

	template <class T, unsigned int M, unsigned int N>
	inline Matrix<T, M, N> & Matrix<T, M, N>::operator+=(const Matrix<T, M, N> & v)
	{
		std::valarray<T>::operator+=(v);
		return *this;
	}

	template <class T, unsigned int M, unsigned int N>
	inline Matrix<T, M, N> & Matrix<T, M, N>::operator-=(const Matrix<T, M, N> & v)
	{
		std::valarray<T>::operator-=(v);
		return *this;
	}

	template <class T, unsigned int M, unsigned int N>
	inline Matrix<T, M, N> & Matrix<T, M, N>::operator*=(const Matrix<T, M, N> & v)
	{
		std::valarray<T>::operator*=(v);
		return *this;
	}

	template <class T, unsigned int M, unsigned int N>
	inline Matrix<T, M, N> & Matrix<T, M, N>::operator/=(const Matrix<T, M, N> & v)
	{
		std::valarray<T>::operator/=(v);
		return *this;
	}

	template <class T, unsigned int M, unsigned int N>
	inline Matrix<T, M, N> & Matrix<T, M, N>::operator%=(const Matrix<T, M, N> & v)
	{
		std::valarray<T>::operator%=(v);
		return *this;
	}

	template <class T, unsigned int M, unsigned int N>
	inline Matrix<T, M, N> & Matrix<T, M, N>::operator&=(const Matrix<T, M, N> & v)
	{
		std::valarray<T>::operator&=(v);
		return *this;
	}

	template <class T, unsigned int M, unsigned int N>
	inline Matrix<T, M, N> & Matrix<T, M, N>::operator|=(const Matrix<T, M, N> & v)
	{
		std::valarray<T>::operator|=(v);
		return *this;
	}

	template <class T, unsigned int M, unsigned int N>
	inline Matrix<T, M, N> & Matrix<T, M, N>::operator^=(const Matrix<T, M, N> & v)
	{
		std::valarray<T>::operator^=(v);
		return *this;
	}

	template <class T, unsigned int M, unsigned int N>
	inline Matrix<T, M, N> & Matrix<T, M, N>::operator<<=(const Matrix<T, M, N> & v)
	{
		std::valarray<T>::operator<<=(v);
		return *this;
	}

	template <class T, unsigned int M, unsigned int N>
	inline Matrix<T, M, N> & Matrix<T, M, N>::operator>>=(const Matrix<T, M, N> & v)
	{
		std::valarray<T>::operator>>=(v);
		return *this;
	}

	template <class T, unsigned int M, unsigned int N>
	inline Matrix<T, M, N> & Matrix<T, M, N>::operator+=(const T & val)
	{
		std::valarray<T>::operator+=(v);
		return *this;
	}

	template <class T, unsigned int M, unsigned int N>
	inline Matrix<T, M, N> & Matrix<T, M, N>::operator-=(const T & val)
	{
		std::valarray<T>::operator-=(v);
		return *this;
	}

	template <class T, unsigned int M, unsigned int N>
	inline Matrix<T, M, N> & Matrix<T, M, N>::operator*=(const T & val)
	{
		std::valarray<T>::operator*=(v);
		return *this;
	}

	template <class T, unsigned int M, unsigned int N>
	inline Matrix<T, M, N> & Matrix<T, M, N>::operator/=(const T & val)
	{
		std::valarray<T>::operator/=(v);
		return *this;
	}

	template <class T, unsigned int M, unsigned int N>
	inline Matrix<T, M, N> & Matrix<T, M, N>::operator%=(const T & val)
	{
		std::valarray<T>::operator%=(v);
		return *this;
	}

	template <class T, unsigned int M, unsigned int N>
	inline Matrix<T, M, N> & Matrix<T, M, N>::operator&=(const T & val)
	{
		std::valarray<T>::operator&=(v);
		return *this;
	}

	template <class T, unsigned int M, unsigned int N>
	inline Matrix<T, M, N> & Matrix<T, M, N>::operator|=(const T & val)
	{
		std::valarray<T>::operator|=(v);
		return *this;
	}

	template <class T, unsigned int M, unsigned int N>
	inline Matrix<T, M, N> & Matrix<T, M, N>::operator^=(const T & val)
	{
		std::valarray<T>::operator^=(v);
		return *this;
	}

	template <class T, unsigned int M, unsigned int N>
	inline Matrix<T, M, N> & Matrix<T, M, N>::operator<<=(const T & val)
	{
		std::valarray<T>::operator<<=(v);
		return *this;
	}

	template <class T, unsigned int M, unsigned int N>
	inline Matrix<T, M, N> & Matrix<T, M, N>::operator>>=(const T & val)
	{
		std::valarray<T>::operator>>=(v);
		return *this;
	}

	template <class T, unsigned int M, unsigned int N>
	inline Matrix<T, M, N> Matrix<T, M, N>::apply(T func(T)) const { return Matrix<T, M, N>(std::move(std::valarray<T>::apply(func))); }

	template <class T, unsigned int M, unsigned int N>
	inline Matrix<T, M, N> Matrix<T, M, N>::apply(T func(const T&)) const { return Matrix<T, M, N>(std::move(std::valarray<T>::apply(func))); }

	template <class T, unsigned int M, unsigned int N>
	inline Matrix<T, M, N> Matrix<T, M, N>::operator+(const Matrix<T, M, N> & rhs) const
		{ return Matrix<T, M, N>(std::move(std::valarray<T>::operator+(*this, rhs))); }

	template <class T, unsigned int M, unsigned int N>
	inline Matrix<T, M, N> Matrix<T, M, N>::operator-(const Matrix<T, M, N> & rhs) const
		{ return Matrix<T, M, N>(std::move(std::valarray<T>::operator-(*this, rhs))); }

	template <class T, unsigned int M, unsigned int N>
	inline Matrix<T, M, N> Matrix<T, M, N>::operator*(const Matrix<T, M, N> & rhs) const
		{ return Matrix<T, M, N>(std::move(std::valarray<T>::operator*(*this, rhs))); }

	template <class T, unsigned int M, unsigned int N>
	inline Matrix<T, M, N> Matrix<T, M, N>::operator/(const Matrix<T, M, N> & rhs) const
		{ return Matrix<T, M, N>(std::move(std::valarray<T>::operator/(*this, rhs))); }

	template <class T, unsigned int M, unsigned int N>
	inline Matrix<T, M, N> Matrix<T, M, N>::operator%(const Matrix<T, M, N> & rhs) const
		{ return Matrix<T, M, N>(std::move(std::valarray<T>::operator%(*this, rhs))); }

	template <class T, unsigned int M, unsigned int N>
	inline Matrix<T, M, N> Matrix<T, M, N>::operator&(const Matrix<T, M, N> & rhs) const
		{ return Matrix<T, M, N>(std::move(std::valarray<T>::operator&(*this, rhs))); }

	template <class T, unsigned int M, unsigned int N>
	inline Matrix<T, M, N> Matrix<T, M, N>::operator|(const Matrix<T, M, N> & rhs) const
		{ return Matrix<T, M, N>(std::move(std::valarray<T>::operator|(*this, rhs))); }

	template <class T, unsigned int M, unsigned int N>
	inline Matrix<T, M, N> Matrix<T, M, N>::operator^(const Matrix<T, M, N> & rhs) const
		{ return Matrix<T, M, N>(std::move(std::valarray<T>::operator^(*this, rhs))); }

	template <class T, unsigned int M, unsigned int N>
	inline Matrix<T, M, N> Matrix<T, M, N>::operator<<(const Matrix<T, M, N> & rhs) const
		{ return Matrix<T, M, N>(std::move(std::valarray<T>::operator<<(*this, rhs))); }

	template <class T, unsigned int M, unsigned int N>
	inline Matrix<T, M, N> Matrix<T, M, N>::operator>>(const Matrix<T, M, N> & rhs) const
		{ return Matrix<T, M, N>(std::move(std::valarray<T>::operator>>(*this, rhs))); }

	template <class T, unsigned int M, unsigned int N>
	inline Matrix<T, M, N> Matrix<T, M, N>::operator&&(const Matrix<T, M, N> & rhs) const
		{ return Matrix<T, M, N>(std::move(std::valarray<T>::operator&&(*this, rhs))); }

	template <class T, unsigned int M, unsigned int N>
	inline Matrix<T, M, N> Matrix<T, M, N>::operator||(const Matrix<T, M, N> & rhs) const
		{ return Matrix<T, M, N>(std::move(std::valarray<T>::operator||(*this, rhs))); }

	template <class T, unsigned int M, unsigned int N>
	inline Matrix<T, M, N> Matrix<T, M, N>::operator+(const T & rhs) const
		{ return Matrix<T, M, N>(std::move(std::operator+(*this, rhs))); }

	template <class T, unsigned int M, unsigned int N>
	inline Matrix<T, M, N> Matrix<T, M, N>::operator-(const T & rhs) const
		{ return Matrix<T, M, N>(std::move(std::operator-(*this, rhs))); }

	template <class T, unsigned int M, unsigned int N>
	inline Matrix<T, M, N> Matrix<T, M, N>::operator*(const T & rhs) const
		{ return Matrix<T, M, N>(std::move(std::operator*(*this, rhs))); }

	template <class T, unsigned int M, unsigned int N>
	inline Matrix<T, M, N> Matrix<T, M, N>::operator/(const T & rhs) const
		{ return Matrix<T, M, N>(std::move(std::operator/(*this, rhs))); }

	template <class T, unsigned int M, unsigned int N>
	inline Matrix<T, M, N> Matrix<T, M, N>::operator%(const T & rhs) const
		{ return Matrix<T, M, N>(std::move(std::operator%(*this, rhs))); }

	template <class T, unsigned int M, unsigned int N>
	inline Matrix<T, M, N> Matrix<T, M, N>::operator&(const T & rhs) const
		{ return Matrix<T, M, N>(std::move(std::operator&(*this, rhs))); }

	template <class T, unsigned int M, unsigned int N>
	inline Matrix<T, M, N> Matrix<T, M, N>::operator|(const T & rhs) const
		{ return Matrix<T, M, N>(std::move(std::operator|(*this, rhs))); }

	template <class T, unsigned int M, unsigned int N>
	inline Matrix<T, M, N> Matrix<T, M, N>::operator^(const T & rhs) const
		{ return Matrix<T, M, N>(std::move(std::operator^(*this, rhs))); }

	template <class T, unsigned int M, unsigned int N>
	inline Matrix<T, M, N> Matrix<T, M, N>::operator<<(const T & rhs) const
		{ return Matrix<T, M, N>(std::move(std::operator<<(*this, rhs))); }

	template <class T, unsigned int M, unsigned int N>
	inline Matrix<T, M, N> Matrix<T, M, N>::operator>>(const T & rhs) const
		{ return Matrix<T, M, N>(std::move(std::operator>>(*this, rhs))); }

	template <class T, unsigned int M, unsigned int N>
	inline Matrix<T, M, N> Matrix<T, M, N>::operator&&(const T & rhs) const
		{ return Matrix<T, M, N>(std::move(std::operator&&(*this, rhs))); }

	template <class T, unsigned int M, unsigned int N>
	inline Matrix<T, M, N> Matrix<T, M, N>::operator||(const T & rhs) const
		{ return Matrix<T, M, N>(std::move(std::operator||(*this, rhs))); }

	template <class T, unsigned int M, unsigned int N>
	bool Matrix<T, M, N>::operator==(const Matrix<T, M, N> & rhs) const { return std::operator==(*this, rhs).min(); }

	template <class T, unsigned int M, unsigned int N>
	Matrix<bool, M, N> Matrix<T, M, N>::operator!=(const Matrix<T, M, N> & rhs)
		{ return Matrix<T, M, N>(std::move(std::valarray<T>::operator!=(rhs))); }

	template <class T, unsigned int M, unsigned int N>
	Matrix<bool, M, N> Matrix<T, M, N>::operator<(const Matrix<T, M, N> & rhs)
		{ return Matrix<T, M, N>(std::move(std::valarray<T>::operator<(rhs))); }

	template <class T, unsigned int M, unsigned int N>
	Matrix<bool, M, N> Matrix<T, M, N>::operator<=(const Matrix<T, M, N> & rhs)
		{ return Matrix<T, M, N>(std::move(std::valarray<T>::operator<=(rhs))); }

	template <class T, unsigned int M, unsigned int N>
	Matrix<bool, M, N> Matrix<T, M, N>::operator>(const Matrix<T, M, N> & rhs)
		{ return Matrix<T, M, N>(std::move(std::valarray<T>::operator>(rhs))); }

	template <class T, unsigned int M, unsigned int N>
	Matrix<bool, M, N> Matrix<T, M, N>::operator>=(const Matrix<T, M, N> & rhs)
		{ return Matrix<T, M, N>(std::move(std::valarray<T>::operator>=(rhs))); }

	template <class T, unsigned int M, unsigned int N>
	Matrix<bool, M, N> Matrix<T, M, N>::operator==(const T & rhs)
		{ return Matrix<T, M, N>(std::move(std::valarray<T>::operator==(rhs))); }

	template <class T, unsigned int M, unsigned int N>
	Matrix<bool, M, N> Matrix<T, M, N>::operator!=(const T & rhs)
		{ return Matrix<T, M, N>(std::move(std::valarray<T>::operator!=(rhs))); }

	template <class T, unsigned int M, unsigned int N>
	Matrix<bool, M, N> Matrix<T, M, N>::operator<(const T & rhs)
		{ return Matrix<T, M, N>(std::move(std::valarray<T>::operator<(rhs))); }

	template <class T, unsigned int M, unsigned int N>
	Matrix<bool, M, N> Matrix<T, M, N>::operator<=(const T & rhs)
		{ return Matrix<T, M, N>(std::move(std::valarray<T>::operator<=(rhs))); }

	template <class T, unsigned int M, unsigned int N>
	Matrix<bool, M, N> Matrix<T, M, N>::operator>(const T & rhs)
		{ return Matrix<T, M, N>(std::move(std::valarray<T>::operator>(rhs))); }

	template <class T, unsigned int M, unsigned int N>
	Matrix<bool, M, N> Matrix<T, M, N>::operator>=(const T & rhs)
		{ return Matrix<T, M, N>(std::move(std::valarray<T>::operator>=(rhs))); }

	template <class T, unsigned int M, unsigned int N>
	inline Matrix<T, M, N> Matrix<T, M, N>::abs() const
		{ return Matrix<T, M, N>(std::move(std::valarray<T>::abs(*this))); }

	template <class T, unsigned int M, unsigned int N>
	inline Matrix<T, M, N> Matrix<T, M, N>::exp() const
		{ return Matrix<T, M, N>(std::move(std::valarray<T>::exp(*this))); }

	template <class T, unsigned int M, unsigned int N>
	inline Matrix<T, M, N> Matrix<T, M, N>::log() const
		{ return Matrix<T, M, N>(std::move(std::valarray<T>::log(*this))); }

	template <class T, unsigned int M, unsigned int N>
	inline Matrix<T, M, N> Matrix<T, M, N>::log10() const
		{ return Matrix<T, M, N>(std::move(std::valarray<T>::log10(*this))); }

	template <class T, unsigned int M, unsigned int N>
	inline Matrix<T, M, N> Matrix<T, M, N>::pow(const Matrix<T, M, N> & exp) const
		{ return Matrix<T, M, N>(std::move(std::valarray<T>::pow(*this, exp))); }

	template <class T, unsigned int M, unsigned int N>
	inline Matrix<T, M, N> Matrix<T, M, N>::pow(const T & exp) const
		{ return Matrix<T, M, N>(std::move(std::valarray<T>::pow(*this, exp))); }

	template <class T, unsigned int M, unsigned int N>
	inline Matrix<T, M, N> Matrix<T, M, N>::sqrt() const
		{ return Matrix<T, M, N>(std::move(std::valarray<T>::sqrt(*this))); }

	template <class T, unsigned int M, unsigned int N>
	inline Matrix<T, M, N> Matrix<T, M, N>::sin() const
		{ return Matrix<T, M, N>(std::move(std::valarray<T>::sin(*this))); }

	template <class T, unsigned int M, unsigned int N>
	inline Matrix<T, M, N> Matrix<T, M, N>::cos() const
		{ return Matrix<T, M, N>(std::move(std::valarray<T>::cos(*this))); }

	template <class T, unsigned int M, unsigned int N>
	inline Matrix<T, M, N> Matrix<T, M, N>::tan() const
		{ return Matrix<T, M, N>(std::move(std::valarray<T>::tan(*this))); }

	template <class T, unsigned int M, unsigned int N>
	inline Matrix<T, M, N> Matrix<T, M, N>::asin() const
		{ return Matrix<T, M, N>(std::move(std::valarray<T>::asin(*this))); }

	template <class T, unsigned int M, unsigned int N>
	inline Matrix<T, M, N> Matrix<T, M, N>::acos() const
		{ return Matrix<T, M, N>(std::move(std::valarray<T>::acos(*this))); }

	template <class T, unsigned int M, unsigned int N>
	inline Matrix<T, M, N> Matrix<T, M, N>::atan() const
		{ return Matrix<T, M, N>(std::move(std::valarray<T>::atan(*this))); }

	template <class T, unsigned int M, unsigned int N>
	inline Matrix<T, M, N> Matrix<T, M, N>::atan2(const Matrix<T, M, N> & x) const
		{ return Matrix<T, M, N>(std::move(std::valarray<T>::atan2(*this, x))); }

	template <class T, unsigned int M, unsigned int N>
	inline Matrix<T, M, N> Matrix<T, M, N>::atan2(const T & x) const
		{ return Matrix<T, M, N>(std::move(std::valarray<T>::atan2(*this, x))); }

	template <class T, unsigned int M, unsigned int N>
	inline Matrix<T, M, N> Matrix<T, M, N>::sinh() const
		{ return Matrix<T, M, N>(std::move(std::valarray<T>::sinh(*this))); }

	template <class T, unsigned int M, unsigned int N>
	inline Matrix<T, M, N> Matrix<T, M, N>::cosh() const
		{ return Matrix<T, M, N>(std::move(std::valarray<T>::cosh(*this))); }

	template <class T, unsigned int M, unsigned int N>
	inline Matrix<T, M, N> Matrix<T, M, N>::tanh() const
		{ return Matrix<T, M, N>(std::move(std::valarray<T>::tanh(*this))); }

	template <class T, unsigned int M, unsigned int N>
	inline T Matrix<T, M, N>::trace() const
	{
		static_assert(M == N, "It is not possible to compute the trace of a non-square matrix.");
		return std::valarray<T>::operator[std::slice(0, M, M + 1)].sum();
	}

	template <class T, unsigned int M, unsigned int N>
	inline T Matrix<T, M, N>::determinant() const
	{
		static_assert(M == N, "It is not possible to compute the determinant of a non-square matrix.");
		return 0;
	}

	template <class T, unsigned int M, unsigned int N>
	inline Matrix<T, M, N> Matrix<T, M, N>::transpose() const
	{
		static_assert(M == N, "It is not possible to compute the transpose matrix of a non-square matrix.");
		return Matrix<T, M, N>();
	}

	template <class T, unsigned int M, unsigned int N>
	inline Matrix<double, M, N> Matrix<T, M, N>::inverse(bool & invertible) const
	{
		static_assert(M == N, "It is not possible to compute the inverse matrix of a non-square matrix.");
		return Matrix<double, M, N>();
	}
}