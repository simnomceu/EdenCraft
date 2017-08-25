#include "debug/exception.hpp"

namespace ece
{
	template <class T>
	inline Matrix3u<T> Matrix3u<T>::Identity() { return Matrix3u<T>(1, 0, 0, 
																	0, 1, 0,
																	0, 0, 1); }

	template <class T>
	inline Matrix3u<T>::Matrix3u() : std::array<Vertex3u<T>, 3>{ Vertex3u<T>(), Vertex3u<T>(), Vertex3u<T>() } {}

	template <class T>
	inline Matrix3u<T>::Matrix3u(const T a11, const T a12, const T a13,
								 const T a21, const T a22, const T a23,
								 const T a31, const T a32, const T a33) :
		std::array<Vertex3u<T>, 3>{ Vertex3u<T>{a11, a12, a13}, Vertex3u<T>{ a21, a22, a23 }, Vertex3u<T>{ a31, a32, a33 } } {}

	template <class T>
	inline Matrix3u<T>::Matrix3u(const Vertex3u<T> & a1, const Vertex3u<T> & a2, const Vertex3u<T> & a3) :
		std::array<Vertex3u<T>, 3>{ a1, a2, a3 } {}

	template <class T>
	template <typename V>
	inline Matrix3u<T>::Matrix3u(const Matrix3u<V> & copy) : std::array<Vertex3u<T>, 3>{ copy[0], copy[1], copy[2] } {}

	template <class T>
	template <typename V>
	inline Matrix3u<T> & Matrix3u<T>::operator=(const Matrix3u<V> & copy)
	{
		(*this)[0] = copy[0];
		(*this)[1] = copy[1];
		(*this)[2] = copy[2];
		return *this;
	}

	template <class T>
	inline Matrix3u<T>& Matrix3u<T>::setIdentity()
	{
		(*this)[0] = { 1, 0, 0 };
		(*this)[1] = { 0, 1, 0 };
		(*this)[2] = { 0, 0, 1 };
		return *this;
	}

	template <class T>
	template<typename V>
	inline Matrix3u<T>& Matrix3u<T>::operator/=(const V value)
	{
		if (value == 0) {
			throw DivideByZeroException("Matrix3u");
		}
		(*this)[0] /= value;
		(*this)[1] /= value;
		(*this)[2] /= value;
		return *this;
	}

	template <class T>
	template<typename V>
	inline Matrix3u<T> & Matrix3u<T>::operator*=(const V value)
	{
		(*this)[0] *= value;
		(*this)[1] *= value;
		(*this)[2] *= value;
		return *this;
	}

	template <class T>
	template <typename V>
	inline Matrix3u<T> & Matrix3u<T>::operator*=(const Matrix3u<V> value)
	{
		T a11 = (*this)[0][0] * value[0][0] + (*this)[0][1] * value[1][0] + (*this)[0][2] * value[2][0];
		T a12 = (*this)[0][0] * value[0][1] + (*this)[0][1] * value[1][1] + (*this)[0][2] * value[2][1];
		T a13 = (*this)[0][0] * value[0][2] + (*this)[0][1] * value[1][2] + (*this)[0][2] * value[2][2];
		T a21 = (*this)[1][0] * value[0][0] + (*this)[1][1] * value[1][0] + (*this)[1][2] * value[2][0];
		T a22 = (*this)[1][0] * value[0][1] + (*this)[1][1] * value[1][1] + (*this)[1][2] * value[2][1];
		T a23 = (*this)[1][0] * value[0][2] + (*this)[1][1] * value[1][2] + (*this)[1][2] * value[2][2];
		T a31 = (*this)[2][0] * value[0][0] + (*this)[2][1] * value[1][0] + (*this)[2][2] * value[2][0];
		T a32 = (*this)[2][0] * value[0][1] + (*this)[2][1] * value[1][1] + (*this)[2][2] * value[2][1];
		T a33 = (*this)[2][0] * value[0][2] + (*this)[2][1] * value[1][2] + (*this)[2][2] * value[2][2];
		(*this)[0][0] = a11;
		(*this)[0][1] = a12;
		(*this)[0][2] = a13;
		(*this)[1][0] = a21;
		(*this)[1][1] = a22;
		(*this)[1][2] = a23;
		(*this)[2][0] = a31;
		(*this)[2][1] = a32;
		(*this)[2][2] = a33;
		return *this;
	}

	template <class T>
	inline Matrix3u<T> & Matrix3u<T>::operator+=(const Matrix3u<T> value)
	{
		(*this)[0] += value[0];
		(*this)[1] += value[1];
		(*this)[2] += value[2];
		return *this;
	}

	template <class T>
	inline Matrix3u<T> & Matrix3u<T>::operator-=(const Matrix3u<T> value)
	{
		(*this)[0] -= value[0];
		(*this)[1] -= value[1];
		(*this)[2] -= value[2];
		return *this;
	}

	template <class T>
	template <typename V>
	inline Matrix3u<T> Matrix3u<T>::operator/(const V value) const
	{
		if (value == 0) {
			throw DivideByZeroException("Matrix3u");
		}
		return Matrix3u<T>{(*this)[0] / value, (*this)[1] / value, (*this)[2] / value};
	}

	template <class T>
	template <typename V>
	inline Matrix3u<T> Matrix3u<T>::operator*(const V value) const
	{
		return Matrix3u<T>{(*this)[0] * value, (*this)[1] * value, (*this)[2] * value};
	}

