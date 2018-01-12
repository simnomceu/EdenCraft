#ifndef ENUM_FLAGS_HPP
#define ENUM_FLAGS_HPP

#include <type_traits>

namespace ece
{
/**
 * @def ENUM_FLAGS_OPERATOR(NAME, OP)
 * @brief Defines a specific overloaded bit to bit operator for a specific class.
 */
#define ENUM_FLAGS_OPERATOR(NAME, OP) \
	inline constexpr NAME operator OP(NAME leftHandSide, NAME rightHandSide) noexcept \
	{ return static_cast<NAME>(static_cast<std::underlying_type_t<NAME>>(leftHandSide) OP static_cast<std::underlying_type_t<NAME>>(rightHandSide)); }

/**
 * @def ENUM_FLAGS_OPERATOR_OVERLOAD(NAME)
 * @brief Defines all bit to bit operators for a specific class.
 */
#define ENUM_FLAGS_OPERATOR_OVERLOAD(NAME) \
	inline constexpr NAME operator ~(NAME value) noexcept \
	{ return static_cast<NAME>(~static_cast<std::underlying_type_t<NAME>>(value)); } \
	ENUM_FLAGS_OPERATOR(NAME, |) \
	ENUM_FLAGS_OPERATOR(NAME, &) \
	ENUM_FLAGS_OPERATOR(NAME, ^)

/**
 * @def EnumFlagsT(TYPE, NAME)
 * @brief Defines a C++14 enumeration to be used has C-like tags.
 * Thus, things like MyEnum::A | MyEnum::B make sense now.
 */
#define EnumFlagsT(TYPE, NAME) \
	enum class NAME; \
	ENUM_FLAGS_OPERATOR_OVERLOAD(NAME) \
	enum class NAME : TYPE

/**
 * @def EnumFlags(NAME)
 * @brief Defines a C++14 enumeration to be used has C-like tags, with default type as char.
 */
#define EnumFlags(NAME) \
	EnumFlagsT(char, NAME)
}

#endif // ENUM_FLAGS_HPP
