#ifndef OLDCAMERA_HPP
#define OLDCAMERA_HPP

#include "glm\glm.hpp"

namespace ece
{
    class OldObject3D;

    using Point3D = glm::vec3;

    class OldCamera
    {
    public:
        OldCamera();
        OldCamera(const OldCamera & copy) = delete;
        OldCamera(OldCamera && move) = delete;
        ~OldCamera() = default;

        OldCamera & operator=(const OldCamera & copy) = delete;
        OldCamera & operator=(OldCamera && move) = delete;

        void lookAt(const OldObject3D & target);
        void lookAt(const Point3D & target);
        void moveTo(const Point3D & position);
        void changeView(const Point3D& position, const Point3D & target);

        const glm::mat4 & getView() const;

    private:
        void correctUpAxis();

        Point3D position;
        Point3D target;
        glm::vec3 upAxis;
        glm::mat4 view;
    };
}

#endif // OLDCAMERA_HPP
