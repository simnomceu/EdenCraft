namespace ece
{
	template<class T>
	inline Uniform<T>::Uniform(const std::string & location, const T & data): BaseUniform(), _location(location), _data(data)
	{
	}

	template <class T>
	std::string Uniform<T>::getLocation() const
	{
		return this->_location;
	}

	template <class T>
	UniformType Uniform<T>::getType() const
	{
		return UniformType::OTHER;
	}

	template <>
	UniformType Uniform<int>::getType() const
	{
		return UniformType::NUMERICAL;
	}

	template <class T>
	T Uniform<T>::getData() const
	{
		return this->_data;
	}

	template<class T>
	inline void Uniform<T>::setLocation(const std::string & location)
	{
		this->_location = location;
	}

	template<class T>
	inline void Uniform<T>::setData(const T & data)
	{
		this->_data = data;
	}
}