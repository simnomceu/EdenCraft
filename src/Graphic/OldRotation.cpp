#include "OldRotation.hpp"

#include "glm\gtx\transform.hpp"

namespace ece
{
    OldRotation::OldRotation(const float angle, const glm::vec3 & axis, const bool animated):
		OldTransformation(), angle(angle), axis(axis), center(0.0f, 0.0f, 0.0f), animated(animated), completed(false)
    {
    }

	OldRotation::OldRotation(const float angle, const glm::vec3 & axis, const Point3D & center, const bool animated):
		OldTransformation(), angle(angle), axis(axis), center(center), animated(animated), completed(false)
    {
    }

    glm::mat4 OldRotation::apply(const float elapsedTime, const glm::mat4 & model)
    {
        glm::mat4 newModel = model;
        if (this->center != Point3D(0.0f, 0.0f, 0.0f)) {
            newModel = glm::translate(newModel, this->center);
        }

        if (!this->animated) {
            newModel = glm::rotate(newModel, glm::radians(this->angle), this->axis);
            this->completed = true;
        }
        else {
            const float angleToApply = copysignf(1.0, this->angle) * elapsedTime * 360 / 5000;
            if (std::fabs(this->angle) <= std::fabs(angleToApply)) {
                newModel = glm::rotate(newModel, glm::radians(this->angle), this->axis);
                this->angle = 0.0f;
                this->completed = true;
            }
            else {
                newModel = glm::rotate(newModel, glm::radians(angleToApply), this->axis);
                this->angle -= angleToApply;
            }
        }

        if (this->center != Point3D(0.0f, 0.0f, 0.0f)) {
            newModel = glm::translate(newModel, - this->center);
        }

        return newModel;
    }

    const bool OldRotation::isCompleted() const
    {
        return this->completed;
    }
}
