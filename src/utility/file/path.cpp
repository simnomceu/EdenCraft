#include "utility/file/path.hpp"

#ifdef __linux__
	#include <unistd.h>
#else
#include <Windows.h>
#endif

#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <sstream>

namespace ece
{

	Path Path::currentPath()
	{
		std::string path;

#ifdef __linux__
		char result[FILENAME_MAX];
		ssize_t count = readlink("/proc/self/exe", result, FILENAME_MAX);
		path = std::string(result, (count > 0) ? count : 0);
#else
		wchar_t wresult[FILENAME_MAX];
		char result[FILENAME_MAX];
		int size = GetModuleFileName(NULL, wresult, FILENAME_MAX);
		size_t copiedSize;
		auto error = wcstombs_s(&copiedSize, result, FILENAME_MAX, wresult, size);
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
