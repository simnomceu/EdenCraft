#ifndef ENGINE_HPP_INCLUDED
#define ENGINE_HPP_INCLUDED

#include <queue>

#include "Communication/ICommunicable.hpp"
#include "Core/IEngine.hpp"
#include "Core/ISystem.hpp"

class Engine: public ICommunicable, public IEngine
{
    public:
        Engine();

        virtual void receive(std::shared_ptr<ITransmitable> newMessageIn);
        virtual void send(std::shared_ptr<ITransmitable> newMessageIn) const;
        virtual void attachOffice(std::weak_ptr<ICentralizer> officeIn);
        virtual void run();
        virtual void stop();
        virtual bool isRunning() const;
        virtual std::string getId() const = 0;
    protected:
        std::weak_ptr<ICentralizer> office;
        std::queue<std::shared_ptr<ITransmitable>> queueMessages;
        bool running;
        std::vector<std::shared_ptr<ISystem>> systems;

        void withdrawMessages();
        void processQueue();
        virtual void processMessage(std::shared_ptr<ITransmitable> messageIn) = 0;
        virtual void update() = 0;
};

#endif // ENGINE_HPP_INCLUDED
