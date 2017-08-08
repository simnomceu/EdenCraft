#include "file\path.hpp"

#include <windows.h>
#include <cstdlib>
#include <iostream>
#include <sstream>

namespace ece
{

	Path Path::currentPath()
	{
		std::string path;

#ifdef __unix__
		char result[PATH_MAX];
		ssize_t count = readlink("/proc/self/exe", result, PATH_MAX);
		path = std::string(result, (count > 0) ? count : 0);
#else
		wchar_t wresult[MAX_PATH];
		char result[MAX_PATH];
		int size = GetModuleFileName(NULL, wresult, MAX_PATH);
		size_t copiedSize;
		auto error = wcstombs_s(&copiedSize, result, MAX_PATH, wresult, size);
		path = std::string(result, size);
#endif
		return Path(path);
	}

	Path::Path(const std::string & pathname): path()
	{
		auto result = std::back_inserter(this->path);
		std::stringstream ss;
		ss.str(pathname);
		std::string item;
		while (std::getline(ss, item, '\\')) {
			*(result++) = item;
		}
	}
}