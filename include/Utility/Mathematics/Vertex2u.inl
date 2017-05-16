namespace ece
{
	template <class T>
	inline Vertex2u<T>::Vertex2u() : std::array<T, 2>{ 0, 0 } {}

	template <class T>
	inline Vertex2u<T>::Vertex2u(const T x, const T y) : std::array<T, 2>{ x, y } {}

	template <class T>
	template <typename V>
	inline Vertex2u<T>::Vertex2u(const Vertex2u<V> & copy) :
		std::array<T, 3>{ static_cast<T>(copy[0]), static_cast<T>(copy[1]) } {}

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
		(*this)[0] += value.x;
		(*this)[1] += value.y;
		return *this;
	}

	template<class T>
	inline Vertex2u<T>& Vertex2u<T>::operator-=(const Vertex2u<T> value)
	{
		(*this)[0] -= value.x;
		(*this)[1] -= value.y;
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