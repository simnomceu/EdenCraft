#ifndef FILE_HPP
#define FILE_HPP

#include <string>
#include <fstream>
#include <vector>

#include "mathematics/vertex3u.hpp"

namespace ece
{
	class File
	{
	public:
		static const std::ios_base::openmode in = std::fstream::in;
		static const std::ios_base::openmode out = std::fstream::out;

		inline File() = default;
		File(const std::string & filename, const std::ios_base::openmode & mode = File::in | File::out);
		File(const File & copy) = delete;
		File(File && move) = default;
		
		inline ~File();

		File & operator=(const File & copy) = delete;
		File & operator=(File && move) = default;

		const bool open(const std::string & filename, const std::ios_base::openmode & mode = File::in | File::out);
		inline const bool isOpen() const;
		void close();

		std::string parseToString();
		template<class T> std::vector<T> parseToVector();

		static const bool exists(const std::string & filename);

		template <class T> File & operator>>(T & value);
		template <class T> File & operator<<(T & value);

	private:
		std::string filename;
		std::fstream stream;
	};

	template<> std::vector<FloatVertex3u> File::parseToVector<FloatVertex3u>();
}

#include "file/file.inl"

#endif // FILE_HPP
