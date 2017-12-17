#include "ia/neural/layer.hpp"

#include <iostream>
#include <random>

namespace ece
{
	Layer::Layer(const int size, const int nbInputs, const double bias) : neurones(size, Neurone(sigmoid, nbInputs)), bias(bias)
	{
	}

	std::vector<double> Layer::evaluate(const std::vector<double>& inputs, const bool split)
	{
		auto nbInputs = this->neurones.size();
		std::vector<double> output(nbInputs);

		if (!split) {
			for (unsigned int i = 0; i < nbInputs; ++i) {
				output[i] = this->neurones[i].evaluate(inputs, this->bias);
			}
		}
		else {
			for (unsigned int i = 0; i < nbInputs; ++i) {
				output[i] = this->neurones[i].evaluate(std::vector<double>(1, inputs[i]), this->bias);
			}
		}
		return output;
	}

	void Layer::learn(const std::vector<double> & fix, const double delta)
	{
		this->bias += delta;
		for (unsigned short int i = 0; i < this->neurones.size(); ++i) {
			this->neurones[i].learn(fix);
		}
	}
}