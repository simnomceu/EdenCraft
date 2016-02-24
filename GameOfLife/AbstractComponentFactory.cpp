#include "AbstractComponentFactory.hpp"

using namespace core::cmp;

AbstractComponentFactory::AbstractComponentFactory(): index(), factories()
{
}

AbstractComponentFactory::~AbstractComponentFactory()
{
}

int AbstractComponentFactory::getType(const std::string & typeIn) const
{
	if (this->index.find(typeIn) != this->index.end()) {
		return this->index.at(std::string(typeIn));
	}
	else {
		throw new std::exception("This type is not already registered.");
	}
}
