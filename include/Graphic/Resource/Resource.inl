namespace ece
{
	inline void Resource::setType(const ResourceType & type) { this->type = type; }
	inline void Resource::setName(const std::string & name) { this->name = name; }

	inline const ResourceType & Resource::getType() const { return this->type; }
	inline const std::string & Resource::getName() const { return this->name; }
}