#include "argument\argument_analyzer.hpp"

namespace ece
{
	void ArgumentAnalyzer::setParameters(int argc, char * argv[])
	{
		for (int i = 1; i < argc; i++) {
			if (argv[i][0] == '-') {
				this->parameters.push_back(std::make_pair<std::string, std::string>(argv[i], ""));
			}
			else {
				if (!this->parameters.empty()) {
					if (!this->parameters.back().second.empty()) {
						throw std::runtime_error("Invalid arguments: " + std::string(argv[i]));
					}
					this->parameters.back().second = argv[i];
				}
				else {
					throw std::runtime_error("Parameter without argument: " + std::string(argv[i]));
				}
			}
		}
	}

	void ArgumentAnalyzer::analyse()
	{
		for (auto it = this->parameters.begin(); it != this->parameters.end(); ++it) {
			bool analyzed = false;
			auto option = this->options.begin();
			while (!analyzed && option != this->options.end()) {
				analyzed = option->apply(it->first, it->second);
				++option;
			}
			if (option == this->options.end() && !analyzed) {
				throw std::runtime_error("Unknown argument: " + it->first);
			}
		}
	}
}