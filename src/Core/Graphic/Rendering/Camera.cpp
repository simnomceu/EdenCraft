#include "Core\Graphic\Rendering\Camera.hpp"

#include "Core\Util\LogService.hpp"
#include "glm\gtx\transform.hpp"

namespace ece
{
	Camera::Camera(): position(0.0f, 0.0f, 0.0f), target(0.0f, 0.0f, 0.0f), upAxis(0.0f, 1.0f, 0.0f)
	{
	}

	void Camera::lookAt(const Object & object)
	{
		this->lookAt(this->position, object.getCenter());
	}

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
				LogServiceLocator::getService().logError("Computation of the up axis is wrong !");
			}
		}
	}

	void Camera::lookUpTo(const Point3D position, const Vertex3D & direction)
	{
		Point3D target = position + direction;
		this->lookAt(position, target);
	}

	void Camera::moveTo(const Point3D position)
	{
		this->position = position;
	}

	quat Camera::getCamera() const
	{
		return glm::lookAt(this->position, this->target, this->upAxis);
	}
}