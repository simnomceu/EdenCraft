#include <iostream>

#ifdef _MSC_VER
#	undef min
#	undef max
#endif

namespace ece
{
	template <class E1, class E2, class Op>
	inline VectorOperation<E1, E2, Op>::VectorOperation(const E1 & lhs, const E2 & rhs) noexcept: VectorExpression<VectorOperation<E1, E2, Op>>(), _lhs(lhs), _rhs(rhs) {}

	template <class E1, class E2, class Op>
	auto VectorOperation<E1, E2, Op>::operator[](const unsigned int index) const { return std::invoke(Op(), this->_lhs[index], this->_rhs[index]); }

	template <class E1, class E2, class Op>
	inline unsigned int VectorOperation<E1, E2, Op>::size() const { return std::max(this->_lhs.size(), this->_rhs.size()); }

	template <class E, class Op>
	inline VectorUnaryOperation<E, Op>::VectorUnaryOperation(const E & lhs) noexcept: VectorExpression<VectorUnaryOperation<E, Op>>(), _lhs(lhs) {}

	template <class E, class Op>
	auto VectorUnaryOperation<E, Op>::operator[](const unsigned int index) const { return std::invoke(Op(), this->_lhs[index]); }

	template <class E, class Op>
	inline unsigned int VectorUnaryOperation<E, Op>::size() const { return this->_lhs.size(); }
}