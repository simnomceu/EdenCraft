#ifndef MOVABLE_HPP
#define MOVABLE_HPP

#include "Util\OpenGL\OpenGL.hpp"

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

		inline virtual const GL::Vertex3D & getPosition() const;

	protected:
		virtual void computeCenter() = 0;

		GL::Vertex3D position;
	};
}

#include "Model\Movable.inl"

#endif // MOVABLE_HPP