#include "utility/debug/exception.hpp"

namespace ece
{
	template<>
	inline int Matrix3u<int>::determinant() const
	{
		return (*this)[0][0] * (*this)[1][1] * (*this)[2][2]
			 + (*this)[0][1] * (*this)[1][2] * (*this)[2][0]
			 + (*this)[0][2] * (*this)[1][0] * (*this)[2][1]
			 - (*this)[0][2] * (*this)[1][1] * (*this)[2][0]
			 - (*this)[0][1] * (*this)[1][0] * (*this)[2][2]
			 - (*this)[0][0] * (*this)[1][2] * (*this)[2][1];
	}

	template<>
	inline unsigned int Matrix3u<unsigned int>::determinant() const
	{
		return (*this)[0][0] * (*this)[1][1] * (*this)[2][2]
			+ (*this)[0][1] * (*this)[1][2] * (*this)[2][0]
			+ (*this)[0][2] * (*this)[1][0] * (*this)[2][1]
			- (*this)[0][2] * (*this)[1][1] * (*this)[2][0]
			- (*this)[0][1] * (*this)[1][0] * (*this)[2][2]
			- (*this)[0][0] * (*this)[1][2] * (*this)[2][1];
	}

	template<>
	inline float Matrix3u<float>::determinant() const
	{
		return (*this)[0][0] * (*this)[1][1] * (*this)[2][2]
			+ (*this)[0][1] * (*this)[1][2] * (*this)[2][0]
			+ (*this)[0][2] * (*this)[1][0] * (*this)[2][1]
			- (*this)[0][2] * (*this)[1][1] * (*this)[2][0]
			- (*this)[0][1] * (*this)[1][0] * (*this)[2][2]
			- (*this)[0][0] * (*this)[1][2] * (*this)[2][1];
	}

	template<>
	inline double Matrix3u<double>::determinant() const
	{
		return (*this)[0][0] * (*this)[1][1] * (*this)[2][2]
			+ (*this)[0][1] * (*this)[1][2] * (*this)[2][0]
			+ (*this)[0][2] * (*this)[1][0] * (*this)[2][1]
			- (*this)[0][2] * (*this)[1][1] * (*this)[2][0]
			- (*this)[0][1] * (*this)[1][0] * (*this)[2][2]
			- (*this)[0][0] * (*this)[1][2] * (*this)[2][1];
	}

	template<>
	inline Matrix3u<int> Matrix3u<int>::transpose() const
	{
		return Matrix3u<int>{ (*this)[0][0], (*this)[1][0], (*this)[2][0],
							  (*this)[0][1], (*this)[1][1], (*this)[2][1],
							  (*this)[0][2], (*this)[1][2], (*this)[2][2] };
	}

	template<>
	inline Matrix3u<unsigned int> Matrix3u<unsigned int>::transpose() const
	{
		return Matrix3u<unsigned int>{ (*this)[0][0], (*this)[1][0], (*this)[2][0],
									   (*this)[0][1], (*this)[1][1], (*this)[2][1],
									   (*this)[0][2], (*this)[1][2], (*this)[2][2] };
	}

	template<>
	inline Matrix3u<float> Matrix3u<float>::transpose() const
	{
		return Matrix3u<float>{ (*this)[0][0], (*this)[1][0], (*this)[2][0],
								(*this)[0][1], (*this)[1][1], (*this)[2][1],
								(*this)[0][2], (*this)[1][2], (*this)[2][2] };
	}

	template<>
	inline Matrix3u<double> Matrix3u<double>::transpose() const
	{
		return Matrix3u<double>{ (*this)[0][0], (*this)[1][0], (*this)[2][0],
								 (*this)[0][1], (*this)[1][1], (*this)[2][1],
								 (*this)[0][2], (*this)[1][2], (*this)[2][2] };
	}

	template<>
	inline Matrix3u<double> Matrix3u<int>::inverse(bool & invertible) const
	{
		auto det = this->determinant();
		invertible = (det != 0);
		if (invertible) {
			double a11 = (*this)[1][1] * (*this)[2][2] - (*this)[1][2] * (*this)[2][1];
			double a12 = (*this)[0][2] * (*this)[2][1] - (*this)[0][1] * (*this)[2][2];
			double a13 = (*this)[0][1] * (*this)[1][2] - (*this)[0][2] * (*this)[1][1];
			double a21 = (*this)[1][2] * (*this)[2][0] - (*this)[1][0] * (*this)[2][2];
			double a22 = (*this)[0][0] * (*this)[2][2] - (*this)[0][2] * (*this)[2][0];
			double a23 = (*this)[0][2] * (*this)[1][0] - (*this)[0][0] * (*this)[1][2];
			double a31 = (*this)[1][0] * (*this)[2][1] - (*this)[1][1] * (*this)[2][0];
			double a32 = (*this)[0][1] * (*this)[2][0] - (*this)[0][0] * (*this)[2][1];
			double a33 = (*this)[0][0] * (*this)[1][1] - (*this)[0][1] * (*this)[1][0];

			return Matrix3u<double>{ a11, a12, a13,
									a21, a22, a23,
									a31, a32, a33 } *(1.0f / det);
		}
		else {
			return Matrix3u<double>();
		}
	}

