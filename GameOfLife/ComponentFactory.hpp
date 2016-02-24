#pragma once

#include <memory>

#include "IComponentFactory.hpp"
#include "Component.hpp"

namespace core
{
	namespace cmp
	{
		template<class T>
		class ComponentFactory : public IComponentFactory
		{
		public:
			ComponentFactory();
			~ComponentFactory();

			std::shared_ptr<Component<T>> build(const int ownerIn, const int typeIn, const int idIn, const T& valueIn);
		};

		template<class T>
		ComponentFactory<T>::ComponentFactory()
		{
		}

		template<class T>
		ComponentFactory<T>::~ComponentFactory()
		{
		}

		template<class T>
		std::shared_ptr<Component<T>> ComponentFactory<T>::build(const int ownerIn, const int typeIn, const int idIn, const T & valueIn)
		{
			return std::shared_ptr<Component<T>>(new Component<T>(ownerIn, typeIn, idIn, valueIn));
		}
	}
}