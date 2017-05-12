#ifndef OPTIONVALUE_HPP
#define OPTIONVALUE_HPP

#include <string>

namespace ece
{
	class OptionValue
	{
	public:
		OptionValue() = default;
		OptionValue(const OptionValue & copy) = default;
		OptionValue(OptionValue && move) = default;

		~OptionValue() = default;

		OptionValue & operator=(const OptionValue & copy) = delete;
		OptionValue & operator=(OptionValue && move) = delete;

		virtual bool isValid(const std::string & value) = 0;
	};
}

#endif // OPTIONVALUE_HPP