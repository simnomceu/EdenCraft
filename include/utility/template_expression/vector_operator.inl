namespace ece
{
	template <typename T1, typename T2, unsigned int Size>
	inline VectorSum<T1, T2, Size>::VectorSum(const Vector<T1, Size> & lhs, const Vector<T2, Size> & rhs) noexcept: _lhs(lhs), _rhs(rhs) {}

	template <typename T1, typename T2, unsigned int Size>
	inline std::common_type_t<T1, T2> VectorSum<T1, T2, Size>::operator[](const unsigned int index) const
	{
		return static_cast<std::common_type_t<T1, T2>>(this->_lhs[index]) + static_cast<std::common_type_t<T1, T2>>(this->_rhs[index]);
	}

	template <typename T1, typename T2, unsigned int Size>
	inline unsigned int VectorSum<T1, T2, Size>::size() const { return this->_lhs.size(); }

	template <typename T1, typename T2, unsigned int Size>
	VectorSum<T1, T2, Size> operator+(const VectorExpression<Vector<T1, Size>, T1> & lhs, const VectorExpression<Vector<T2, Size>, T2> & rhs) { return VectorSum<T1, T2, Size>(lhs, rhs); }
}