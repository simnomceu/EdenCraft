#ifndef STRINGOPTIONVALUE_HPP
#define STRINGOPTIONVALUE_HPP

#include <string>

#include "System\Argument\OptionValue.hpp"

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

#include "System\Argument\StringOptionValue.inl"

#endif // STRINGOPTIONVALUE_HPP
