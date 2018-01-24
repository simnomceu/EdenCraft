#ifndef ENUM_COUNT_HPP
#define ENUM_COUNT_HPP

#include <type_traits>

namespace ece
{
	template <typename T, typename = typename std::enable_if_t<std::is_enum_v<T>>>
	struct EnumCount
	{
		static constexpr unsigned short int value = 0;
	};

	template <typename T>
	inline constexpr unsigned short int EnumCount_v = EnumCount<T>::value;
}

#endif // ENUM_COUNT_HPP