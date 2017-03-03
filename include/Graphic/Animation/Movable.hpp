#ifndef MOVABLE_HPP
#define MOVABLE_HPP

#include "glm\glm.hpp"

namespace ece
{
	class Movable
	{
	public:
		inline virtual ~Movable() = 0;

		virtual const glm::vec3 & getPosition() const = 0;
	};
}

#include "Animation\Movable.inl"

#endif // MOVABLE_HPP