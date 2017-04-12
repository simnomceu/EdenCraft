#ifndef ROTATION_HPP
#define ROTATION_HPP

#include "Animation\Transformation.hpp"

namespace ece
{
	class Rotation: public Transformation
	{
	public:
		Rotation() = default;
		Rotation(const Rotation & copy) = default;
		Rotation(Rotation && move) = default;

		~Rotation() = default;

		Rotation & operator=(const Rotation & copy) = default;
		Rotation & operator=(Rotation && move) = default;
	};
}

#endif // ROTATION_HPP