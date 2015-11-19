#ifndef ICENTRALIZER_HPP
#define ICENTRALIZER_HPP

#include <memory>

#include "ITransmitable.hpp"

class ICentralizer
{
    public:
        virtual ~ICentralizer() {}
        virtual void post(std::shared_ptr<ITransmitable> newMessageIn) = 0;
};

#endif // ICENTRALIZER_HPP
