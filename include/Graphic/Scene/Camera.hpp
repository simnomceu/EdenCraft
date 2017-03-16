#ifndef CAMERA_HPP
#define CAMERA_HPP

#include "Model\Movable.hpp"
#include "Util\Type.hpp"

namespace ece
{

	class Camera
	{
	public:
		inline Camera();
		Camera(const Camera & copy) = default;
		Camera(Camera && move) = default;

		~Camera() = default;

		Camera & operator=(const Camera & copy) = default;
		Camera & operator=(Camera && move) = default;

		inline void lookAt(const Movable & object);
		inline void lookAt(const Point3D & target);
		inline void lookUpTo(const Vertex3D & direction);
		inline void moveTo(const Movable & object);
		inline void moveTo(const Point3D position);
		inline void moveIn(const Vertex3D & direction);

		inline Matrix4x4 getCamera() const;

	private:
		void updatePosition(const Point3D position, const Point3D & target);

		Point3D position;
		Point3D target;
		Vertex3D upAxis;
	};
}

#include "Scene\Camera.inl"

#endif // CAMERA_HPP