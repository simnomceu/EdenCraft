namespace ece
{
	inline ResourceHandler::ResourceHandler(const std::shared_ptr<Resource> & resource): _resource(resource) {}

	inline std::weak_ptr<Resource> ResourceHandler::operator->() { return this->_resource; }

	inline std::weak_ptr<Resource> ResourceHandler::operator*() { return this->_resource; }
}