#include "Util\File\ParserModelDAT.hpp"

#include "Util\File\File.hpp"
#include "Util\Debug\FileException.hpp"

namespace ece
{
	void ParserModelDAT::open(const std::string & filename)
	{
		File file;
		try {
			file.open(filename, std::ios_base::in);

			std::vector<float> tmp(file.parseToVector<float>());
			int size = (int)tmp.size() / 2;
			this->vertices.insert(this->vertices.begin(), tmp.begin(), tmp.begin() + size);
			this->colors.insert(this->colors.begin(), tmp.begin() + size, tmp.end());
		}
		catch (FileException & e) {
			throw e;
		}
	}
}