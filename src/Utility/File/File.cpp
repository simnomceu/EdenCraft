#include "File\File.hpp"

#include "Debug\Exception.hpp"
#include <iostream>

namespace ece
{
	const bool File::open(const std::string & filename, const std::ios_base::openmode & mode)
	{
		this->close();
		if (!File::exists(filename)) {
			throw FileException::makeException(BAD_PATH, filename);
		}
		this->filename = filename;
		std::fstream::open(this->filename, mode);
		return this->isOpen();
	}

	void File::close()
	{
		if (this->isOpen()) {
			std::fstream::close();
		}
	}

	std::string File::parseToString()
	{
		std::string content = "";
		while (this->good()) {
			std::string line;
			std::getline(*this, line);
			content.append(line + "\n");
		}
		return content;
	}

	template<>
	std::vector<FloatVertex3D> File::parseToVector<FloatVertex3D>()
	{
		std::vector<FloatVertex3D> content;
		FloatVertex3D value;
		try {
			while (this->good()) {
				*this >> value.position[X] >> value.position[Y] >> value.position[Z];
				content.push_back(value);
			}
		}
		catch (std::exception & e) {
			throw FileException::makeException(PARSE_ERROR, this->filename + " (" + e.what() + ")");
		}
		return content;
	}

	const bool File::exists(const std::string & filename)
	{
		struct stat info;
		int ret = -1;

		ret = stat(filename.c_str(), &info);
		return 0 == ret;
	}
}