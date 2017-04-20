#include "glm\gtc\matrix_transform.hpp"

namespace ece
{
	inline Camera::Camera() : position(0.0f, 0.0f, 0.0f), target(0.0f, 0.0f, 0.0f), upAxis(0.0f, 1.0f, 0.0f) {}

	inline void Camera::lookAt(const Movable & object) { this->updatePosition(this->position, object.getPosition()); }

	inline void Camera::lookAt(const FloatPoint3D & target) { this->updatePosition(this->position, target); }

	inline void Camera::lookUpTo(const FloatVertex3D & direction) { this->updatePosition(this->position, this->target + direction); }

	inline void Camera::moveTo(const Movable & object) { this->updatePosition(object.getPosition(), this->target); }

	inline void Camera::moveTo(const FloatPoint3D & position) { this->updatePosition(position, this->target); }

	inline void Camera::moveIn(const FloatVertex3D & direction) { this->updatePosition(this->position + direction, this->target); }

	inline glm::mat4 Camera::getCamera() const 
	{ 
		return glm::lookAt(glm::vec3(this->position.x, this->position.y, this->position.z), 
							glm::vec3(this->target.x, this->target.y, this->target.z),
							glm::vec3(this->upAxis.x, this->upAxis.y, this->upAxis.z));
	}
}