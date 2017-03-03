#ifndef OLDFILEEXCEPTION_HPP
#define OLDFILEEXCEPTION_HPP

#include <exception>
#include <string>

namespace ece
{
    class OldFileException: public std::exception
    {
    public:
        enum Type : unsigned short int {
            BAD_PATH = 0
        };

        OldFileException(const Type type, const std::string & filename);

        virtual char const * what() const;
    private:
        std::string content;
    };
}

#endif // OLDFILEEXCEPTION_HPP
