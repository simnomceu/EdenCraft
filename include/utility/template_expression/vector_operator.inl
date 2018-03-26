namespace ece
{
	template <class E1, class E2>
	inline VectorSum<E1, E2>::VectorSum(const E1 & lhs, const E2 & rhs) noexcept: _lhs(lhs), _rhs(rhs) {}

	template <class E1, class E2>
	inline auto VectorSum<E1, E2>::operator[](const unsigned int index) const { return this->_lhs[index] + this->_rhs[index]; }

	template <class E1, class E2>
	inline unsigned int VectorSum<E1, E2>::size() const { return this->_lhs.size(); }

	template <class E1, class E2, typename enabled>
	VectorSum<E1, E2> operator+(const E1 & lhs, const E2 & rhs) { return VectorSum<E1, E2>(lhs, rhs); }

	template <class E1, class E2>
	inline VectorSubtract<E1, E2>::VectorSubtract(const E1 & lhs, const E2 & rhs) noexcept: _lhs(lhs), _rhs(rhs) {}

	template <class E1, class E2>
	inline auto VectorSubtract<E1, E2>::operator[](const unsigned int index) const { return this->_lhs[index] - this->_rhs[index]; }

	template <class E1, class E2>
	inline unsigned int VectorSubtract<E1, E2>::size() const { return this->_lhs.size(); }

	template <class E1, class E2, typename enabled>
	VectorSubtract<E1, E2> operator-(const E1 & lhs, const E2 & rhs) { return VectorSubtract<E1, E2>(lhs, rhs); }
}