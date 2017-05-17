namespace ece
{
	template <class T>
	inline Matrix2u<T> Matrix2u<T>::Identity() { return Matrix2u<T>(1, 0, 0, 1); }

	template <class T>
	inline Matrix2u<T>::Matrix2u() : std::array<Vertex2u<T>, 2>{ {0, 0}, {0, 0} } {}

	template <class T>
	inline Matrix2u<T>::Matrix2u(const T a11, const T a12, const T a21, const T a22):
		std::array<Vertex2u<T>, 2>{ {a11, a12}, { a21, a22 } } {}

	template <class T>
	inline Matrix2u<T>::Matrix2u(const Vertex2u<T> & a1, const Vertex2u<T> & a2) : std::array<Vertex2u<T>, 2>{ a1, a2 } {}

	template <class T>
	template <typename V>
	inline Matrix2u<T>::Matrix2u(const Matrix2u<V> & copy): std::array<Vertex2u<T>, 2>{ copy[0], copy[1] } {}

	template <class T>
	template <typename V>
	inline Matrix2u<T> & Matrix2u<T>::operator=(const Matrix2u<V> & copy) 
	{
		(*this)[0] = copy[0];
		(*this)[1] = copy[1];
		return *this;
	}

	template <class T>
	inline Matrix2u<T>& Matrix2u<T>::setIdentity()
	{
		(*this)[0] = { 1, 0 };
		(*this)[1] = { 0, 1 };
		return *this;
	}

	template <class T>
	template<typename V>
	inline Matrix2u<T>& Matrix2u<T>::operator/=(const V value)
	{
		(*this)[0] /= value;
		(*this)[1] /= value;
		return *this;
	}

	template <class T>
	template<typename V>
	inline Matrix2u<T>& Matrix2u<T>::operator*=(const V value)
	{
		(*this)[0] *= value;
		(*this)[1] *= value;
		return *this;
	}

	template <class T>
	template <typename V>
	inline Matrix2u<T> Matrix2u<T>::operator*=(const Matrix2u<V> value)
	{
		T a11 = (*this)[0][0] * value[0][0] + (*this)[0][1] * value[1][0];
		T a12 = (*this)[0][0] * value[0][1] + (*this)[0][1] * value[1][1];
		T a21 = (*this)[1][0] * value[0][0] + (*this)[1][1] * value[1][0];
		T a22 = (*this)[0][0] * value[0][1] + (*this)[0][1] * value[1][1];
		(*this)[0][0] = a11;
		(*this)[0][1] = a12;
		(*this)[1][0] = a21;
		(*this)[1][1] = a22;
		return *this;
	}

	template <class T>
	inline Matrix2u<T>& Matrix2u<T>::operator+=(const Matrix2u<T> value)
	{
		(*this)[0] += value[0];
		(*this)[1] += value[1];
		return *this;
	}

	template <class T>
	inline Matrix2u<T>& Matrix2u<T>::operator-=(const Matrix2u<T> value)
	{
		(*this)[0] -= value[0];
		(*this)[1] -= value[1];
		return *this;
	}

	template <class T>
	template <typename V>
	inline Matrix2u<T> Matrix2u<T>::operator/(const V value) const
	{
		return Matrix2u<T>{(*this)[0] / value, (*this)[1] / value};
	}

	template <class T>
	template <typename V>
	inline Matrix2u<T> Matrix2u<T>::operator*(const V value) const
	{
		return Matrix2u<T>{(*this)[0] * value, (*this)[1] * value};
	}

	template <class T>
	template <typename V>
	inline Vertex2u<T> Matrix2u<T>::operator*(const Vertex2u<V> value) const
	{
		T a11 = (*this)[0][0] * value[0] + (*this)[0][1] * value[1];
		T a21 = (*this)[1][0] * value[0] + (*this)[1][1] * value[1];
		return Vertex2u<T>(a11, a21);
	}

	template <class T>
	template <typename V>
	inline Matrix2u<T> Matrix2u<T>::operator*(const Matrix2u<V> value) const
	{
		T a11 = (*this)[0][0] * value[0][0] + (*this)[0][1] * value[1][0];
		T a12 = (*this)[0][0] * value[0][1] + (*this)[0][1] * value[1][1];
		T a21 = (*this)[1][0] * value[0][0] + (*this)[1][1] * value[1][0];
		T a22 = (*this)[0][0] * value[0][1] + (*this)[0][1] * value[1][1];
		return Matrix2u<T>(a11, a12, a21, a22);
	}

	template <class T>
	inline Matrix2u<T> Matrix2u<T>::operator+(const Matrix2u<T> value) const
	{
		return Matrix2u<T>{(*this)[0] + value[0], (*this)[1] + value[1]};
	}

	template <class T>
	inline Matrix2u<T> Matrix2u<T>::operator-(const Matrix2u<T> value) const
	{
		return Matrix2u<T>{(*this)[0] - value[0], (*this)[1] - value[1]};
	}

	template <class T>
	inline Matrix2u<T> Matrix2u<T>::operator-() const
	{
		return Matrix2u<T>{-(*this)[0], -(*this)[1]};
	}

	template <class T>
	inline bool Matrix2u<T>::operator==(const Matrix2u<T> & rightOperand) const
	{
		return (*this)[0] == rightOperand[0] && (*this)[1] == rightOperand[1];
	}

	template <class T>
	inline Vertex2u<T> Matrix2u<T>::getColumn(const int index) const
	{
		return Vertex2u<T>((*this)[0][index], (*this)[1][index]);
	}

	template <class T>
	inline Vertex2u<T> Matrix2u<T>::getRow(const int index) const
	{
		return Vertex2u<T>((*this)[index]);
	}

	template <class T>
	inline Vertex2u<T> & Matrix2u<T>::getRow(const int index)
	{
		return (*this)[index];
	}

	template<class T>
	inline T Matrix2u<T>::determinant() const
	{
		return (*this)[0][0] * (*this)[1][1] - (*this)[0][1] * (*this)[1][0];
	}

	template<class T>
	inline Matrix2u<T> Matrix2u<T>::transpose() const
	{
		return Matrix2u<T>((*this)[0][0], (*this)[1][0], (*this)[0][1], (*this)[1][1]);
	}

	template<class T>
	inline Matrix2u<T> Matrix2u<T>::inverse(bool & invertible) const
	{
		auto det = this->determinant();
		invertible = (det != 0);
		if (invertible) {
			return Matrix2u<T>((*this)[1][1], -(*this)[0][1], -(*this)[1][0], (*this)[0][0]) * (1.0f / det);
		}
		else {
			return Matrix2u<T>();
		}
	}
}