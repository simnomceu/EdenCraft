#pragma once

#include <vector>
#include <memory>
#include <bitset>
#include <string>

#include "Component.hpp"

namespace ECS
{
	//class Component;
	class World;

	using ListComponents = std::vector<std::unique_ptr<Component>>;
	using EntityUUID = unsigned int;
	using Bitset = std::bitset<16>;
	using ComponentIndex = unsigned int;

	class Entity
	{
	public:
		Entity(std::weak_ptr<World> world, const EntityUUID uuid);
		Entity(const Entity&) = delete; /* No possibility to copy. */

		Entity& operator=(Entity const& clone) = delete;

		~Entity();

		template<typename ComponentType> ComponentType& addComponent();

		template<typename ComponentType> void removeComponent();
		void removeComponent(const ComponentIndex index);
		void removeAllComponents();

		const EntityUUID getUUID() const;
		Component& getComponent(const ComponentIndex index) const;
		template<typename ComponentType> ComponentType& getComponent() const;
		const ListComponents getAllComponents() const;
		const Bitset getListedComponents() const;
		const Bitset getListedSystems() const;
		std::weak_ptr<World> getWorld() const;
		const bool isAlive() const;
		const bool isDirty() const;

		void kill();

		std::string& toString() const;

	private:
		EntityUUID _uuid;
		ListComponents _components;

		Bitset _listedComponents;
		Bitset _listedSystems;

		std::weak_ptr<World> _world;

		bool _alive;
		bool _dirty;
	};

	template<typename ComponentType>
	ComponentType & Entity::addComponent()
	{
		auto component = std::make_unique<ComponentType>();
		_components.push_back(component);

		auto index = _world.getComponentIndex();
		auto id = index.getId<ComponentType>();
		_listedComponents[id] = 1;
		_dirty = true;
	}
}