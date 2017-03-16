#include "OldAnimation.hpp"

namespace ece
{
    void OldAnimation::add(const std::shared_ptr<OldTransformation> & transformation)
    {
        this->transformations.push(transformation);
    }

    void OldAnimation::animate(const float elapsedTime, glm::mat4 & model)
    {
        if (!this->transformations.empty()) {
            std::shared_ptr<OldTransformation> & currentTransformation = this->transformations.front();

            model = currentTransformation->apply(elapsedTime, model);

            if (currentTransformation->isCompleted()) {
                this->transformations.pop();
            }
        }
    }

    void OldAnimation::clear()
    {
        while (!this->transformations.empty()) {
            this->transformations.pop();
        }
    }
}
