#pragma once

#include <unordered_map>
#include <memory>

#include "ComponentFactory.hpp"

namespace core
{
	namespace cmp
	{
		using ComponentType = int;

		class AbstractComponentFactory
		{
		public:
			AbstractComponentFactory();
			~AbstractComponentFactory();

			template<class T> void registerFactory(const std::string& idIn);
			template<class T> std::shared_ptr<IComponent> build(const int ownerIn, const std::string& typeIn, const int idIn, const T& valueIn);
			ComponentType getType(const std::string& typeIn) const;
		private:
			std::unordered_map<std::string, ComponentType> index;
			std::vector<std::shared_ptr<IComponentFactory>> factories;
		};

		template<class T>
		void AbstractComponentFactory::registerFactory(const std::string & idIn)
		{
			if (this->index.find(idIn) == this->index.end()) {
				this->index.insert(std::pair<std::string, int>(idIn, this->index.size()));
				std::shared_ptr<IComponentFactory> tmp(new ComponentFactory<T>());
				this->factories.push_back(tmp);
			}
			else {
				throw new std::exception("A factory with the same id as already be registered.");
			}
		}

		template<class T>
		std::shared_ptr<IComponent> AbstractComponentFactory::build(const int ownerIn, const std::string& typeIn, const int idIn, const T& valueIn)
		{
			if (this->index.find(typeIn) != this->index.end()) {
				return std::static_pointer_cast<ComponentFactory<T>>(this->factories[this->index[typeIn]])->build(ownerIn, this->index[typeIn], idIn, valueIn);
			}
			else {
				throw new std::exception("No factory with this id is currently registered.");
			}
		}
	}
}