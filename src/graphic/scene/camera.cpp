#include "graphic/scene/camera.hpp"

#include "utility/debug/exception.hpp"

namespace ece
{
	void Camera::updatePosition(const FloatPoint3u & position, const FloatPoint3u & target)
	{
		this->position = position;
		this->target = target;

		auto direction = target - position;
		direction.normalize();
		if (direction == this->upAxis) {
			if (direction == UP) {
				this->upAxis = RIGHT;
			}
			else if (direction == RIGHT) {
				this->upAxis = FRONT;
			}
			else if (direction == FRONT) {
				this->upAxis = UP;
			}
			else {
				throw BadInputException("Computation of the up axis is wrong !");
			}
		}
	}
}