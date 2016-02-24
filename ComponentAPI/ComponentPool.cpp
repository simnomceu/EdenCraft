#include "stdafx.h"
#include "ComponentPool.hpp"

#include <string>

using namespace cmp;

ComponentPool::ComponentPool(): components()
{
}


ComponentPool::~ComponentPool()
{
}

std::shared_ptr<std::vector<std::shared_ptr<AbstractComponent>>> cmp::ComponentPool::access(const std::string& typeIn)
{
	if (this->components.find(typeIn) != this->components.end()) {
		return this->components[typeIn];
	}
	else {
		throw std::exception(("This type is not registered : " + typeIn + ".").c_str());
	}
}

void cmp::ComponentPool::addList(const std::string& typeIn)
{
	if (this->components.find(typeIn) == this->components.end()) {
		this->components[typeIn] = std::make_shared<std::vector<std::shared_ptr<AbstractComponent>>>();
	}
	else {
		throw std::exception(("Type " + typeIn + "already exists. Try an other id.").c_str());
	}
}
