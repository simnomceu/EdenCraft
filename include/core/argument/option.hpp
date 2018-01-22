#ifndef OPTION_HPP
#define OPTION_HPP

#include <string>
#include <memory>
#include <functional>

#include "core/argument/option_value.hpp"

namespace ece
{
	class Option
	{
	public:
		Option() = delete;
		inline Option(const std::string & name, const std::shared_ptr<OptionValue> & value, const std::function<void(const std::string &)> & command);
		Option(const Option & copy) = default;
		Option(Option && move) = default;

		~Option() = default;

		Option & operator=(const Option & copy) = default;
		Option & operator=(Option && move) = default;

		bool apply(const std::string & optionName, const std::string & optionValue = "");

	private:
		std::string _name;
		std::shared_ptr<OptionValue> _value;
		std::function<void(const std::string &)> _command;
	};
}

#include "core/argument/option.inl"

#endif // OPTION_HPP