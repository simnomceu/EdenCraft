#ifndef TRANSFORM_HPP
#define TRANSFORM_HPP

#define PI 3.14159265359

#include "Mathematics\Matrix4u.hpp"
#include "Mathematics\Vertex3u.hpp"
#include "Mathematics\Rectangle.hpp"

namespace ece
{
	FloatMatrix4u lookAt(const FloatPoint3u & eye, const FloatPoint3u & target, const FloatVertex3u & upAxis);

	FloatMatrix4u perspective(const float FOV, const float ratio, const float nearClipping, const float farClipping);

	FloatMatrix4u orthographic(const Rectangle<float> & screen, const float nearClipping, const float farClipping);
}

#endif // TRANSFORM_HPP
