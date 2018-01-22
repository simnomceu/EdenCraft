#ifndef RESOURCE_MANAGER_HPP
#define RESOURCE_MANAGER_HPP

#include <map>
#include <string>
#include <memory>

#include "core/resource/resource_handler.hpp"
#include "core/resource/resource_loader.hpp"
#include "core/resource/resource_unloader.hpp"

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
		void loadResource(const std::string & identifier, const std::shared_ptr<ResourceLoader> & loader);
		void unloadResource(const std::string & identifier);
		void unloadResource(const std::string & identifier, const std::shared_ptr<ResourceUnloader> & unloader);

		std::weak_ptr<Resource> getResource(const std::string & identifier);

		void clear();

		void registerLoader(const std::string & extension, const std::shared_ptr<ResourceLoader> & loader);
		void registerUnloader(const std::string & extension, const std::shared_ptr<ResourceUnloader> & unloader);

	private:
		std::map<std::string, ResourceHandler> _resources;
		std::map<std::string, std::shared_ptr<ResourceLoader>> _loaders;
		std::map<std::string, std::shared_ptr<ResourceUnloader>> _unloaders;
	};
}

#endif // RESOURCE_MANAGER_HPP