#pragma once

#ifdef COMPILE_MYLIBRARY
	#define MYLIBRARY_EXPORT __declspec(dllexport)
#else
	#define MYLIBRARY_EXPORT __declspec(dllimport)
#endif

#include "AbstractComponent.hpp"

namespace cmp
{
	template<class T>
	class Component : public AbstractComponent
	{
	public :
		Component(const int ownerIn, const std::string& typeIn, const T& valueIn);
		~Component();
		const T& read() const;
		void update(const T& newValueIn);

	private:
		T value;
	};

	/* ==================================================================================================== */

	template<class T>
	Component<T>::Component(const int ownerIn, const std::string& typeIn, const T& valueIn) : AbstractComponent(ownerIn, typeIn), value(valueIn)
	{
	}

	template<class T>
	Component<T>::~Component()
	{
	}

	template<class T>
	const T& Component<T>::read() const
	{
		return this->value;
	}

	template<class T>
	void Component<T>::update(const T& newValueIn)
	{
		this->value = newValueIn;
	}
}