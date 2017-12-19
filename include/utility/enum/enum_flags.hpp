#ifndef ENUM_FLAGS_HPP
#define ENUM_FLAGS_HPP

#include <type_traits>

namespace ece
{
/**
 * @define ENUM_FLAGS_OPERATOR
 * @brief
 */
#define ENUM_FLAGS_OPERATOR(NAME, OP) \
	inline constexpr NAME operator OP(NAME leftHandSide, NAME rightHandSide) noexcept \
	{ return static_cast<NAME>(static_cast<std::underlying_type_t<NAME>>(leftHandSide) OP static_cast<std::underlying_type_t<NAME>>(rightHandSide)); }

/**
 * @define ENUM_FLAGS_OPERATOR_OVERLOAD
 * @brief
 */
#define ENUM_FLAGS_OPERATOR_OVERLOAD(NAME) \
	inline constexpr NAME operator ~(NAME value) noexcept \
	{ return static_cast<NAME>(~static_cast<std::underlying_type_t<NAME>>(value)); } \
	ENUM_FLAGS_OPERATOR(NAME, |) \
	ENUM_FLAGS_OPERATOR(NAME, &) \
	ENUM_FLAGS_OPERATOR(NAME, ^)

/**
 * @define EnumFlagsT
 * @brief
 */
#define EnumFlagsT(TYPE, NAME) \
	enum class NAME; \
	ENUM_FLAGS_OPERATOR_OVERLOAD(NAME) \
	enum class NAME : TYPE

/**
 * @define EnumFlags
 * @brief
 */
#define EnumFlags(NAME) \
	EnumFlagsT(char, NAME)
}

#endif // ENUM_FLAGS_HPP
