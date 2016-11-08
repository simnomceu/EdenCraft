#ifndef BASECOMPONENT_HPP
#define BASECOMPONENT_HPP

#include "Core\Util\Module\ServiceFactory.hpp"

namespace ece
{
	typedef ServiceFactory<BaseComponent> ComponentFactory;

	class BaseComponent
	{
	public:
		using ComponentType = unsigned int;
		using ComponentID = unsigned int;

		inline BaseComponent(const ComponentID id);
		inline virtual ~BaseComponent() = 0;

		inline const ComponentID getID() const;
		inline const unsigned int getOwner() const;

	private:
		ComponentType type;
		ComponentID id;
		unsigned int owner;
	};
}

#include "ECS\BaseComponent.inl"

#endif // BASECOMPONENT_HPP
