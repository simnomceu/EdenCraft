#ifndef CAMERA_HPP
#define CAMERA_HPP

#include "Core\Graphic\Animation\Movable.hpp"
#include "Core\Graphic\Rendering\Object.hpp"
#include "glm\glm.hpp"

namespace ece
{
	using quat = glm::mat4;
	using Point3D = glm::vec3;
	using Vertex3D = glm::vec3;

	class Camera: public Movable
	{
	public:
		Camera();

		void lookAt(const Object & object);
		void lookAt(const Point3D position, const Point3D & target);
		void lookUpTo(const Point3D position, const Vertex3D & direction);
		void moveTo(const Point3D position);

		quat getCamera() const;

	private:
		Point3D position;
		Point3D target;
		Vertex3D upAxis;
	};
}

#endif // CAMERA_HPP