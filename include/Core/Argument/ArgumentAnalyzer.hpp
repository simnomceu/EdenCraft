#ifndef ARGUMENTANALYZER_HPP
#define ARGUMENTANALYZER_HPP

#include <vector>

#include "Argument\Option.hpp"

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

#include "Argument\ArgumentAnalyzer.inl"

#endif // ARGUMENTANALYZER_HPP