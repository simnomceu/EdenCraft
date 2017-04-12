#ifndef TRANSFORMATION_HPP
#define TRANSFORMATION_HPP

namespace ece
{
	class Transformation
	{
	public:
		Transformation() = default;
		Transformation(const Transformation & copy) = default;
		Transformation(Transformation && move) = default;

		~Transformation() = default;

		Transformation & operator=(const Transformation & copy) = default;
		Transformation & operator=(Transformation && move) = default;
	};
}

#endif // TRANSFORMATION_HPP