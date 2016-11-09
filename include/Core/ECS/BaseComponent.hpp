#ifndef BASECOMPONENT_HPP
#define BASECOMPONENT_HPP

namespace ece
{
	class BaseComponent
	{
	public:
		using ComponentID = unsigned int;

		BaseComponent(const ComponentID id);
		virtual ~BaseComponent() = 0;

		const ComponentID getID() const;
		const unsigned int getOwner() const;

	private:
		ComponentID id;
		unsigned int owner;
	};
}

#endif // BASECOMPONENT_HPP
