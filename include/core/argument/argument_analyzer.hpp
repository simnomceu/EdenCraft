#ifndef ARGUMENT_ANALYZER_HPP
#define ARGUMENT_ANALYZER_HPP

#include <vector>

#include "argument/option.hpp"

namespace ece
{
	class ArgumentAnalyzer
	{
	public:
		ArgumentAnalyzer() = default;
		ArgumentAnalyzer(const ArgumentAnalyzer & copy) = default;
		ArgumentAnalyzer(ArgumentAnalyzer && move) = default;

		~ArgumentAnalyzer() = default;

		ArgumentAnalyzer & operator=(const ArgumentAnalyzer & copy) = default;
		ArgumentAnalyzer & operator=(ArgumentAnalyzer && move) = default;

		inline void addOption(const Option & option);

		void setParameters(int argc, char * argv[]);

		void analyse();

	private:
		std::vector<Option> options;
		std::vector<std::pair<std::string, std::string>> parameters;
	};
}

#include "argument/argument_analyzer.inl"

#endif // ARGUMENT_ANALYZER_HPP