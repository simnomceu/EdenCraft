#pragma once

#include "AbstractComponentBuilder.hpp"
#include "Component.hpp"

namespace cmp
{
	template<class T>
	class ComponentBuilder : public AbstractComponentBuilder
	{
	public:
		ComponentBuilder();
		~ComponentBuilder();

		std::shared_ptr<Component<T>> build(const int ownerIn, const std::string& typeIn, const T& valueIn);
	};

	template<class T>
	ComponentBuilder<T>::ComponentBuilder() : AbstractComponentBuilder()
	{
	}

	template<class T>
	ComponentBuilder<T>::~ComponentBuilder()
	{
	}

	template<class T>
	std::shared_ptr<Component<T>> ComponentBuilder<T>::build(const int ownerIn, const std::string& typeIn, const T& valueIn)
	{
		return std::make_shared<Component<T>>(ownerIn, typeIn, valueIn);
	}
}