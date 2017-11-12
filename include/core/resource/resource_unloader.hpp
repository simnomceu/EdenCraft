#ifndef RESOURCE_UNLOADER_HPP
#define RESOURCE_UNLOADER_HPP

#include "core/resource/resource_handler.hpp"

namespace ece
{
	class ResourceUnloader
	{
	public:
		ResourceUnloader() = default;
		ResourceUnloader(const ResourceUnloader & copy) = default;
		ResourceUnloader(ResourceUnloader && move) = default;

		inline virtual ~ResourceUnloader() = 0;

		ResourceUnloader & operator=(const ResourceUnloader & copy) = default;
		ResourceUnloader & operator=(ResourceUnloader && move) = default;

		virtual void unload(ResourceHandler & handler) const = 0;
	};
}

#include "core/resource/resource_unloader.inl"

#endif // RESOURCE_UNLOADER_HPP