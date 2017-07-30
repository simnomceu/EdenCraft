namespace ece
{
	inline ResourceHandler::ResourceHandler(const std::shared_ptr<Resource> & resource): resource(resource) {}

	inline std::weak_ptr<Resource> ResourceHandler::operator->() { return this->resource; }

	inline std::weak_ptr<Resource> ResourceHandler::operator*() { return this->resource; }
}