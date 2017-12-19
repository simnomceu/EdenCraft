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
		Quaternion(const EulerAngle<T> & eulerAngle);
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

		inline EulerAngle<T> toEulerAngle() const noexcept;
		inline Matrix4u<T> toMatrix() const noexcept;

		inline T & getW() noexcept;
		inline T & getX() noexcept;
		inline T & getY() noexcept;
		inline T & getZ() noexcept;

		inline T getW() const noexcept;
		inline T getX() const noexcept;
		inline T getY() const noexcept;
		inline T getZ() const noexcept;

	private:
		T w;
		T x;
		T y;
		T z;
	};
}

#include "utility/mathematics/quaternion.inl"

#endif // QUATERNION_HPP