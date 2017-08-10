#ifndef ANIMATION_HPP
#define ANIMATION_HPP

#include "animation/transformation.hpp"

#include <queue>
#include <memory>

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

		void add(const std::shared_ptr<Transformation> & transformation);
		void clear();

	private:
		std::queue<std::shared_ptr<Transformation>> transformations;
	};
}

#endif // ANIMATION_HPP