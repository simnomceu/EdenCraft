#ifndef BASECOMPONENT_HPP
#define BASECOMPONENT_HPP

#include "Service\ServiceFactory.hpp"

namespace ece
{
	class BaseComponent
	{
	public:
		using ComponentType = unsigned int;
		using ComponentID = unsigned int;

		BaseComponent() = default;
		inline BaseComponent(const ComponentID id);
		inline virtual ~BaseComponent() = 0;

		inline const ComponentType getType() const;
		inline const ComponentID getID() const;
		inline const unsigned int getOwner() const;

	private:
		ComponentType type;
		ComponentID id;
		unsigned int owner;
	};

	typedef ServiceFactory<BaseComponent> ComponentFactory;
}

#include "ECS\BaseComponent.inl"

#endif // BASECOMPONENT_HPP
