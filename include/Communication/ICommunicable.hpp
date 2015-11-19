#ifndef ICOMMUNICABLE_HPP_INCLUDED
#define ICOMMUNICABLE_HPP_INCLUDED

#include <memory>

#include "ITransmitable.hpp"
#include "ICentralizer.hpp"

class ICommunicable
{
    public:
        virtual ~ICommunicable() {}

        virtual void receive(std::shared_ptr<ITransmitable> newMessageIn) = 0;
        virtual void send(std::shared_ptr<ITransmitable> newMessageIn) const = 0;
        virtual void attachOffice(std::weak_ptr<ICentralizer> officeIn) = 0;
};

#endif // ICOMMUNICABLE_HPP_INCLUDED
