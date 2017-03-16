#ifndef ANIMATION_HPP
#define ANIMATION_HPP

namespace ece
{
	class Animation
	{
	public:
		Animation() = default;
		Animation(const Animation & copy) = default;
		Animation(Animation && move) = default;

		~Animation() = default;

		Animation & operator=(const Animation & copy) = default;
		Animation & operator=(Animation && move) = default;
	};
}

#endif // ANIMATION_HPP