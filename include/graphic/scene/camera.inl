//#include "glm\gtc\matrix_transform.hpp"
#include "utility/mathematics/transform.hpp"

namespace ece
{
	inline Camera::Camera() : _position{ 0.0f, 0.0f, 0.0f }, _target{ 0.0f, 0.0f, 0.0f }, _upAxis{ 0.0f, 1.0f, 0.0f } {}

	inline void Camera::lookAt(const Movable & object) { this->updatePosition(this->_position, object.getPosition()); }

	inline void Camera::lookAt(const FloatVertex3u & target) { this->updatePosition(this->_position, target); }

	inline void Camera::lookUpTo(const FloatVector3u & direction) { this->updatePosition(this->_position, this->_target + direction); }

	inline void Camera::moveTo(const Movable & object) { this->updatePosition(object.getPosition(), this->_target); }

	inline void Camera::moveTo(const FloatVertex3u & position) { this->updatePosition(position, this->_target); }

	inline void Camera::moveIn(const FloatVector3u & direction) { this->updatePosition(this->_position + direction, this->_target); }

	/*inline glm::mat4 Camera::getCamera() const 
	{ 
		return glm::lookAt(glm::vec3(this->position[X], this->position[Y], this->position[Z]),
							glm::vec3(this->target[X], this->target[Y], this->target[Z]),
							glm::vec3(this->upAxis[X], this->upAxis[Y], this->upAxis[Z]));
	}*/

	inline FloatMatrix4u Camera::getCamera() const { return ece::lookAt(this->_position, this->_target, this->_upAxis); }
}