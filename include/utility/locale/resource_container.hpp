#ifndef RESOURCE_CONTAINER_HPP
#define RESOURCE_CONTAINER_HPP

#include "utility/locale/locale_resource.hpp"

namespace ece
{
	class ResourceContainer: public LocaleResource
	{
	public:
		using LocaleResource::insert;
		using LocaleResource::clear;
	};
}

#endif // RESOURCE_CONTAINER_HPP