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

		const Matrix4x4 & getProjection() const;
	};
}

#endif // PROJECTION_HPP