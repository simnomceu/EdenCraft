#ifndef CAMERA_HPP
#define CAMERA_HPP

#include "Animation\Movable.hpp"
#include "Rendering\Object.hpp"
#include "glm\glm.hpp"

namespace ece
{
	using quat = glm::mat4;
	using Point3D = glm::vec3;
	using Vertex3D = glm::vec3;

	class Camera: public Movable
	{
	public:
		inline Camera();

		inline void lookAt(const Object & object);
		inline void lookAt(const Point3D & target);
		void lookAt(const Point3D position, const Point3D & target);
		void lookUpTo(const Point3D position, const Vertex3D & direction);
		inline void moveTo(const Point3D position);

		inline quat getCamera() const;

	private:
		Point3D position;
		Point3D target;
		Vertex3D upAxis;
	};
}

#include "Rendering\Camera.inl"

#endif // CAMERA_HPP