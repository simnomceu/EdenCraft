#pragma once

#include <vector>
#include <memory>
#include <string>

#include "Component.hpp"

namespace ECS
{
	class World;

	using ListComponents = std::vector<std::unique_ptr<ECS::BaseComponent>>;

	class Entity
	{
	public:
		Entity(std::weak_ptr<World> world, const EntityUUID uuid);
		Entity(const Entity&) = delete; /* No possibility to copy. */

		Entity& operator=(Entity const& clone) = delete;

		~Entity();

		template<typename ComponentType> ComponentType& addComponent();

		template<typename ComponentType> void removeComponent();
		void removeComponent(const ComponentID id);
		void removeAllComponents();

		const EntityUUID getUUID() const;
		BaseComponent& getComponent(const ComponentID index) const;
		template<typename ComponentType> ComponentType& getComponent() const;
		const ListComponents& getAllComponents() const;
		const Bitset& getListedComponents() const;
		const Bitset& getListedSystems() const;
		std::weak_ptr<World> getWorld() const;
		const bool isAlive() const;
		const bool isDirty() const;

		void kill();

		const std::string toString() const;

	private:
		EntityUUID _uuid;
		ListComponents _components;

		Bitset _listedComponents;
		Bitset _listedSystems;

		std::weak_ptr<World> _world;

		bool _alive;
		bool _dirty;
	};
}

#include "Entity.inl"