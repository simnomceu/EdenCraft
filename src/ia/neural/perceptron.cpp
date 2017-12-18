#include "ia/neural/perceptron.hpp"

#include <iostream>

namespace ece
{
	Perceptron::Perceptron(const int nbInputs, const double learningFactor, const double threshold) :
		learningFactor(learningFactor), neurone(sigmoid, nbInputs), bias(threshold)
	{
	}

	double Perceptron::evaluate(const std::vector<double> & inputs)
	{
		return this->neurone.evaluate(inputs, this->bias);
	}

	void Perceptron::learn(const std::vector<double> & inputs, const double result, const double output)
	{
		double delta = (result - output) * learningFactor;
		auto fix = inputs;
		for (auto & it : fix) {
			it *= delta;
		}
		this->bias += delta;
		this->neurone.learn(fix);
	}
}