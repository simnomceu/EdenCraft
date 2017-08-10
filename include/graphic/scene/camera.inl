//#include "glm\gtc\matrix_transform.hpp"
#include "mathematics/transform.hpp"

namespace ece
{
	inline Camera::Camera() : position(0.0f, 0.0f, 0.0f), target(0.0f, 0.0f, 0.0f), upAxis(0.0f, 1.0f, 0.0f) {}

	inline void Camera::lookAt(const Movable & object) { this->updatePosition(this->position, object.getPosition()); }

	inline void Camera::lookAt(const FloatPoint3u & target) { this->updatePosition(this->position, target); }

	inline void Camera::lookUpTo(const FloatVertex3u & direction) { this->updatePosition(this->position, this->target + direction); }

	inline void Camera::moveTo(const Movable & object) { this->updatePosition(object.getPosition(), this->target); }

	inline void Camera::moveTo(const FloatPoint3u & position) { this->updatePosition(position, this->target); }

	inline void Camera::moveIn(const FloatVertex3u & direction) { this->updatePosition(this->position + direction, this->target); }

	/*inline glm::mat4 Camera::getCamera() const 
	{ 
		return glm::lookAt(glm::vec3(this->position[X], this->position[Y], this->position[Z]),
							glm::vec3(this->target[X], this->target[Y], this->target[Z]),
							glm::vec3(this->upAxis[X], this->upAxis[Y], this->upAxis[Z]));
	}*/

	inline FloatMatrix4u Camera::getCamera() const { return ece::lookAt(this->position, this->target, this->upAxis); }
}