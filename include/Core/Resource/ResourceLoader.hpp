#ifndef RESOURCELOADER_HPP
#define RESOURCELOADER_HPP

#include <string>

#include "Resource\ResourceHandler.hpp"

namespace ece
{
	class ResourceLoader
	{
	public:
		ResourceLoader() = default;
		ResourceLoader(const ResourceLoader & copy) = default;
		ResourceLoader(ResourceLoader && move) = default;

		virtual ~ResourceLoader() = 0;

		ResourceLoader & operator=(const ResourceLoader & copy) = default;
		ResourceLoader & operator=(ResourceLoader && move) = default;

		virtual ResourceHandler load(const std::string & identifier) const = 0;
	};
}

#endif // RESOURCELOADER_HPP