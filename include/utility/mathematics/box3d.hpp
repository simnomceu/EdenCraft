#ifndef BOX3D_HPP
#define BOX3D_HPP

#include "mathematics/vertex3u.hpp"

namespace ece
{
	class Box3D
	{
	public:
		Box3D() = delete;
		inline Box3D(const FloatVertex3u & a, const FloatVertex3u & b);
		Box3D(const Box3D & copy) = default;
		Box3D(Box3D && move) = default;

		~Box3D() = default;

		Box3D & operator=(const Box3D & copy) = default;
		Box3D & operator=(Box3D && move) = default;

		inline FloatVertex3u getCenter() const;

	private:
		FloatVertex3u a;
		FloatVertex3u b;
	};
}

#include "mathematics/box3d.inl"

#endif // BOX3D_HPP
