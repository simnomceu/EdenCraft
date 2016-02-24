#pragma once

#include <unordered_map>
#include <vector>

#include "EngineFactory.hpp"

namespace core
{
	namespace eng
	{
		using EngineType = int;

		class AbstractEngineFactory
		{
		public:
			AbstractEngineFactory();
			~AbstractEngineFactory();

			template<class T> void registerFactory(const std::string& idIn);
			template<class T> std::shared_ptr<T> build(const bool activeIn, const int refreshRateIn, const std::string& idAccountIn);
			EngineType getType(const std::string& typeIn) const;

		private:
			std::unordered_map<std::string, EngineType> index;
			std::vector<std::shared_ptr<IEngineFactory>> factories;
		};

		template<class T>
		void AbstractEngineFactory::registerFactory(const std::string & idIn)
		{
			if (this->index.find(idIn) == this->index.end()) {
				this->index.insert(std::pair<std::string, int>(idIn, this->index.size()));
				std::shared_ptr<IEngineFactory> tmp(new EngineFactory<T>());
				this->factories.push_back(tmp);
			}
			else {
				throw new std::exception("A factory with the same id as already be registered.");
			}
		}
		
		template<class T>
		std::shared_ptr<T> AbstractEngineFactory::build(const bool activeIn, const int refreshRateIn, const std::string & idAccountIn)
		{
			if (this->index.find(idAccountIn) != this->index.end()) {
				return std::static_pointer_cast<EngineFactory<T>>(this->factories[this->index[idAccountIn]])->build(activeIn, refreshRateIn);
			}
			else {
				throw new std::exception("No factory with this id is currently registered.");
			}
		}
	}
}