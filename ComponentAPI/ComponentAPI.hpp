#pragma once

#ifdef COMPILE_MYLIBRARY
	#define MYLIBRARY_EXPORT __declspec(dllexport)
#else
	#define MYLIBRARY_EXPORT __declspec(dllimport)
#endif

#include "ComponentFactory.hpp"
#include "ComponentPool.hpp"
#include "TypeComponentIndex.hpp"

namespace cmp
{
	class MYLIBRARY_EXPORT ComponentAPI
	{
	public:
		ComponentAPI();
		~ComponentAPI();

		template<class T> void registerType(const std::string& typeIn);
		template<class T> std::shared_ptr<Component<T>> buildComponent(const int ownerIn, const std::string& typeIn, const T& valueIn);
		std::shared_ptr<std::vector<std::shared_ptr<AbstractComponent>>> accessComponents(const std::string& typeIn);

	private:
		ComponentFactory factory;
		ComponentPool pool;
		TypeComponentIndex index;
	};

	template<class T>
	void ComponentAPI::registerType(const std::string & typeIn)
	{
		if (!this->index.contains(typeIn)) {
			this->index.registerType(typeIn);
			this->factory.registerType<T>(typeIn);
			this->pool.addList(typeIn);
		}
		else {
			throw std::exception(("This type already exists : " + typeIn + ".").c_str());
		}
	}

	template<class T>
	std::shared_ptr<Component<T>> ComponentAPI::buildComponent(const int ownerIn, const std::string & typeIn, const T & valueIn)
	{
		if (this->index.contains(typeIn)) {
			return this->factory.build<T>(ownerIn, typeIn, valueIn);
		}
		else {
			throw std::exception(("Incorrect component type for building : " + typeIn + ".").c_str());
		}
	}
}