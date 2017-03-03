#ifndef OLDANIMATION_HPP
#define OLDANIMATION_HPP

#include <memory>
#include <queue>

#include "Rendering\Model\OldTransformation.hpp"

namespace ece
{
    class OldAnimation
    {
    public:
        OldAnimation() = default;
        OldAnimation(const OldAnimation & copy) = default;
        OldAnimation(OldAnimation && move) = default;
        ~OldAnimation() = default;

        OldAnimation & operator=(const OldAnimation & copy) = default;
        OldAnimation & operator=(OldAnimation && copy) = default;

        void add(const std::shared_ptr<OldTransformation> & transformation);
        void animate(const float elapsedTime, glm::mat4 & model);
        void clear();

    private:
        std::queue<std::shared_ptr<OldTransformation>> transformations;
    };
}

#endif // OLDANIMATION_HPP
