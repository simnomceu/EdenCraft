#include "graphic/scene/camera.hpp"

#include "utility/debug/exception.hpp"

namespace ece
{
	void Camera::updatePosition(const FloatVector3u & position, const FloatVector3u & target)
	{
		this->_position = position;
		this->_target = target;

		auto direction = target - position;
		direction.normalize();
		if (direction == this->_upAxis) {
			if (direction == UP) {
				this->_upAxis = RIGHT;
			}
			else if (direction == RIGHT) {
				this->_upAxis = FRONT;
			}
			else if (direction == FRONT) {
				this->_upAxis = UP;
			}
			else {
				throw BadInputException("Computation of the up axis is wrong !");
			}
		}
	}
}