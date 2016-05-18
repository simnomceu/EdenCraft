#pragma once

template<typename ComponentType>
ECS::Component<ComponentType>::Component(std::shared_ptr<ECS::Index<ECS::BaseComponent>> index) : _id(-1)
{
	if (index->isRegistered<ComponentType>()) {
		_id = index->getIndex<ComponentType>();
	}
	else {
		// TODO Gestion de l'erreur.
	}
}

template<typename ComponentType>
ECS::Component<ComponentType>::~Component()
{
}

template<typename ComponentType>
const ECS::ComponentID ECS::Component<ComponentType>::getID() const
{
	return _id;
}