#ifndef OPTION_VALUE_HPP
#define OPTION_VALUE_HPP

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

#endif // OPTION_VALUE_HPP