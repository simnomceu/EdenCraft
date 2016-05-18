#pragma once

#include "Index.hpp"
#include "BaseComponent.hpp"

namespace ECS
{
	template <typename ComponentType>
	class Component: public BaseComponent
	{
	public:
		Component(std::shared_ptr<ECS::Index<ECS::BaseComponent>> index);
		~Component();

		const ComponentID getID() const;

	private:
		ComponentID _id;
	};
}

#include "Component.inl"