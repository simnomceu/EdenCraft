#include "core/argument/argument_analyzer.hpp"

namespace ece
{
	void ArgumentAnalyzer::setParameters(int argc, char * argv[])
	{
		for (int i = 1; i < argc; i++) {
			if (argv[i][0] == '-') {
				this->_parameters.push_back(std::make_pair<std::string, std::string>(argv[i], ""));
			}
			else {
				if (!this->_parameters.empty()) {
					if (!this->_parameters.back().second.empty()) {
						throw std::runtime_error("Invalid arguments: " + std::string(argv[i]));
					}
					this->_parameters.back().second = argv[i];
				}
				else {
					throw std::runtime_error("Parameter without argument: " + std::string(argv[i]));
				}
			}
		}
	}

	void ArgumentAnalyzer::analyse()
	{
		for (auto it = this->_parameters.begin(); it != this->_parameters.end(); ++it) {
			bool analyzed = false;
			auto option = this->_options.begin();
			while (!analyzed && option != this->_options.end()) {
				analyzed = option->apply(it->first, it->second);
				++option;
			}
			if (option == this->_options.end() && !analyzed) {
				throw std::runtime_error("Unknown argument: " + it->first);
			}
		}
	}
}