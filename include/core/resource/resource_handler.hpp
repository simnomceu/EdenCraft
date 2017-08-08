#ifndef RESOURCE_HANDLER_HPP
#define RESOURCE_HANDLER_HPP

#include <memory>

#include "resource\resource.hpp"

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

#include "resource\resource_handler.inl"

#endif // RESOURCE_HANDLER_HPP