	template <class T>
	template <typename V>
	inline Vertex3u<T> Matrix3u<T>::operator*(const Vertex3u<V> value) const
	{
		T a11 = (*this)[0][0] * value[0] + (*this)[0][1] * value[1] + (*this)[0][2] * value[2];
		T a21 = (*this)[1][0] * value[0] + (*this)[1][1] * value[1] + (*this)[1][2] * value[2];
		T a31 = (*this)[2][0] * value[0] + (*this)[2][1] * value[1] + (*this)[2][2] * value[2];
		return Vertex3u<T>(a11, a21, a31);
	}

	template <class T>
	template <typename V>
	inline Matrix3u<T> Matrix3u<T>::operator*(const Matrix3u<V> value) const
	{
		T a11 = (*this)[0][0] * value[0][0] + (*this)[0][1] * value[1][0] + (*this)[0][2] * value[2][0];
		T a12 = (*this)[0][0] * value[0][1] + (*this)[0][1] * value[1][1] + (*this)[0][2] * value[2][1];
		T a13 = (*this)[0][0] * value[0][2] + (*this)[0][1] * value[1][2] + (*this)[0][2] * value[2][2];
		T a21 = (*this)[1][0] * value[0][0] + (*this)[1][1] * value[1][0] + (*this)[1][2] * value[2][0];
		T a22 = (*this)[1][0] * value[0][1] + (*this)[1][1] * value[1][1] + (*this)[1][2] * value[2][1];
		T a23 = (*this)[1][0] * value[0][2] + (*this)[1][1] * value[1][2] + (*this)[1][2] * value[2][2];
		T a31 = (*this)[2][0] * value[0][0] + (*this)[2][1] * value[1][0] + (*this)[2][2] * value[2][0];
		T a32 = (*this)[2][0] * value[0][1] + (*this)[2][1] * value[1][1] + (*this)[2][2] * value[2][1];
		T a33 = (*this)[2][0] * value[0][2] + (*this)[2][1] * value[1][2] + (*this)[2][2] * value[2][2];
		return Matrix3u<T>(a11, a12, a13, 
						   a21, a22, a23,
						   a31, a32, a33);
	}

	template <class T>
	inline Matrix3u<T> Matrix3u<T>::operator+(const Matrix3u<T> value) const
	{
		return Matrix3u<T>{(*this)[0] + value[0], (*this)[1] + value[1], (*this)[2] + value[2]};
	}

	template <class T>
	inline Matrix3u<T> Matrix3u<T>::operator-(const Matrix3u<T> value) const
	{
		return Matrix3u<T>{(*this)[0] - value[0], (*this)[1] - value[1], (*this)[2] - value[2]};
	}

	template <class T>
	inline Matrix3u<T> Matrix3u<T>::operator-() const
	{
		return Matrix3u<T>{-(*this)[0], -(*this)[1], -(*this)[2]};
	}

	template <class T>
	inline bool Matrix3u<T>::operator==(const Matrix3u<T> & rightOperand) const
	{
		return (*this)[0] == rightOperand[0] && (*this)[1] == rightOperand[1] && (*this)[2] == rightOperand[2];
	}

	template <class T>
	inline Vertex3u<T> Matrix3u<T>::getColumn(const int index) const
	{
		return Vertex3u<T>((*this)[0][index], (*this)[1][index], (*this)[2][index]);
	}

	template <class T>
	inline Vertex3u<T> Matrix3u<T>::getRow(const int index) const
	{
		return Vertex3u<T>((*this)[index]);
	}

	template <class T>
	inline Vertex3u<T> & Matrix3u<T>::getRow(const int index)
	{
		return (*this)[index];
	}

	template<class T>
	inline T Matrix3u<T>::determinant() const
	{
		return (*this)[0][0] * (*this)[1][1] * (*this)[2][2]
			 + (*this)[0][1] * (*this)[1][2] * (*this)[2][0]
			 + (*this)[0][2] * (*this)[1][0] * (*this)[2][1]
			 - (*this)[0][2] * (*this)[1][1] * (*this)[2][0]
			 - (*this)[0][1] * (*this)[1][0] * (*this)[2][2]
			 - (*this)[0][0] * (*this)[1][2] * (*this)[2][1];
	}

	template<class T>
	inline Matrix3u<T> Matrix3u<T>::transpose() const
	{
		return Matrix3u<T>((*this)[0][0], (*this)[1][0], (*this)[2][0], 
						   (*this)[0][1], (*this)[1][1], (*this)[2][1],
						   (*this)[0][2], (*this)[1][2], (*this)[2][2]);
	}

	template<class T>
	inline Matrix3u<T> Matrix3u<T>::inverse(bool & invertible) const
	{
		auto det = this->determinant();
		invertible = (det != 0);
		if (invertible) {
			T a11 = (*this)[1][1] * (*this)[2][2] - (*this)[1][2] * (*this)[2][1];
			T a12 = (*this)[0][2] * (*this)[2][1] - (*this)[0][1] * (*this)[2][2];
			T a13 = (*this)[0][1] * (*this)[1][2] - (*this)[0][2] * (*this)[1][1];
			T a21 = (*this)[1][2] * (*this)[2][0] - (*this)[1][0] * (*this)[2][2];
			T a22 = (*this)[0][0] * (*this)[2][2] - (*this)[0][2] * (*this)[2][0];
			T a23 = (*this)[0][2] * (*this)[1][0] - (*this)[0][0] * (*this)[1][2];
			T a31 = (*this)[1][0] * (*this)[2][1] - (*this)[1][1] * (*this)[2][0];
			T a32 = (*this)[0][1] * (*this)[2][0] - (*this)[0][0] * (*this)[2][1];
			T a33 = (*this)[0][0] * (*this)[1][1] - (*this)[0][1] * (*this)[1][0];

			return Matrix3u<T>(a11, a12, a13, 
							   a21, a22, a23,
							   a31, a32, a33) * (1.0f / det);
		}
		else {
			return Matrix3u<T>();
		}
	}
}