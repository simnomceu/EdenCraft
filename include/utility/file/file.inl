#include "utility/debug/exception.hpp"

namespace ece
{
	inline File::File() : filename(), stream() {}

	inline File::File(const std::string & filename, const OpenMode & mode): filename(filename), stream()
	{
		this->stream.open(this->filename, static_cast<std::ios_base::openmode>(mode));
	}

	inline File::File(File && move): filename(std::move(move.filename)), stream(std::move(move.stream))
	{
		move.close();
	}

	inline File::~File() { this->stream.close(); }

	inline const bool File::isOpen() const { return this->stream.is_open(); }

	template <class T>
	File & File::operator>>(T & value)
	{
		this->stream >> value;
		return *this;
	}

	template <class T>
	File & File::operator<<(T & value)
	{
		this->stream << value;
		return *this;
	}

	template <class T>
	std::vector<T> File::parseToVector()
	{
		std::vector<T> content;
		if (this->isOpen()) {
			T value;
			try {
				while (this->stream.good()) {
					this->stream >> value;
					content.push_back(value);
				}
			}
#pragma warning(suppress: 4101)
			catch (std::exception & e) {
				throw FileException(FileCodeError::PARSE_ERROR, this->filename);
			}
		}
		return content;
	}
}
