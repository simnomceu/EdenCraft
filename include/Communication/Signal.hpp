#ifndef SIGNAL_HPP_INCLUDED
#define SIGNAL_HPP_INCLUDED

#include "Transmitable.hpp"

class Signal: public Transmitable
{
    public:
        Signal(const std::string& titleIn, const bool stateIn, const std::string& sourceIn);

        virtual std::string getType() const;
    private:

};

#endif // SIGNAL_HPP_INCLUDED
