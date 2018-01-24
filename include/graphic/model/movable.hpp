#ifndef MOVABLE_HPP
#define MOVABLE_HPP

#include "utility/mathematics/vector3u.hpp"

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

		inline virtual const FloatVector3u & getPosition() const;

	protected:
		virtual void computeCenter() = 0;

		FloatVector3u _position;
	};
}

#include "graphic/model/movable.inl"

#endif // MOVABLE_HPP