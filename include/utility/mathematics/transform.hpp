#ifndef TRANSFORM_HPP
#define TRANSFORM_HPP

#define PI 3.14159265359

#include "mathematics/matrix4u.hpp"
#include "mathematics/vertex3u.hpp"
#include "mathematics/rectangle.hpp"

namespace ece
{
	FloatMatrix4u lookAt(const FloatPoint3u & eye, const FloatPoint3u & target, const FloatVertex3u & upAxis);

	FloatMatrix4u perspective(const float FOV, const float ratio, const float nearClipping, const float farClipping);

	FloatMatrix4u orthographic(const Rectangle<float> & screen, const float nearClipping, const float farClipping);
}

#endif // TRANSFORM_HPP
