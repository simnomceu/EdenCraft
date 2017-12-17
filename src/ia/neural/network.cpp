#include "ia/neural/network.hpp"

namespace ece
{
	Network::Network(const int nbInputs, const int nbOutputs, const double threshold, const double learningFactor) : 
		inputLayer(nbInputs, 1, threshold), 
		hiddenLayers(), 
		outputLayer(nbOutputs, 1, threshold),
		learningFactor(learningFactor)
	{
		hiddenLayers.resize(1);
		hiddenLayers[0] = Layer((nbInputs + nbOutputs) / 2, nbInputs, threshold);
	}

	std::vector<double> Network::evaluate(const std::vector<double> & inputs)
	{
		auto hiddenInputs = this->inputLayer.evaluate(inputs, true);
		auto outputInputs = this->hiddenLayers[0].evaluate(hiddenInputs);
		auto result = this->outputLayer.evaluate(outputInputs);
	}

	void Network::learn(const std::vector<double> & inputs, const std::vector<double> & result, const std::vector<double> & output)
	{
		double delta = (result[0] - output[0]) * this->learningFactor;
		auto fix = inputs;
		for (auto & it : fix) {
			it *= delta;
		}
		this->inputLayer.learn(fix, delta);
	}
}