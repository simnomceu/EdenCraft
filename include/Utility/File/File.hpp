#ifndef FILE_HPP
#define FILE_HPP

#include <string>
#include <fstream>
#include <vector>

#include "Mathematics\Vertex3u.hpp"

namespace ece
{
	class File: private std::fstream
	{
	public:
		using std::fstream::operator<<;
		using std::fstream::operator>>;

		inline File() = default;
		File(const std::string & filename, const std::ios_base::openmode & mode);
		File(const File & copy) = delete;
		File(File && move) = default;
		
		inline ~File();

		File & operator=(const File & copy) = delete;
		File & operator=(File && move) = default;

		const bool open(const std::string & filename, const std::ios_base::openmode & mode);
		inline const bool isOpen() const;
		void close();

		std::string parseToString();
		template<class T> std::vector<T> parseToVector();

		static const bool exists(const std::string & filename);

	private:
		std::string filename;
	};

	template<> std::vector<FloatVertex3u> File::parseToVector<FloatVertex3u>();
}

#include "File\File.inl"

#endif // FILE_HPP