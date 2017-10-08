#ifndef INTEGER_OPTION_VALUE_HPP
#define INTEGER_OPTION_VALUE_HPP

#include "argument/option_value.hpp"

namespace ece
{
	class IntegerOptionValue: public OptionValue
	{
	public:
		IntegerOptionValue() = default;
		IntegerOptionValue(const IntegerOptionValue & copy) = default;
		IntegerOptionValue(IntegerOptionValue && move) = default;

		~IntegerOptionValue() = default;

		IntegerOptionValue & operator=(const IntegerOptionValue & copy) = default;
		IntegerOptionValue & operator=(IntegerOptionValue && move) = default;

		inline virtual bool isValid(const std::string & value) override;
	};
}

#include "argument\integer_option_value.inl"

#endif // INTEGER_OPTION_VALUE_HPP