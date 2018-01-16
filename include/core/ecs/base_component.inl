namespace ece
{
	inline BaseComponent::BaseComponent(const ComponentID /*id*/) {}

	inline BaseComponent::~BaseComponent() {}

	inline const BaseComponent::ComponentID BaseComponent::getID() const { return this->id; }

	inline const unsigned int BaseComponent::getOwner() const { return this->owner; }
}