#ifndef COMPONENT_HPP
#define COMPONENT_HPP

#include "core/ecs/base_component.hpp"

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
		T _value;
	};
}

#include "core/ecs/component.inl"

#endif // COMPONENT_HPP
