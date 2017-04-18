#ifndef CAMERA_HPP
#define CAMERA_HPP

#include "Model\Movable.hpp"
#include "Mathematics\Vertex3D.hpp"
#include "glm\glm.hpp"

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
		inline void lookAt(const FloatVertex3D & target);
		inline void lookUpTo(const FloatVertex3D & direction);
		inline void moveTo(const Movable & object);
		inline void moveTo(const FloatVertex3D & position);
		inline void moveIn(const FloatVertex3D & direction);

		inline glm::mat4 getCamera() const;

	private:
		void updatePosition(const FloatVertex3D & position, const FloatVertex3D & target);

		FloatVertex3D position;
		FloatVertex3D target;
		FloatVertex3D upAxis;
	};
}

#include "Scene\Camera.inl"

#endif // CAMERA_HPP