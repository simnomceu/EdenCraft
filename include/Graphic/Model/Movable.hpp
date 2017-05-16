#ifndef MOVABLE_HPP
#define MOVABLE_HPP

#include "Mathematics\Vertex3D.hpp"

namespace ece
{
	class Movable
	{
	public:
		inline Movable();
		Movable(const Movable & copy) = default;
		Movable(Movable && move) = default;

		inline virtual ~Movable() = 0;

		Movable & operator=(const Movable & copy) = default;
		Movable & operator=(Movable && move) = default;

		inline virtual const FloatVertex3D & getPosition() const;

	protected:
		virtual void computeCenter() = 0;

		FloatVertex3D position;
	};
}

#include "Model\Movable.inl"

#endif // MOVABLE_HPP