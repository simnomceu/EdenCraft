#ifndef ENUMOPTIONVALUE_HPP
#define ENUMOPTIONVALUE_HPP

#include <vector>
#include <string>

#include "System\Argument\OptionValue.hpp"

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

#include "System\Argument\EnumOptionValue.inl"

#endif // ENUMOPTIONVALUE_HPP