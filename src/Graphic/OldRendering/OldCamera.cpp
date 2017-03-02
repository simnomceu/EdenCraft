#include "OldRendering\OldCamera.hpp"

#include "glm\gtc\matrix_transform.hpp"
#include "OldRendering\OldObject3D.hpp"

namespace ece
{
	OldCamera::OldCamera(): position(0.0f, 0.0f, 2.0f), target(0.0f, 0.0f, -1.0f), upAxis(0.0f, 1.0f, 0.0f), view(1.0f)
    {
        this->correctUpAxis();
        this->view = glm::lookAt(this->position, this->target, this->upAxis);
    }

    void OldCamera::lookAt(const OldObject3D & target)
    {
        this->target = target.getRelativeCenter();
        this->correctUpAxis();
        this->view = glm::lookAt(this->position, this->target, this->upAxis);
    }

    void OldCamera::lookAt(const Point3D & target)
    {
        this->target = target + this->position;
        this->correctUpAxis();
        this->view = glm::lookAt(this->position, this->target, this->upAxis);
    }

    void OldCamera::moveTo(const Point3D & position)
    {
        this->position = position;
        this->correctUpAxis();
        this->view = glm::lookAt(this->position, this->target, this->upAxis);
    }

    void OldCamera::changeView(const Point3D& position, const Point3D & target)
    {
        this->position = position;
        this->target = target;
        this->correctUpAxis();
        this->view = glm::lookAt(this->position, this->target, this->upAxis);
    }

    const glm::mat4 & OldCamera::getView() const
    {
        return this->view;
    }

    void OldCamera::correctUpAxis()
    {
        if((this->position.x == 0 && this->position.y != 0 && this->position.z == 0)
                || (this->target.x == 0 && this->target.y != 0 && this->target.z == 0)) {
            this->upAxis = glm::vec3(0, 0, 1);
        } else {
            this->upAxis = glm::vec3(0, 1, 0);
        }
    }
}
