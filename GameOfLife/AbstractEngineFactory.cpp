#include "AbstractEngineFactory.hpp"

using namespace core::eng;

AbstractEngineFactory::AbstractEngineFactory(): index(), factories()
{
}

AbstractEngineFactory::~AbstractEngineFactory()
{
}

EngineType AbstractEngineFactory::getType(const std::string& typeIn) const
{
	if (this->index.find(typeIn) != this->index.end()) {
		return this->index.at(typeIn);
	}
	else {
		throw new std::exception("This type is not already registered.");
	}
}
