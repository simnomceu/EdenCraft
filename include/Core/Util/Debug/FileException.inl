namespace ece
{
	inline char const * FileException::what() const { return this->content.c_str(); }
}