#ifndef TRANSMITABLE_HPP_INCLUDED
#define TRANSMITABLE_HPP_INCLUDED

#include "ITransmitable.hpp"

#include <vector>

class Transmitable: public ITransmitable
{
    public:
        Transmitable();
        ~Transmitable();

        virtual std::string getType() const = 0;
        virtual std::string getRecipient(const int indiceIn) const;
        virtual int getNumberOfRecipients() const;
        virtual std::string getTitle() const;
        virtual bool getBroadcast() const;
        virtual void addRecipient(const std::string& idIn);
        virtual void setTitle(const std::string& titleIn);
    protected:
        std::vector<std::string> recipients;
        std::string title;
        bool broadcast;
};

#endif // TRANSMITABLE_HPP_INCLUDED
