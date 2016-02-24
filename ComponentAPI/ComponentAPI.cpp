#include "stdafx.h"
#include "ComponentAPI.hpp"

using namespace cmp;

ComponentAPI::ComponentAPI() : factory(), pool(), index()
{
}

ComponentAPI::~ComponentAPI()
{
}

std::shared_ptr<std::vector<std::shared_ptr<AbstractComponent>>> ComponentAPI::accessComponents(const std::string & typeIn)
{
	if (this->index.contains(typeIn)) {
		return this->pool.access(typeIn);
	}
	else {
		throw std::exception(("Incorrect component type for building : " + typeIn + ".").c_str());
	}
}
