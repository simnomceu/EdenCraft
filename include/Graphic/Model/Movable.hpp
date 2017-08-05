#ifndef MOVABLE_HPP
#define MOVABLE_HPP

#include "Mathematics\Vertex3u.hpp"

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

		inline virtual const FloatVertex3u & getPosition() const;

	protected:
		virtual void computeCenter() = 0;

		FloatVertex3u position;
	};
}

#include "Model\Movable.inl"

#endif // MOVABLE_HPP