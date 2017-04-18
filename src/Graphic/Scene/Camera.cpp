#include "Scene\Camera.hpp"

#include "Debug\Exception.hpp"
#include "glm\gtx\transform.hpp"

namespace ece
{
	void Camera::updatePosition(const FloatVertex3D & position, const FloatVertex3D & target)
	{
		this->position = position;
		this->target = target;

		auto direction = target - position;
		direction.normalize();
		if (direction == this->upAxis) {
			if (direction == FloatVertex3D(1.0f, 0.0f, 0.0f)) {
				this->upAxis = FloatVertex3D(0.0f, 1.0f, 0.0f);
			}
			else if (direction == FloatVertex3D(0.0f, 1.0f, 0.0f)) {
				this->upAxis = FloatVertex3D(0.0f, 0.0f, 1.0f);
			}
			else if (direction == FloatVertex3D(0.0f, 0.0f, 1.0f)) {
				this->upAxis = FloatVertex3D(1.0f, 0.0f, 0.0f);
			}
			else {
				throw BadInputException::makeException("Computation of the up axis is wrong !");
			}
		}
	}
}