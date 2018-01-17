namespace ece
{
	inline Resource::~Resource() {}

	inline void Resource::setType(const ResourceType & type) { this->_type = type; }
	
	inline void Resource::setName(const std::string & name) { this->_name = name; }

	inline const ResourceType & Resource::getType() const { return this->_type; }
	
	inline const std::string & Resource::getName() const { return this->_name; }
}