#include "Core/Entity.hpp"

Entity::Entity(const int idIn, const int archetypeIn): id(idIn), archetype(archetypeIn)
{

}

int Entity::getId() const
{
    return this->id;
}

int Entity::getArchetype() const
{
    return this->archetype;
}
