#ifndef PROJECTION_HPP
#define PROJECTION_HPP

#include "Util\OpenGL\OpenGL.hpp"

namespace ece
{
	class Projection
	{
	public:
		Projection() = default;
		Projection(const Projection & copy) = default;
		Projection(Projection && move) = default;

		~Projection() = default;

		Projection & operator=(const Projection & copy) = default;
		Projection & operator=(Projection && move) = default;

		inline void setProjection(const double FOV, const double ratio, const double nearClipping, const double farClipping);

		inline const GL::Matrix4x4 & getProjection() const;

	private:
		GL::Matrix4x4 projection;
	};
}

#include "Scene\Projection.inl"

#endif // PROJECTION_HPP