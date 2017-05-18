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
		return Vertex3u<T>((*this)[X] * value, (*this)[Y] * value, (*this)[Z] * value);
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