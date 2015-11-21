#ifndef IENGINE_HPP_INCLUDED
#define IENGINE_HPP_INCLUDED

class IEngine
{
    public:
        virtual ~IEngine() {}

        virtual void run() = 0;
        virtual void stop() = 0;
        virtual bool isRunning() const = 0;
        virtual std::string getId() const = 0;
};

#endif // IENGINE_HPP_INCLUDED
