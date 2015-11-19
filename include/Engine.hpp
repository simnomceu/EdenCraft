#ifndef ENGINE_HPP_INCLUDED
#define ENGINE_HPP_INCLUDED

#include <queue>

#include "ICommunicable.hpp"

class Engine: public ICommunicable
{
    public:
        Engine();

        virtual void receive(std::shared_ptr<ITransmitable> newMessageIn);
        virtual void send(std::shared_ptr<ITransmitable> newMessageIn) const;
        virtual void attachOffice(std::weak_ptr<ICentralizer> officeIn);
    private:
        std::weak_ptr<ICentralizer> office;
        std::queue<std::shared_ptr<ITransmitable>> queueMessages;
};

#endif // ENGINE_HPP_INCLUDED
