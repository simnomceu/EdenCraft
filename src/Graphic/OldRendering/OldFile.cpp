#include "OldRendering\OldFile.hpp"

#include <sys/stat.h>

#include "OldRendering\OldFileException.hpp"

namespace ece
{
	OldFile::OldFile(const std::string & filename, const std::ios_base::openmode & mode): std::fstream(filename, mode)
    {
    }

    const bool OldFile::openFile(const std::string & filename, const std::ios_base::openmode & mode)
    {
        this->close();
        if(!OldFile::existsFile(filename)) {
            throw OldFileException(OldFileException::BAD_PATH, filename);
        }
        this->open(filename, mode);
        return this->isOpen();
    }

    const bool OldFile::isOpen() const
    {
        return this->is_open();
    }

    void OldFile::close()
    {
        if (this->isOpen()) {
            this->close();
        }
    }

    std::string OldFile::copyToString()
    {
        std::string content = "";
        while(this->good()) {
            std::string line;
            std::getline(*this, line);
            content.append(line + "\n");
        }
        return content;
    }

    const bool OldFile::existsFile(const std::string & filename)
    {
        struct stat info;
        int ret = -1;

        ret = stat(filename.c_str(), &info);
        return 0 == ret;
    }
}
