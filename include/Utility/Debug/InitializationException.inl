namespace ece
{
	inline InitializationException::InitializationException(const std::string & target): std::exception(), content("")
	{
		this->content += target + " has failed to initialized.";
	}

	inline char const * InitializationException::what() const { return this->content.data(); }
}