#include "resource/resource_manager.hpp"

#include "log/service_logger.hpp"
#include "debug/exception.hpp"

namespace ece
{
	void ResourceManager::loadResource(const std::string & identifier)
	{
		auto extension = identifier.substr(identifier.find_last_of('.') + 1);
		if (this->loaders.find(extension) != this->loaders.end()) {
			this->loadResource(identifier, this->loaders[extension]);
		}
		else {
			std::string errorMessage = "It is not possible to identify a loader for the resource "
				+ identifier
				+ ". Please, provide a loader explicitly for this resource.";
			ServiceLoggerLocator::getService().logError(errorMessage);
		}
	}

	void ResourceManager::loadResource(const std::string & identifier, const std::shared_ptr<ResourceLoader> & loader)
	{
		if (this->resources.find(identifier) == this->resources.end()) {
			this->resources[identifier] = loader->load(identifier);
		}
		else {
			std::string errorMessage = "A resource with the identifier "
				+ identifier
				+ " has already been loaded. Please, first unload it, before loading a new one.";
			ServiceLoggerLocator::getService().logError(errorMessage);
		}
	}

	void ResourceManager::unloadResource(const std::string & identifier)
	{
		auto extension = identifier.substr(identifier.find_last_of('.') + 1);
		if (this->unloaders.find(extension) != this->unloaders.end()) {
			this->unloadResource(identifier, this->unloaders[extension]);
		}
		else {
			std::string errorMessage = "It is not possible to identify an unloader for the resource "
				+ identifier
				+ ". Please, provide an unloader explicitly for this resource.";
			ServiceLoggerLocator::getService().logError(errorMessage);
		}
	}

	void ResourceManager::unloadResource(const std::string & identifier, const std::shared_ptr<ResourceUnloader> & unloader)
	{
		if (this->resources.find(identifier) != this->resources.end()) {
			unloader->unload(this->resources[identifier]);
			this->resources.erase(identifier);
		}
		else {
			std::string errorMessage = "It is not possible to unload the resource "
				+ identifier
				+ " because this resource has not been loader yet.";
			ServiceLoggerLocator::getService().logError(errorMessage);
		}
	}

	std::weak_ptr<Resource> ResourceManager::getResource(const std::string & identifier)
	{
		if (this->resources.find(identifier) == this->resources.end()) {
			throw OutOfRangeException("Resource " + identifier);
		}
		return *this->resources[identifier];
	}

	void ResourceManager::clear()
	{
		while (!this->resources.empty()) {
			auto const & pair = this->resources.begin();
			this->unloadResource(pair->first);
		}

		this->loaders.clear();
		this->unloaders.clear();
	}

	void ResourceManager::registerLoader(const std::string & extension, const std::shared_ptr<ResourceLoader> & loader)
	{
		if (this->loaders.find(extension) == this->loaders.end()) {
			this->loaders[extension] = loader;
		}
		else {
			std::string errorMessage = "A loader associated to the extension "
				+ extension
				+ " has already been registered. A new loader associated to this extension would create a conflict.";
		}
	}

	void ResourceManager::registerUnloader(const std::string & extension, const std::shared_ptr<ResourceUnloader> & unloader)
	{
		if (this->unloaders.find(extension) == this->unloaders.end()) {
			this->unloaders[extension] = unloader;
		}
		else {
			std::string errorMessage = "An unloader associated to the extension "
				+ extension
				+ " has already been registered. A new unloader associated to this extension would create a conflict.";
		}
	}
}
