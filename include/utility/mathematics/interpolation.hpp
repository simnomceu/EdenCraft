#ifndef INTERPOLATION_HPP
#define INTERPOLATION_HPP

namespace ece
{
	template <class T> class Quaternion<T>;

	template <class T>
	T lerp(const T a, const T b);

	template <class T>
	Quaternion<T> slerp(const T t, const Quaternion<T> & a, const Quaternion<T> & b);
}

#endif // INTERPOLATION_HPP