#include "Debug\Exception.hpp"

namespace ece
{
	inline File::File(const std::string & filename, const std::ios_base::openmode & mode) : std::fstream(filename, mode)
	{
		this->open(filename, mode);
	}

	inline File::~File() { this->close(); }

	inline const bool File::isOpen() const { return this->is_open(); }

	template<class T>
	std::vector<T> File::parseToVector()
	{
		std::vector<T> content;
		if (this->isOpen()) {
			T value;
			try {
				while (this->good()) {
					*this >> value;
					content.push_back(value);
				}
			}
#pragma warning(suppress: 4101)
			catch (std::exception & e) {
				throw FileException::makeException(FileCodeError::PARSE_ERROR, this->filename);
			}
		}
		return content;
	}
}