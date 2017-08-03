#ifndef COMPONENT_HPP
#define COMPONENT_HPP

#include "ECS\BaseComponent.hpp"

namespace ece
{
	template<class T>
	class Component: public BaseComponent
	{
	public:
		Component();
		~Component();

		const T & get();
		void set(const T &  value);

	protected:
		T value;
	};
}

#include "ECS\Component.inl"

#endif // COMPONENT_HPP
