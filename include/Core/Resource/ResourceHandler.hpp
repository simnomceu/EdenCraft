#ifndef RESOURCEHANDLER_HPP
#define RESOURCEHANDLER_HPP

#include <memory>

#include "Resource\Resource.hpp"

namespace ece
{
	class ResourceHandler
	{
	public:
		ResourceHandler() = default;
		inline ResourceHandler(const std::shared_ptr<Resource> & resource);
		ResourceHandler(const ResourceHandler & copy) = default;
		ResourceHandler(ResourceHandler && move) = default;

		~ResourceHandler() = default;

		ResourceHandler & operator=(const ResourceHandler & copy) = default;
		ResourceHandler & operator=(ResourceHandler && move) = default;

		inline std::weak_ptr<Resource> operator->();
		inline std::weak_ptr<Resource> operator*();

	private:
		std::shared_ptr<Resource> resource;
	};
}

#include "Resource\ResourceHandler.inl"

#endif // RESOURCEHANDLER_HPP