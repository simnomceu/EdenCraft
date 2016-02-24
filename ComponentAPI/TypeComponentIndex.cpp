#include "stdafx.h"
#include "TypeComponentIndex.hpp"

using namespace cmp;

TypeComponentIndex::TypeComponentIndex() : index()
{
}

TypeComponentIndex::~TypeComponentIndex()
{
}

void TypeComponentIndex::registerType(const std::string & typeIn)
{
	if (!this->contains(typeIn)) {
		this->index.insert(typeIn);
	}
}

const bool TypeComponentIndex::contains(const std::string & typeIn) const
{
	return this->index.find(typeIn) != this->index.end();
}
