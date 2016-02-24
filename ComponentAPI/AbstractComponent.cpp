#include "stdafx.h"
#include "AbstractComponent.hpp"

/* ==================================================================================================== */

using namespace cmp;

/* ==================================================================================================== */

AbstractComponent::AbstractComponent(const int ownerIn, const std::string& typeIn) : pOwner(ownerIn), pType(typeIn)
{
}

/* ==================================================================================================== */

AbstractComponent::~AbstractComponent()
{
}

/* ==================================================================================================== */

const std::string& AbstractComponent::type() const
{
	return this->pType;
}

/* ==================================================================================================== */

const int AbstractComponent::owner() const
{
	return this->pOwner;
}
