#ifndef ENUM_OPTION_VALUE_HPP
#define ENUM_OPTION_VALUE_HPP

#include <vector>
#include <string>

#include "core/argument/option_value.hpp"

namespace ece
{
	class EnumOptionValue : public OptionValue
	{
	public:
		EnumOptionValue() = default;
		EnumOptionValue(const EnumOptionValue & copy) = default;
		EnumOptionValue(EnumOptionValue && move) = default;

		~EnumOptionValue() = default;

		EnumOptionValue & operator=(const EnumOptionValue & copy) = default;
		EnumOptionValue & operator=(EnumOptionValue && move) = default;

		inline virtual bool isValid(const std::string & value) override;

		inline void addValue(const std::string & value);

	private:
		std::vector<std::string> values;
	};
}

#include "core/argument/enum_option_value.inl"

#endif // ENUM_OPTION_VALUE_HPP