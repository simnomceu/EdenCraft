#ifndef MESSAGE_HPP_INCLUDED
#define MESSAGE_HPP_INCLUDED

#include "Transmitable.hpp"

#include <map>

class Message: public Transmitable
{
    public:
        Message(const std::string& titleIn);

        virtual std::string getType() const;
        void addIntData(const std::pair<std::string, int>& newDataIn);
        void addStringData(const std::pair<std::string, std::string>& newDataIn);
        int getIntData(const std::string& keyIn);
        std::string getStringData(const std::string& keyIn);
    private:
        std::map<std::string, int> intData;
        std::map<std::string, std::string> stringData;
};

#endif // MESSAGE_HPP_INCLUDED
