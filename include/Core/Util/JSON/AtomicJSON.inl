#include "AtomicJSON.hpp"

#include <iostream>

namespace ece
{
	template<class T>
	AtomicJSON<T>::AtomicJSON(const std::string & key, const T & value, const std::weak_ptr<NodeJSON>& parent) : NodeJSON(parent), key(key), value(value)
	{
	}

	template<class T>
	bool AtomicJSON<T>::isAtomic() const
	{
		return true;
	}

	template<class T>
	TypeNodeJSON AtomicJSON<T>::getType() const
	{
		return TypeNodeJSON::NULL_JSON;
	}

	template<>
	inline TypeNodeJSON BooleanJSON::getType() const
	{
		return TypeNodeJSON::BOOLEAN;
	}

	template<>
	inline TypeNodeJSON IntegerJSON::getType() const
	{
		return TypeNodeJSON::INTEGER;
	}

	template<>
	inline TypeNodeJSON DoubleJSON::getType() const
	{
		return TypeNodeJSON::DOUBLE;
	}

	template<>
	inline TypeNodeJSON StringJSON::getType() const
	{
		return TypeNodeJSON::STRING;
	}

	template<class T>
	const T & AtomicJSON<T>::getValue() const
	{
		return this->value;
	}

	template<class T>
	void AtomicJSON<T>::setValue(const T & value)
	{
		this->value = value;
	}

	template<class T>
	inline const std::string & AtomicJSON<T>::getKey() const
	{
		return this->key;
	}
}