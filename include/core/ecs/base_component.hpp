#ifndef BASE_COMPONENT_HPP
#define BASE_COMPONENT_HPP

namespace ece
{
	class BaseComponent
	{
	public:
		using ComponentID = unsigned int;

		BaseComponent() = default;
		inline BaseComponent(const ComponentID id);
		inline virtual ~BaseComponent() = 0;

		inline const ComponentID getID() const;
		inline const unsigned int getOwner() const;

	private:
		ComponentID id;
		unsigned int owner;
	};
}

#include "ecs\base_component.inl"

#endif // BASE_COMPONENT_HPP
