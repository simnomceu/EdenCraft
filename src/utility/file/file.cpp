#include "utility/file/file.hpp"

#include "utility/debug/exception.hpp"

#include <iostream>
#ifdef __linux__
	#include <sys/stat.h>
#endif

namespace ece
{
	const bool File::open(const std::string & filename, const std::ios_base::openmode & mode)
	{
		this->stream.close();
		if (!File::exists(filename)) {
			throw FileException(BAD_PATH, filename);
		}
		this->filename = filename;
		this->stream.open(this->filename, mode);
		return this->isOpen();
	}

	void File::close()
	{
		if (this->isOpen()) {
			this->stream.close();
		}
	}

	std::string File::parseToString()
	{
		std::string content = "";
		if (this->isOpen()) {
			while (this->stream.good()) {
				std::string line;
				std::getline(this->stream, line);
				content.append(line + "\n");
			}
		}
		return content;
	}

	template<>
	std::vector<FloatVertex3u> File::parseToVector<FloatVertex3u>()
	{
		std::vector<FloatVertex3u> content;
		if (this->isOpen()) {
			FloatVertex3u value;
			try {
				while (this->stream.good()) {
					*this >> value[X] >> value[Y] >> value[Z];
					content.push_back(value);
				}
			}
			catch (std::exception & e) {
				throw FileException(PARSE_ERROR, this->filename + " (" + e.what() + ")");
			}
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
