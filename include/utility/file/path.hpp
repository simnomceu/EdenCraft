#ifndef PATH_HPP
#define PATH_HPP

#include <string>
#include <vector>

namespace ece
{
	class Path
	{
	public:
		static Path currentPath();
		
		Path() = default;
		Path(const std::string & pathname);
		Path(const Path & copy) = default;
		Path(Path && move) = default;

		~Path() = default;

		Path & operator=(const Path & copy) = default;
		Path & operator=(Path && move) = default;

		inline int getDepth() const;
		inline std::string getPathname() const;
		inline std::string getPath() const;
		inline std::string getFilename() const;
		inline std::string & operator[](const int index);

		inline bool exists() const;
		inline bool isFile() const;
		inline bool isFolder() const;

	private:
		std::vector<std::string> path;
	};
}

#include "file\path.inl"

#endif // PATH_HPP
