namespace ece
{
	template <>
	inline int Matrix2u<int>::determinant() const
	{
		return (*this)[0][0] * (*this)[1][1] - (*this)[0][1] * (*this)[1][0];
	}

	template <>
	inline unsigned int Matrix2u<unsigned int>::determinant() const
	{
		return (*this)[0][0] * (*this)[1][1] - (*this)[0][1] * (*this)[1][0];
	}

	template <>
	inline float Matrix2u<float>::determinant() const
	{
		return (*this)[0][0] * (*this)[1][1] - (*this)[0][1] * (*this)[1][0];
	}

	template <>
	inline double Matrix2u<double>::determinant() const
	{
		return (*this)[0][0] * (*this)[1][1] - (*this)[0][1] * (*this)[1][0];
	}

	template<>
	inline Matrix2u<int> Matrix2u<int>::transpose() const
	{
		return Matrix2u<int>{ (*this)[0][0], (*this)[1][0], (*this)[0][1], (*this)[1][1] };
	}

	template<>
	inline Matrix2u<unsigned int> Matrix2u<unsigned int>::transpose() const
	{
		return Matrix2u<unsigned int>{ (*this)[0][0], (*this)[1][0], (*this)[0][1], (*this)[1][1] };
	}

	template<>
	inline Matrix2u<float> Matrix2u<float>::transpose() const
	{
		return Matrix2u<float>{ (*this)[0][0], (*this)[1][0], (*this)[0][1], (*this)[1][1] };
	}

	template<>
	inline Matrix2u<double> Matrix2u<double>::transpose() const
	{
		return Matrix2u<double>{ (*this)[0][0], (*this)[1][0], (*this)[0][1], (*this)[1][1] };
	}

	template<>
	inline Matrix2u<double> Matrix2u<int>::inverse(bool & invertible) const
	{
		auto det = this->determinant();
		invertible = (det != 0);
		if (invertible) {
			return Matrix2u<double>{ static_cast<double>((*this)[1][1]), static_cast<double>(-(*this)[0][1]), 
									static_cast<double>(-(*this)[1][0]), static_cast<double>((*this)[0][0]) } *(1.0f / det);
		}
		else {
			return Matrix2u<double>();
		}
	}

	template<>
	inline Matrix2u<double> Matrix2u<unsigned int>::inverse(bool & invertible) const
	{
		auto det = this->determinant();
		invertible = (det != 0);
		if (invertible) {
			return Matrix2u<double>{ static_cast<double>((*this)[1][1]), static_cast<double>(-(*this)[0][1]), 
									static_cast<double>(-(*this)[1][0]), static_cast<double>((*this)[0][0]) } *(1.0f / det);
		}
		else {
			return Matrix2u<double>();
		}
	}

	template<>
	inline Matrix2u<double> Matrix2u<float>::inverse(bool & invertible) const
	{
		auto det = this->determinant();
		invertible = (det != 0);
		if (invertible) {
			return Matrix2u<double>{ (*this)[1][1], -(*this)[0][1], -(*this)[1][0], (*this)[0][0] } *(1.0f / det);
		}
		else {
			return Matrix2u<double>();
		}
	}

	template<>
	inline Matrix2u<double> Matrix2u<double>::inverse(bool & invertible) const
	{
		auto det = this->determinant();
		invertible = (det != 0);
		if (invertible) {
			return Matrix2u<double>{ (*this)[1][1], -(*this)[0][1], -(*this)[1][0], (*this)[0][0] } *(1.0f / det);
		}
		else {
			return Matrix2u<double>();
		}
	}
}