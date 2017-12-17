#include "ia/neural/perceptron.hpp"

#include <iostream>

namespace ece
{
	Perceptron::Perceptron(const int nbInputs, const double learningFactor, const double threshold) :
		learningFactor(learningFactor), layer(1, nbInputs, threshold)
	{
	}

	double Perceptron::evaluate(const std::vector<double> & inputs)
	{
		return layer.evaluate(inputs)[0];
	}

	void Perceptron::learn(const std::vector<double> & inputs, const double result, const double output)
	{
		double delta = (result - output) * learningFactor;
		auto fix = inputs;
		for (auto & it : fix) {
			it *= delta;
		}
		this->layer.learn(fix, delta);
	}
}