namespace ece
{
	inline File::File(const std::string & filename, const std::ios_base::openmode & mode) : std::fstream(filename, mode)
	{
		this->open(filename, mode);
	}

	inline const bool File::isOpen() const { return this->is_open(); }

	template<class T>
	std::vector<T> File::parseToVector()
	{
		std::vector<T> content;
		T value;
		try {
			while (this->good()) {
				*this >> value;
				content.push_back(value);
			}
		}
		catch (std::exception & e) {
			throw FileException(PARSE_ERROR, this->filename);
		}
		return content;
	}
}