#ifndef NETWORK_HPP
#define NETWORK_HPP

#include "ia/neural/layer.hpp"

namespace ece
{
	class Network
	{
	public:
		Network() = delete;
		Network(const int nbInputs, const int nbOutputs, const double threshold, const double learningFactor);
		Network(const Network & copy) = default;
		Network(Network && move) = default;

		~Network() = default;

		Network & operator=(const Network & copy) = default;
		Network & operator=(Network && move) = default;

		std::vector<double> evaluate(const std::vector<double> & inputs);
		void learn(const std::vector<double> & inputs, const std::vector<double> & result, const std::vector<double> & output);

	private:
		Layer inputLayer;
		std::vector<Layer> hiddenLayers;
		Layer outputLayer;

		double learningFactor;
	};
}

#endif // NETWORK_HPP
