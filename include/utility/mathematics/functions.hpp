#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP

#include <cmath>

namespace ece
{
	inline double heaviside(const double value) noexcept;

	inline double halfMaxHeaviside(const double value) noexcept;

	inline double sigmoid(const double value) noexcept;
}

#include "utility/mathematics/functions.inl"

#endif // FUNCTIONS_HPP
