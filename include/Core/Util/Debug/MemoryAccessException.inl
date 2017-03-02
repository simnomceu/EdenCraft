namespace ece
{
	inline MemoryAccessException::MemoryAccessException(const std::string & target) : content("")
	{
		this->content = "Bad access to " + target + ". The pointer has expired.";
	}

	inline MemoryAccessException::MemoryAccessException(const std::string & target, const std::string & origin) : content("")
	{
		this->content = "Bad access to " + target + " from " + origin + ". The pointer has expired.";
	}

	inline char const * MemoryAccessException::what() const { return this->content.c_str(); }
}