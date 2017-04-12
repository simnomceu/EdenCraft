#ifndef RESOURCEMANAGER_HPP
#define RESOURCEMANAGER_HPP

#include <map>

#include "Resource\ResourceHandler.hpp"

namespace ece
{
	class ResourceManager
	{
	public:
		ResourceManager() = default;
		ResourceManager(const ResourceManager & copy) = delete;
		ResourceManager(ResourceManager && move) = default;

		~ResourceManager() = default;

		ResourceManager & operator=(const ResourceManager & copy) = delete;
		ResourceManager & operator=(ResourceManager && move) = default;

		void loadResource(const std::string & identifier);
		void unloadResource(const std::string & identifier);

		std::weak_ptr<Resource> getResource(const std::string & identifier);

		void clear();

	private:
		std::map<std::string, ResourceHandler> resources;
	};
}

#endif // RESOURCEMANAGER_HPP