	template<>
	inline Matrix3u<double> Matrix3u<unsigned int>::inverse(bool & invertible) const
	{
		auto det = this->determinant();
		invertible = (det != 0);
		if (invertible) {
			double a11 = (*this)[1][1] * (*this)[2][2] - (*this)[1][2] * (*this)[2][1];
			double a12 = (*this)[0][2] * (*this)[2][1] - (*this)[0][1] * (*this)[2][2];
			double a13 = (*this)[0][1] * (*this)[1][2] - (*this)[0][2] * (*this)[1][1];
			double a21 = (*this)[1][2] * (*this)[2][0] - (*this)[1][0] * (*this)[2][2];
			double a22 = (*this)[0][0] * (*this)[2][2] - (*this)[0][2] * (*this)[2][0];
			double a23 = (*this)[0][2] * (*this)[1][0] - (*this)[0][0] * (*this)[1][2];
			double a31 = (*this)[1][0] * (*this)[2][1] - (*this)[1][1] * (*this)[2][0];
			double a32 = (*this)[0][1] * (*this)[2][0] - (*this)[0][0] * (*this)[2][1];
			double a33 = (*this)[0][0] * (*this)[1][1] - (*this)[0][1] * (*this)[1][0];

			return Matrix3u<double>{ a11, a12, a13,
									a21, a22, a23,
									a31, a32, a33 } *(1.0f / det);
		}
		else {
			return Matrix3u<double>();
		}
	}

	template<>
	inline Matrix3u<double> Matrix3u<float>::inverse(bool & invertible) const
	{
		auto det = this->determinant();
		invertible = (det != 0);
		if (invertible) {
			double a11 = (*this)[1][1] * (*this)[2][2] - (*this)[1][2] * (*this)[2][1];
			double a12 = (*this)[0][2] * (*this)[2][1] - (*this)[0][1] * (*this)[2][2];
			double a13 = (*this)[0][1] * (*this)[1][2] - (*this)[0][2] * (*this)[1][1];
			double a21 = (*this)[1][2] * (*this)[2][0] - (*this)[1][0] * (*this)[2][2];
			double a22 = (*this)[0][0] * (*this)[2][2] - (*this)[0][2] * (*this)[2][0];
			double a23 = (*this)[0][2] * (*this)[1][0] - (*this)[0][0] * (*this)[1][2];
			double a31 = (*this)[1][0] * (*this)[2][1] - (*this)[1][1] * (*this)[2][0];
			double a32 = (*this)[0][1] * (*this)[2][0] - (*this)[0][0] * (*this)[2][1];
			double a33 = (*this)[0][0] * (*this)[1][1] - (*this)[0][1] * (*this)[1][0];

			return Matrix3u<double>{ a11, a12, a13,
									a21, a22, a23,
									a31, a32, a33 } *(1.0f / det);
		}
		else {
			return Matrix3u<double>();
		}
	}

	template<>
	inline Matrix3u<double> Matrix3u<double>::inverse(bool & invertible) const
	{
		auto det = this->determinant();
		invertible = (det != 0);
		if (invertible) {
			double a11 = (*this)[1][1] * (*this)[2][2] - (*this)[1][2] * (*this)[2][1];
			double a12 = (*this)[0][2] * (*this)[2][1] - (*this)[0][1] * (*this)[2][2];
			double a13 = (*this)[0][1] * (*this)[1][2] - (*this)[0][2] * (*this)[1][1];
			double a21 = (*this)[1][2] * (*this)[2][0] - (*this)[1][0] * (*this)[2][2];
			double a22 = (*this)[0][0] * (*this)[2][2] - (*this)[0][2] * (*this)[2][0];
			double a23 = (*this)[0][2] * (*this)[1][0] - (*this)[0][0] * (*this)[1][2];
			double a31 = (*this)[1][0] * (*this)[2][1] - (*this)[1][1] * (*this)[2][0];
			double a32 = (*this)[0][1] * (*this)[2][0] - (*this)[0][0] * (*this)[2][1];
			double a33 = (*this)[0][0] * (*this)[1][1] - (*this)[0][1] * (*this)[1][0];

			return Matrix3u<double>{ a11, a12, a13,
									a21, a22, a23,
									a31, a32, a33 } *(1.0f / det);
		}
		else {
			return Matrix3u<double>();
		}
	}
}