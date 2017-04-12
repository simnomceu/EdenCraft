#ifndef SKELETON_HPP
#define SKELETON_HPP

namespace ece
{
	class Skeleton
	{
	public:
		Skeleton() = default;
		Skeleton(const Skeleton & copy) = default;
		Skeleton(Skeleton && move) = default;

		~Skeleton() = default;

		Skeleton & operator=(const Skeleton & copy) = default;
		Skeleton & operator=(Skeleton && move) = default;
	};
}

#endif // SKELETON_HPP