#ifndef CAMERA_HPP
#define CAMERA_HPP

#include "model\movable.hpp"
#include "mathematics\vertex3u.hpp"
#include "mathematics\matrix4u.hpp"
//#include "glm\glm.hpp"

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
		inline void lookAt(const FloatPoint3u & target);
		inline void lookUpTo(const FloatVertex3u & direction);
		inline void moveTo(const Movable & object);
		inline void moveTo(const FloatPoint3u & position);
		inline void moveIn(const FloatVertex3u & direction);

		//inline glm::mat4 getCamera() const;
		inline FloatMatrix4u getCamera() const;

	private:
		void updatePosition(const FloatPoint3u & position, const FloatPoint3u & target);

		FloatPoint3u position;
		FloatPoint3u target;
		FloatVertex3u upAxis;
	};
}

#include "scene\camera.inl"

#endif // CAMERA_HPP