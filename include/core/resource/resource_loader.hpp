#ifndef RESOURCE_LOADER_HPP
#define RESOURCE_LOADER_HPP

#include <string>

#include "resource/resource_handler.hpp"

namespace ece
{
	class ResourceLoader
	{
	public:
		ResourceLoader() = default;
		ResourceLoader(const ResourceLoader & copy) = default;
		ResourceLoader(ResourceLoader && move) = default;

		inline virtual ~ResourceLoader() = 0;

		ResourceLoader & operator=(const ResourceLoader & copy) = default;
		ResourceLoader & operator=(ResourceLoader && move) = default;

		virtual ResourceHandler load(const std::string & identifier) const = 0;
	};
}

#include "resource/resource_loader.inl"

#endif // RESOURCE_LOADER_HPP