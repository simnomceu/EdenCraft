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

		BaseComponent(const ComponentID id);
		virtual ~BaseComponent() = 0;

		const ComponentType getType() const;
		const ComponentID getID() const;
		const unsigned int getOwner() const;

	private:
		ComponentType type;
		ComponentID id;
		unsigned int owner;
	};
}

#endif // BASECOMPONENT_HPP
