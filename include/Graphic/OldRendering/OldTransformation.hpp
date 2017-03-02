#ifndef OLDTRANSFORMATION_HPP
#define OLDTRANSFORMATION_HPP

#include "glm\glm.hpp"

namespace ece
{
    class OldTransformation
    {
    public:
        virtual ~OldTransformation() = default;

        virtual glm::mat4 apply(const float elapsedTime, const glm::mat4 & model) = 0;
        virtual const bool isCompleted() const = 0;
    };
}

#endif // OLDTRANSFORMATION_HPP
