#include "core/resource/resource_manager.hpp"

#include "utility/log/service_logger.hpp"
#include "utility/debug/exception.hpp"

namespace ece
{
	void ResourceManager::loadResource(const std::string & identifier)
	{
		auto extension = identifier.substr(identifier.find_last_of('.') + 1);
		if (this->_loaders.find(extension) != this->_loaders.end()) {
			this->loadResource(identifier, this->_loaders[extension]);
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
		if (this->_resources.find(identifier) == this->_resources.end()) {
			this->_resources[identifier] = loader->load(identifier);
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
		if (this->_unloaders.find(extension) != this->_unloaders.end()) {
			this->unloadResource(identifier, this->_unloaders[extension]);
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
		if (this->_resources.find(identifier) != this->_resources.end()) {
			unloader->unload(this->_resources[identifier]);
			this->_resources.erase(identifier);
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
		if (this->_resources.find(identifier) == this->_resources.end()) {
			throw OutOfRangeException("Resource " + identifier);
		}
		return *this->_resources[identifier];
	}

	void ResourceManager::clear()
	{
		while (!this->_resources.empty()) {
			auto const & pair = this->_resources.begin();
			this->unloadResource(pair->first);
		}

		this->_loaders.clear();
		this->_unloaders.clear();
	}

	void ResourceManager::registerLoader(const std::string & extension, const std::shared_ptr<ResourceLoader> & loader)
	{
		if (this->_loaders.find(extension) == this->_loaders.end()) {
			this->_loaders[extension] = loader;
		}
		else {
			std::string errorMessage = "A loader associated to the extension "
				+ extension
				+ " has already been registered. A new loader associated to this extension would create a conflict.";
		}
	}

	void ResourceManager::registerUnloader(const std::string & extension, const std::shared_ptr<ResourceUnloader> & unloader)
	{
		if (this->_unloaders.find(extension) == this->_unloaders.end()) {
			this->_unloaders[extension] = unloader;
		}
		else {
			std::string errorMessage = "An unloader associated to the extension "
				+ extension
				+ " has already been registered. A new unloader associated to this extension would create a conflict.";
		}
	}
}
