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
		inline void lookAt(const GL::Point3D & target);
		inline void lookUpTo(const GL::Vertex3D & direction);
		inline void moveTo(const Movable & object);
		inline void moveTo(const GL::Point3D position);
		inline void moveIn(const GL::Vertex3D & direction);

		inline GL::Matrix4x4 getCamera() const;

	private:
		void updatePosition(const GL::Point3D position, const GL::Point3D & target);

		GL::Point3D position;
		GL::Point3D target;
		GL::Vertex3D upAxis;
	};
}

#include "Scene\Camera.inl"

#endif // CAMERA_HPP