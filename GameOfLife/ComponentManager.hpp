#pragma once

#include <iostream>
#include <unordered_map>
#include <memory>

#include "Component.hpp"
#include "Indexer.hpp"
#include "AbstractComponentFactory.hpp"

namespace core
{
	namespace cmp
	{
		// ============================================================================================================
		/**
		  * @brief Alias.
		  */
		// ============================================================================================================
		using IComponentPtr = std::shared_ptr<IComponent>;
		using ComponentIterator = std::pair<std::multimap<int, int>::iterator, std::multimap<int, int>::iterator>;

		// ============================================================================================================
		/**
		  * @class ComponentManager
		  * @brief Manage components. Schedule writing en reading access.
		 */
		// ============================================================================================================
		class ComponentManager
		{
		public:
			ComponentManager();
			~ComponentManager();
			// TODO convert all from std::string& to std::string and use factory.getType();
			template<class T> void addComponent(const EntityID ownerIn, const std::string& typeIn, const T& valueIn);

			void removeComponent(const ComponentID idIn);
			void removeComponent(const EntityID ownerIn, const std::string& typeIn);
			void removeComponentsByOwner(const EntityID ownerIn);
			void removeComponentsByType(const std::string& typeIn);

			template<class T> const T& getComponent(const ComponentID idIn);
			template<class T> const T& getComponent(const EntityID ownerIn, const std::string& typeIn);

			ComponentIterator getComponentsByOwner(const EntityID ownerIn);
			ComponentIterator getComponentsByType(const std::string& typeIn);

			 template<class T> void setComponent(const ComponentID idIn, const T& valueIn);
			 template<class T> void setComponent(const EntityID ownerIn, std::string& typeIn, const T& valueIn);

			 int getId(const EntityID ownerIn, const std::string& typeIn) const;
			 template<class T> void registerType(const std::string& typeIn);
		private:
			std::unordered_map<ComponentID, IComponentPtr> components; /**< @brief Components registered. */
			Indexer byTypeIndex; /**< @brief index to look for id by type.*/
			Indexer byOwnerIndex; /**< @brief index to look for id by owner.*/
			AbstractComponentFactory factory; /**< @brief use to build new component.*/
		};

		// ============================================================================================================
		template<class T>
		void ComponentManager::addComponent(const EntityID ownerIn, const std::string& typeIn, const T & valueIn)
		{
			int id = this->getId(ownerIn, typeIn);
			if (this->components.find(id) == this->components.end()) {
				this->components.insert(std::pair<ComponentID, IComponentPtr>(id, this->factory.build<T>(ownerIn, typeIn, id, valueIn)));
				this->byTypeIndex.add(this->factory.getType(typeIn), id);
				this->byOwnerIndex.add(ownerIn, id);
			}
		}

		// ============================================================================================================
		template<class T>
		const T & ComponentManager::getComponent(const ComponentID idIn)
		{
			try {
				return std::static_pointer_cast<Component<T>>(this->components[idIn])->getValue();
			}
			catch (const std::exception& e) {
				std::cerr << "No match found between the type and the id." << e.what() << std::endl;
			}
		}

		// ============================================================================================================
		template<class T>
		const T & ComponentManager::getComponent(const EntityID ownerIn, const std::string& typeIn)
		{
			return this->getComponent(this->getId(ownerIn, typeIn));
		}

		// ============================================================================================================
		template<class T>
		void ComponentManager::setComponent(const ComponentID idIn, const T & valueIn)
		{
			try {
				std::static_pointer_cast<Component<T>>(this->components[idIn])->setValue(valueIn);
			}
			catch (const std::exception& e) {
				std::cerr << "Incompatible value with component type." << e.what() << std::endl;
			}
		}

		// ============================================================================================================
		template<class T>
		void ComponentManager::setComponent(const EntityID ownerIn, std::string& typeIn, const T & valueIn)
		{
			int id = this->getId(ownerIn, typeIn);
			try {
				std::static_pointer_cast<Component<T>>(this->components[id])->setValue(valueIn);
			}
			catch (const std::exception& e) {
				std::cerr << "Incompatible value with component type." << e.what() << std::endl;
			}
		}
		
		template<class T>
		void ComponentManager::registerType(const std::string & typeIn)
		{
			try {
				this->factory.registerFactory<T>(typeIn);
			}
			catch (const std::exception& e) {
				std::cerr << e.what() << std::endl;
			}
		}
	}
}