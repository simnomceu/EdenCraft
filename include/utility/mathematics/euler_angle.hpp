#ifndef EULER_ANGLE_HPP
#define EULER_ANGLE_HPP

namespace ece
{
	class EulerAngle
	{
	public:
		EulerAngle() = default;
		EulerAngle(const EulerAngle & copy) = default;
		EulerAngle(EulerAngle && move) = default;

		~EulerAngle() = default;

		EulerAngle & operator=(const EulerAngle & copy) = default;
		EulerAngle & operator=(EulerAngle && move) = default;

	private:

	};
}

#endif // EULER_ANGLE_HPP
