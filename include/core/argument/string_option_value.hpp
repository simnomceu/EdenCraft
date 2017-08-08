#ifndef STRING_OPTION_VALUE_HPP
#define STRING_OPTION_VALUE_HPP

#include <string>

#include "argument\option_value.hpp"

namespace ece
{
	class StringOptionValue: public OptionValue
	{
	public:
		StringOptionValue() = default;
		StringOptionValue(const StringOptionValue & copy) = default;
		StringOptionValue(StringOptionValue && move) = default;

		~StringOptionValue() = default;

		StringOptionValue & operator=(const StringOptionValue & copy) = default;
		StringOptionValue & operator=(StringOptionValue && move) = default;

		inline virtual bool isValid(const std::string & value) override;
	};
}

#include "argument\string_option_value.inl"

#endif // STRING_OPTION_VALUE_HPP
