#include <cmath>
#include <iostream>
#include "teacher.hpp"

namespace ece
{
	inline Teacher::Teacher(const double thresholdError): thresholdError(thresholdError)
	{
	}

	void Teacher::teachTo(const Epoch & epoch, Perceptron & perceptron)
	{
		int count = 0;
		std::vector<double> errors(epoch.patterns.size());
		double error = 0.0;
		std::cout << "========== Pattern " << epoch.name << " ==========" << std::endl;
		do {
			error = 0;
			std::cout << "Epoch " << count << " | Output: ";
			for (unsigned int i = 0; i < epoch.patterns.size(); ++i) {
				auto output = perceptron.evaluate(epoch.patterns[i].inputs);
				perceptron.learn(epoch.patterns[i].inputs, epoch.patterns[i].result, output);
				errors[i] = std::fabs(epoch.patterns[i].result - output);
				error += errors[i];
				std::cout << output << "|";
			}
			error /= epoch.patterns.size();
			std::cout << "Error: " << error << std::endl;
			++count;
		} while (error > this->thresholdError);
		std::cout << "========== Learning " << epoch.name << " completed ==========" << std::endl << std::endl;
	}
}