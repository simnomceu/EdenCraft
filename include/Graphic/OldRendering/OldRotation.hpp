#ifndef OLDROTATION_HPP
#define OLDROTATION_HPP

#include "OldRendering\OldTransformation.hpp"

namespace ece
{
    using Point3D = glm::vec3;

    class OldRotation: public OldTransformation
    {
    public:
        OldRotation() = delete;
        OldRotation(const float angle, const glm::vec3 & axis, const bool animated = true);
        OldRotation(const float angle, const glm::vec3 & axis, const Point3D & center, const bool animated = true);
        OldRotation(const OldRotation & copy) = default;
        OldRotation(OldRotation && move) = default;
         ~OldRotation() = default;

        OldRotation & operator=(const OldRotation & copy) = default;
        OldRotation & operator=(OldRotation && move) = default;

        virtual glm::mat4 apply(const float elapsedTime, const glm::mat4 & model);
        virtual const bool isCompleted() const;

    private:
        float angle;
        glm::vec3 axis;
        Point3D center;
        bool animated;

        bool completed;
    };
}

#endif // OLDROTATION_HPP
