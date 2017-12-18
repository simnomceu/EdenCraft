#ifndef QUATERNION_HPP
#define QUATERNION_HPP

#include "utility/mathematics/vertex3u.hpp"

namespace ece
{
	template <class T> class EulerAngle<T>;
	template <class T> class Matrix4u<T>;

	template <class T>
	class Quaternion
	{
	public:
		inline constexpr Quaternion() noexcept;
		inline Quaternion(const T w, const T x, const T y, const T z) noexcept;
		inline Quaternion(const T angle, const Vertex3u<T> & axis) noexcept;
		Quaternion(const Quaternion<T> & copy) = default;
		Quaternion(Quaternion<T> && move) = default;

		~Quaternion() = default;

		Quaternion<T> & operator=(const Quaternion<T> & copy) = default;
		Quaternion<T> & operator=(Quaternion<T> && move) = default;

		inline Quaternion<T> operator+(const Quaternion<T> & rightOperator) const noexcept;
		inline Quaternion<T> operator-(const Quaternion<T> & rightOperator) const noexcept;
		template<class U> inline Quaternion<T> operator*(const U rightOperator) const noexcept;
		Quaternion<T> operator*(const Quaternion<T> & rightOperator) const;
		template<class U> inline Quaternion<T> operator/(const U rightOperator) const noexcept;

		Quaternion<T> & operator+=(const Quaternion<T> & rightOperator) noexcept;
		Quaternion<T> & operator-=(const Quaternion<T> & rightOperator) noexcept;

		inline Quaternion<T> conjugate() const noexcept;
		inline T norm() const noexcept;
		inline Quaternion<T> normalize() const noexcept;
		inline Quaternion<T> inverse() const noexcept;
		inline T dot(const Quaternion<T> & rightOperand) const noexcept;

		inline T real() const noexcept;
		inline T angle() const noexcept;
		inline Vector3u<T> axis() const noexcept;

		inline EulerRotation<T> toEulerAngle() const noexcept;
		inline Matrix4u<T> toMatrix() const noexcept;

	private:
		T w;
		T x;
		T y;
		T z;
	};
}

#include "utility/mathematics/quaternion.hpp"

#endif // QUATERNION_HPP