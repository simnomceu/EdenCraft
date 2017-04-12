#ifndef RESOURCECONTAINER_HPP
#define RESOURCECONTAINER_HPP

#include "Locale\LocaleResource.hpp"

namespace ece
{
	class ResourceContainer: public LocaleResource
	{
	public:
		using LocaleResource::insert;
		using LocaleResource::clear;
	};
}

#endif // RESOURCECONTAINER_HPP