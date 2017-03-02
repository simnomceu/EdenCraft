#include "glm\gtx\transform.hpp"

namespace ece
{
	inline Camera::Camera() : position(0.0f, 0.0f, 0.0f), target(0.0f, 0.0f, 0.0f), upAxis(0.0f, 1.0f, 0.0f) {}

	inline void Camera::lookAt(const Object & object) { this->lookAt(this->position, object.getCenter()); }

	inline void Camera::lookAt(const Point3D & target) { this->lookAt(this->position, target); }

	inline void Camera::moveTo(const Point3D position) { this->position = position; }

	inline quat Camera::getCamera() const { return glm::lookAt(this->position, this->target, this->upAxis); }
}