#ifndef OLDFILE_HPP
#define OLDFILE_HPP

#include <fstream>
#include <memory>
#include <vector>

namespace ece
{
    class OldFile: private std::fstream
    {
    public:
        using std::fstream::operator<<;
        using std::fstream::operator>>;
        using std::fstream::eof;

        OldFile() = default;
        OldFile(const std::string & filename, const std::ios_base::openmode & mode);
        OldFile(const OldFile & copy) = default;
        OldFile(OldFile && move) = default;
        ~OldFile() = default;

        OldFile & operator=(const OldFile & copy) = default;
        OldFile & operator=(OldFile && move) = default;

        const bool openFile(const std::string & filename, const std::ios_base::openmode & mode);
        const bool isOpen() const;
        void close();

        std::string copyToString();
        template<class T> std::vector<T> copyToVector();

        static const bool existsFile(const std::string & filename);
    };

    template<class T>
    std::vector<T> OldFile::copyToVector()
    {
        std::vector<T> content;
        T value;
        while (this->good()) {
            *this >> value;
            content.push_back(value);
        }
        return content;
    }
}

#endif // OLDFILE_HPP
