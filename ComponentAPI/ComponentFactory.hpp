#pragma once

#pragma warning( push )
#pragma warning( disable: 4251 )

#ifdef COMPILE_MYLIBRARY
	#define MYLIBRARY_EXPORT __declspec(dllexport)
#else   
	#define MYLIBRARY_EXPORT __declspec(dllimport)
#endif

#include <map>
#include <memory>
#include <string>

#include "ComponentBuilder.hpp"

namespace cmp
{
	class MYLIBRARY_EXPORT ComponentFactory
	{
	public:
		ComponentFactory();
		~ComponentFactory();

		template<class T> void registerType(const std::string& typeIn);
		template<class T> std::shared_ptr<Component<T>> build(const int ownerIn, const std::string& typeIn, const T& valueIn);

	private:
		std::map<std::string, std::shared_ptr<AbstractComponentBuilder>> builders;
	};

	template<class T>
	void ComponentFactory::registerType(const std::string& typeIn)
	{
		if (this->builders.find(typeIn) == this->builders.end()) {
			this->builders[typeIn] = std::make_shared<ComponentBuilder<T>>();
		}
		else {
			throw std::exception(("This builder already exists : " + typeIn + ".").c_str());
		}
	}

	template<class T>
	std::shared_ptr<Component<T>> ComponentFactory::build(const int ownerIn, const std::string& typeIn, const T & valueIn)
	{
		return std::static_pointer_cast<ComponentBuilder<T>>(this->builders[typeIn])->build(ownerIn, typeIn,  valueIn);
	}
}

#pragma warning( pop )