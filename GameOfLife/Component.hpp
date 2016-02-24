#pragma once

#include "IComponent.hpp"

namespace core
{
	namespace cmp
	{
		// ============================================================================================================
		/**
		  * @class Component <<template>>
		  * @brief Template derived class component.
		  */
		// ============================================================================================================
		template<class T>
		class Component : public IComponent
		{
		public:
			Component(const EntityID ownerIn, const ComponentType typeIn, const ComponentID idIn, const T& valueIn);
			virtual ~Component();

			virtual EntityID getOwner() const;
			virtual ComponentType getType() const;
			virtual ComponentID getID() const;
			virtual const T& getValue() const;
			virtual void setValue(const T& valueIn);

		private:
			EntityID owner; /**< @brief Indexation key by owner. */
			ComponentType type; /**< @brief Indexation key by type. */
			ComponentID id; /**< @biref Indexation key by direct identification */
			T value;
		};

		// ============================================================================================================
		/**
		  * @brief Constructor.
		  */
		// ============================================================================================================
		template<class T>
		Component<T>::Component(const EntityID ownerIn, const ComponentType typeIn, const ComponentID idIn, const T& valueIn):
			owner(ownerIn), type(typeIn), id(idIn), value(valueIn)
		{
		}

		// ============================================================================================================
		/**
		  * @brief Destructor.
		  */
		// ============================================================================================================
		template<class T>
		Component<T>::~Component()
		{
		}

		// ============================================================================================================
		/**
		  * @brief Accessor for owner property.
		  * @return EntityID <<copy>>
		  */
		// ============================================================================================================
		template<class T>
		EntityID Component<T>::getOwner() const
		{
			return this->owner;
		}

		// ============================================================================================================
		/**
		  * @brief Accessor for type property.
		  * @return ComponentType <<copy>>
		  */
		// ============================================================================================================
		template<class T>
		ComponentType Component<T>::getType() const
		{
			return this->type;
		}

		// ============================================================================================================
		/**
		  * @brief Accessor for id property.
		  * @return ComponentID <<copy>>
		  */
		// ============================================================================================================
		template<class T>
		ComponentID Component<T>::getID() const
		{
			return this->id;
		}

		// ============================================================================================================
		/**
		  * @brief Accessor for value property.
		  * @return T object <<const reference>>
		  */
		// ============================================================================================================
		template<class T>
		const T& Component<T>::getValue() const
		{
			return this->value;
		}

		// ============================================================================================================
		/**
		  * @brief Mutator for value property.
		  * @param valueIn - T object <<const reference>>
		  */
		// ============================================================================================================
		template<class T>
		void Component<T>::setValue(const T& valueIn)
		{
			this->value = valueIn;
		}
	}
}