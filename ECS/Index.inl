#pragma once

template <typename BaseType>
std::shared_ptr<ECS::Index<BaseType>> ECS::Index<BaseType>::_instance;

template <typename BaseType>
ECS::Index<BaseType>::Index() : _index()
{
}

template<typename BaseType>
std::shared_ptr<ECS::Index<BaseType>> ECS::Index<BaseType>::getInstance()
{
	if (ECS::Index<BaseType>::_instance.get() == nullptr) {
		ECS::Index<BaseType>::_instance = std::make_shared<ECS::Index<BaseType>>(ECS::Index<BaseType>());
	}
	return ECS::Index<BaseType>::_instance;
}

template <typename BaseType>
ECS::Index<BaseType>::~Index()
{
}

template <typename BaseType>
template<typename Type>
void ECS::Index<BaseType>::registerElement()
{
	int id = (int)_index.size();
	std::string key = typeid(Type).name();

	if (_index.find(key) == _index.end()) {
		auto element = std::make_pair(key, id);
		_index.insert(std::move(element));
	}
}

template <typename BaseType>
template<typename Type>
const int ECS::Index<BaseType>::getIndex()
{
	std::string key = typeid(Type).name();
	int id = -1;
	if (_index.find(key) != _index.end()) {
		id = _index[key];
	}

	return id;
}

template<typename BaseType>
template<typename Type>
bool ECS::Index<BaseType>::isRegistered()
{
	std::string key = typeid(Type).name();
	return _index.find(key) != _index.end();
}

template <typename BaseType>
template <typename Type>
void ECS::Index<BaseType>::unregisterElement()
{
	std::string key = typeid(Type).name();

	if (_index.find(key) != _index.end()) {
		_index.erase(key);
	}
}