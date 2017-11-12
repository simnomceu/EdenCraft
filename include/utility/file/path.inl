#include <sstream>
#include <iterator>
#include <algorithm>
#include <fstream>

#include <sys/stat.h>
#ifndef __unix__
	#define S_ISREG(m) (((m) & S_IFMT) == S_IFREG)
	#define S_ISDIR(m) (((m) & S_IFMT) == S_IFDIR)
#endif

namespace ece
{
	inline int Path::getDepth() const { return this->path.size(); }

	inline std::string Path::getPathname() const
	{
		std::stringstream res;
		std::copy(this->path.begin(), this->path.end(), std::ostream_iterator<std::string>(res, "\\"));
		std::string  strres = res.str();
		return strres.substr(0, strres.size() - 1);
	}

	inline std::string Path::getPath() const {
		std::stringstream res;
		std::copy(this->path.begin(), this->path.end() - 1, std::ostream_iterator<std::string>(res, "\\"));
		std::string  strres = res.str() + '\\';
		return strres.substr(0, strres.size() - 1);
	}

	inline std::string Path::getFilename() const { return this->path.back(); }
	
	inline std::string & Path::operator[](const int index) { return this->path[index]; }

	inline bool Path::exists() const { return this->isFile() || this->isFolder(); }

	inline bool Path::isFile() const { return false; }

	inline bool Path::isFolder() const { return false; }
}