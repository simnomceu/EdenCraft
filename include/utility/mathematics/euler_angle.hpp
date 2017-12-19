#ifndef EULER_ANGLE_HPP
#define EULER_ANGLE_HPP

namespace ece
{
	template <class T> Quaternion<T>;
	template <class T> Matrix4u<T>;

	template <class T>
	class EulerAngle
	{
	public:
		inline constexpr EulerAngle() noexcept;
		inline EulerAngle(const double roll, const double pitch, const double yaw) noexcept;
		EulerAngle(const Quaternion<T> & quaternion);
		EulerAngle(const EulerAngle & copy) = default;
		EulerAngle(EulerAngle && move) = default;

		~EulerAngle() = default;

		EulerAngle & operator=(const EulerAngle & copy) = default;
		EulerAngle & operator=(EulerAngle && move) = default;

		Quaternion<T> toQuaternion() const;
		Matrix4u<T> toMatrix() const;

		inline T & getRoll() noexcept;
		inline T & getPitch() noexcept;
		inline T & getYaw() noexcept;

		inline T getRoll() const noexcept;
		inline T getPitch() const noexcept;
		inline T getYaw() const noexcept;

	private:
		T roll; // x-axis rotation
		T pitch; // y-axis rotation
		T yaw; // z-axis rotation
	};
}

#include "utility/mathematics/euler_angle.inl"

#endif // EULER_ANGLE_HPP
