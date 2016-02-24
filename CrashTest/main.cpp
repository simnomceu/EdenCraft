#include "stdafx.h"
#include <iostream>
#include <memory>

#include "ComponentAPI.hpp"
#include "AbstractComponent.hpp"
#include "Component.hpp"

using namespace cmp;

int main()
{
	ComponentAPI api;
	api.registerType<int>("health");

	try {
		auto healthComponents = api.accessComponents("health");
		std::cout << healthComponents->size() << std::endl;
		auto& oldOne = *healthComponents;
		
		auto newOneSp = std::make_shared<std::vector<std::shared_ptr<AbstractComponent>>>();
		auto& newOne = *newOneSp;
		newOne.reserve(oldOne.size()+1);
		for (auto const& element : oldOne) {
			newOne.push_back(element);
		}
		newOne.push_back(api.buildComponent<int>(1, "health", 20));
		std::atomic_store(&healthComponents, newOneSp);
		std::cout << healthComponents->size() << std::endl;	

		auto component = (*healthComponents)[0];
		auto intComponent = std::static_pointer_cast<Component<int>>(component);
		std::cout << intComponent->read() << "pv" << std::endl;
		intComponent->update(17);
		std::cout << intComponent->read() << "pv" << std::endl;
	}
	catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
	while (1) {

	}
    return 0;
}

