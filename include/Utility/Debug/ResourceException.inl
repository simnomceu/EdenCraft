namespace ece
{
	inline ResourceException::ResourceException(const std::string & target, const unsigned short int id): message("") 
	{
		this->message += "The resource " + target + " with the ID " + std::to_string(id) + " is not available.";
	}

	inline char const * ResourceException::what() const { return this->message.data(); }
}