#ifndef BOX3D_HPP
#define BOX3D_HPP

#include "Vertex.hpp"

namespace ece
{
	class Box3D
	{
	public:
		Box3D() = delete;
		inline Box3D(const FloatVertex3D & a, FloatVertex3D & b);
		Box3D(const Box3D & copy) = default;
		Box3D(Box3D && move) = default;

		~Box3D() = default;

		Box3D & operator=(const Box3D & copy) = default;
		Box3D & operator=(Box3D && move) = default;

		inline FloatVertex3D getCenter() const;

	private:
		FloatVertex3D a;
		FloatVertex3D b;
	};
}

#include "Geom\Box3D.inl"

#endif // BOX3D_HPP