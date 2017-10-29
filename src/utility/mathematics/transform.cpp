#include "mathematics/transform.hpp"

#include <cmath>

namespace ece
{
	FloatMatrix4u lookAt(const FloatPoint3u & eye, const FloatPoint3u & target, const FloatVertex3u & upAxis)
	{
		FloatVertex3u x, y, z;
		z = eye - target;
		z.normalize();
		y = upAxis;
		x = y.cross(z);
		y = z.cross(x);
		x.normalize();
		y.normalize();

		return FloatMatrix4u(x[0], y[0], z[0], 0.0f,
							   x[1], y[1], z[1], 0.0f,
							   x[2], y[2], z[2], 0.0f,
							   -x.dot(eye), -y.dot(eye), -z.dot(eye), 1.0f);
	}

	FloatMatrix4u perspective(const float FOV, const float ratio, const float nearClipping, const float farClipping)
	{
		float scale = static_cast<float>(std::tan(FOV * 0.5f * PI / 180.0f)) * nearClipping;
		Rectangle<float> screen(-ratio * scale, -scale, 2.0f * std::fabs(-ratio * scale), 2 * std::fabs(scale));
		float right = screen.getX() + screen.getWidth();
		float top = screen.getY() + screen.getHeight();

		return FloatMatrix4u(2.0f * nearClipping / screen.getWidth(), 0.0f, 0.0f, 0.0f,
							 0.0f, 2.0f * nearClipping / screen.getHeight(), 0.0f, 0.0f,
							 (right + screen.getX()) / (right - screen.getX()), (top + screen.getY()) / (top - screen.getY()), 
							 -(farClipping + nearClipping) / (farClipping - nearClipping), -1.0f,
							 0.0f, 0.0f, -2.0f * farClipping * nearClipping / (farClipping - nearClipping), 0.0f);
	}


	FloatMatrix4u orthographic(const Rectangle<float> & screen, const float nearClipping, const float farClipping)
	{
		float right = screen.getX() + screen.getWidth();
		float top = screen.getY() + screen.getHeight();

		return FloatMatrix4u(2.0f / screen.getWidth(), 0.0f, 0.0f, 0.0f,
							 0.0f, 2.0f / screen.getHeight(), 0.0f, 0.0f,
							 0.0f, 0.0f, -2.0f / (farClipping - nearClipping), 0.0f,
							 -(right + screen.getX()) / (right - screen.getX()), 
							 -(top + screen.getY()) / (top - screen.getY()), 
							 -(farClipping + nearClipping) / (farClipping - nearClipping), 1.0f);
	}
}
