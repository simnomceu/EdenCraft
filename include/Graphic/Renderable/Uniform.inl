#include "Uniform.hpp"

namespace ece
{
	template<class T>
	inline Uniform<T>::Uniform(const std::string & location, const T & data): BaseUniform(), location(location), data(data)
	{
	}

	template <class T>
	std::string Uniform<T>::getLocation() const
	{
		return this->location;
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
		return this->data;
	}

	template<class T>
	inline void Uniform<T>::setLocation(const std::string & location)
	{
		this->location = location;
	}

	template<class T>
	inline void Uniform<T>::setData(const T & data)
	{
		this->data = data;
	}
}