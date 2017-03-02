#ifndef COMPONENT_HPP
#define COMPONENT_HPP

#include "ECS\BaseComponent.hpp"

namespace ece
{
	template<class T>
	class Component: public BaseComponent
	{
	public:
		inline Component();
		inline ~Component();

		inline const T & get();
		inline void set(const T &  value);
	protected:
		T value;
	};
}

#include "ECS\Component.inl"

#endif // COMPONENT_HPP
