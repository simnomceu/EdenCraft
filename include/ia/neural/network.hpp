#ifndef NETWORK_HPP
#define NETWORK_HPP

#include "ia/neural/layer.hpp"

namespace ece
{
	template <unsigned int Input, unsigned int Output, unsigned int Hidden>
	class Network
	{
	public:
		Network() = delete;
		Network(const SPLIT_RULE splitRule, const double threshold, const double learningFactor);
		Network(const Network & copy) = default;
		Network(Network && move) = default;

		~Network() = default;

		Network & operator=(const Network & copy) = default;
		Network & operator=(Network && move) = default;

		std::vector<double> evaluate(const std::vector<double> & inputs);
		void learn(const std::vector<double> & inputs, const std::vector<double> & results);

	private:
		Layer<Input> inputLayer;
		std::array<Layer<(Input + Output) / 2>, Hidden> hiddenLayers;
		Layer<Output> outputLayer;

		double learningFactor;
	};
}

#include "ia/neural/network.inl"

#endif // NETWORK_HPP
