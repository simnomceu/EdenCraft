#include "ComponentManager.hpp"


using namespace core::cmp;

// ============================================================================================================
/**
  * @brief Constructor.
  */
// ============================================================================================================
ComponentManager::ComponentManager(): components(), byTypeIndex(), byOwnerIndex(), factory()
{
}

// ============================================================================================================
/**
  * @brief Destructor.
  */
// ============================================================================================================
ComponentManager::~ComponentManager()
{
}

// ============================================================================================================
/**
  * @brief Remove a component which is the id.
  * @param idIn - ComponentID <<alias int>> <<const value>>
  */
// ============================================================================================================
void ComponentManager::removeComponent(const ComponentID idIn)
{
	this->byOwnerIndex.remove(this->components[idIn]->getOwner());
	this->byTypeIndex.remove(this->components[idIn]->getType());
	this->components.erase(idIn);
}

// ============================================================================================================
/**
  * @brief Remove a component by owner and type.
  * @param ownerIn - EntityID <<alias int>> <<const value>>
  * @param typeIn - std::string& <<alias int>> <<const value>>
  */
// ============================================================================================================
void ComponentManager::removeComponent(const EntityID ownerIn, const std::string& typeIn)
{
	int id = this->getId(ownerIn, typeIn);
	this->byOwnerIndex.remove(ownerIn);
	this->byTypeIndex.remove(this->factory.getType(typeIn));
	this->components.erase(id);
}

// ============================================================================================================
/**
  * @brief Remove components which is the owner.
  * @param ownerIn - EntityID <<alias int>> <<const value>>
  */
// ============================================================================================================
void ComponentManager::removeComponentsByOwner(const EntityID ownerIn)
{
	auto components = this->byOwnerIndex.get(ownerIn);
	for (auto it = components.first; it != components.second; ++it) {
		this->byTypeIndex.remove(this->components[it->second]->getType());
		this->components.erase(it->second);
	}
	this->byOwnerIndex.remove(ownerIn);
}

// ============================================================================================================
/**
  * @brief Remove components which is the type.
  * @param typeIn - std::string& <<alias int>> <<const value>>
  */
// ============================================================================================================
void ComponentManager::removeComponentsByType(const std::string& typeIn)
{
	auto components = this->byTypeIndex.get(this->factory.getType(typeIn));
	for (auto it = components.first; it != components.second; ++it) {
		this->byOwnerIndex.remove(this->components[it->second]->getType());
		this->components.erase(it->second);
	}
	this->byTypeIndex.remove(this->factory.getType(typeIn));
}

// ============================================================================================================
ComponentIterator ComponentManager::getComponentsByOwner(const EntityID ownerIn)
{
	return this->byOwnerIndex.get(ownerIn);
}

// ============================================================================================================
ComponentIterator ComponentManager::getComponentsByType(const std::string& typeIn)
{
	return this->byTypeIndex.get(this->factory.getType(typeIn));
}

// ============================================================================================================
int ComponentManager::getId(const EntityID ownerIn, const std::string& typeIn) const
{
	int shift = 1;
	if (this->factory.getType(typeIn) > 0) {
		shift = static_cast<int>(log10(this->factory.getType(typeIn)) + 1);
	}
	return static_cast<int>(ownerIn * pow(10, shift) + this->factory.getType(typeIn));
}

