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
		return Vertex4u<T>((*this)[0] * value, (*this)[1] * value, (*this)[2] * value, (*this)[3] * value);
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