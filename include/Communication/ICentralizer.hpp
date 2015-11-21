#ifndef ICENTRALIZER_HPP
#define ICENTRALIZER_HPP

#include <memory>

#include "ITransmitable.hpp"

class ICentralizer
{
    public:
        virtual ~ICentralizer() {}
        virtual void post(std::shared_ptr<ITransmitable> newMessageIn) = 0;
        virtual bool newMessages(const std::string& accountIn) = 0;
        virtual std::shared_ptr<ITransmitable> withdraw(const std::string& accountIn) = 0;
};

#endif // ICENTRALIZER_HPP
