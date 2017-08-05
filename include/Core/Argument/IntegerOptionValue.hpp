#ifndef INTEGEROPTIONVALUE_HPP
#define INTEGEROPTIONVALUE_HPP

#include "Argument\OptionValue.hpp"

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

#include "Argument\IntegerOptionValue.inl"

#endif // INTEGEROPTIONVALUE_HPP