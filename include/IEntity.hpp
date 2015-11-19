#ifndef IENTITY_HPP_INCLUDED
#define IENTITY_HPP_INCLUDED

class IEntity
{
public:
    ~IEntity() {}

    virtual const int getID() const = 0;
    virtual const bool operator==(const IEntity& rightOperantIn) const = 0;
};

#endif // IENTITY_HPP_INCLUDED
