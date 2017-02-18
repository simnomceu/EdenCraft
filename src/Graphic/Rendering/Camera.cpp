#include "Rendering\Camera.hpp"

#include "Util\Log\ServiceLogger.hpp"

namespace ece
{
	void Camera::lookAt(const Point3D position, const Point3D & target)
	{
		this->position = position;
		this->target = target;

		auto direction = glm::normalize(target - position);
		if (direction == this->upAxis) {
			if (direction == Vertex3D(1.0f, 0.0f, 0.0f)) {
				this->upAxis = Vertex3D(0.0f, 1.0f, 0.0f);
			}
			else if (direction == Vertex3D(0.0f, 1.0f, 0.0f)) {
				this->upAxis = Vertex3D(0.0f, 0.0f, 1.0f);
			}
			else if (direction == Vertex3D(0.0f, 0.0f, 1.0f)) {
				this->upAxis = Vertex3D(1.0f, 0.0f, 0.0f);
			}
			else {
				ServiceLoggerLocator::getService().logError("Computation of the up axis is wrong !");
			}
		}
	}

	void Camera::lookUpTo(const Point3D position, const Vertex3D & direction)
	{
		Point3D target = position + direction;
		this->lookAt(position, target);
	}
}