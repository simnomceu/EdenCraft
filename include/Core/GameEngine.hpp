#ifndef GAMEENGINE_HPP_INCLUDED
#define GAMEENGINE_HPP_INCLUDED

#include "Core/Engine.hpp"

class GameEngine: public Engine
{
    public:
        GameEngine();

        virtual std::string getId() const;

    protected:
        virtual void processMessage(std::shared_ptr<ITransmitable> messageIn);
        virtual void update();

    private:
/*        std::vector<std::shared_ptr<Entity>> entities;
        int entityCount;
        std::shared_ptr<EntityFactory> factory;

        void addEntity(int typeIn);*/
};

#endif // GAMEENGINE_HPP_INCLUDED
