#ifndef MOVABLE_HPP
#define MOVABLE_HPP

#include "glm\glm.hpp"

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

		inline virtual const glm::vec3 & getPosition() const;

	protected:
		virtual void computeCenter() = 0;

		glm::vec3 position;
	};
}

#include "Rendering\Model\Movable.inl"

#endif // MOVABLE_HPP