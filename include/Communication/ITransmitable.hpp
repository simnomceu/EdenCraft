#ifndef ITRANSMITABLE_HPP_INCLUDED
#define ITRANSMITABLE_HPP_INCLUDED

#include <string>

class ITransmitable
{
    public:
        virtual ~ITransmitable() {}

        virtual std::string getType() const = 0;
        virtual std::string getRecipient(const int indiceIn) const = 0;
        virtual int getNumberOfRecipients() const = 0;
        virtual std::string getTitle() const = 0;
        virtual bool getBroadcast() const = 0;
};

#endif // ITRANSMITABLE_HPP_INCLUDED
