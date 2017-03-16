#include "Util\OpenGL\OpenGL.hpp"

namespace ece
{
	inline Camera::Camera() : position(0.0f, 0.0f, 0.0f), target(0.0f, 0.0f, 0.0f), upAxis(0.0f, 1.0f, 0.0f) {}

	inline void Camera::lookAt(const Movable & object) { this->updatePosition(this->position, object.getPosition()); }

	inline void Camera::lookAt(const Point3D & target) { this->updatePosition(this->position, target); }

	inline void Camera::lookUpTo(const Vertex3D & direction) { this->updatePosition(this->position, this->target + direction); }

	inline void Camera::moveTo(const Movable & object) { this->updatePosition(object.getPosition(), this->target); }

	inline void Camera::moveTo(const Point3D position) { this->updatePosition(position, this->target); }

	inline void Camera::moveIn(const Vertex3D & direction) { this->updatePosition(this->position + direction, this->target); }

	inline Matrix4x4 Camera::getCamera() const { return OpenGL::lookAt(this->position, this->target, this->upAxis); }
}