#ifndef BASECOMPONENT_HPP
#define BASECOMPONENT_HPP

namespace ece
{
	class BaseComponent
	{
	public:
		using ComponentID = unsigned int;

		inline BaseComponent(const ComponentID id);
		inline virtual ~BaseComponent() = 0;

		inline const ComponentID getID() const;
		inline const unsigned int getOwner() const;

	private:
		ComponentID id;
		unsigned int owner;
	};
}

#include "ECS\BaseComponent.inl"

#endif // BASECOMPONENT_HPP
