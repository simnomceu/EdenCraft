namespace ece
{
	inline OutOfRangeException::OutOfRangeException(const std::string & type, const int id) : content()
	{
		this->content = "Out of range access for " + type + " " + std::to_string(id);
	}

	inline char const * OutOfRangeException::what() const { return this->content.c_str(); }
}