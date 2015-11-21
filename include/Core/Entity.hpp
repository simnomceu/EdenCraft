#ifndef ENTITY_HPP_INCLUDED
#define ENTITY_HPP_INCLUDED

class Entity
{
    public:
        Entity(const int idIn, const int archetypeIn);

        int getId() const;
        int getArchetype() const;
    private:
        int id;
        int archetype;
};

#endif // ENTITY_HPP_INCLUDED
