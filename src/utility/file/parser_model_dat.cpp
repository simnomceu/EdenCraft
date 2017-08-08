#include "file\parser_model_dat.hpp"

#include "file\file.hpp"
#include "debug\exception.hpp"

namespace ece
{
	void ParserModelDAT::open(const std::string & filename)
	{
		File file;
		try {
			file.open(filename, std::ios_base::in);

			std::vector<FloatVertex3u> tmp(file.parseToVector<FloatVertex3u>());
			int size = (int)tmp.size() / 2;
			this->vertices.insert(this->vertices.begin(), tmp.begin(), tmp.begin() + size);
			this->colors.insert(this->colors.begin(), tmp.begin() + size, tmp.end());
		}
		catch (FileException & e) {
			throw e;
		}
	}
}